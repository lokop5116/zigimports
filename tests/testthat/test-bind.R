lib_fn <- function(name, args = NULL, returns = "void") {
  zig_bind(mathlib(), name, args = args, returns = returns)
}

test_that("mixed scalar types with a return value (add(i32, f64) -> f64)", {
  skip_if_no_zig()
  add <- lib_fn("add", c("i32", "f64"), "f64")
  expect_equal(add(2L, 0.5), 2.5)
  expect_equal(add(-3L, 0.5), -2.5)
  expect_equal(add(2, 0.5), 2.5)            # double coerced to i32
  expect_identical(attr(add, "zig_signature"), "add(i32, f64) -> f64")
  expect_identical(attr(add, "zig_name"), "add")
})

test_that("no-argument functions and i32 returns", {
  skip_if_no_zig()
  answer <- lib_fn("answer", returns = "i32")
  expect_identical(answer(), 42L)
})

test_that("bool arguments and returns", {
  skip_if_no_zig()
  is_even <- lib_fn("is_even", "i32", "bool")
  expect_true(is_even(4L))
  expect_false(is_even(7L))
  expect_false(is_even(-3L))
  negate <- lib_fn("negate", "bool", "bool")
  expect_false(negate(TRUE))
  expect_true(negate(FALSE))
})

test_that("NA and NaN are passed through", {
  skip_if_no_zig()
  is_min_int <- lib_fn("is_min_int", "i32", "bool")
  expect_true(is_min_int(NA_integer_))
  expect_false(is_min_int(5L))
  is_nan <- lib_fn("is_nan", "f64", "bool")
  expect_true(is_nan(NaN))
  expect_true(is_nan(NA_real_))
  expect_false(is_nan(1))
})

test_that("six mixed arguments", {
  skip_if_no_zig()
  six <- lib_fn("six", c("i32", "f64", "i32", "f64", "i32", "f64"), "f64")
  expect_equal(six(1L, 2, 3L, 4, 5L, 6), 21)
})

test_that("double vectors: read-only and in-place functions", {
  skip_if_no_zig()
  total <- lib_fn("total", c("ptr_f64", "i32"), "f64")
  expect_equal(as.numeric(total(c(1, 2, 3), 3L)), 6)
  expect_equal(as.numeric(total(numeric(0), 0L)), 0)
  big <- as.numeric(1:1000000)
  expect_equal(as.numeric(total(big, 1000000L)), sum(big))

  scale <- lib_fn("scale", c("ptr_f64", "i32", "f64"))
  res <- scale(x = c(1, 2, 3), n = 3L, k = 10)
  expect_equal(res$x, c(10, 20, 30))
  expect_named(res, "x")
})

test_that("the caller's vectors are never modified", {
  skip_if_no_zig()
  scale <- lib_fn("scale", c("ptr_f64", "i32", "f64"))
  x <- c(1, 2, 3)
  res <- scale(x, 3L, 10)
  expect_equal(x, c(1, 2, 3))
  expect_equal(res[[1]], c(10, 20, 30))

  y <- 1:3 + 0                             # a fresh double vector
  y2 <- y
  scale(y, 3L, 2)
  expect_identical(y, y2)
})

test_that("integer and logical vectors", {
  skip_if_no_zig()
  fill <- lib_fn("fill", c("ptr_i32", "i32", "i32"))
  expect_identical(fill(rep(0L, 4), 4L, 7L)[[1]], rep(7L, 4))
  count_true <- lib_fn("count_true", c("ptr_i32", "i32"), "i32")
  expect_identical(as.integer(count_true(c(TRUE, FALSE, TRUE), 3L)), 2L)
  expect_identical(as.integer(count_true(c(0L, 5L, 9L, 0L), 4L)), 2L)
})

test_that("mixed scalar and pointer arguments with a return value", {
  skip_if_no_zig()
  mix <- lib_fn("mix", c("f64", "i32", "ptr_f64", "f64"), "i32")
  res <- mix(1.5, 4L, 0, 0.25)
  expect_identical(as.integer(res), 8L)
  expect_equal(attr(res, "args")[[1]], 6.25)
})

test_that("strings as arguments and return values", {
  skip_if_no_zig()
  str_len <- lib_fn("str_len", "str", "i32")
  expect_identical(as.integer(str_len("hello")), 5L)
  expect_identical(as.integer(str_len("")), 0L)
  expect_identical(as.integer(str_len("h\u00e9llo")), 6L)   # UTF-8 bytes
  concat_len <- lib_fn("concat_len", c("str", "str"), "i32")
  expect_identical(concat_len("ab", "cde"), 5L)
  hello <- lib_fn("hello", returns = "str")
  expect_identical(hello(), "hello from zig")
})

test_that("bound functions report misuse", {
  skip_if_no_zig()
  add <- lib_fn("add", c("i32", "f64"), "f64")
  expect_error(add(1L), "expected 2 argument")
  expect_error(add(1L, 2, 3), "expected 2 argument")
  expect_error(add(c(1L, 2L), 2), "length 1")
  expect_error(add(NULL, 2), "atomic")
  expect_error(zig_bind(mathlib(), "no_such_fn"), "not found")
  expect_error(zig_bind(mathlib(), "add", args = "u128"), "unsupported type")
  expect_error(zig_bind(mathlib(), "add", returns = "ptr_f64"), "pointer return")
  expect_error(zig_bind(mathlib(), "add", args = rep("i32", 7)), "at most 6")
})
