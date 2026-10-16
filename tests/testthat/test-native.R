# Error paths of the C layer. These never reach the dispatched function, so
# they are safe to run without a Zig library. The function address is only a
# placeholder for the validation checks.
addr <- C_zig_ffi_call$address
ffi <- function(sig, ret, args, a = addr) {
  .Call(C_zig_ffi_call, a, sig, ret, args)
}

test_that("the native layer validates its inputs", {
  expect_error(ffi("", "V", list(), a = 1), "external pointer")
  expect_error(.Call(C_zig_ffi_call, addr, 1, "V", list()), "invalid arguments")
  expect_error(.Call(C_zig_ffi_call, addr, "", "V", 1), "invalid arguments")
  expect_error(.Call(C_zig_ffi_call, addr, c("I", "I"), "V", list(1L)),
               "invalid arguments")
  expect_error(ffi("", "VV", list()), "invalid return kind")
  expect_error(ffi("II", "V", list(1L)), "expected 2 argument")
  expect_error(ffi(strrep("I", 7), "V", as.list(1:7)), "too many arguments")
  expect_error(ffi("X", "V", list(1L)), "invalid signature")
})

test_that("the native layer type-checks every argument", {
  expect_error(ffi("I", "V", list("a")), "single integer")
  expect_error(ffi("I", "V", list(1:2)), "single integer")
  expect_error(ffi("I", "V", list(1.5)), "single integer")
  expect_error(ffi("D", "V", list(1L)), "single double")
  expect_error(ffi("D", "V", list(c(1, 2))), "single double")
  expect_error(ffi("P", "V", list(list())), "unsupported type")
  expect_error(ffi("P", "V", list(c("a", "b"))), "single non-NA string")
  expect_error(ffi("P", "V", list(NA_character_)), "single non-NA string")
  expect_error(ffi("ID", "V", list(1L, "a")), "argument 2")
})

test_that("unsupported return kinds are rejected before any call", {
  expect_error(ffi("", "Z", list()), "unsupported function signature")
  expect_error(ffi("ID", "Q", list(1L, 1)), "unsupported function signature")
})

test_that(".zig_invoke checks the argument count first", {
  expect_error(.zig_invoke(NULL, list(1), c("i32", "f64"), "void"),
               "expected 2 argument")
  expect_error(.zig_invoke(NULL, list(), "f64", "void"), "expected 1 argument")
})
