test_that("type names are normalised", {
  expect_equal(.norm_types(c("i32", "c_int", "double", "[*]f64", "logical",
                             "[*:0]const u8")),
               c("i32", "i32", "f64", "ptr_f64", "bool", "str"))
  expect_equal(.norm_types(c("int", "integer", "numeric", "character",
                             "string", "ptr_i32", "[*]i32", "[*]c_int",
                             "void")),
               c("i32", "i32", "f64", "str", "str", "ptr_i32", "ptr_i32",
                 "ptr_i32", "void"))
  expect_equal(.norm_types(" f64 "), "f64")
  expect_error(.norm_types("u128"), "unsupported type")
  expect_error(.norm_types(c("i32", "bogus", "alsobad")), "'bogus', 'alsobad'")
})

test_that("argument and return types are validated", {
  expect_equal(.norm_args(NULL), character())
  expect_equal(.norm_args(character()), character())
  expect_equal(.norm_args(c("i32", "f64")), c("i32", "f64"))
  expect_error(.norm_args(c("i32", "void")), "only valid as a return type")
  expect_error(.norm_args(rep("i32", 7)), "at most 6")
  expect_length(.norm_args(rep("i32", 6)), 6)
  expect_equal(.norm_ret("f64"), "f64")
  expect_equal(.norm_ret("void"), "void")
  expect_error(.norm_ret("ptr_f64"), "pointer return")
  expect_error(.norm_ret("ptr_i32"), "pointer return")
  expect_error(.norm_ret(c("i32", "f64")), "single type")
})

test_that("call signatures are encoded", {
  expect_equal(.sig_string(c("i32", "f64")), "ID")
  expect_equal(.sig_string(c("ptr_f64", "i32", "str", "bool")), "PIPI")
  expect_equal(.sig_string(c("f64", "f64", "ptr_i32")), "DDP")
  expect_equal(.sig_string(character()), "")
})

test_that("scalar arguments are coerced", {
  expect_identical(.coerce_arg(2, "i32", 1L), 2L)
  expect_identical(.coerce_arg(2L, "f64", 1L), 2)
  expect_identical(.coerce_arg(TRUE, "bool", 1L), 1L)
  expect_identical(.coerce_arg(FALSE, "bool", 1L), 0L)
  expect_identical(.coerce_arg(0, "bool", 1L), 0L)
  expect_identical(.coerce_arg("a", "str", 1L), "a")
  expect_identical(.coerce_arg(NA_integer_, "i32", 1L), NA_integer_)
})

test_that("vector arguments are coerced", {
  expect_identical(.coerce_arg(c(1, 2), "ptr_f64", 1L), c(1, 2))
  expect_identical(.coerce_arg(1:3, "ptr_f64", 1L), c(1, 2, 3))
  expect_identical(.coerce_arg(c(TRUE, FALSE), "ptr_i32", 1L), c(1L, 0L))
  expect_identical(.coerce_arg(c(1, 2), "ptr_i32", 1L), c(1L, 2L))
  expect_identical(.coerce_arg(numeric(0), "ptr_f64", 1L), numeric(0))
})

test_that("bad arguments are rejected", {
  expect_error(.coerce_arg(c(1, 2), "f64", 1L), "length 1")
  expect_error(.coerce_arg(c(1L, 2L), "i32", 1L), "length 1")
  expect_error(.coerce_arg(c("a", "b"), "str", 1L), "length 1")
  expect_error(.coerce_arg(numeric(0), "f64", 1L), "length 1")
  expect_error(.coerce_arg(NA, "bool", 1L), "NA")
  expect_error(.coerce_arg(NA_character_, "str", 1L), "NA")
  expect_error(.coerce_arg(NULL, "f64", 1L), "atomic")
  expect_error(.coerce_arg(list(1), "f64", 1L), "atomic")
  expect_error(.coerce_arg(1, "nonsense", 1L), "unknown type")
})

test_that("types are inferred from values", {
  expect_equal(.infer_types(list(1L, 2.5, TRUE, "a", c(1, 2), 1:2, c(TRUE, FALSE))),
               c("i32", "f64", "bool", "str", "ptr_f64", "ptr_i32", "ptr_i32"))
  expect_equal(.infer_types(list()), character())
  expect_error(.infer_types(list(c("a", "b"))), "cannot infer")
  expect_error(.infer_types(list(list(1))), "cannot infer")
  expect_error(.infer_types(list(NULL)), "cannot infer")
})

test_that("snippet argument types are chosen from R values", {
  expect_equal(.snippet_types(list(1, 1:3, TRUE, "s")),
               c("ptr_f64", "ptr_i32", "ptr_i32", "str"))
  expect_error(.snippet_types(list(c("a", "b"))), "unsupported snippet")
})

test_that("snippets are wrapped into an exported function", {
  src <- .wrap_snippet("x[0] += 1;", "x", "ptr_f64", "void")
  expect_match(src, "export fn zig_snippet(x: [*]f64, zig_lens: [*]i32) void",
               fixed = TRUE)
  expect_match(src, "_ = @TypeOf(x);", fixed = TRUE)
  expect_match(src, "_ = @TypeOf(zig_lens);", fixed = TRUE)
  expect_match(src, "x[0] += 1;", fixed = TRUE)
  expect_match(src, "const std = @import(\"std\");", fixed = TRUE)

  src <- .wrap_snippet("return 1.0;", character(), character(), "f64")
  expect_match(src, "export fn zig_snippet(zig_lens: [*]i32) f64", fixed = TRUE)

  src <- .wrap_snippet("return 1;", c("a", "s"), c("ptr_i32", "str"), "i32")
  expect_match(src, "(a: [*]i32, s: [*:0]const u8, zig_lens: [*]i32) i32",
               fixed = TRUE)
  src <- .wrap_snippet("return true;", "a", "ptr_f64", "bool")
  expect_match(src, ") bool {", fixed = TRUE)
  src <- .wrap_snippet("return \"x\";", "a", "ptr_f64", "str")
  expect_match(src, ") [*:0]const u8 {", fixed = TRUE)
})

test_that("snippet argument names are validated", {
  expect_error(.wrap_snippet("", "1x", "ptr_f64", "void"), "valid Zig")
  expect_error(.wrap_snippet("", "a b", "ptr_f64", "void"), "valid Zig")
  expect_error(.wrap_snippet("", "", "ptr_f64", "void"), "valid Zig")
  expect_error(.wrap_snippet("", NULL, "ptr_f64", "void"), "valid Zig")
  expect_error(.wrap_snippet("", "zig_lens", "ptr_f64", "void"), "reserved")
})
