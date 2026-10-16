#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>
#include <string.h>
#include "zigimports.h"

/* Call a native function with by-value arguments and a return value.
 *
 *   addr : external pointer (NativeSymbol address) of the function
 *   sig  : one character per argument: 'I' int, 'D' double, 'P' pointer
 *   ret  : one character: 'V' void, 'I' int, 'D' double, 'B' bool, 'S' string
 *   args : list of already coerced R values, one per argument
 *
 * Pointer arguments are duplicated first, so the caller's vectors are never
 * modified. Returns list(value, list-of-(possibly modified)-arguments). */
SEXP zig_ffi_call(SEXP addr, SEXP sig, SEXP ret, SEXP args)
{
    zigimports_fn fn;
    const char *s, *r;
    int n, i;
    zigimports_arg a[ZIGIMPORTS_MAX_ARGS];
    zigimports_ret out;
    SEXP work, val, res;

    if (TYPEOF(addr) != EXTPTRSXP)
        error("'addr' must be an external pointer");
    fn = (zigimports_fn) R_ExternalPtrAddrFn(addr);
    if (fn == NULL)
        error("null function pointer");
    if (!isString(sig) || LENGTH(sig) != 1 || !isString(ret) ||
        LENGTH(ret) != 1 || TYPEOF(args) != VECSXP)
        error("invalid arguments");

    s = CHAR(STRING_ELT(sig, 0));
    r = CHAR(STRING_ELT(ret, 0));
    n = (int) strlen(s);
    if (strlen(r) != 1)
        error("invalid return kind");
    if (n > ZIGIMPORTS_MAX_ARGS)
        error("too many arguments (maximum is %d)", ZIGIMPORTS_MAX_ARGS);
    if (n != LENGTH(args))
        error("expected %d argument(s) but got %d", n, LENGTH(args));

    memset(&out, 0, sizeof(out));
    memset(a, 0, sizeof(a));
    work = PROTECT(allocVector(VECSXP, n));

    for (i = 0; i < n; i++) {
        SEXP x = VECTOR_ELT(args, i);
        SET_VECTOR_ELT(work, i, x);
        switch (s[i]) {
        case 'I':
            if ((TYPEOF(x) != INTSXP && TYPEOF(x) != LGLSXP) || XLENGTH(x) != 1)
                error("argument %d must be a single integer", i + 1);
            a[i].i = INTEGER(x)[0];
            break;
        case 'D':
            if (TYPEOF(x) != REALSXP || XLENGTH(x) != 1)
                error("argument %d must be a single double", i + 1);
            a[i].d = REAL(x)[0];
            break;
        case 'P': {
            SEXP y;
            if (TYPEOF(x) == STRSXP) {
                if (XLENGTH(x) != 1 || STRING_ELT(x, 0) == NA_STRING)
                    error("argument %d must be a single non-NA string", i + 1);
                a[i].p = (void *) CHAR(STRING_ELT(x, 0));
            } else if (TYPEOF(x) == REALSXP) {
                SET_VECTOR_ELT(work, i, y = duplicate(x));
                a[i].p = (void *) REAL(y);
            } else if (TYPEOF(x) == INTSXP) {
                SET_VECTOR_ELT(work, i, y = duplicate(x));
                a[i].p = (void *) INTEGER(y);
            } else if (TYPEOF(x) == LGLSXP) {
                SET_VECTOR_ELT(work, i, y = duplicate(x));
                a[i].p = (void *) LOGICAL(y);
            } else {
                error("argument %d has an unsupported type", i + 1);
            }
            break;
        }
        default:
            error("invalid signature character");
        }
    }

    if (zigimports_dispatch(fn, n, s, a, r[0], &out) != 0)
        error("unsupported function signature");

    switch (r[0]) {
    case 'V': val = R_NilValue; break;
    case 'I': val = ScalarInteger(out.i); break;
    case 'D': val = ScalarReal(out.d); break;
    case 'B': val = ScalarLogical(out.i != 0); break;
    case 'S':
        if (out.s == NULL)
            val = ScalarString(NA_STRING);
        else
            val = ScalarString(mkCharCE(out.s, CE_UTF8));
        break;
    default: error("invalid return kind");
    }
    PROTECT(val);
    res = PROTECT(allocVector(VECSXP, 2));
    SET_VECTOR_ELT(res, 0, val);
    SET_VECTOR_ELT(res, 1, work);
    UNPROTECT(3);
    return res;
}

static const R_CallMethodDef CallEntries[] = {
    {"zig_ffi_call", (DL_FUNC) &zig_ffi_call, 4},
    {NULL, NULL, 0}
};

void R_init_zigimports(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
    R_forceSymbols(dll, TRUE);
}
