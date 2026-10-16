# Internal helpers for zigimports -------------------------------------------------

.ZIGIMPORTS_MAX_ARGS <- 6L

.is_windows <- function() .Platform$OS.type == "windows"

# ".so" on Linux, ".dll" on Windows
.lib_ext <- function() .Platform$dynlib.ext

# Quote a string for the platform's shell (cmd.exe vs sh)
.shq <- function(x) shQuote(x, type = if (.is_windows()) "cmd" else "sh")

# Accepted type names -> canonical type names
.type_map <- c(
  i32 = "i32", int = "i32", integer = "i32", c_int = "i32",
  f64 = "f64", double = "f64", numeric = "f64",
  bool = "bool", logical = "bool",
  void = "void",
  ptr_f64 = "ptr_f64", "[*]f64" = "ptr_f64",
  ptr_i32 = "ptr_i32", "[*]i32" = "ptr_i32", "[*]c_int" = "ptr_i32",
  str = "str", character = "str", string = "str",
  "[*:0]const u8" = "str"
)

# Canonical type -> calling-convention kind used by the C layer
.arg_kind <- c(i32 = "I", bool = "I", f64 = "D",
               ptr_f64 = "P", ptr_i32 = "P", str = "P")
.ret_kind <- c(void = "V", i32 = "I", f64 = "D", bool = "B", str = "S")

.norm_types <- function(x) {
  key <- trimws(as.character(x))
  out <- unname(.type_map[key])
  if (anyNA(out)) {
    stop("unsupported type(s): ", paste0("'", key[is.na(out)], "'", collapse = ", "),
         ". Supported: i32, f64, bool, str, ptr_f64, ptr_i32 (and void for ",
         "return values)", call. = FALSE)
  }
  out
}

.norm_args <- function(args) {
  if (is.null(args) || length(args) == 0L) return(character())
  out <- .norm_types(args)
  if (any(out == "void")) {
    stop("'void' is only valid as a return type", call. = FALSE)
  }
  if (length(out) > .ZIGIMPORTS_MAX_ARGS) {
    stop("at most ", .ZIGIMPORTS_MAX_ARGS, " arguments are supported", call. = FALSE)
  }
  out
}

.norm_ret <- function(returns) {
  if (length(returns) != 1L) {
    stop("'returns' must be a single type", call. = FALSE)
  }
  out <- .norm_types(returns)
  if (out %in% c("ptr_f64", "ptr_i32")) {
    stop("pointer return types are not supported", call. = FALSE)
  }
  out
}

.sig_string <- function(argtypes) {
  paste(unname(.arg_kind[argtypes]), collapse = "")
}

# Guess Zig types from R values (used when 'args' is not given)
.infer_types <- function(vals) {
  one <- function(x) {
    n <- length(x)
    if (is.double(x)) {
      if (n == 1L) "f64" else "ptr_f64"
    } else if (is.integer(x)) {
      if (n == 1L) "i32" else "ptr_i32"
    } else if (is.logical(x)) {
      if (n == 1L) "bool" else "ptr_i32"
    } else if (is.character(x) && n == 1L) {
      "str"
    } else {
      stop("cannot infer a Zig type for an argument of class '", class(x)[1L],
           "' and length ", n, "; use 'args' to be explicit", call. = FALSE)
    }
  }
  unname(vapply(vals, one, character(1)))
}

# Coerce one R value to the representation the C layer expects
.coerce_arg <- function(x, type, i) {
  if (!is.atomic(x) || is.null(x)) {
    stop("argument ", i, " must be an atomic vector", call. = FALSE)
  }
  if (type %in% c("i32", "f64", "bool", "str") && length(x) != 1L) {
    stop("argument ", i, " must have length 1 for type '", type, "'",
         call. = FALSE)
  }
  switch(type,
    i32 = , ptr_i32 = as.integer(x),
    f64 = , ptr_f64 = as.double(x),
    bool = {
      v <- as.logical(x)
      if (is.na(v)) stop("argument ", i, " must not be NA", call. = FALSE)
      as.integer(v)
    },
    str = {
      v <- as.character(x)
      if (is.na(v)) stop("argument ", i, " must not be NA", call. = FALSE)
      enc2utf8(v)
    },
    stop("unknown type '", type, "'", call. = FALSE)
  )
}

