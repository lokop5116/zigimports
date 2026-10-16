#' Compile and run Zig code from R
#'
#' Compiles 'Zig' source into a temporary shared library with the \code{zig}
#' compiler, loads it, calls it, and cleans up. Requires Zig (0.11 or later)
#' to be installed and on the \code{PATH}, or located through
#' \code{options(zigimports.zig = ...)} or the \code{ZIGIMPORTS_ZIG} environment variable.
#' All build files are written to a temporary directory.
#'
#' There are two modes:
#' \itemize{
#'   \item \strong{Function mode} (\code{fn} given): \code{code} is a complete
#'     Zig source (or the path to a \code{.zig} file) that defines
#'     \code{export fn <fn>}. The function is called with \code{...}. Argument
#'     types are given by \code{args}; if \code{NULL} they are inferred
#'     (length-1 double, integer, logical and string values are passed by
#'     value, longer vectors as pointers). Use \code{args} when a
#'     length-1 vector must be passed as a pointer.
#'   \item \strong{Snippet mode} (\code{fn = NULL}): \code{code} is just a
#'     function body. Each named argument in \code{...} becomes a Zig
#'     parameter with that name: a pointer for numeric, integer and logical
#'     vectors (\code{[*]f64} or \code{[*]i32}) and \code{[*:0]const u8} for
#'     a single string. The vector lengths are available as
#'     \code{zig_lens[i]} in argument order, and \code{std} is already
#'     imported. The body can \code{return} a value if \code{returns} is
#'     set.
#' }
#' See \code{\link{zig_bind}} for the supported types and conventions.
#'
#' @param code Zig source code (character string), or path to a \code{.zig}
#'   file.
#' @param ... Arguments passed to the Zig function. Must be named in snippet
#'   mode.
#' @param fn Name of the exported function to call, or \code{NULL} for snippet
#'   mode.
#' @param args Argument types (function mode only); see \code{\link{zig_bind}}.
#' @param returns Return type of the function or snippet.
#' @param optimize Zig optimisation mode.
#' @param flags Extra command-line flags for \code{zig build-lib}, e.g.
#'   \code{"-lc"}.
#' @param zig Path or name of the Zig compiler. Defaults to
#'   \code{getOption("zigimports.zig")}, then \code{ZIGIMPORTS_ZIG}, then \code{"zig"}.
#' @param keep If \code{TRUE}, keep the temporary build directory and report
#'   its location.
#' @param verbose If \code{TRUE}, show the generated source and compiler
#'   command.
#' @return As for functions created by \code{\link{zig_bind}}: the Zig return
#'   value (with the modified vector arguments in the \code{"args"}
#'   attribute), or, for \code{returns = "void"}, a named list of the
#'   modified vector arguments (invisible \code{NULL} if there are none).
#' @seealso \code{\link{zig_load}}, \code{\link{zig_bind}}
#' @examples
#' if (nzchar(Sys.which("zig"))) {
#'   # Function mode: mixed argument types and a return value
#'   src <- "export fn add(a: i32, b: f64) f64 {
#'     return @as(f64, @floatFromInt(a)) + b;
#'   }"
#'   zig_call(src, fn = "add", args = c("i32", "f64"), returns = "f64",
#'            2L, 0.5)
#'
#' }
#'
#' \donttest{
#' if (nzchar(Sys.which("zig"))) {
#'   # Snippet mode: double every element of a vector
#'   zig_call("
#'     var i: usize = 0;
#'     while (i < @as(usize, @intCast(zig_lens[0]))) : (i += 1) x[i] *= 2;
#'   ", x = c(1, 2, 3))
#' }
#' }
#' @export
zig_call <- function(code, ..., fn = NULL, args = NULL, returns = "void",
                     optimize = c("ReleaseFast", "ReleaseSafe",
                                  "ReleaseSmall", "Debug"),
                     flags = character(), zig = NULL,
                     keep = FALSE, verbose = FALSE) {
  optimize <- match.arg(optimize)
  vals <- list(...)
  rettype <- .norm_ret(returns)
  hidden <- 0L

  if (!is.character(code) || !length(code)) {
    stop("'code' must be a character string of Zig source", call. = FALSE)
  }
  if (length(code) == 1L && grepl("\\.zig$", code) && file.exists(code)) {
    code <- readLines(code, warn = FALSE)
  }
  code <- paste(code, collapse = "\n")

  if (is.null(fn)) {
    # snippet mode
    if (!is.null(args)) {
      stop("'args' is only used in function mode; snippet arguments are typed ",
           "from their R values", call. = FALSE)
    }
    if (grepl("\\bexport\\s+fn\\b", code)) {
      stop("'code' defines exported functions; set 'fn' to the one to call",
           call. = FALSE)
    }
    argtypes <- .snippet_types(vals)
    code <- .wrap_snippet(code, names(vals), argtypes, rettype)
    fn <- "zig_snippet"
    vals <- c(vals, list(zig_lens = as.integer(lengths(vals))))
    argtypes <- c(argtypes, "ptr_i32")
    hidden <- 1L
  } else {
    argtypes <- if (is.null(args)) .infer_types(vals) else .norm_args(args)
  }
  if (length(argtypes) > .ZIGIMPORTS_MAX_ARGS) {
    stop("at most ", .ZIGIMPORTS_MAX_ARGS, " arguments are supported", call. = FALSE)
  }

  zig <- .find_zig(zig)

  build_dir <- tempfile("zigimports_")
  dir.create(build_dir, recursive = TRUE)
  src <- file.path(build_dir, "zigimports_code.zig")
  out <- file.path(build_dir, paste0(basename(build_dir), .lib_ext()))

  writeLines(code, src)
  if (verbose) message("zigimports: source:\n", code)

  loaded <- FALSE
  on.exit({
    if (loaded) try(dyn.unload(out), silent = TRUE)  # unload before deleting (Windows)
    if (keep) {
      message("zigimports: build directory kept at ", build_dir)
    } else {
      unlink(build_dir, recursive = TRUE, force = TRUE)
    }
  }, add = TRUE)

  .compile_zig(src, out, optimize, flags, zig, verbose)

  lib <- zig_load(out)
  loaded <- TRUE
  sym <- .get_symbol(lib, fn)
  .zig_invoke(sym, vals, argtypes, rettype, hidden = hidden)
}

