# Shared helpers for the test suite -----------------------------------------

# Tests that need the Zig compiler are skipped on CRAN and when zig is absent.
skip_if_no_zig <- function() {
  testthat::skip_on_cran()
  testthat::skip_if(!nzchar(Sys.which("zig")), "zig compiler not available")
}

# The example library is compiled and loaded once per test run.
.zt <- new.env(parent = emptyenv())

mathlib <- function() {
  if (is.null(.zt$lib)) {
    src <- system.file("examples", "mathlib.zig", package = "zigimports")
    testthat::skip_if(!nzchar(src), "example source not installed")
    dir <- tempfile("zigimports_test_")
    dir.create(dir)
    out <- file.path(dir, paste0("mathlib", .Platform$dynlib.ext))
    .compile_zig(src, out)
    .zt$lib <- zig_load(out)
  }
  .zt$lib
}

# Number of zigimports build directories currently in tempdir()
n_build_dirs <- function() {
  length(list.files(tempdir(), pattern = "^zigimports_[0-9a-f]+$"))
}