# Locate the Zig compiler
.find_zig <- function(zig = NULL) {
  if (is.null(zig) || !nzchar(zig)) {
    zig <- getOption("zigimports.zig", NULL)
  }
  if (is.null(zig) || !nzchar(zig)) {
    zig <- Sys.getenv("ZIGIMPORTS_ZIG", unset = "")
  }
  if (!nzchar(zig)) zig <- "zig"

  found <- Sys.which(zig)
  if (nzchar(found)) return(unname(found))
  if (file.exists(zig)) return(normalizePath(zig, winslash = "/"))
  stop("Could not find the Zig compiler ('", zig, "'). Install Zig and put it ",
       "on your PATH, or set options(zigimports.zig = '/path/to/zig') or the ",
       "ZIGIMPORTS_ZIG environment variable.", call. = FALSE)
}

# Compile a Zig source file into a shared library. All Zig cache files are
# kept next to the output (inside a temporary directory).
.compile_zig <- function(src, out, optimize = "ReleaseFast",
                         flags = character(), zig = .find_zig(),
                         verbose = FALSE) {
  work <- dirname(out)
  cache <- file.path(work, "zig-cache")
  gcache <- file.path(work, "zig-global-cache")
  dir.create(cache, showWarnings = FALSE, recursive = TRUE)
  dir.create(gcache, showWarnings = FALSE, recursive = TRUE)

  old <- setwd(work)
  on.exit(setwd(old), add = TRUE)

  args <- c("build-lib", .shq(src),
            "-dynamic",
            "-O", optimize,
            paste0("-femit-bin=", .shq(out)),
            "--cache-dir", .shq(cache),
            "--global-cache-dir", .shq(gcache),
            flags)
  if (verbose) message("zigimports: ", zig, " ", paste(args, collapse = " "))

  res <- suppressWarnings(system2(zig, args, stdout = TRUE, stderr = TRUE))
  status <- attr(res, "status")
  if (verbose && length(res)) message(paste(res, collapse = "\n"))

  if ((!is.null(status) && status != 0L) || !file.exists(out)) {
    stop("Zig compilation failed:\n", paste(res, collapse = "\n"), call. = FALSE)
  }
  invisible(out)
}

# Look up an exported symbol in a loaded library
.get_symbol <- function(lib, name) {
  if (!inherits(lib, "zig_lib")) {
    stop("'lib' must be the result of zig_load()", call. = FALSE)
  }
  if (!is.character(name) || length(name) != 1L || is.na(name)) {
    stop("'name' must be a single string", call. = FALSE)
  }
  tryCatch(
    getNativeSymbolInfo(name, lib$dll),
    error = function(e) {
      stop("Symbol '", name, "' not found in ", basename(lib$path),
           ". Was the Zig function declared with 'export fn'?", call. = FALSE)
    }
  )
}

# Call a native symbol. 'hidden' = number of trailing internal arguments that
# are not reported back to the user.
.zig_invoke <- function(sym, vals, argtypes, rettype,
                        sig = .sig_string(argtypes), hidden = 0L) {
  if (length(vals) != length(argtypes)) {
    stop("expected ", length(argtypes), " argument(s) but got ", length(vals),
         call. = FALSE)
  }
  for (i in seq_along(vals)) {
    vals[[i]] <- .coerce_arg(vals[[i]], argtypes[i], i)
  }

  res <- .Call(C_zig_ffi_call, sym$address, sig,
               unname(.ret_kind[rettype]), vals)
  value <- res[[1L]]
  changed <- res[[2L]]

  ptr <- which(argtypes %in% c("ptr_f64", "ptr_i32"))
  ptr <- ptr[ptr <= length(vals) - hidden]
  modified <- changed[ptr]
  names(modified) <- names(vals)[ptr]

  if (rettype == "void") {
    if (length(ptr)) modified else invisible(NULL)
  } else {
    if (length(ptr)) attr(value, "args") <- modified
    value
  }
}