# Snippet mode: every R vector is passed as a pointer
.snippet_types <- function(vals) {
  one <- function(x) {
    if (is.double(x)) {
      "ptr_f64"
    } else if (is.integer(x) || is.logical(x)) {
      "ptr_i32"
    } else if (is.character(x) && length(x) == 1L) {
      "str"
    } else {
      stop("unsupported snippet argument of class '", class(x)[1L],
           "' and length ", length(x), call. = FALSE)
    }
  }
  unname(vapply(vals, one, character(1)))
}

# Turn a function body plus named args into a full Zig source file
.wrap_snippet <- function(code, nm, types, rettype) {
  if (length(types) &&
      (is.null(nm) || any(!nzchar(nm)) ||
       !all(grepl("^[A-Za-z_][A-Za-z0-9_]*$", nm)))) {
    stop("in snippet mode all arguments must be named with valid Zig ",
         "identifiers", call. = FALSE)
  }
  if ("zig_lens" %in% nm) {
    stop("'zig_lens' is a reserved argument name", call. = FALSE)
  }

  zparam <- c(ptr_f64 = "[*]f64", ptr_i32 = "[*]i32", str = "[*:0]const u8")
  zret <- c(void = "void", i32 = "i32", f64 = "f64", bool = "bool",
            str = "[*:0]const u8")

  params <- c(sprintf("%s: %s", nm, unname(zparam[types])), "zig_lens: [*]i32")
  # Reference every parameter so Zig never reports it as unused. A plain
  # `_ = x;` is rejected by newer Zig as a "pointless discard" when the
  # snippet also uses x; `_ = @TypeOf(x);` is accepted in both cases.
  discards <- c(sprintf("    _ = @TypeOf(%s);", nm), "    _ = @TypeOf(zig_lens);")

  paste0(
    "const std = @import(\"std\");\n\n",
    "export fn zig_snippet(", paste(params, collapse = ", "), ") ",
    unname(zret[rettype]), " {\n",
    paste(discards, collapse = "\n"), "\n",
    code, "\n}\n"
  )
}
