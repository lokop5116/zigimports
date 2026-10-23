# zigimports

Call [Zig](https://ziglang.org) code from R. Works on **Linux** (`.so`) and **Windows** (`.dll`).

| Function   | What it does |
|------------|--------------|
| `zig_load(path)` | Load a Zig-compiled `.so` / `.dll` |
| `zig_bind(lib, name, args, returns)` | Bind an exported Zig function (from `zig_load()`) to an R function |
| `zig_call(code, ..., fn)` | Compile and run arbitrary Zig code from inside R |

## Install

```r
install.packages("path/to/zigimports_0.1.0.tar.gz", repos = NULL, type = "source")
```
Installing needs a C compiler (Rtools on Windows). `zig_call()` also needs the `zig` compiler (0.11 or later) on your `PATH`, or `options(zigimports.zig = "C:/zig/zig.exe")`, or the env var `ZIGIMPORTS_ZIG`.

## Types

Arguments are passed **by value** with the native C calling convention, so mixed signatures like `add(i32, f64) -> f64` work.

| `args` / `returns` | Zig type | R value |
|--------------------|----------|---------|
| `"i32"` | `i32`, `c_int` | single integer |
| `"f64"` | `f64` | single double |
| `"bool"` | `bool` | single logical |
| `"str"` | `[*:0]const u8` | single string (arguments and return values) |
| `"ptr_f64"` | `[*]f64` | double vector (argument only) |
| `"ptr_i32"` | `[*]i32` | integer / logical vector (argument only) |
| `"void"` | `void` | return type only |

Up to 6 arguments. Vectors are copied before the call, and the modified copies are returned (in `attr(, "args")`, or as the result for `void` functions). Functions must be `export fn`.

## Usage

```zig
// mathlib.zig
export fn add(a: i32, b: f64) f64 {
    return @as(f64, @floatFromInt(a)) + b;
}
```

```sh
zig build-lib mathlib.zig -dynamic -O ReleaseFast   # libmathlib.so / mathlib.dll
```

```r
library(zigimports)
lib <- zig_load("libmathlib.so")                    # "mathlib.dll" on Windows
add <- zig_bind(lib, "add", args = c("i32", "f64"), returns = "f64")
add(2L, 0.5)                                        # 2.5

# Run Zig inline (function mode)
zig_call("export fn inc(x: f64) f64 { return x + 1; }",
         fn = "inc", returns = "f64", 41)           # 42

# Snippet mode: named args become pointers; lengths are in zig_lens
zig_call("x[0] *= 2;", x = c(1, 2))$x               # 2 2
```

## Notes
- Zig code runs inside the R process: a crash in Zig crashes R.
- Not supported: `f32`, 64-bit integers, structs, callbacks, returning pointers other than strings.
- Fill in the author name and email in `DESCRIPTION` (`Authors@R`) before submitting to CRAN.
