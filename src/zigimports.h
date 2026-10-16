#ifndef ZIGIMPORTS_H
#define ZIGIMPORTS_H

#define ZIGIMPORTS_MAX_ARGS 6

typedef void (*zigimports_fn)(void);

typedef union {
    int i;
    double d;
    void *p;
} zigimports_arg;

typedef union {
    int i;
    double d;
    const char *s;
} zigimports_ret;

/* Calls fn with the given argument kinds ('I', 'D', 'P') and return kind
 * ('V', 'I', 'D', 'B', 'S'). Returns 0 on success, -1 for an unsupported
 * signature. */
int zigimports_dispatch(zigimports_fn fn, int n, const char *sig, const zigimports_arg *a,
                  char rk, zigimports_ret *out);

#endif
