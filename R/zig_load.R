#' Load a Zig shared library
#'
#' Loads a shared library produced by the 'Zig' compiler (a \code{.so} file on
#' Linux or a \code{.dll} file on Windows) so that its exported functions can be
#' bound with \code{\link{zig_bind}}.
#'
#' @param path Path to the compiled shared library.
#' @return An object of class \code{"zig_lib"}: a list with the normalised
#'   \code{path}, the library \code{name}, and the \code{dll} handle returned by
#'   \code{\link[base]{dyn.load}}.
#' @seealso \code{\link{zig_bind}}, \code{\link{zig_call}}
#' @examples
#' if (nzchar(Sys.which("zig"))) {
#'   q <- function(p) shQuote(p, type = if (.Platform$OS.type == "windows") "cmd" else "sh")
#'   src <- system.file("examples", "mathlib.zig", package = "zigimports")
#'   tmp <- tempfile("zigimports_ex_")
#'   dir.create(tmp)
#'   out <- file.path(tmp, paste0("mathlib", .Platform$dynlib.ext))
#'   status <- system2("zig", c("build-lib", q(src), "-dynamic", "-O", "ReleaseFast",
#'                              paste0("-femit-bin=", q(out)),
#'                              "--cache-dir", q(file.path(tmp, "c")),
#'                              "--global-cache-dir", q(file.path(tmp, "g"))),
#'                     stdout = FALSE, stderr = FALSE)
#'   if (status == 0L && file.exists(out)) {
#'     lib <- zig_load(out)
#'     print(lib)
#'     dyn.unload(lib$path)
#'   }
#'   unlink(tmp, recursive = TRUE)
#' }
#' @export
zig_load <- function(path) {
  if (!is.character(path) || length(path) != 1L || is.na(path)) {
    stop("'path' must be a single string", call. = FALSE)
  }
  if (!file.exists(path)) {
    stop("File not found: ", path, call. = FALSE)
  }
  path <- normalizePath(path, winslash = "/", mustWork = TRUE)

  ext <- tolower(sub("^.*\\.", "", basename(path)))
  if (!ext %in% c("so", "dll", "dylib")) {
    warning("'", basename(path), "' does not look like a shared library",
            call. = FALSE)
  }

  dll <- tryCatch(
    dyn.load(path),
    error = function(e) {
      stop("Could not load '", path, "': ", conditionMessage(e), call. = FALSE)
    }
  )

  structure(list(path = path, name = dll[["name"]], dll = dll),
            class = "zig_lib")
}

#' @export
print.zig_lib <- function(x, ...) {
  cat("<zig_lib> ", x$name, "\n  path: ", x$path, "\n", sep = "")
  invisible(x)
}
