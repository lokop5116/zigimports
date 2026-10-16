#' Bind an exported Zig function to an R function
#'
#' Looks up a function exported from a library loaded with
#' \code{\link{zig_load}} and returns an ordinary R function that calls it.
#' Arguments are passed by value with the native C calling convention, so
#' functions with mixed argument types, such as
#' \code{export fn add(a: i32, b: f64) f64}, work as expected.
#'
#' Supported types (a Zig-style or R-style name may be used):
#' \tabular{lll}{
#'   \strong{Type} \tab \strong{Zig} \tab \strong{R value}\cr
#'   \code{"i32"} \tab \code{i32}, \code{c_int} \tab single integer\cr
#'   \code{"f64"} \tab \code{f64} \tab single double\cr
#'   \code{"bool"} \tab \code{bool} \tab single logical\cr
#'   \code{"str"} \tab \code{[*:0]const u8} \tab single string\cr
#'   \code{"ptr_f64"} \tab \code{[*]f64} \tab double vector\cr
#'   \code{"ptr_i32"} \tab \code{[*]i32} \tab integer or logical vector
#' }
#' \code{"void"} is also valid as a return type. Functions must be declared
#' with \code{export fn}, take at most six arguments, and cannot return
#' pointers other than strings. Vector arguments are copied before the call,
#' so the caller's data is never modified; the modified copies are returned
#' (see Value). \code{NA} integers are passed as the C value \code{INT_MIN}.
#' The Zig code runs inside the R process: a crash in Zig crashes R.
#'
#' @param lib A \code{zig_lib} object returned by \code{\link{zig_load}}.
#' @param name Name of the exported Zig function.
#' @param args Character vector with the type of each argument, or
#'   \code{NULL} for a function without arguments.
#' @param returns Return type of the Zig function (default \code{"void"}).
#' @return A function taking the Zig function's arguments. Calling it returns
#'   the Zig return value. If the function has vector arguments, their
#'   (possibly modified) copies are returned as a named list: in the
#'   \code{"args"} attribute of the return value, or as the result itself for
#'   a \code{void} function.
#' @seealso \code{\link{zig_load}}, \code{\link{zig_call}}
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
#'     add <- zig_bind(lib, "add", args = c("i32", "f64"), returns = "f64")
#'     add(2L, 0.5)
#'     total <- zig_bind(lib, "total", args = c("ptr_f64", "i32"), returns = "f64")
#'     total(c(1, 2, 3), 3L)
#'     dyn.unload(lib$path)
#'   }
#'   unlink(tmp, recursive = TRUE)
#' }
#' @export
zig_bind <- function(lib, name, args = NULL, returns = "void") {
  sym <- .get_symbol(lib, name)
  argtypes <- .norm_args(args)
  rettype <- .norm_ret(returns)
  sig <- .sig_string(argtypes)

  f <- function(...) {
    .zig_invoke(sym, list(...), argtypes, rettype, sig)
  }
  attr(f, "zig_name") <- name
  attr(f, "zig_signature") <- sprintf("%s(%s) -> %s", name,
                                      paste(argtypes, collapse = ", "), rettype)
  f
}
