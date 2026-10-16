add_src <- "export fn add(a: i32, b: f64) f64 {
  return @as(f64, @floatFromInt(a)) + b;
}"

test_that("function mode: mixed types, explicit and inferred", {
  skip_if_no_zig()
  expect_equal(zig_call(add_src, fn = "add", args = c("i32", "f64"),
                        returns = "f64", 2L, 0.5), 2.5)
  expect_equal(zig_call(add_src, fn = "add", returns = "f64", 3L, 1.5), 4.5)
})

test_that("function mode: bool and string returns", {
  skip_if_no_zig()
  src <- "export fn is_even(n: i32) bool { return @mod(n, 2) == 0; }"
  expect_true(zig_call(src, fn = "is_even", returns = "bool", 4L))
  expect_false(zig_call(src, fn = "is_even", returns = "bool", 7L))
  src <- "export fn name() [*:0]const u8 { return \"zig\"; }"
  expect_identical(zig_call(src, fn = "name", returns = "str"), "zig")
})

test_that("function mode: a length-1 vector can be passed as a pointer", {
  skip_if_no_zig()
  src <- "export fn setv(p: [*]f64) void { p[0] = 9; }"
  res <- zig_call(src, fn = "setv", args = "ptr_f64", 1)
  expect_equal(res[[1]], 9)
})

test_that("function mode: code can come from a .zig file", {
  skip_if_no_zig()
  f <- tempfile(fileext = ".zig")
  writeLines("export fn twice(x: f64) f64 { return x * 2; }", f)
  on.exit(unlink(f), add = TRUE)
  expect_equal(zig_call(f, fn = "twice", returns = "f64", 21), 42)
})

test_that("function mode: a missing function is reported", {
  skip_if_no_zig()
  expect_error(zig_call(add_src, fn = "nope", args = c("i32", "f64"),
                        returns = "f64", 1L, 1), "not found")
})

test_that("every optimisation mode works", {
  skip_if_no_zig()
  for (mode in c("Debug", "ReleaseSafe", "ReleaseSmall", "ReleaseFast")) {
    expect_equal(zig_call(add_src, fn = "add", returns = "f64",
                          optimize = mode, 2L, 0.5), 2.5, info = mode)
  }
  expect_error(zig_call(add_src, fn = "add", optimize = "Fastest", 1L, 1),
               "should be one of")
})

test_that("snippet mode: in-place changes on copies", {
  skip_if_no_zig()
  x <- c(1, 2)
  res <- zig_call("x[0] *= 2;", x = x)
  expect_equal(res$x, c(2, 2))
  expect_equal(x, c(1, 2))
})

test_that("snippet mode: lengths of several arguments", {
  skip_if_no_zig()
  res <- zig_call("a[0] = @floatFromInt(zig_lens[1]);", a = 0, b = c(1, 2, 3))
  expect_equal(res$a, 3)
  expect_equal(res$b, c(1, 2, 3))
  expect_named(res, c("a", "b"))
})

test_that("snippet mode: loops, integers and strings", {
  skip_if_no_zig()
  res <- zig_call("
    var i: usize = 0;
    while (i < @as(usize, @intCast(zig_lens[0]))) : (i += 1) x[i] *= 2;
  ", x = c(1, 2, 3))
  expect_equal(res$x, c(2, 4, 6))

  res <- zig_call("v[0] = 7;", v = 1L)
  expect_identical(res$v, 7L)

  res <- zig_call("return @intCast(std.mem.len(s));", s = "abc", returns = "i32")
  expect_identical(res, 3L)
})

test_that("snippet mode: return values", {
  skip_if_no_zig()
  res <- zig_call("return a[0] + 1.0;", a = 2, returns = "f64")
  expect_equal(as.numeric(res), 3)
  expect_true(zig_call("return a[0] > 1.0;", a = 2, returns = "bool"))
  expect_identical(zig_call("return \"hi\";", returns = "str"), "hi")
  expect_identical(zig_call("return 5;", returns = "i32"), 5L)
})

test_that("snippet mode: no arguments and void result", {
  skip_if_no_zig()
  expect_null(zig_call("const x: i32 = 1; _ = x;"))
})

test_that("snippet mode validates its input", {
  expect_error(zig_call("x[0] = 1;", 1), "named")
  expect_error(zig_call("x[0] = 1;", x = 1, args = "ptr_f64"), "only used in function mode")
  expect_error(zig_call("export fn f() void {}"), "set 'fn'")
  expect_error(zig_call("x[0] = 1;", zig_lens = 1), "reserved")
  expect_error(zig_call("x[0] = 1;", x = list(1)), "unsupported snippet")
  expect_error(zig_call(character()), "character string")
  expect_error(zig_call(1), "character string")
  expect_error(zig_call("", fn = "f", args = rep("i32", 7)), "at most 6")
  expect_error(zig_call("", returns = "ptr_f64"), "pointer return")
})

test_that("compile errors are reported with the compiler output", {
  skip_if_no_zig()
  expect_error(zig_call("export fn f() void { nonsense }", fn = "f"),
               "Zig compilation failed")
  expect_error(zig_call("this is not zig;", x = 1), "Zig compilation failed")
})

test_that("temporary build directories are cleaned up", {
  skip_if_no_zig()
  before <- n_build_dirs()
  zig_call(add_src, fn = "add", returns = "f64", 1L, 1)
  expect_equal(n_build_dirs(), before)
  # also after a failed compilation
  try(zig_call("export fn f() void { nonsense }", fn = "f"), silent = TRUE)
  expect_equal(n_build_dirs(), before)
})

test_that("keep = TRUE keeps the build directory and reports it", {
  skip_if_no_zig()
  msgs <- character()
  res <- withCallingHandlers(
    zig_call(add_src, fn = "add", returns = "f64", keep = TRUE, 1L, 1),
    message = function(m) {
      msgs <<- c(msgs, conditionMessage(m))
      invokeRestart("muffleMessage")
    })
  expect_equal(res, 2)
  kept <- sub(".*kept at (.*)\n?$", "\\1", msgs[grepl("kept at", msgs)])
  expect_length(kept, 1)
  kept <- trimws(kept)
  expect_true(dir.exists(kept))
  expect_true(file.exists(file.path(kept, "zigimports_code.zig")))
  unlink(kept, recursive = TRUE)
})

test_that("verbose = TRUE shows the source and compiler command", {
  skip_if_no_zig()
  expect_message(
    zig_call(add_src, fn = "add", returns = "f64", verbose = TRUE, 1L, 1),
    "build-lib")
})

test_that("zig_call does not leave the working directory changed", {
  skip_if_no_zig()
  wd <- getwd()
  zig_call(add_src, fn = "add", returns = "f64", 1L, 1)
  try(zig_call("export fn f() void { nonsense }", fn = "f"), silent = TRUE)
  expect_identical(getwd(), wd)
})

test_that("zig caches stay out of the working directory", {
  skip_if_no_zig()
  d <- tempfile("zigimports_cwd_")
  dir.create(d)
  old <- setwd(d)
  on.exit({ setwd(old); unlink(d, recursive = TRUE) }, add = TRUE)
  zig_call(add_src, fn = "add", returns = "f64", 1L, 1)
  expect_length(list.files(d, all.files = TRUE, no.. = TRUE), 0)
})
