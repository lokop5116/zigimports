test_that("zig_load validates its input", {
  expect_error(zig_load("does-not-exist.so"), "File not found")
  expect_error(zig_load(1), "single string")
  expect_error(zig_load(c("a", "b")), "single string")
  expect_error(zig_load(NA_character_), "single string")
})

test_that("zig_load rejects files that are not shared libraries", {
  bad <- tempfile(fileext = ".so")
  writeLines("this is not a shared library", bad)
  on.exit(unlink(bad), add = TRUE)
  expect_error(zig_load(bad), "Could not load")

  odd <- tempfile(fileext = ".txt")
  writeLines("still not a library", odd)
  on.exit(unlink(odd), add = TRUE)
  expect_warning(try(zig_load(odd), silent = TRUE), "does not look like")
})

test_that("zig_bind validates the library and names", {
  expect_error(zig_bind(list(), "f"), "zig_load")
  expect_error(zig_bind(NULL, "f"), "zig_load")
  fake <- structure(list(path = "x.so", name = "x", dll = NULL), class = "zig_lib")
  expect_error(zig_bind(fake, c("a", "b")), "single string")
  expect_error(zig_bind(fake, NA_character_), "single string")
  expect_error(zig_bind(fake, 1), "single string")
})

test_that("compiler lookup honours argument, option and environment", {
  expect_error(.find_zig("definitely-not-a-zig-binary"), "Could not find")

  old_opt <- options(zigimports.zig = "definitely-not-a-zig-binary")
  on.exit(options(old_opt), add = TRUE)
  expect_error(.find_zig(), "definitely-not-a-zig-binary")
  options(zigimports.zig = NULL)

  old_env <- Sys.getenv("ZIGIMPORTS_ZIG", unset = NA)
  on.exit(if (is.na(old_env)) Sys.unsetenv("ZIGIMPORTS_ZIG")
          else Sys.setenv(ZIGIMPORTS_ZIG = old_env), add = TRUE)
  Sys.setenv(ZIGIMPORTS_ZIG = "env-zig-that-does-not-exist")
  expect_error(.find_zig(), "env-zig-that-does-not-exist")

  # an explicit path to an existing file is accepted
  f <- tempfile()
  file.create(f)
  on.exit(unlink(f), add = TRUE)
  expect_equal(.find_zig(f), normalizePath(f, winslash = "/"))
})

test_that("zig_call reports a missing compiler", {
  expect_error(zig_call("x[0] = 1;", x = 1, zig = "definitely-not-a-zig-binary"),
               "Could not find the Zig compiler")
})

test_that("zig_load works on a compiled library", {
  skip_if_no_zig()
  lib <- mathlib()
  expect_s3_class(lib, "zig_lib")
  expect_true(file.exists(lib$path))
  expect_output(print(lib), "<zig_lib>")
  expect_output(print(lib), "path:")
  capture.output(printed <- print(lib))
  expect_identical(printed, lib)
  # loading the same file twice is harmless
  expect_s3_class(zig_load(lib$path), "zig_lib")
})
