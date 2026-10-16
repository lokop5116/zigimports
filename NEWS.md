# zigimports 0.1.0

* Initial release.
* `zig_load()` loads a shared library compiled from 'Zig' (`.so` / `.dll`).
* `zig_bind()` binds exported functions. Arguments are passed by value
  (`i32`, `f64`, `bool`, strings, and vectors as pointers) and return values
  (`void`, `i32`, `f64`, `bool`, strings) are supported.
* `zig_call()` compiles and runs 'Zig' source or snippets from R.
