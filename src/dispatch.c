/* GENERATED FILE - do not edit. Regenerate with data-raw/gen_dispatch.py */
#include <stddef.h>
#include "zigimports.h"

#define ZIGIMPORTS_CALL(TYPES, ARGS)                                              \
    switch (rk) {                                                           \
    case 'V': ((void (*) TYPES) fn) ARGS; break;                            \
    case 'I': out->i = ((int (*) TYPES) fn) ARGS; break;                    \
    case 'D': out->d = ((double (*) TYPES) fn) ARGS; break;                 \
    case 'B': out->i = ((unsigned char (*) TYPES) fn) ARGS; break;          \
    case 'S': out->s = ((const char *(*) TYPES) fn) ARGS; break;            \
    default: return -1;                                                     \
    }

int zigimports_dispatch(zigimports_fn fn, int n, const char *sig, const zigimports_arg *a,
                  char rk, zigimports_ret *out)
{
    long key = 0, p3 = 1;
    int i;
    (void) a;
    if (n < 0 || n > ZIGIMPORTS_MAX_ARGS) return -1;
    for (i = 0; i < n; i++) {
        int d;
        switch (sig[i]) {
        case 'I': d = 0; break;
        case 'D': d = 1; break;
        case 'P': d = 2; break;
        default: return -1;
        }
        key = key * 3 + d;
        p3 *= 3;
    }
    key += (p3 - 1) / 2;  /* offset: number of shorter signatures */
    switch (key) {
    case 0: ZIGIMPORTS_CALL((void), ()) break; /* - */
    case 1: ZIGIMPORTS_CALL((int), (a[0].i)) break; /* I */
    case 2: ZIGIMPORTS_CALL((double), (a[0].d)) break; /* D */
    case 3: ZIGIMPORTS_CALL((void *), (a[0].p)) break; /* P */
    case 4: ZIGIMPORTS_CALL((int, int), (a[0].i, a[1].i)) break; /* II */
    case 5: ZIGIMPORTS_CALL((int, double), (a[0].i, a[1].d)) break; /* ID */
    case 6: ZIGIMPORTS_CALL((int, void *), (a[0].i, a[1].p)) break; /* IP */
    case 7: ZIGIMPORTS_CALL((double, int), (a[0].d, a[1].i)) break; /* DI */
    case 8: ZIGIMPORTS_CALL((double, double), (a[0].d, a[1].d)) break; /* DD */
    case 9: ZIGIMPORTS_CALL((double, void *), (a[0].d, a[1].p)) break; /* DP */
    case 10: ZIGIMPORTS_CALL((void *, int), (a[0].p, a[1].i)) break; /* PI */
    case 11: ZIGIMPORTS_CALL((void *, double), (a[0].p, a[1].d)) break; /* PD */
    case 12: ZIGIMPORTS_CALL((void *, void *), (a[0].p, a[1].p)) break; /* PP */
    case 13: ZIGIMPORTS_CALL((int, int, int), (a[0].i, a[1].i, a[2].i)) break; /* III */
    case 14: ZIGIMPORTS_CALL((int, int, double), (a[0].i, a[1].i, a[2].d)) break; /* IID */
    case 15: ZIGIMPORTS_CALL((int, int, void *), (a[0].i, a[1].i, a[2].p)) break; /* IIP */
    case 16: ZIGIMPORTS_CALL((int, double, int), (a[0].i, a[1].d, a[2].i)) break; /* IDI */
    case 17: ZIGIMPORTS_CALL((int, double, double), (a[0].i, a[1].d, a[2].d)) break; /* IDD */
    case 18: ZIGIMPORTS_CALL((int, double, void *), (a[0].i, a[1].d, a[2].p)) break; /* IDP */
    case 19: ZIGIMPORTS_CALL((int, void *, int), (a[0].i, a[1].p, a[2].i)) break; /* IPI */
    case 20: ZIGIMPORTS_CALL((int, void *, double), (a[0].i, a[1].p, a[2].d)) break; /* IPD */
    case 21: ZIGIMPORTS_CALL((int, void *, void *), (a[0].i, a[1].p, a[2].p)) break; /* IPP */
    case 22: ZIGIMPORTS_CALL((double, int, int), (a[0].d, a[1].i, a[2].i)) break; /* DII */
    case 23: ZIGIMPORTS_CALL((double, int, double), (a[0].d, a[1].i, a[2].d)) break; /* DID */
    case 24: ZIGIMPORTS_CALL((double, int, void *), (a[0].d, a[1].i, a[2].p)) break; /* DIP */
    case 25: ZIGIMPORTS_CALL((double, double, int), (a[0].d, a[1].d, a[2].i)) break; /* DDI */
    case 26: ZIGIMPORTS_CALL((double, double, double), (a[0].d, a[1].d, a[2].d)) break; /* DDD */
    case 27: ZIGIMPORTS_CALL((double, double, void *), (a[0].d, a[1].d, a[2].p)) break; /* DDP */
    case 28: ZIGIMPORTS_CALL((double, void *, int), (a[0].d, a[1].p, a[2].i)) break; /* DPI */
    case 29: ZIGIMPORTS_CALL((double, void *, double), (a[0].d, a[1].p, a[2].d)) break; /* DPD */
    case 30: ZIGIMPORTS_CALL((double, void *, void *), (a[0].d, a[1].p, a[2].p)) break; /* DPP */
    case 31: ZIGIMPORTS_CALL((void *, int, int), (a[0].p, a[1].i, a[2].i)) break; /* PII */
    case 32: ZIGIMPORTS_CALL((void *, int, double), (a[0].p, a[1].i, a[2].d)) break; /* PID */
    case 33: ZIGIMPORTS_CALL((void *, int, void *), (a[0].p, a[1].i, a[2].p)) break; /* PIP */
    case 34: ZIGIMPORTS_CALL((void *, double, int), (a[0].p, a[1].d, a[2].i)) break; /* PDI */
    case 35: ZIGIMPORTS_CALL((void *, double, double), (a[0].p, a[1].d, a[2].d)) break; /* PDD */
    case 36: ZIGIMPORTS_CALL((void *, double, void *), (a[0].p, a[1].d, a[2].p)) break; /* PDP */
    case 37: ZIGIMPORTS_CALL((void *, void *, int), (a[0].p, a[1].p, a[2].i)) break; /* PPI */
    case 38: ZIGIMPORTS_CALL((void *, void *, double), (a[0].p, a[1].p, a[2].d)) break; /* PPD */
    case 39: ZIGIMPORTS_CALL((void *, void *, void *), (a[0].p, a[1].p, a[2].p)) break; /* PPP */
    case 40: ZIGIMPORTS_CALL((int, int, int, int), (a[0].i, a[1].i, a[2].i, a[3].i)) break; /* IIII */
    case 41: ZIGIMPORTS_CALL((int, int, int, double), (a[0].i, a[1].i, a[2].i, a[3].d)) break; /* IIID */
    case 42: ZIGIMPORTS_CALL((int, int, int, void *), (a[0].i, a[1].i, a[2].i, a[3].p)) break; /* IIIP */
    case 43: ZIGIMPORTS_CALL((int, int, double, int), (a[0].i, a[1].i, a[2].d, a[3].i)) break; /* IIDI */
    case 44: ZIGIMPORTS_CALL((int, int, double, double), (a[0].i, a[1].i, a[2].d, a[3].d)) break; /* IIDD */
    case 45: ZIGIMPORTS_CALL((int, int, double, void *), (a[0].i, a[1].i, a[2].d, a[3].p)) break; /* IIDP */
    case 46: ZIGIMPORTS_CALL((int, int, void *, int), (a[0].i, a[1].i, a[2].p, a[3].i)) break; /* IIPI */
    case 47: ZIGIMPORTS_CALL((int, int, void *, double), (a[0].i, a[1].i, a[2].p, a[3].d)) break; /* IIPD */
    case 48: ZIGIMPORTS_CALL((int, int, void *, void *), (a[0].i, a[1].i, a[2].p, a[3].p)) break; /* IIPP */
    case 49: ZIGIMPORTS_CALL((int, double, int, int), (a[0].i, a[1].d, a[2].i, a[3].i)) break; /* IDII */
    case 50: ZIGIMPORTS_CALL((int, double, int, double), (a[0].i, a[1].d, a[2].i, a[3].d)) break; /* IDID */
    case 51: ZIGIMPORTS_CALL((int, double, int, void *), (a[0].i, a[1].d, a[2].i, a[3].p)) break; /* IDIP */
    case 52: ZIGIMPORTS_CALL((int, double, double, int), (a[0].i, a[1].d, a[2].d, a[3].i)) break; /* IDDI */
    case 53: ZIGIMPORTS_CALL((int, double, double, double), (a[0].i, a[1].d, a[2].d, a[3].d)) break; /* IDDD */
    case 54: ZIGIMPORTS_CALL((int, double, double, void *), (a[0].i, a[1].d, a[2].d, a[3].p)) break; /* IDDP */
    case 55: ZIGIMPORTS_CALL((int, double, void *, int), (a[0].i, a[1].d, a[2].p, a[3].i)) break; /* IDPI */
    case 56: ZIGIMPORTS_CALL((int, double, void *, double), (a[0].i, a[1].d, a[2].p, a[3].d)) break; /* IDPD */
    case 57: ZIGIMPORTS_CALL((int, double, void *, void *), (a[0].i, a[1].d, a[2].p, a[3].p)) break; /* IDPP */
    case 58: ZIGIMPORTS_CALL((int, void *, int, int), (a[0].i, a[1].p, a[2].i, a[3].i)) break; /* IPII */
    case 59: ZIGIMPORTS_CALL((int, void *, int, double), (a[0].i, a[1].p, a[2].i, a[3].d)) break; /* IPID */
    case 60: ZIGIMPORTS_CALL((int, void *, int, void *), (a[0].i, a[1].p, a[2].i, a[3].p)) break; /* IPIP */
    case 61: ZIGIMPORTS_CALL((int, void *, double, int), (a[0].i, a[1].p, a[2].d, a[3].i)) break; /* IPDI */
    case 62: ZIGIMPORTS_CALL((int, void *, double, double), (a[0].i, a[1].p, a[2].d, a[3].d)) break; /* IPDD */
    case 63: ZIGIMPORTS_CALL((int, void *, double, void *), (a[0].i, a[1].p, a[2].d, a[3].p)) break; /* IPDP */
    case 64: ZIGIMPORTS_CALL((int, void *, void *, int), (a[0].i, a[1].p, a[2].p, a[3].i)) break; /* IPPI */
    case 65: ZIGIMPORTS_CALL((int, void *, void *, double), (a[0].i, a[1].p, a[2].p, a[3].d)) break; /* IPPD */
    case 66: ZIGIMPORTS_CALL((int, void *, void *, void *), (a[0].i, a[1].p, a[2].p, a[3].p)) break; /* IPPP */
    case 67: ZIGIMPORTS_CALL((double, int, int, int), (a[0].d, a[1].i, a[2].i, a[3].i)) break; /* DIII */
    case 68: ZIGIMPORTS_CALL((double, int, int, double), (a[0].d, a[1].i, a[2].i, a[3].d)) break; /* DIID */
    case 69: ZIGIMPORTS_CALL((double, int, int, void *), (a[0].d, a[1].i, a[2].i, a[3].p)) break; /* DIIP */
    case 70: ZIGIMPORTS_CALL((double, int, double, int), (a[0].d, a[1].i, a[2].d, a[3].i)) break; /* DIDI */
    case 71: ZIGIMPORTS_CALL((double, int, double, double), (a[0].d, a[1].i, a[2].d, a[3].d)) break; /* DIDD */
    case 72: ZIGIMPORTS_CALL((double, int, double, void *), (a[0].d, a[1].i, a[2].d, a[3].p)) break; /* DIDP */
    case 73: ZIGIMPORTS_CALL((double, int, void *, int), (a[0].d, a[1].i, a[2].p, a[3].i)) break; /* DIPI */
    case 74: ZIGIMPORTS_CALL((double, int, void *, double), (a[0].d, a[1].i, a[2].p, a[3].d)) break; /* DIPD */
    case 75: ZIGIMPORTS_CALL((double, int, void *, void *), (a[0].d, a[1].i, a[2].p, a[3].p)) break; /* DIPP */
    case 76: ZIGIMPORTS_CALL((double, double, int, int), (a[0].d, a[1].d, a[2].i, a[3].i)) break; /* DDII */
    case 77: ZIGIMPORTS_CALL((double, double, int, double), (a[0].d, a[1].d, a[2].i, a[3].d)) break; /* DDID */
    case 78: ZIGIMPORTS_CALL((double, double, int, void *), (a[0].d, a[1].d, a[2].i, a[3].p)) break; /* DDIP */
    case 79: ZIGIMPORTS_CALL((double, double, double, int), (a[0].d, a[1].d, a[2].d, a[3].i)) break; /* DDDI */
    case 80: ZIGIMPORTS_CALL((double, double, double, double), (a[0].d, a[1].d, a[2].d, a[3].d)) break; /* DDDD */
    case 81: ZIGIMPORTS_CALL((double, double, double, void *), (a[0].d, a[1].d, a[2].d, a[3].p)) break; /* DDDP */
    case 82: ZIGIMPORTS_CALL((double, double, void *, int), (a[0].d, a[1].d, a[2].p, a[3].i)) break; /* DDPI */
    case 83: ZIGIMPORTS_CALL((double, double, void *, double), (a[0].d, a[1].d, a[2].p, a[3].d)) break; /* DDPD */
    case 84: ZIGIMPORTS_CALL((double, double, void *, void *), (a[0].d, a[1].d, a[2].p, a[3].p)) break; /* DDPP */
    case 85: ZIGIMPORTS_CALL((double, void *, int, int), (a[0].d, a[1].p, a[2].i, a[3].i)) break; /* DPII */
    case 86: ZIGIMPORTS_CALL((double, void *, int, double), (a[0].d, a[1].p, a[2].i, a[3].d)) break; /* DPID */
    case 87: ZIGIMPORTS_CALL((double, void *, int, void *), (a[0].d, a[1].p, a[2].i, a[3].p)) break; /* DPIP */
    case 88: ZIGIMPORTS_CALL((double, void *, double, int), (a[0].d, a[1].p, a[2].d, a[3].i)) break; /* DPDI */
    case 89: ZIGIMPORTS_CALL((double, void *, double, double), (a[0].d, a[1].p, a[2].d, a[3].d)) break; /* DPDD */
    case 90: ZIGIMPORTS_CALL((double, void *, double, void *), (a[0].d, a[1].p, a[2].d, a[3].p)) break; /* DPDP */
    case 91: ZIGIMPORTS_CALL((double, void *, void *, int), (a[0].d, a[1].p, a[2].p, a[3].i)) break; /* DPPI */
    case 92: ZIGIMPORTS_CALL((double, void *, void *, double), (a[0].d, a[1].p, a[2].p, a[3].d)) break; /* DPPD */
    case 93: ZIGIMPORTS_CALL((double, void *, void *, void *), (a[0].d, a[1].p, a[2].p, a[3].p)) break; /* DPPP */
    case 94: ZIGIMPORTS_CALL((void *, int, int, int), (a[0].p, a[1].i, a[2].i, a[3].i)) break; /* PIII */
    case 95: ZIGIMPORTS_CALL((void *, int, int, double), (a[0].p, a[1].i, a[2].i, a[3].d)) break; /* PIID */
    case 96: ZIGIMPORTS_CALL((void *, int, int, void *), (a[0].p, a[1].i, a[2].i, a[3].p)) break; /* PIIP */
    case 97: ZIGIMPORTS_CALL((void *, int, double, int), (a[0].p, a[1].i, a[2].d, a[3].i)) break; /* PIDI */
    case 98: ZIGIMPORTS_CALL((void *, int, double, double), (a[0].p, a[1].i, a[2].d, a[3].d)) break; /* PIDD */
    case 99: ZIGIMPORTS_CALL((void *, int, double, void *), (a[0].p, a[1].i, a[2].d, a[3].p)) break; /* PIDP */
    case 100: ZIGIMPORTS_CALL((void *, int, void *, int), (a[0].p, a[1].i, a[2].p, a[3].i)) break; /* PIPI */
    case 101: ZIGIMPORTS_CALL((void *, int, void *, double), (a[0].p, a[1].i, a[2].p, a[3].d)) break; /* PIPD */
    case 102: ZIGIMPORTS_CALL((void *, int, void *, void *), (a[0].p, a[1].i, a[2].p, a[3].p)) break; /* PIPP */
    case 103: ZIGIMPORTS_CALL((void *, double, int, int), (a[0].p, a[1].d, a[2].i, a[3].i)) break; /* PDII */
    case 104: ZIGIMPORTS_CALL((void *, double, int, double), (a[0].p, a[1].d, a[2].i, a[3].d)) break; /* PDID */
    case 105: ZIGIMPORTS_CALL((void *, double, int, void *), (a[0].p, a[1].d, a[2].i, a[3].p)) break; /* PDIP */
    case 106: ZIGIMPORTS_CALL((void *, double, double, int), (a[0].p, a[1].d, a[2].d, a[3].i)) break; /* PDDI */
    case 107: ZIGIMPORTS_CALL((void *, double, double, double), (a[0].p, a[1].d, a[2].d, a[3].d)) break; /* PDDD */
    case 108: ZIGIMPORTS_CALL((void *, double, double, void *), (a[0].p, a[1].d, a[2].d, a[3].p)) break; /* PDDP */
    case 109: ZIGIMPORTS_CALL((void *, double, void *, int), (a[0].p, a[1].d, a[2].p, a[3].i)) break; /* PDPI */
    case 110: ZIGIMPORTS_CALL((void *, double, void *, double), (a[0].p, a[1].d, a[2].p, a[3].d)) break; /* PDPD */
    case 111: ZIGIMPORTS_CALL((void *, double, void *, void *), (a[0].p, a[1].d, a[2].p, a[3].p)) break; /* PDPP */
    case 112: ZIGIMPORTS_CALL((void *, void *, int, int), (a[0].p, a[1].p, a[2].i, a[3].i)) break; /* PPII */
    case 113: ZIGIMPORTS_CALL((void *, void *, int, double), (a[0].p, a[1].p, a[2].i, a[3].d)) break; /* PPID */
    case 114: ZIGIMPORTS_CALL((void *, void *, int, void *), (a[0].p, a[1].p, a[2].i, a[3].p)) break; /* PPIP */
    case 115: ZIGIMPORTS_CALL((void *, void *, double, int), (a[0].p, a[1].p, a[2].d, a[3].i)) break; /* PPDI */
    case 116: ZIGIMPORTS_CALL((void *, void *, double, double), (a[0].p, a[1].p, a[2].d, a[3].d)) break; /* PPDD */
    case 117: ZIGIMPORTS_CALL((void *, void *, double, void *), (a[0].p, a[1].p, a[2].d, a[3].p)) break; /* PPDP */
    case 118: ZIGIMPORTS_CALL((void *, void *, void *, int), (a[0].p, a[1].p, a[2].p, a[3].i)) break; /* PPPI */
    case 119: ZIGIMPORTS_CALL((void *, void *, void *, double), (a[0].p, a[1].p, a[2].p, a[3].d)) break; /* PPPD */
    case 120: ZIGIMPORTS_CALL((void *, void *, void *, void *), (a[0].p, a[1].p, a[2].p, a[3].p)) break; /* PPPP */
    case 121: ZIGIMPORTS_CALL((int, int, int, int, int), (a[0].i, a[1].i, a[2].i, a[3].i, a[4].i)) break; /* IIIII */
    case 122: ZIGIMPORTS_CALL((int, int, int, int, double), (a[0].i, a[1].i, a[2].i, a[3].i, a[4].d)) break; /* IIIID */
    case 123: ZIGIMPORTS_CALL((int, int, int, int, void *), (a[0].i, a[1].i, a[2].i, a[3].i, a[4].p)) break; /* IIIIP */
    case 124: ZIGIMPORTS_CALL((int, int, int, double, int), (a[0].i, a[1].i, a[2].i, a[3].d, a[4].i)) break; /* IIIDI */
    case 125: ZIGIMPORTS_CALL((int, int, int, double, double), (a[0].i, a[1].i, a[2].i, a[3].d, a[4].d)) break; /* IIIDD */
    case 126: ZIGIMPORTS_CALL((int, int, int, double, void *), (a[0].i, a[1].i, a[2].i, a[3].d, a[4].p)) break; /* IIIDP */
    case 127: ZIGIMPORTS_CALL((int, int, int, void *, int), (a[0].i, a[1].i, a[2].i, a[3].p, a[4].i)) break; /* IIIPI */
    case 128: ZIGIMPORTS_CALL((int, int, int, void *, double), (a[0].i, a[1].i, a[2].i, a[3].p, a[4].d)) break; /* IIIPD */
    case 129: ZIGIMPORTS_CALL((int, int, int, void *, void *), (a[0].i, a[1].i, a[2].i, a[3].p, a[4].p)) break; /* IIIPP */
    case 130: ZIGIMPORTS_CALL((int, int, double, int, int), (a[0].i, a[1].i, a[2].d, a[3].i, a[4].i)) break; /* IIDII */
    case 131: ZIGIMPORTS_CALL((int, int, double, int, double), (a[0].i, a[1].i, a[2].d, a[3].i, a[4].d)) break; /* IIDID */
    case 132: ZIGIMPORTS_CALL((int, int, double, int, void *), (a[0].i, a[1].i, a[2].d, a[3].i, a[4].p)) break; /* IIDIP */
    case 133: ZIGIMPORTS_CALL((int, int, double, double, int), (a[0].i, a[1].i, a[2].d, a[3].d, a[4].i)) break; /* IIDDI */
    case 134: ZIGIMPORTS_CALL((int, int, double, double, double), (a[0].i, a[1].i, a[2].d, a[3].d, a[4].d)) break; /* IIDDD */
    case 135: ZIGIMPORTS_CALL((int, int, double, double, void *), (a[0].i, a[1].i, a[2].d, a[3].d, a[4].p)) break; /* IIDDP */
    case 136: ZIGIMPORTS_CALL((int, int, double, void *, int), (a[0].i, a[1].i, a[2].d, a[3].p, a[4].i)) break; /* IIDPI */
    case 137: ZIGIMPORTS_CALL((int, int, double, void *, double), (a[0].i, a[1].i, a[2].d, a[3].p, a[4].d)) break; /* IIDPD */
    case 138: ZIGIMPORTS_CALL((int, int, double, void *, void *), (a[0].i, a[1].i, a[2].d, a[3].p, a[4].p)) break; /* IIDPP */
    case 139: ZIGIMPORTS_CALL((int, int, void *, int, int), (a[0].i, a[1].i, a[2].p, a[3].i, a[4].i)) break; /* IIPII */
    case 140: ZIGIMPORTS_CALL((int, int, void *, int, double), (a[0].i, a[1].i, a[2].p, a[3].i, a[4].d)) break; /* IIPID */
    case 141: ZIGIMPORTS_CALL((int, int, void *, int, void *), (a[0].i, a[1].i, a[2].p, a[3].i, a[4].p)) break; /* IIPIP */
    case 142: ZIGIMPORTS_CALL((int, int, void *, double, int), (a[0].i, a[1].i, a[2].p, a[3].d, a[4].i)) break; /* IIPDI */
    case 143: ZIGIMPORTS_CALL((int, int, void *, double, double), (a[0].i, a[1].i, a[2].p, a[3].d, a[4].d)) break; /* IIPDD */
    case 144: ZIGIMPORTS_CALL((int, int, void *, double, void *), (a[0].i, a[1].i, a[2].p, a[3].d, a[4].p)) break; /* IIPDP */
    case 145: ZIGIMPORTS_CALL((int, int, void *, void *, int), (a[0].i, a[1].i, a[2].p, a[3].p, a[4].i)) break; /* IIPPI */
    case 146: ZIGIMPORTS_CALL((int, int, void *, void *, double), (a[0].i, a[1].i, a[2].p, a[3].p, a[4].d)) break; /* IIPPD */
    case 147: ZIGIMPORTS_CALL((int, int, void *, void *, void *), (a[0].i, a[1].i, a[2].p, a[3].p, a[4].p)) break; /* IIPPP */
    case 148: ZIGIMPORTS_CALL((int, double, int, int, int), (a[0].i, a[1].d, a[2].i, a[3].i, a[4].i)) break; /* IDIII */
    case 149: ZIGIMPORTS_CALL((int, double, int, int, double), (a[0].i, a[1].d, a[2].i, a[3].i, a[4].d)) break; /* IDIID */
    case 150: ZIGIMPORTS_CALL((int, double, int, int, void *), (a[0].i, a[1].d, a[2].i, a[3].i, a[4].p)) break; /* IDIIP */
    case 151: ZIGIMPORTS_CALL((int, double, int, double, int), (a[0].i, a[1].d, a[2].i, a[3].d, a[4].i)) break; /* IDIDI */
    case 152: ZIGIMPORTS_CALL((int, double, int, double, double), (a[0].i, a[1].d, a[2].i, a[3].d, a[4].d)) break; /* IDIDD */
    case 153: ZIGIMPORTS_CALL((int, double, int, double, void *), (a[0].i, a[1].d, a[2].i, a[3].d, a[4].p)) break; /* IDIDP */
    case 154: ZIGIMPORTS_CALL((int, double, int, void *, int), (a[0].i, a[1].d, a[2].i, a[3].p, a[4].i)) break; /* IDIPI */
    case 155: ZIGIMPORTS_CALL((int, double, int, void *, double), (a[0].i, a[1].d, a[2].i, a[3].p, a[4].d)) break; /* IDIPD */
    case 156: ZIGIMPORTS_CALL((int, double, int, void *, void *), (a[0].i, a[1].d, a[2].i, a[3].p, a[4].p)) break; /* IDIPP */
    case 157: ZIGIMPORTS_CALL((int, double, double, int, int), (a[0].i, a[1].d, a[2].d, a[3].i, a[4].i)) break; /* IDDII */
    case 158: ZIGIMPORTS_CALL((int, double, double, int, double), (a[0].i, a[1].d, a[2].d, a[3].i, a[4].d)) break; /* IDDID */
    case 159: ZIGIMPORTS_CALL((int, double, double, int, void *), (a[0].i, a[1].d, a[2].d, a[3].i, a[4].p)) break; /* IDDIP */
    case 160: ZIGIMPORTS_CALL((int, double, double, double, int), (a[0].i, a[1].d, a[2].d, a[3].d, a[4].i)) break; /* IDDDI */
    case 161: ZIGIMPORTS_CALL((int, double, double, double, double), (a[0].i, a[1].d, a[2].d, a[3].d, a[4].d)) break; /* IDDDD */
    case 162: ZIGIMPORTS_CALL((int, double, double, double, void *), (a[0].i, a[1].d, a[2].d, a[3].d, a[4].p)) break; /* IDDDP */
    case 163: ZIGIMPORTS_CALL((int, double, double, void *, int), (a[0].i, a[1].d, a[2].d, a[3].p, a[4].i)) break; /* IDDPI */
    case 164: ZIGIMPORTS_CALL((int, double, double, void *, double), (a[0].i, a[1].d, a[2].d, a[3].p, a[4].d)) break; /* IDDPD */
    case 165: ZIGIMPORTS_CALL((int, double, double, void *, void *), (a[0].i, a[1].d, a[2].d, a[3].p, a[4].p)) break; /* IDDPP */
    case 166: ZIGIMPORTS_CALL((int, double, void *, int, int), (a[0].i, a[1].d, a[2].p, a[3].i, a[4].i)) break; /* IDPII */
    case 167: ZIGIMPORTS_CALL((int, double, void *, int, double), (a[0].i, a[1].d, a[2].p, a[3].i, a[4].d)) break; /* IDPID */
    case 168: ZIGIMPORTS_CALL((int, double, void *, int, void *), (a[0].i, a[1].d, a[2].p, a[3].i, a[4].p)) break; /* IDPIP */
    case 169: ZIGIMPORTS_CALL((int, double, void *, double, int), (a[0].i, a[1].d, a[2].p, a[3].d, a[4].i)) break; /* IDPDI */
    case 170: ZIGIMPORTS_CALL((int, double, void *, double, double), (a[0].i, a[1].d, a[2].p, a[3].d, a[4].d)) break; /* IDPDD */
    case 171: ZIGIMPORTS_CALL((int, double, void *, double, void *), (a[0].i, a[1].d, a[2].p, a[3].d, a[4].p)) break; /* IDPDP */
    case 172: ZIGIMPORTS_CALL((int, double, void *, void *, int), (a[0].i, a[1].d, a[2].p, a[3].p, a[4].i)) break; /* IDPPI */
    case 173: ZIGIMPORTS_CALL((int, double, void *, void *, double), (a[0].i, a[1].d, a[2].p, a[3].p, a[4].d)) break; /* IDPPD */
    case 174: ZIGIMPORTS_CALL((int, double, void *, void *, void *), (a[0].i, a[1].d, a[2].p, a[3].p, a[4].p)) break; /* IDPPP */
    case 175: ZIGIMPORTS_CALL((int, void *, int, int, int), (a[0].i, a[1].p, a[2].i, a[3].i, a[4].i)) break; /* IPIII */
    case 176: ZIGIMPORTS_CALL((int, void *, int, int, double), (a[0].i, a[1].p, a[2].i, a[3].i, a[4].d)) break; /* IPIID */
    case 177: ZIGIMPORTS_CALL((int, void *, int, int, void *), (a[0].i, a[1].p, a[2].i, a[3].i, a[4].p)) break; /* IPIIP */
    case 178: ZIGIMPORTS_CALL((int, void *, int, double, int), (a[0].i, a[1].p, a[2].i, a[3].d, a[4].i)) break; /* IPIDI */
    case 179: ZIGIMPORTS_CALL((int, void *, int, double, double), (a[0].i, a[1].p, a[2].i, a[3].d, a[4].d)) break; /* IPIDD */
    case 180: ZIGIMPORTS_CALL((int, void *, int, double, void *), (a[0].i, a[1].p, a[2].i, a[3].d, a[4].p)) break; /* IPIDP */
    case 181: ZIGIMPORTS_CALL((int, void *, int, void *, int), (a[0].i, a[1].p, a[2].i, a[3].p, a[4].i)) break; /* IPIPI */
    case 182: ZIGIMPORTS_CALL((int, void *, int, void *, double), (a[0].i, a[1].p, a[2].i, a[3].p, a[4].d)) break; /* IPIPD */
    case 183: ZIGIMPORTS_CALL((int, void *, int, void *, void *), (a[0].i, a[1].p, a[2].i, a[3].p, a[4].p)) break; /* IPIPP */
    case 184: ZIGIMPORTS_CALL((int, void *, double, int, int), (a[0].i, a[1].p, a[2].d, a[3].i, a[4].i)) break; /* IPDII */
    case 185: ZIGIMPORTS_CALL((int, void *, double, int, double), (a[0].i, a[1].p, a[2].d, a[3].i, a[4].d)) break; /* IPDID */
    case 186: ZIGIMPORTS_CALL((int, void *, double, int, void *), (a[0].i, a[1].p, a[2].d, a[3].i, a[4].p)) break; /* IPDIP */
    case 187: ZIGIMPORTS_CALL((int, void *, double, double, int), (a[0].i, a[1].p, a[2].d, a[3].d, a[4].i)) break; /* IPDDI */
    case 188: ZIGIMPORTS_CALL((int, void *, double, double, double), (a[0].i, a[1].p, a[2].d, a[3].d, a[4].d)) break; /* IPDDD */
    case 189: ZIGIMPORTS_CALL((int, void *, double, double, void *), (a[0].i, a[1].p, a[2].d, a[3].d, a[4].p)) break; /* IPDDP */
    case 190: ZIGIMPORTS_CALL((int, void *, double, void *, int), (a[0].i, a[1].p, a[2].d, a[3].p, a[4].i)) break; /* IPDPI */
    case 191: ZIGIMPORTS_CALL((int, void *, double, void *, double), (a[0].i, a[1].p, a[2].d, a[3].p, a[4].d)) break; /* IPDPD */
    case 192: ZIGIMPORTS_CALL((int, void *, double, void *, void *), (a[0].i, a[1].p, a[2].d, a[3].p, a[4].p)) break; /* IPDPP */
    case 193: ZIGIMPORTS_CALL((int, void *, void *, int, int), (a[0].i, a[1].p, a[2].p, a[3].i, a[4].i)) break; /* IPPII */
    case 194: ZIGIMPORTS_CALL((int, void *, void *, int, double), (a[0].i, a[1].p, a[2].p, a[3].i, a[4].d)) break; /* IPPID */
    case 195: ZIGIMPORTS_CALL((int, void *, void *, int, void *), (a[0].i, a[1].p, a[2].p, a[3].i, a[4].p)) break; /* IPPIP */
    case 196: ZIGIMPORTS_CALL((int, void *, void *, double, int), (a[0].i, a[1].p, a[2].p, a[3].d, a[4].i)) break; /* IPPDI */
    case 197: ZIGIMPORTS_CALL((int, void *, void *, double, double), (a[0].i, a[1].p, a[2].p, a[3].d, a[4].d)) break; /* IPPDD */
    case 198: ZIGIMPORTS_CALL((int, void *, void *, double, void *), (a[0].i, a[1].p, a[2].p, a[3].d, a[4].p)) break; /* IPPDP */
    case 199: ZIGIMPORTS_CALL((int, void *, void *, void *, int), (a[0].i, a[1].p, a[2].p, a[3].p, a[4].i)) break; /* IPPPI */
    case 200: ZIGIMPORTS_CALL((int, void *, void *, void *, double), (a[0].i, a[1].p, a[2].p, a[3].p, a[4].d)) break; /* IPPPD */
    case 201: ZIGIMPORTS_CALL((int, void *, void *, void *, void *), (a[0].i, a[1].p, a[2].p, a[3].p, a[4].p)) break; /* IPPPP */
    case 202: ZIGIMPORTS_CALL((double, int, int, int, int), (a[0].d, a[1].i, a[2].i, a[3].i, a[4].i)) break; /* DIIII */
    case 203: ZIGIMPORTS_CALL((double, int, int, int, double), (a[0].d, a[1].i, a[2].i, a[3].i, a[4].d)) break; /* DIIID */
    case 204: ZIGIMPORTS_CALL((double, int, int, int, void *), (a[0].d, a[1].i, a[2].i, a[3].i, a[4].p)) break; /* DIIIP */
    case 205: ZIGIMPORTS_CALL((double, int, int, double, int), (a[0].d, a[1].i, a[2].i, a[3].d, a[4].i)) break; /* DIIDI */
    case 206: ZIGIMPORTS_CALL((double, int, int, double, double), (a[0].d, a[1].i, a[2].i, a[3].d, a[4].d)) break; /* DIIDD */
    case 207: ZIGIMPORTS_CALL((double, int, int, double, void *), (a[0].d, a[1].i, a[2].i, a[3].d, a[4].p)) break; /* DIIDP */
    case 208: ZIGIMPORTS_CALL((double, int, int, void *, int), (a[0].d, a[1].i, a[2].i, a[3].p, a[4].i)) break; /* DIIPI */
    case 209: ZIGIMPORTS_CALL((double, int, int, void *, double), (a[0].d, a[1].i, a[2].i, a[3].p, a[4].d)) break; /* DIIPD */
    case 210: ZIGIMPORTS_CALL((double, int, int, void *, void *), (a[0].d, a[1].i, a[2].i, a[3].p, a[4].p)) break; /* DIIPP */
    case 211: ZIGIMPORTS_CALL((double, int, double, int, int), (a[0].d, a[1].i, a[2].d, a[3].i, a[4].i)) break; /* DIDII */
    case 212: ZIGIMPORTS_CALL((double, int, double, int, double), (a[0].d, a[1].i, a[2].d, a[3].i, a[4].d)) break; /* DIDID */
    case 213: ZIGIMPORTS_CALL((double, int, double, int, void *), (a[0].d, a[1].i, a[2].d, a[3].i, a[4].p)) break; /* DIDIP */
    case 214: ZIGIMPORTS_CALL((double, int, double, double, int), (a[0].d, a[1].i, a[2].d, a[3].d, a[4].i)) break; /* DIDDI */
    case 215: ZIGIMPORTS_CALL((double, int, double, double, double), (a[0].d, a[1].i, a[2].d, a[3].d, a[4].d)) break; /* DIDDD */
    case 216: ZIGIMPORTS_CALL((double, int, double, double, void *), (a[0].d, a[1].i, a[2].d, a[3].d, a[4].p)) break; /* DIDDP */
    case 217: ZIGIMPORTS_CALL((double, int, double, void *, int), (a[0].d, a[1].i, a[2].d, a[3].p, a[4].i)) break; /* DIDPI */
    case 218: ZIGIMPORTS_CALL((double, int, double, void *, double), (a[0].d, a[1].i, a[2].d, a[3].p, a[4].d)) break; /* DIDPD */
    case 219: ZIGIMPORTS_CALL((double, int, double, void *, void *), (a[0].d, a[1].i, a[2].d, a[3].p, a[4].p)) break; /* DIDPP */
    case 220: ZIGIMPORTS_CALL((double, int, void *, int, int), (a[0].d, a[1].i, a[2].p, a[3].i, a[4].i)) break; /* DIPII */
    case 221: ZIGIMPORTS_CALL((double, int, void *, int, double), (a[0].d, a[1].i, a[2].p, a[3].i, a[4].d)) break; /* DIPID */
    case 222: ZIGIMPORTS_CALL((double, int, void *, int, void *), (a[0].d, a[1].i, a[2].p, a[3].i, a[4].p)) break; /* DIPIP */
    case 223: ZIGIMPORTS_CALL((double, int, void *, double, int), (a[0].d, a[1].i, a[2].p, a[3].d, a[4].i)) break; /* DIPDI */
    case 224: ZIGIMPORTS_CALL((double, int, void *, double, double), (a[0].d, a[1].i, a[2].p, a[3].d, a[4].d)) break; /* DIPDD */
    case 225: ZIGIMPORTS_CALL((double, int, void *, double, void *), (a[0].d, a[1].i, a[2].p, a[3].d, a[4].p)) break; /* DIPDP */
    case 226: ZIGIMPORTS_CALL((double, int, void *, void *, int), (a[0].d, a[1].i, a[2].p, a[3].p, a[4].i)) break; /* DIPPI */
    case 227: ZIGIMPORTS_CALL((double, int, void *, void *, double), (a[0].d, a[1].i, a[2].p, a[3].p, a[4].d)) break; /* DIPPD */
    case 228: ZIGIMPORTS_CALL((double, int, void *, void *, void *), (a[0].d, a[1].i, a[2].p, a[3].p, a[4].p)) break; /* DIPPP */
    case 229: ZIGIMPORTS_CALL((double, double, int, int, int), (a[0].d, a[1].d, a[2].i, a[3].i, a[4].i)) break; /* DDIII */
    case 230: ZIGIMPORTS_CALL((double, double, int, int, double), (a[0].d, a[1].d, a[2].i, a[3].i, a[4].d)) break; /* DDIID */
    case 231: ZIGIMPORTS_CALL((double, double, int, int, void *), (a[0].d, a[1].d, a[2].i, a[3].i, a[4].p)) break; /* DDIIP */
    case 232: ZIGIMPORTS_CALL((double, double, int, double, int), (a[0].d, a[1].d, a[2].i, a[3].d, a[4].i)) break; /* DDIDI */
    case 233: ZIGIMPORTS_CALL((double, double, int, double, double), (a[0].d, a[1].d, a[2].i, a[3].d, a[4].d)) break; /* DDIDD */
    case 234: ZIGIMPORTS_CALL((double, double, int, double, void *), (a[0].d, a[1].d, a[2].i, a[3].d, a[4].p)) break; /* DDIDP */
    case 235: ZIGIMPORTS_CALL((double, double, int, void *, int), (a[0].d, a[1].d, a[2].i, a[3].p, a[4].i)) break; /* DDIPI */
    case 236: ZIGIMPORTS_CALL((double, double, int, void *, double), (a[0].d, a[1].d, a[2].i, a[3].p, a[4].d)) break; /* DDIPD */
    case 237: ZIGIMPORTS_CALL((double, double, int, void *, void *), (a[0].d, a[1].d, a[2].i, a[3].p, a[4].p)) break; /* DDIPP */
    case 238: ZIGIMPORTS_CALL((double, double, double, int, int), (a[0].d, a[1].d, a[2].d, a[3].i, a[4].i)) break; /* DDDII */
    case 239: ZIGIMPORTS_CALL((double, double, double, int, double), (a[0].d, a[1].d, a[2].d, a[3].i, a[4].d)) break; /* DDDID */
    case 240: ZIGIMPORTS_CALL((double, double, double, int, void *), (a[0].d, a[1].d, a[2].d, a[3].i, a[4].p)) break; /* DDDIP */
    case 241: ZIGIMPORTS_CALL((double, double, double, double, int), (a[0].d, a[1].d, a[2].d, a[3].d, a[4].i)) break; /* DDDDI */
    case 242: ZIGIMPORTS_CALL((double, double, double, double, double), (a[0].d, a[1].d, a[2].d, a[3].d, a[4].d)) break; /* DDDDD */
    case 243: ZIGIMPORTS_CALL((double, double, double, double, void *), (a[0].d, a[1].d, a[2].d, a[3].d, a[4].p)) break; /* DDDDP */
    case 244: ZIGIMPORTS_CALL((double, double, double, void *, int), (a[0].d, a[1].d, a[2].d, a[3].p, a[4].i)) break; /* DDDPI */
    case 245: ZIGIMPORTS_CALL((double, double, double, void *, double), (a[0].d, a[1].d, a[2].d, a[3].p, a[4].d)) break; /* DDDPD */
    case 246: ZIGIMPORTS_CALL((double, double, double, void *, void *), (a[0].d, a[1].d, a[2].d, a[3].p, a[4].p)) break; /* DDDPP */
    case 247: ZIGIMPORTS_CALL((double, double, void *, int, int), (a[0].d, a[1].d, a[2].p, a[3].i, a[4].i)) break; /* DDPII */
    case 248: ZIGIMPORTS_CALL((double, double, void *, int, double), (a[0].d, a[1].d, a[2].p, a[3].i, a[4].d)) break; /* DDPID */
    case 249: ZIGIMPORTS_CALL((double, double, void *, int, void *), (a[0].d, a[1].d, a[2].p, a[3].i, a[4].p)) break; /* DDPIP */
    case 250: ZIGIMPORTS_CALL((double, double, void *, double, int), (a[0].d, a[1].d, a[2].p, a[3].d, a[4].i)) break; /* DDPDI */
    case 251: ZIGIMPORTS_CALL((double, double, void *, double, double), (a[0].d, a[1].d, a[2].p, a[3].d, a[4].d)) break; /* DDPDD */
    case 252: ZIGIMPORTS_CALL((double, double, void *, double, void *), (a[0].d, a[1].d, a[2].p, a[3].d, a[4].p)) break; /* DDPDP */
    case 253: ZIGIMPORTS_CALL((double, double, void *, void *, int), (a[0].d, a[1].d, a[2].p, a[3].p, a[4].i)) break; /* DDPPI */
    case 254: ZIGIMPORTS_CALL((double, double, void *, void *, double), (a[0].d, a[1].d, a[2].p, a[3].p, a[4].d)) break; /* DDPPD */
    case 255: ZIGIMPORTS_CALL((double, double, void *, void *, void *), (a[0].d, a[1].d, a[2].p, a[3].p, a[4].p)) break; /* DDPPP */
    case 256: ZIGIMPORTS_CALL((double, void *, int, int, int), (a[0].d, a[1].p, a[2].i, a[3].i, a[4].i)) break; /* DPIII */
    case 257: ZIGIMPORTS_CALL((double, void *, int, int, double), (a[0].d, a[1].p, a[2].i, a[3].i, a[4].d)) break; /* DPIID */
    case 258: ZIGIMPORTS_CALL((double, void *, int, int, void *), (a[0].d, a[1].p, a[2].i, a[3].i, a[4].p)) break; /* DPIIP */
    case 259: ZIGIMPORTS_CALL((double, void *, int, double, int), (a[0].d, a[1].p, a[2].i, a[3].d, a[4].i)) break; /* DPIDI */
    case 260: ZIGIMPORTS_CALL((double, void *, int, double, double), (a[0].d, a[1].p, a[2].i, a[3].d, a[4].d)) break; /* DPIDD */
    case 261: ZIGIMPORTS_CALL((double, void *, int, double, void *), (a[0].d, a[1].p, a[2].i, a[3].d, a[4].p)) break; /* DPIDP */
    case 262: ZIGIMPORTS_CALL((double, void *, int, void *, int), (a[0].d, a[1].p, a[2].i, a[3].p, a[4].i)) break; /* DPIPI */
    case 263: ZIGIMPORTS_CALL((double, void *, int, void *, double), (a[0].d, a[1].p, a[2].i, a[3].p, a[4].d)) break; /* DPIPD */
    case 264: ZIGIMPORTS_CALL((double, void *, int, void *, void *), (a[0].d, a[1].p, a[2].i, a[3].p, a[4].p)) break; /* DPIPP */
    case 265: ZIGIMPORTS_CALL((double, void *, double, int, int), (a[0].d, a[1].p, a[2].d, a[3].i, a[4].i)) break; /* DPDII */
    case 266: ZIGIMPORTS_CALL((double, void *, double, int, double), (a[0].d, a[1].p, a[2].d, a[3].i, a[4].d)) break; /* DPDID */
    case 267: ZIGIMPORTS_CALL((double, void *, double, int, void *), (a[0].d, a[1].p, a[2].d, a[3].i, a[4].p)) break; /* DPDIP */
    case 268: ZIGIMPORTS_CALL((double, void *, double, double, int), (a[0].d, a[1].p, a[2].d, a[3].d, a[4].i)) break; /* DPDDI */
    case 269: ZIGIMPORTS_CALL((double, void *, double, double, double), (a[0].d, a[1].p, a[2].d, a[3].d, a[4].d)) break; /* DPDDD */
    case 270: ZIGIMPORTS_CALL((double, void *, double, double, void *), (a[0].d, a[1].p, a[2].d, a[3].d, a[4].p)) break; /* DPDDP */
    case 271: ZIGIMPORTS_CALL((double, void *, double, void *, int), (a[0].d, a[1].p, a[2].d, a[3].p, a[4].i)) break; /* DPDPI */
    case 272: ZIGIMPORTS_CALL((double, void *, double, void *, double), (a[0].d, a[1].p, a[2].d, a[3].p, a[4].d)) break; /* DPDPD */
    case 273: ZIGIMPORTS_CALL((double, void *, double, void *, void *), (a[0].d, a[1].p, a[2].d, a[3].p, a[4].p)) break; /* DPDPP */
    case 274: ZIGIMPORTS_CALL((double, void *, void *, int, int), (a[0].d, a[1].p, a[2].p, a[3].i, a[4].i)) break; /* DPPII */
    case 275: ZIGIMPORTS_CALL((double, void *, void *, int, double), (a[0].d, a[1].p, a[2].p, a[3].i, a[4].d)) break; /* DPPID */
    case 276: ZIGIMPORTS_CALL((double, void *, void *, int, void *), (a[0].d, a[1].p, a[2].p, a[3].i, a[4].p)) break; /* DPPIP */
    case 277: ZIGIMPORTS_CALL((double, void *, void *, double, int), (a[0].d, a[1].p, a[2].p, a[3].d, a[4].i)) break; /* DPPDI */
    case 278: ZIGIMPORTS_CALL((double, void *, void *, double, double), (a[0].d, a[1].p, a[2].p, a[3].d, a[4].d)) break; /* DPPDD */
    case 279: ZIGIMPORTS_CALL((double, void *, void *, double, void *), (a[0].d, a[1].p, a[2].p, a[3].d, a[4].p)) break; /* DPPDP */
    case 280: ZIGIMPORTS_CALL((double, void *, void *, void *, int), (a[0].d, a[1].p, a[2].p, a[3].p, a[4].i)) break; /* DPPPI */
    case 281: ZIGIMPORTS_CALL((double, void *, void *, void *, double), (a[0].d, a[1].p, a[2].p, a[3].p, a[4].d)) break; /* DPPPD */
    case 282: ZIGIMPORTS_CALL((double, void *, void *, void *, void *), (a[0].d, a[1].p, a[2].p, a[3].p, a[4].p)) break; /* DPPPP */
    case 283: ZIGIMPORTS_CALL((void *, int, int, int, int), (a[0].p, a[1].i, a[2].i, a[3].i, a[4].i)) break; /* PIIII */
    case 284: ZIGIMPORTS_CALL((void *, int, int, int, double), (a[0].p, a[1].i, a[2].i, a[3].i, a[4].d)) break; /* PIIID */
    case 285: ZIGIMPORTS_CALL((void *, int, int, int, void *), (a[0].p, a[1].i, a[2].i, a[3].i, a[4].p)) break; /* PIIIP */
    case 286: ZIGIMPORTS_CALL((void *, int, int, double, int), (a[0].p, a[1].i, a[2].i, a[3].d, a[4].i)) break; /* PIIDI */
    case 287: ZIGIMPORTS_CALL((void *, int, int, double, double), (a[0].p, a[1].i, a[2].i, a[3].d, a[4].d)) break; /* PIIDD */
    case 288: ZIGIMPORTS_CALL((void *, int, int, double, void *), (a[0].p, a[1].i, a[2].i, a[3].d, a[4].p)) break; /* PIIDP */
    case 289: ZIGIMPORTS_CALL((void *, int, int, void *, int), (a[0].p, a[1].i, a[2].i, a[3].p, a[4].i)) break; /* PIIPI */
    case 290: ZIGIMPORTS_CALL((void *, int, int, void *, double), (a[0].p, a[1].i, a[2].i, a[3].p, a[4].d)) break; /* PIIPD */
    case 291: ZIGIMPORTS_CALL((void *, int, int, void *, void *), (a[0].p, a[1].i, a[2].i, a[3].p, a[4].p)) break; /* PIIPP */
    case 292: ZIGIMPORTS_CALL((void *, int, double, int, int), (a[0].p, a[1].i, a[2].d, a[3].i, a[4].i)) break; /* PIDII */
    case 293: ZIGIMPORTS_CALL((void *, int, double, int, double), (a[0].p, a[1].i, a[2].d, a[3].i, a[4].d)) break; /* PIDID */
    case 294: ZIGIMPORTS_CALL((void *, int, double, int, void *), (a[0].p, a[1].i, a[2].d, a[3].i, a[4].p)) break; /* PIDIP */
    case 295: ZIGIMPORTS_CALL((void *, int, double, double, int), (a[0].p, a[1].i, a[2].d, a[3].d, a[4].i)) break; /* PIDDI */
    case 296: ZIGIMPORTS_CALL((void *, int, double, double, double), (a[0].p, a[1].i, a[2].d, a[3].d, a[4].d)) break; /* PIDDD */
    case 297: ZIGIMPORTS_CALL((void *, int, double, double, void *), (a[0].p, a[1].i, a[2].d, a[3].d, a[4].p)) break; /* PIDDP */
    case 298: ZIGIMPORTS_CALL((void *, int, double, void *, int), (a[0].p, a[1].i, a[2].d, a[3].p, a[4].i)) break; /* PIDPI */
    case 299: ZIGIMPORTS_CALL((void *, int, double, void *, double), (a[0].p, a[1].i, a[2].d, a[3].p, a[4].d)) break; /* PIDPD */
    case 300: ZIGIMPORTS_CALL((void *, int, double, void *, void *), (a[0].p, a[1].i, a[2].d, a[3].p, a[4].p)) break; /* PIDPP */
    case 301: ZIGIMPORTS_CALL((void *, int, void *, int, int), (a[0].p, a[1].i, a[2].p, a[3].i, a[4].i)) break; /* PIPII */
    case 302: ZIGIMPORTS_CALL((void *, int, void *, int, double), (a[0].p, a[1].i, a[2].p, a[3].i, a[4].d)) break; /* PIPID */
    case 303: ZIGIMPORTS_CALL((void *, int, void *, int, void *), (a[0].p, a[1].i, a[2].p, a[3].i, a[4].p)) break; /* PIPIP */
    case 304: ZIGIMPORTS_CALL((void *, int, void *, double, int), (a[0].p, a[1].i, a[2].p, a[3].d, a[4].i)) break; /* PIPDI */
    case 305: ZIGIMPORTS_CALL((void *, int, void *, double, double), (a[0].p, a[1].i, a[2].p, a[3].d, a[4].d)) break; /* PIPDD */
    case 306: ZIGIMPORTS_CALL((void *, int, void *, double, void *), (a[0].p, a[1].i, a[2].p, a[3].d, a[4].p)) break; /* PIPDP */
    case 307: ZIGIMPORTS_CALL((void *, int, void *, void *, int), (a[0].p, a[1].i, a[2].p, a[3].p, a[4].i)) break; /* PIPPI */
    case 308: ZIGIMPORTS_CALL((void *, int, void *, void *, double), (a[0].p, a[1].i, a[2].p, a[3].p, a[4].d)) break; /* PIPPD */
    case 309: ZIGIMPORTS_CALL((void *, int, void *, void *, void *), (a[0].p, a[1].i, a[2].p, a[3].p, a[4].p)) break; /* PIPPP */
    case 310: ZIGIMPORTS_CALL((void *, double, int, int, int), (a[0].p, a[1].d, a[2].i, a[3].i, a[4].i)) break; /* PDIII */
    case 311: ZIGIMPORTS_CALL((void *, double, int, int, double), (a[0].p, a[1].d, a[2].i, a[3].i, a[4].d)) break; /* PDIID */
    case 312: ZIGIMPORTS_CALL((void *, double, int, int, void *), (a[0].p, a[1].d, a[2].i, a[3].i, a[4].p)) break; /* PDIIP */
    case 313: ZIGIMPORTS_CALL((void *, double, int, double, int), (a[0].p, a[1].d, a[2].i, a[3].d, a[4].i)) break; /* PDIDI */
    case 314: ZIGIMPORTS_CALL((void *, double, int, double, double), (a[0].p, a[1].d, a[2].i, a[3].d, a[4].d)) break; /* PDIDD */
    case 315: ZIGIMPORTS_CALL((void *, double, int, double, void *), (a[0].p, a[1].d, a[2].i, a[3].d, a[4].p)) break; /* PDIDP */
    case 316: ZIGIMPORTS_CALL((void *, double, int, void *, int), (a[0].p, a[1].d, a[2].i, a[3].p, a[4].i)) break; /* PDIPI */
    case 317: ZIGIMPORTS_CALL((void *, double, int, void *, double), (a[0].p, a[1].d, a[2].i, a[3].p, a[4].d)) break; /* PDIPD */
    case 318: ZIGIMPORTS_CALL((void *, double, int, void *, void *), (a[0].p, a[1].d, a[2].i, a[3].p, a[4].p)) break; /* PDIPP */
    case 319: ZIGIMPORTS_CALL((void *, double, double, int, int), (a[0].p, a[1].d, a[2].d, a[3].i, a[4].i)) break; /* PDDII */
    case 320: ZIGIMPORTS_CALL((void *, double, double, int, double), (a[0].p, a[1].d, a[2].d, a[3].i, a[4].d)) break; /* PDDID */
    case 321: ZIGIMPORTS_CALL((void *, double, double, int, void *), (a[0].p, a[1].d, a[2].d, a[3].i, a[4].p)) break; /* PDDIP */
    case 322: ZIGIMPORTS_CALL((void *, double, double, double, int), (a[0].p, a[1].d, a[2].d, a[3].d, a[4].i)) break; /* PDDDI */
    case 323: ZIGIMPORTS_CALL((void *, double, double, double, double), (a[0].p, a[1].d, a[2].d, a[3].d, a[4].d)) break; /* PDDDD */
    case 324: ZIGIMPORTS_CALL((void *, double, double, double, void *), (a[0].p, a[1].d, a[2].d, a[3].d, a[4].p)) break; /* PDDDP */
    case 325: ZIGIMPORTS_CALL((void *, double, double, void *, int), (a[0].p, a[1].d, a[2].d, a[3].p, a[4].i)) break; /* PDDPI */
    case 326: ZIGIMPORTS_CALL((void *, double, double, void *, double), (a[0].p, a[1].d, a[2].d, a[3].p, a[4].d)) break; /* PDDPD */
    case 327: ZIGIMPORTS_CALL((void *, double, double, void *, void *), (a[0].p, a[1].d, a[2].d, a[3].p, a[4].p)) break; /* PDDPP */
    case 328: ZIGIMPORTS_CALL((void *, double, void *, int, int), (a[0].p, a[1].d, a[2].p, a[3].i, a[4].i)) break; /* PDPII */
    case 329: ZIGIMPORTS_CALL((void *, double, void *, int, double), (a[0].p, a[1].d, a[2].p, a[3].i, a[4].d)) break; /* PDPID */
    case 330: ZIGIMPORTS_CALL((void *, double, void *, int, void *), (a[0].p, a[1].d, a[2].p, a[3].i, a[4].p)) break; /* PDPIP */
    case 331: ZIGIMPORTS_CALL((void *, double, void *, double, int), (a[0].p, a[1].d, a[2].p, a[3].d, a[4].i)) break; /* PDPDI */
    case 332: ZIGIMPORTS_CALL((void *, double, void *, double, double), (a[0].p, a[1].d, a[2].p, a[3].d, a[4].d)) break; /* PDPDD */
    case 333: ZIGIMPORTS_CALL((void *, double, void *, double, void *), (a[0].p, a[1].d, a[2].p, a[3].d, a[4].p)) break; /* PDPDP */
    case 334: ZIGIMPORTS_CALL((void *, double, void *, void *, int), (a[0].p, a[1].d, a[2].p, a[3].p, a[4].i)) break; /* PDPPI */
    case 335: ZIGIMPORTS_CALL((void *, double, void *, void *, double), (a[0].p, a[1].d, a[2].p, a[3].p, a[4].d)) break; /* PDPPD */
    case 336: ZIGIMPORTS_CALL((void *, double, void *, void *, void *), (a[0].p, a[1].d, a[2].p, a[3].p, a[4].p)) break; /* PDPPP */
    case 337: ZIGIMPORTS_CALL((void *, void *, int, int, int), (a[0].p, a[1].p, a[2].i, a[3].i, a[4].i)) break; /* PPIII */
    case 338: ZIGIMPORTS_CALL((void *, void *, int, int, double), (a[0].p, a[1].p, a[2].i, a[3].i, a[4].d)) break; /* PPIID */
    case 339: ZIGIMPORTS_CALL((void *, void *, int, int, void *), (a[0].p, a[1].p, a[2].i, a[3].i, a[4].p)) break; /* PPIIP */
    case 340: ZIGIMPORTS_CALL((void *, void *, int, double, int), (a[0].p, a[1].p, a[2].i, a[3].d, a[4].i)) break; /* PPIDI */
    case 341: ZIGIMPORTS_CALL((void *, void *, int, double, double), (a[0].p, a[1].p, a[2].i, a[3].d, a[4].d)) break; /* PPIDD */
    case 342: ZIGIMPORTS_CALL((void *, void *, int, double, void *), (a[0].p, a[1].p, a[2].i, a[3].d, a[4].p)) break; /* PPIDP */
    case 343: ZIGIMPORTS_CALL((void *, void *, int, void *, int), (a[0].p, a[1].p, a[2].i, a[3].p, a[4].i)) break; /* PPIPI */
    case 344: ZIGIMPORTS_CALL((void *, void *, int, void *, double), (a[0].p, a[1].p, a[2].i, a[3].p, a[4].d)) break; /* PPIPD */
    case 345: ZIGIMPORTS_CALL((void *, void *, int, void *, void *), (a[0].p, a[1].p, a[2].i, a[3].p, a[4].p)) break; /* PPIPP */
    case 346: ZIGIMPORTS_CALL((void *, void *, double, int, int), (a[0].p, a[1].p, a[2].d, a[3].i, a[4].i)) break; /* PPDII */
    case 347: ZIGIMPORTS_CALL((void *, void *, double, int, double), (a[0].p, a[1].p, a[2].d, a[3].i, a[4].d)) break; /* PPDID */
    case 348: ZIGIMPORTS_CALL((void *, void *, double, int, void *), (a[0].p, a[1].p, a[2].d, a[3].i, a[4].p)) break; /* PPDIP */
    case 349: ZIGIMPORTS_CALL((void *, void *, double, double, int), (a[0].p, a[1].p, a[2].d, a[3].d, a[4].i)) break; /* PPDDI */
    case 350: ZIGIMPORTS_CALL((void *, void *, double, double, double), (a[0].p, a[1].p, a[2].d, a[3].d, a[4].d)) break; /* PPDDD */
    case 351: ZIGIMPORTS_CALL((void *, void *, double, double, void *), (a[0].p, a[1].p, a[2].d, a[3].d, a[4].p)) break; /* PPDDP */
    case 352: ZIGIMPORTS_CALL((void *, void *, double, void *, int), (a[0].p, a[1].p, a[2].d, a[3].p, a[4].i)) break; /* PPDPI */
    case 353: ZIGIMPORTS_CALL((void *, void *, double, void *, double), (a[0].p, a[1].p, a[2].d, a[3].p, a[4].d)) break; /* PPDPD */
    case 354: ZIGIMPORTS_CALL((void *, void *, double, void *, void *), (a[0].p, a[1].p, a[2].d, a[3].p, a[4].p)) break; /* PPDPP */
    case 355: ZIGIMPORTS_CALL((void *, void *, void *, int, int), (a[0].p, a[1].p, a[2].p, a[3].i, a[4].i)) break; /* PPPII */
    case 356: ZIGIMPORTS_CALL((void *, void *, void *, int, double), (a[0].p, a[1].p, a[2].p, a[3].i, a[4].d)) break; /* PPPID */
    case 357: ZIGIMPORTS_CALL((void *, void *, void *, int, void *), (a[0].p, a[1].p, a[2].p, a[3].i, a[4].p)) break; /* PPPIP */
    case 358: ZIGIMPORTS_CALL((void *, void *, void *, double, int), (a[0].p, a[1].p, a[2].p, a[3].d, a[4].i)) break; /* PPPDI */
    case 359: ZIGIMPORTS_CALL((void *, void *, void *, double, double), (a[0].p, a[1].p, a[2].p, a[3].d, a[4].d)) break; /* PPPDD */
    case 360: ZIGIMPORTS_CALL((void *, void *, void *, double, void *), (a[0].p, a[1].p, a[2].p, a[3].d, a[4].p)) break; /* PPPDP */
    case 361: ZIGIMPORTS_CALL((void *, void *, void *, void *, int), (a[0].p, a[1].p, a[2].p, a[3].p, a[4].i)) break; /* PPPPI */
    case 362: ZIGIMPORTS_CALL((void *, void *, void *, void *, double), (a[0].p, a[1].p, a[2].p, a[3].p, a[4].d)) break; /* PPPPD */
    case 363: ZIGIMPORTS_CALL((void *, void *, void *, void *, void *), (a[0].p, a[1].p, a[2].p, a[3].p, a[4].p)) break; /* PPPPP */
    case 364: ZIGIMPORTS_CALL((int, int, int, int, int, int), (a[0].i, a[1].i, a[2].i, a[3].i, a[4].i, a[5].i)) break; /* IIIIII */
    case 365: ZIGIMPORTS_CALL((int, int, int, int, int, double), (a[0].i, a[1].i, a[2].i, a[3].i, a[4].i, a[5].d)) break; /* IIIIID */
    case 366: ZIGIMPORTS_CALL((int, int, int, int, int, void *), (a[0].i, a[1].i, a[2].i, a[3].i, a[4].i, a[5].p)) break; /* IIIIIP */
    case 367: ZIGIMPORTS_CALL((int, int, int, int, double, int), (a[0].i, a[1].i, a[2].i, a[3].i, a[4].d, a[5].i)) break; /* IIIIDI */
    case 368: ZIGIMPORTS_CALL((int, int, int, int, double, double), (a[0].i, a[1].i, a[2].i, a[3].i, a[4].d, a[5].d)) break; /* IIIIDD */
    case 369: ZIGIMPORTS_CALL((int, int, int, int, double, void *), (a[0].i, a[1].i, a[2].i, a[3].i, a[4].d, a[5].p)) break; /* IIIIDP */
    case 370: ZIGIMPORTS_CALL((int, int, int, int, void *, int), (a[0].i, a[1].i, a[2].i, a[3].i, a[4].p, a[5].i)) break; /* IIIIPI */
    case 371: ZIGIMPORTS_CALL((int, int, int, int, void *, double), (a[0].i, a[1].i, a[2].i, a[3].i, a[4].p, a[5].d)) break; /* IIIIPD */
    case 372: ZIGIMPORTS_CALL((int, int, int, int, void *, void *), (a[0].i, a[1].i, a[2].i, a[3].i, a[4].p, a[5].p)) break; /* IIIIPP */
    case 373: ZIGIMPORTS_CALL((int, int, int, double, int, int), (a[0].i, a[1].i, a[2].i, a[3].d, a[4].i, a[5].i)) break; /* IIIDII */
    case 374: ZIGIMPORTS_CALL((int, int, int, double, int, double), (a[0].i, a[1].i, a[2].i, a[3].d, a[4].i, a[5].d)) break; /* IIIDID */
    case 375: ZIGIMPORTS_CALL((int, int, int, double, int, void *), (a[0].i, a[1].i, a[2].i, a[3].d, a[4].i, a[5].p)) break; /* IIIDIP */
    case 376: ZIGIMPORTS_CALL((int, int, int, double, double, int), (a[0].i, a[1].i, a[2].i, a[3].d, a[4].d, a[5].i)) break; /* IIIDDI */
    case 377: ZIGIMPORTS_CALL((int, int, int, double, double, double), (a[0].i, a[1].i, a[2].i, a[3].d, a[4].d, a[5].d)) break; /* IIIDDD */
    case 378: ZIGIMPORTS_CALL((int, int, int, double, double, void *), (a[0].i, a[1].i, a[2].i, a[3].d, a[4].d, a[5].p)) break; /* IIIDDP */
    case 379: ZIGIMPORTS_CALL((int, int, int, double, void *, int), (a[0].i, a[1].i, a[2].i, a[3].d, a[4].p, a[5].i)) break; /* IIIDPI */
    case 380: ZIGIMPORTS_CALL((int, int, int, double, void *, double), (a[0].i, a[1].i, a[2].i, a[3].d, a[4].p, a[5].d)) break; /* IIIDPD */
    case 381: ZIGIMPORTS_CALL((int, int, int, double, void *, void *), (a[0].i, a[1].i, a[2].i, a[3].d, a[4].p, a[5].p)) break; /* IIIDPP */
    case 382: ZIGIMPORTS_CALL((int, int, int, void *, int, int), (a[0].i, a[1].i, a[2].i, a[3].p, a[4].i, a[5].i)) break; /* IIIPII */
    case 383: ZIGIMPORTS_CALL((int, int, int, void *, int, double), (a[0].i, a[1].i, a[2].i, a[3].p, a[4].i, a[5].d)) break; /* IIIPID */
    case 384: ZIGIMPORTS_CALL((int, int, int, void *, int, void *), (a[0].i, a[1].i, a[2].i, a[3].p, a[4].i, a[5].p)) break; /* IIIPIP */
    case 385: ZIGIMPORTS_CALL((int, int, int, void *, double, int), (a[0].i, a[1].i, a[2].i, a[3].p, a[4].d, a[5].i)) break; /* IIIPDI */
    case 386: ZIGIMPORTS_CALL((int, int, int, void *, double, double), (a[0].i, a[1].i, a[2].i, a[3].p, a[4].d, a[5].d)) break; /* IIIPDD */
    case 387: ZIGIMPORTS_CALL((int, int, int, void *, double, void *), (a[0].i, a[1].i, a[2].i, a[3].p, a[4].d, a[5].p)) break; /* IIIPDP */
    case 388: ZIGIMPORTS_CALL((int, int, int, void *, void *, int), (a[0].i, a[1].i, a[2].i, a[3].p, a[4].p, a[5].i)) break; /* IIIPPI */
    case 389: ZIGIMPORTS_CALL((int, int, int, void *, void *, double), (a[0].i, a[1].i, a[2].i, a[3].p, a[4].p, a[5].d)) break; /* IIIPPD */
    case 390: ZIGIMPORTS_CALL((int, int, int, void *, void *, void *), (a[0].i, a[1].i, a[2].i, a[3].p, a[4].p, a[5].p)) break; /* IIIPPP */
    case 391: ZIGIMPORTS_CALL((int, int, double, int, int, int), (a[0].i, a[1].i, a[2].d, a[3].i, a[4].i, a[5].i)) break; /* IIDIII */
    case 392: ZIGIMPORTS_CALL((int, int, double, int, int, double), (a[0].i, a[1].i, a[2].d, a[3].i, a[4].i, a[5].d)) break; /* IIDIID */
    case 393: ZIGIMPORTS_CALL((int, int, double, int, int, void *), (a[0].i, a[1].i, a[2].d, a[3].i, a[4].i, a[5].p)) break; /* IIDIIP */
    case 394: ZIGIMPORTS_CALL((int, int, double, int, double, int), (a[0].i, a[1].i, a[2].d, a[3].i, a[4].d, a[5].i)) break; /* IIDIDI */
    case 395: ZIGIMPORTS_CALL((int, int, double, int, double, double), (a[0].i, a[1].i, a[2].d, a[3].i, a[4].d, a[5].d)) break; /* IIDIDD */
    case 396: ZIGIMPORTS_CALL((int, int, double, int, double, void *), (a[0].i, a[1].i, a[2].d, a[3].i, a[4].d, a[5].p)) break; /* IIDIDP */
    case 397: ZIGIMPORTS_CALL((int, int, double, int, void *, int), (a[0].i, a[1].i, a[2].d, a[3].i, a[4].p, a[5].i)) break; /* IIDIPI */
    case 398: ZIGIMPORTS_CALL((int, int, double, int, void *, double), (a[0].i, a[1].i, a[2].d, a[3].i, a[4].p, a[5].d)) break; /* IIDIPD */
    case 399: ZIGIMPORTS_CALL((int, int, double, int, void *, void *), (a[0].i, a[1].i, a[2].d, a[3].i, a[4].p, a[5].p)) break; /* IIDIPP */
    case 400: ZIGIMPORTS_CALL((int, int, double, double, int, int), (a[0].i, a[1].i, a[2].d, a[3].d, a[4].i, a[5].i)) break; /* IIDDII */
    case 401: ZIGIMPORTS_CALL((int, int, double, double, int, double), (a[0].i, a[1].i, a[2].d, a[3].d, a[4].i, a[5].d)) break; /* IIDDID */
    case 402: ZIGIMPORTS_CALL((int, int, double, double, int, void *), (a[0].i, a[1].i, a[2].d, a[3].d, a[4].i, a[5].p)) break; /* IIDDIP */
    case 403: ZIGIMPORTS_CALL((int, int, double, double, double, int), (a[0].i, a[1].i, a[2].d, a[3].d, a[4].d, a[5].i)) break; /* IIDDDI */
    case 404: ZIGIMPORTS_CALL((int, int, double, double, double, double), (a[0].i, a[1].i, a[2].d, a[3].d, a[4].d, a[5].d)) break; /* IIDDDD */
    case 405: ZIGIMPORTS_CALL((int, int, double, double, double, void *), (a[0].i, a[1].i, a[2].d, a[3].d, a[4].d, a[5].p)) break; /* IIDDDP */
    case 406: ZIGIMPORTS_CALL((int, int, double, double, void *, int), (a[0].i, a[1].i, a[2].d, a[3].d, a[4].p, a[5].i)) break; /* IIDDPI */
    case 407: ZIGIMPORTS_CALL((int, int, double, double, void *, double), (a[0].i, a[1].i, a[2].d, a[3].d, a[4].p, a[5].d)) break; /* IIDDPD */
    case 408: ZIGIMPORTS_CALL((int, int, double, double, void *, void *), (a[0].i, a[1].i, a[2].d, a[3].d, a[4].p, a[5].p)) break; /* IIDDPP */
    case 409: ZIGIMPORTS_CALL((int, int, double, void *, int, int), (a[0].i, a[1].i, a[2].d, a[3].p, a[4].i, a[5].i)) break; /* IIDPII */
    case 410: ZIGIMPORTS_CALL((int, int, double, void *, int, double), (a[0].i, a[1].i, a[2].d, a[3].p, a[4].i, a[5].d)) break; /* IIDPID */
    case 411: ZIGIMPORTS_CALL((int, int, double, void *, int, void *), (a[0].i, a[1].i, a[2].d, a[3].p, a[4].i, a[5].p)) break; /* IIDPIP */
    case 412: ZIGIMPORTS_CALL((int, int, double, void *, double, int), (a[0].i, a[1].i, a[2].d, a[3].p, a[4].d, a[5].i)) break; /* IIDPDI */
    case 413: ZIGIMPORTS_CALL((int, int, double, void *, double, double), (a[0].i, a[1].i, a[2].d, a[3].p, a[4].d, a[5].d)) break; /* IIDPDD */
    case 414: ZIGIMPORTS_CALL((int, int, double, void *, double, void *), (a[0].i, a[1].i, a[2].d, a[3].p, a[4].d, a[5].p)) break; /* IIDPDP */
    case 415: ZIGIMPORTS_CALL((int, int, double, void *, void *, int), (a[0].i, a[1].i, a[2].d, a[3].p, a[4].p, a[5].i)) break; /* IIDPPI */
    case 416: ZIGIMPORTS_CALL((int, int, double, void *, void *, double), (a[0].i, a[1].i, a[2].d, a[3].p, a[4].p, a[5].d)) break; /* IIDPPD */
    case 417: ZIGIMPORTS_CALL((int, int, double, void *, void *, void *), (a[0].i, a[1].i, a[2].d, a[3].p, a[4].p, a[5].p)) break; /* IIDPPP */
    case 418: ZIGIMPORTS_CALL((int, int, void *, int, int, int), (a[0].i, a[1].i, a[2].p, a[3].i, a[4].i, a[5].i)) break; /* IIPIII */
    case 419: ZIGIMPORTS_CALL((int, int, void *, int, int, double), (a[0].i, a[1].i, a[2].p, a[3].i, a[4].i, a[5].d)) break; /* IIPIID */
    case 420: ZIGIMPORTS_CALL((int, int, void *, int, int, void *), (a[0].i, a[1].i, a[2].p, a[3].i, a[4].i, a[5].p)) break; /* IIPIIP */
    case 421: ZIGIMPORTS_CALL((int, int, void *, int, double, int), (a[0].i, a[1].i, a[2].p, a[3].i, a[4].d, a[5].i)) break; /* IIPIDI */
    case 422: ZIGIMPORTS_CALL((int, int, void *, int, double, double), (a[0].i, a[1].i, a[2].p, a[3].i, a[4].d, a[5].d)) break; /* IIPIDD */
    case 423: ZIGIMPORTS_CALL((int, int, void *, int, double, void *), (a[0].i, a[1].i, a[2].p, a[3].i, a[4].d, a[5].p)) break; /* IIPIDP */
    case 424: ZIGIMPORTS_CALL((int, int, void *, int, void *, int), (a[0].i, a[1].i, a[2].p, a[3].i, a[4].p, a[5].i)) break; /* IIPIPI */
    case 425: ZIGIMPORTS_CALL((int, int, void *, int, void *, double), (a[0].i, a[1].i, a[2].p, a[3].i, a[4].p, a[5].d)) break; /* IIPIPD */
    case 426: ZIGIMPORTS_CALL((int, int, void *, int, void *, void *), (a[0].i, a[1].i, a[2].p, a[3].i, a[4].p, a[5].p)) break; /* IIPIPP */
    case 427: ZIGIMPORTS_CALL((int, int, void *, double, int, int), (a[0].i, a[1].i, a[2].p, a[3].d, a[4].i, a[5].i)) break; /* IIPDII */
    case 428: ZIGIMPORTS_CALL((int, int, void *, double, int, double), (a[0].i, a[1].i, a[2].p, a[3].d, a[4].i, a[5].d)) break; /* IIPDID */
    case 429: ZIGIMPORTS_CALL((int, int, void *, double, int, void *), (a[0].i, a[1].i, a[2].p, a[3].d, a[4].i, a[5].p)) break; /* IIPDIP */
    case 430: ZIGIMPORTS_CALL((int, int, void *, double, double, int), (a[0].i, a[1].i, a[2].p, a[3].d, a[4].d, a[5].i)) break; /* IIPDDI */
    case 431: ZIGIMPORTS_CALL((int, int, void *, double, double, double), (a[0].i, a[1].i, a[2].p, a[3].d, a[4].d, a[5].d)) break; /* IIPDDD */
    case 432: ZIGIMPORTS_CALL((int, int, void *, double, double, void *), (a[0].i, a[1].i, a[2].p, a[3].d, a[4].d, a[5].p)) break; /* IIPDDP */
    case 433: ZIGIMPORTS_CALL((int, int, void *, double, void *, int), (a[0].i, a[1].i, a[2].p, a[3].d, a[4].p, a[5].i)) break; /* IIPDPI */
    case 434: ZIGIMPORTS_CALL((int, int, void *, double, void *, double), (a[0].i, a[1].i, a[2].p, a[3].d, a[4].p, a[5].d)) break; /* IIPDPD */
    case 435: ZIGIMPORTS_CALL((int, int, void *, double, void *, void *), (a[0].i, a[1].i, a[2].p, a[3].d, a[4].p, a[5].p)) break; /* IIPDPP */
    case 436: ZIGIMPORTS_CALL((int, int, void *, void *, int, int), (a[0].i, a[1].i, a[2].p, a[3].p, a[4].i, a[5].i)) break; /* IIPPII */
    case 437: ZIGIMPORTS_CALL((int, int, void *, void *, int, double), (a[0].i, a[1].i, a[2].p, a[3].p, a[4].i, a[5].d)) break; /* IIPPID */
    case 438: ZIGIMPORTS_CALL((int, int, void *, void *, int, void *), (a[0].i, a[1].i, a[2].p, a[3].p, a[4].i, a[5].p)) break; /* IIPPIP */
    case 439: ZIGIMPORTS_CALL((int, int, void *, void *, double, int), (a[0].i, a[1].i, a[2].p, a[3].p, a[4].d, a[5].i)) break; /* IIPPDI */
    case 440: ZIGIMPORTS_CALL((int, int, void *, void *, double, double), (a[0].i, a[1].i, a[2].p, a[3].p, a[4].d, a[5].d)) break; /* IIPPDD */
    case 441: ZIGIMPORTS_CALL((int, int, void *, void *, double, void *), (a[0].i, a[1].i, a[2].p, a[3].p, a[4].d, a[5].p)) break; /* IIPPDP */
    case 442: ZIGIMPORTS_CALL((int, int, void *, void *, void *, int), (a[0].i, a[1].i, a[2].p, a[3].p, a[4].p, a[5].i)) break; /* IIPPPI */
    case 443: ZIGIMPORTS_CALL((int, int, void *, void *, void *, double), (a[0].i, a[1].i, a[2].p, a[3].p, a[4].p, a[5].d)) break; /* IIPPPD */
    case 444: ZIGIMPORTS_CALL((int, int, void *, void *, void *, void *), (a[0].i, a[1].i, a[2].p, a[3].p, a[4].p, a[5].p)) break; /* IIPPPP */
    case 445: ZIGIMPORTS_CALL((int, double, int, int, int, int), (a[0].i, a[1].d, a[2].i, a[3].i, a[4].i, a[5].i)) break; /* IDIIII */
    case 446: ZIGIMPORTS_CALL((int, double, int, int, int, double), (a[0].i, a[1].d, a[2].i, a[3].i, a[4].i, a[5].d)) break; /* IDIIID */
    case 447: ZIGIMPORTS_CALL((int, double, int, int, int, void *), (a[0].i, a[1].d, a[2].i, a[3].i, a[4].i, a[5].p)) break; /* IDIIIP */
    case 448: ZIGIMPORTS_CALL((int, double, int, int, double, int), (a[0].i, a[1].d, a[2].i, a[3].i, a[4].d, a[5].i)) break; /* IDIIDI */
    case 449: ZIGIMPORTS_CALL((int, double, int, int, double, double), (a[0].i, a[1].d, a[2].i, a[3].i, a[4].d, a[5].d)) break; /* IDIIDD */
    case 450: ZIGIMPORTS_CALL((int, double, int, int, double, void *), (a[0].i, a[1].d, a[2].i, a[3].i, a[4].d, a[5].p)) break; /* IDIIDP */
    case 451: ZIGIMPORTS_CALL((int, double, int, int, void *, int), (a[0].i, a[1].d, a[2].i, a[3].i, a[4].p, a[5].i)) break; /* IDIIPI */
    case 452: ZIGIMPORTS_CALL((int, double, int, int, void *, double), (a[0].i, a[1].d, a[2].i, a[3].i, a[4].p, a[5].d)) break; /* IDIIPD */
    case 453: ZIGIMPORTS_CALL((int, double, int, int, void *, void *), (a[0].i, a[1].d, a[2].i, a[3].i, a[4].p, a[5].p)) break; /* IDIIPP */
    case 454: ZIGIMPORTS_CALL((int, double, int, double, int, int), (a[0].i, a[1].d, a[2].i, a[3].d, a[4].i, a[5].i)) break; /* IDIDII */
    case 455: ZIGIMPORTS_CALL((int, double, int, double, int, double), (a[0].i, a[1].d, a[2].i, a[3].d, a[4].i, a[5].d)) break; /* IDIDID */
    case 456: ZIGIMPORTS_CALL((int, double, int, double, int, void *), (a[0].i, a[1].d, a[2].i, a[3].d, a[4].i, a[5].p)) break; /* IDIDIP */
    case 457: ZIGIMPORTS_CALL((int, double, int, double, double, int), (a[0].i, a[1].d, a[2].i, a[3].d, a[4].d, a[5].i)) break; /* IDIDDI */
    case 458: ZIGIMPORTS_CALL((int, double, int, double, double, double), (a[0].i, a[1].d, a[2].i, a[3].d, a[4].d, a[5].d)) break; /* IDIDDD */
    case 459: ZIGIMPORTS_CALL((int, double, int, double, double, void *), (a[0].i, a[1].d, a[2].i, a[3].d, a[4].d, a[5].p)) break; /* IDIDDP */
    case 460: ZIGIMPORTS_CALL((int, double, int, double, void *, int), (a[0].i, a[1].d, a[2].i, a[3].d, a[4].p, a[5].i)) break; /* IDIDPI */
    case 461: ZIGIMPORTS_CALL((int, double, int, double, void *, double), (a[0].i, a[1].d, a[2].i, a[3].d, a[4].p, a[5].d)) break; /* IDIDPD */
    case 462: ZIGIMPORTS_CALL((int, double, int, double, void *, void *), (a[0].i, a[1].d, a[2].i, a[3].d, a[4].p, a[5].p)) break; /* IDIDPP */
    case 463: ZIGIMPORTS_CALL((int, double, int, void *, int, int), (a[0].i, a[1].d, a[2].i, a[3].p, a[4].i, a[5].i)) break; /* IDIPII */
    case 464: ZIGIMPORTS_CALL((int, double, int, void *, int, double), (a[0].i, a[1].d, a[2].i, a[3].p, a[4].i, a[5].d)) break; /* IDIPID */
    case 465: ZIGIMPORTS_CALL((int, double, int, void *, int, void *), (a[0].i, a[1].d, a[2].i, a[3].p, a[4].i, a[5].p)) break; /* IDIPIP */
    case 466: ZIGIMPORTS_CALL((int, double, int, void *, double, int), (a[0].i, a[1].d, a[2].i, a[3].p, a[4].d, a[5].i)) break; /* IDIPDI */
    case 467: ZIGIMPORTS_CALL((int, double, int, void *, double, double), (a[0].i, a[1].d, a[2].i, a[3].p, a[4].d, a[5].d)) break; /* IDIPDD */
    case 468: ZIGIMPORTS_CALL((int, double, int, void *, double, void *), (a[0].i, a[1].d, a[2].i, a[3].p, a[4].d, a[5].p)) break; /* IDIPDP */
    case 469: ZIGIMPORTS_CALL((int, double, int, void *, void *, int), (a[0].i, a[1].d, a[2].i, a[3].p, a[4].p, a[5].i)) break; /* IDIPPI */
    case 470: ZIGIMPORTS_CALL((int, double, int, void *, void *, double), (a[0].i, a[1].d, a[2].i, a[3].p, a[4].p, a[5].d)) break; /* IDIPPD */
    case 471: ZIGIMPORTS_CALL((int, double, int, void *, void *, void *), (a[0].i, a[1].d, a[2].i, a[3].p, a[4].p, a[5].p)) break; /* IDIPPP */
    case 472: ZIGIMPORTS_CALL((int, double, double, int, int, int), (a[0].i, a[1].d, a[2].d, a[3].i, a[4].i, a[5].i)) break; /* IDDIII */
    case 473: ZIGIMPORTS_CALL((int, double, double, int, int, double), (a[0].i, a[1].d, a[2].d, a[3].i, a[4].i, a[5].d)) break; /* IDDIID */
    case 474: ZIGIMPORTS_CALL((int, double, double, int, int, void *), (a[0].i, a[1].d, a[2].d, a[3].i, a[4].i, a[5].p)) break; /* IDDIIP */
    case 475: ZIGIMPORTS_CALL((int, double, double, int, double, int), (a[0].i, a[1].d, a[2].d, a[3].i, a[4].d, a[5].i)) break; /* IDDIDI */
    case 476: ZIGIMPORTS_CALL((int, double, double, int, double, double), (a[0].i, a[1].d, a[2].d, a[3].i, a[4].d, a[5].d)) break; /* IDDIDD */
    case 477: ZIGIMPORTS_CALL((int, double, double, int, double, void *), (a[0].i, a[1].d, a[2].d, a[3].i, a[4].d, a[5].p)) break; /* IDDIDP */
    case 478: ZIGIMPORTS_CALL((int, double, double, int, void *, int), (a[0].i, a[1].d, a[2].d, a[3].i, a[4].p, a[5].i)) break; /* IDDIPI */
    case 479: ZIGIMPORTS_CALL((int, double, double, int, void *, double), (a[0].i, a[1].d, a[2].d, a[3].i, a[4].p, a[5].d)) break; /* IDDIPD */
    case 480: ZIGIMPORTS_CALL((int, double, double, int, void *, void *), (a[0].i, a[1].d, a[2].d, a[3].i, a[4].p, a[5].p)) break; /* IDDIPP */
    case 481: ZIGIMPORTS_CALL((int, double, double, double, int, int), (a[0].i, a[1].d, a[2].d, a[3].d, a[4].i, a[5].i)) break; /* IDDDII */
    case 482: ZIGIMPORTS_CALL((int, double, double, double, int, double), (a[0].i, a[1].d, a[2].d, a[3].d, a[4].i, a[5].d)) break; /* IDDDID */
    case 483: ZIGIMPORTS_CALL((int, double, double, double, int, void *), (a[0].i, a[1].d, a[2].d, a[3].d, a[4].i, a[5].p)) break; /* IDDDIP */
    case 484: ZIGIMPORTS_CALL((int, double, double, double, double, int), (a[0].i, a[1].d, a[2].d, a[3].d, a[4].d, a[5].i)) break; /* IDDDDI */
    case 485: ZIGIMPORTS_CALL((int, double, double, double, double, double), (a[0].i, a[1].d, a[2].d, a[3].d, a[4].d, a[5].d)) break; /* IDDDDD */
    case 486: ZIGIMPORTS_CALL((int, double, double, double, double, void *), (a[0].i, a[1].d, a[2].d, a[3].d, a[4].d, a[5].p)) break; /* IDDDDP */
    case 487: ZIGIMPORTS_CALL((int, double, double, double, void *, int), (a[0].i, a[1].d, a[2].d, a[3].d, a[4].p, a[5].i)) break; /* IDDDPI */
    case 488: ZIGIMPORTS_CALL((int, double, double, double, void *, double), (a[0].i, a[1].d, a[2].d, a[3].d, a[4].p, a[5].d)) break; /* IDDDPD */
    case 489: ZIGIMPORTS_CALL((int, double, double, double, void *, void *), (a[0].i, a[1].d, a[2].d, a[3].d, a[4].p, a[5].p)) break; /* IDDDPP */
    case 490: ZIGIMPORTS_CALL((int, double, double, void *, int, int), (a[0].i, a[1].d, a[2].d, a[3].p, a[4].i, a[5].i)) break; /* IDDPII */
    case 491: ZIGIMPORTS_CALL((int, double, double, void *, int, double), (a[0].i, a[1].d, a[2].d, a[3].p, a[4].i, a[5].d)) break; /* IDDPID */
    case 492: ZIGIMPORTS_CALL((int, double, double, void *, int, void *), (a[0].i, a[1].d, a[2].d, a[3].p, a[4].i, a[5].p)) break; /* IDDPIP */
    case 493: ZIGIMPORTS_CALL((int, double, double, void *, double, int), (a[0].i, a[1].d, a[2].d, a[3].p, a[4].d, a[5].i)) break; /* IDDPDI */
    case 494: ZIGIMPORTS_CALL((int, double, double, void *, double, double), (a[0].i, a[1].d, a[2].d, a[3].p, a[4].d, a[5].d)) break; /* IDDPDD */
    case 495: ZIGIMPORTS_CALL((int, double, double, void *, double, void *), (a[0].i, a[1].d, a[2].d, a[3].p, a[4].d, a[5].p)) break; /* IDDPDP */
    case 496: ZIGIMPORTS_CALL((int, double, double, void *, void *, int), (a[0].i, a[1].d, a[2].d, a[3].p, a[4].p, a[5].i)) break; /* IDDPPI */
    case 497: ZIGIMPORTS_CALL((int, double, double, void *, void *, double), (a[0].i, a[1].d, a[2].d, a[3].p, a[4].p, a[5].d)) break; /* IDDPPD */
    case 498: ZIGIMPORTS_CALL((int, double, double, void *, void *, void *), (a[0].i, a[1].d, a[2].d, a[3].p, a[4].p, a[5].p)) break; /* IDDPPP */
    case 499: ZIGIMPORTS_CALL((int, double, void *, int, int, int), (a[0].i, a[1].d, a[2].p, a[3].i, a[4].i, a[5].i)) break; /* IDPIII */
    case 500: ZIGIMPORTS_CALL((int, double, void *, int, int, double), (a[0].i, a[1].d, a[2].p, a[3].i, a[4].i, a[5].d)) break; /* IDPIID */
    case 501: ZIGIMPORTS_CALL((int, double, void *, int, int, void *), (a[0].i, a[1].d, a[2].p, a[3].i, a[4].i, a[5].p)) break; /* IDPIIP */
    case 502: ZIGIMPORTS_CALL((int, double, void *, int, double, int), (a[0].i, a[1].d, a[2].p, a[3].i, a[4].d, a[5].i)) break; /* IDPIDI */
    case 503: ZIGIMPORTS_CALL((int, double, void *, int, double, double), (a[0].i, a[1].d, a[2].p, a[3].i, a[4].d, a[5].d)) break; /* IDPIDD */
    case 504: ZIGIMPORTS_CALL((int, double, void *, int, double, void *), (a[0].i, a[1].d, a[2].p, a[3].i, a[4].d, a[5].p)) break; /* IDPIDP */
    case 505: ZIGIMPORTS_CALL((int, double, void *, int, void *, int), (a[0].i, a[1].d, a[2].p, a[3].i, a[4].p, a[5].i)) break; /* IDPIPI */
    case 506: ZIGIMPORTS_CALL((int, double, void *, int, void *, double), (a[0].i, a[1].d, a[2].p, a[3].i, a[4].p, a[5].d)) break; /* IDPIPD */
    case 507: ZIGIMPORTS_CALL((int, double, void *, int, void *, void *), (a[0].i, a[1].d, a[2].p, a[3].i, a[4].p, a[5].p)) break; /* IDPIPP */
    case 508: ZIGIMPORTS_CALL((int, double, void *, double, int, int), (a[0].i, a[1].d, a[2].p, a[3].d, a[4].i, a[5].i)) break; /* IDPDII */
    case 509: ZIGIMPORTS_CALL((int, double, void *, double, int, double), (a[0].i, a[1].d, a[2].p, a[3].d, a[4].i, a[5].d)) break; /* IDPDID */
    case 510: ZIGIMPORTS_CALL((int, double, void *, double, int, void *), (a[0].i, a[1].d, a[2].p, a[3].d, a[4].i, a[5].p)) break; /* IDPDIP */
    case 511: ZIGIMPORTS_CALL((int, double, void *, double, double, int), (a[0].i, a[1].d, a[2].p, a[3].d, a[4].d, a[5].i)) break; /* IDPDDI */
    case 512: ZIGIMPORTS_CALL((int, double, void *, double, double, double), (a[0].i, a[1].d, a[2].p, a[3].d, a[4].d, a[5].d)) break; /* IDPDDD */
    case 513: ZIGIMPORTS_CALL((int, double, void *, double, double, void *), (a[0].i, a[1].d, a[2].p, a[3].d, a[4].d, a[5].p)) break; /* IDPDDP */
    case 514: ZIGIMPORTS_CALL((int, double, void *, double, void *, int), (a[0].i, a[1].d, a[2].p, a[3].d, a[4].p, a[5].i)) break; /* IDPDPI */
    case 515: ZIGIMPORTS_CALL((int, double, void *, double, void *, double), (a[0].i, a[1].d, a[2].p, a[3].d, a[4].p, a[5].d)) break; /* IDPDPD */
    case 516: ZIGIMPORTS_CALL((int, double, void *, double, void *, void *), (a[0].i, a[1].d, a[2].p, a[3].d, a[4].p, a[5].p)) break; /* IDPDPP */
    case 517: ZIGIMPORTS_CALL((int, double, void *, void *, int, int), (a[0].i, a[1].d, a[2].p, a[3].p, a[4].i, a[5].i)) break; /* IDPPII */
    case 518: ZIGIMPORTS_CALL((int, double, void *, void *, int, double), (a[0].i, a[1].d, a[2].p, a[3].p, a[4].i, a[5].d)) break; /* IDPPID */
    case 519: ZIGIMPORTS_CALL((int, double, void *, void *, int, void *), (a[0].i, a[1].d, a[2].p, a[3].p, a[4].i, a[5].p)) break; /* IDPPIP */
    case 520: ZIGIMPORTS_CALL((int, double, void *, void *, double, int), (a[0].i, a[1].d, a[2].p, a[3].p, a[4].d, a[5].i)) break; /* IDPPDI */
    case 521: ZIGIMPORTS_CALL((int, double, void *, void *, double, double), (a[0].i, a[1].d, a[2].p, a[3].p, a[4].d, a[5].d)) break; /* IDPPDD */
    case 522: ZIGIMPORTS_CALL((int, double, void *, void *, double, void *), (a[0].i, a[1].d, a[2].p, a[3].p, a[4].d, a[5].p)) break; /* IDPPDP */
    case 523: ZIGIMPORTS_CALL((int, double, void *, void *, void *, int), (a[0].i, a[1].d, a[2].p, a[3].p, a[4].p, a[5].i)) break; /* IDPPPI */
    case 524: ZIGIMPORTS_CALL((int, double, void *, void *, void *, double), (a[0].i, a[1].d, a[2].p, a[3].p, a[4].p, a[5].d)) break; /* IDPPPD */
    case 525: ZIGIMPORTS_CALL((int, double, void *, void *, void *, void *), (a[0].i, a[1].d, a[2].p, a[3].p, a[4].p, a[5].p)) break; /* IDPPPP */
    case 526: ZIGIMPORTS_CALL((int, void *, int, int, int, int), (a[0].i, a[1].p, a[2].i, a[3].i, a[4].i, a[5].i)) break; /* IPIIII */
    case 527: ZIGIMPORTS_CALL((int, void *, int, int, int, double), (a[0].i, a[1].p, a[2].i, a[3].i, a[4].i, a[5].d)) break; /* IPIIID */
    case 528: ZIGIMPORTS_CALL((int, void *, int, int, int, void *), (a[0].i, a[1].p, a[2].i, a[3].i, a[4].i, a[5].p)) break; /* IPIIIP */
    case 529: ZIGIMPORTS_CALL((int, void *, int, int, double, int), (a[0].i, a[1].p, a[2].i, a[3].i, a[4].d, a[5].i)) break; /* IPIIDI */
    case 530: ZIGIMPORTS_CALL((int, void *, int, int, double, double), (a[0].i, a[1].p, a[2].i, a[3].i, a[4].d, a[5].d)) break; /* IPIIDD */
    case 531: ZIGIMPORTS_CALL((int, void *, int, int, double, void *), (a[0].i, a[1].p, a[2].i, a[3].i, a[4].d, a[5].p)) break; /* IPIIDP */
    case 532: ZIGIMPORTS_CALL((int, void *, int, int, void *, int), (a[0].i, a[1].p, a[2].i, a[3].i, a[4].p, a[5].i)) break; /* IPIIPI */
    case 533: ZIGIMPORTS_CALL((int, void *, int, int, void *, double), (a[0].i, a[1].p, a[2].i, a[3].i, a[4].p, a[5].d)) break; /* IPIIPD */
    case 534: ZIGIMPORTS_CALL((int, void *, int, int, void *, void *), (a[0].i, a[1].p, a[2].i, a[3].i, a[4].p, a[5].p)) break; /* IPIIPP */
    case 535: ZIGIMPORTS_CALL((int, void *, int, double, int, int), (a[0].i, a[1].p, a[2].i, a[3].d, a[4].i, a[5].i)) break; /* IPIDII */
    case 536: ZIGIMPORTS_CALL((int, void *, int, double, int, double), (a[0].i, a[1].p, a[2].i, a[3].d, a[4].i, a[5].d)) break; /* IPIDID */
    case 537: ZIGIMPORTS_CALL((int, void *, int, double, int, void *), (a[0].i, a[1].p, a[2].i, a[3].d, a[4].i, a[5].p)) break; /* IPIDIP */
    case 538: ZIGIMPORTS_CALL((int, void *, int, double, double, int), (a[0].i, a[1].p, a[2].i, a[3].d, a[4].d, a[5].i)) break; /* IPIDDI */
    case 539: ZIGIMPORTS_CALL((int, void *, int, double, double, double), (a[0].i, a[1].p, a[2].i, a[3].d, a[4].d, a[5].d)) break; /* IPIDDD */
    case 540: ZIGIMPORTS_CALL((int, void *, int, double, double, void *), (a[0].i, a[1].p, a[2].i, a[3].d, a[4].d, a[5].p)) break; /* IPIDDP */
    case 541: ZIGIMPORTS_CALL((int, void *, int, double, void *, int), (a[0].i, a[1].p, a[2].i, a[3].d, a[4].p, a[5].i)) break; /* IPIDPI */
    case 542: ZIGIMPORTS_CALL((int, void *, int, double, void *, double), (a[0].i, a[1].p, a[2].i, a[3].d, a[4].p, a[5].d)) break; /* IPIDPD */
    case 543: ZIGIMPORTS_CALL((int, void *, int, double, void *, void *), (a[0].i, a[1].p, a[2].i, a[3].d, a[4].p, a[5].p)) break; /* IPIDPP */
    case 544: ZIGIMPORTS_CALL((int, void *, int, void *, int, int), (a[0].i, a[1].p, a[2].i, a[3].p, a[4].i, a[5].i)) break; /* IPIPII */
    case 545: ZIGIMPORTS_CALL((int, void *, int, void *, int, double), (a[0].i, a[1].p, a[2].i, a[3].p, a[4].i, a[5].d)) break; /* IPIPID */
    case 546: ZIGIMPORTS_CALL((int, void *, int, void *, int, void *), (a[0].i, a[1].p, a[2].i, a[3].p, a[4].i, a[5].p)) break; /* IPIPIP */
    case 547: ZIGIMPORTS_CALL((int, void *, int, void *, double, int), (a[0].i, a[1].p, a[2].i, a[3].p, a[4].d, a[5].i)) break; /* IPIPDI */
    case 548: ZIGIMPORTS_CALL((int, void *, int, void *, double, double), (a[0].i, a[1].p, a[2].i, a[3].p, a[4].d, a[5].d)) break; /* IPIPDD */
    case 549: ZIGIMPORTS_CALL((int, void *, int, void *, double, void *), (a[0].i, a[1].p, a[2].i, a[3].p, a[4].d, a[5].p)) break; /* IPIPDP */
    case 550: ZIGIMPORTS_CALL((int, void *, int, void *, void *, int), (a[0].i, a[1].p, a[2].i, a[3].p, a[4].p, a[5].i)) break; /* IPIPPI */
    case 551: ZIGIMPORTS_CALL((int, void *, int, void *, void *, double), (a[0].i, a[1].p, a[2].i, a[3].p, a[4].p, a[5].d)) break; /* IPIPPD */
    case 552: ZIGIMPORTS_CALL((int, void *, int, void *, void *, void *), (a[0].i, a[1].p, a[2].i, a[3].p, a[4].p, a[5].p)) break; /* IPIPPP */
    case 553: ZIGIMPORTS_CALL((int, void *, double, int, int, int), (a[0].i, a[1].p, a[2].d, a[3].i, a[4].i, a[5].i)) break; /* IPDIII */
    case 554: ZIGIMPORTS_CALL((int, void *, double, int, int, double), (a[0].i, a[1].p, a[2].d, a[3].i, a[4].i, a[5].d)) break; /* IPDIID */
    case 555: ZIGIMPORTS_CALL((int, void *, double, int, int, void *), (a[0].i, a[1].p, a[2].d, a[3].i, a[4].i, a[5].p)) break; /* IPDIIP */
    case 556: ZIGIMPORTS_CALL((int, void *, double, int, double, int), (a[0].i, a[1].p, a[2].d, a[3].i, a[4].d, a[5].i)) break; /* IPDIDI */
    case 557: ZIGIMPORTS_CALL((int, void *, double, int, double, double), (a[0].i, a[1].p, a[2].d, a[3].i, a[4].d, a[5].d)) break; /* IPDIDD */
    case 558: ZIGIMPORTS_CALL((int, void *, double, int, double, void *), (a[0].i, a[1].p, a[2].d, a[3].i, a[4].d, a[5].p)) break; /* IPDIDP */
    case 559: ZIGIMPORTS_CALL((int, void *, double, int, void *, int), (a[0].i, a[1].p, a[2].d, a[3].i, a[4].p, a[5].i)) break; /* IPDIPI */
    case 560: ZIGIMPORTS_CALL((int, void *, double, int, void *, double), (a[0].i, a[1].p, a[2].d, a[3].i, a[4].p, a[5].d)) break; /* IPDIPD */
    case 561: ZIGIMPORTS_CALL((int, void *, double, int, void *, void *), (a[0].i, a[1].p, a[2].d, a[3].i, a[4].p, a[5].p)) break; /* IPDIPP */
    case 562: ZIGIMPORTS_CALL((int, void *, double, double, int, int), (a[0].i, a[1].p, a[2].d, a[3].d, a[4].i, a[5].i)) break; /* IPDDII */
    case 563: ZIGIMPORTS_CALL((int, void *, double, double, int, double), (a[0].i, a[1].p, a[2].d, a[3].d, a[4].i, a[5].d)) break; /* IPDDID */
    case 564: ZIGIMPORTS_CALL((int, void *, double, double, int, void *), (a[0].i, a[1].p, a[2].d, a[3].d, a[4].i, a[5].p)) break; /* IPDDIP */
    case 565: ZIGIMPORTS_CALL((int, void *, double, double, double, int), (a[0].i, a[1].p, a[2].d, a[3].d, a[4].d, a[5].i)) break; /* IPDDDI */
    case 566: ZIGIMPORTS_CALL((int, void *, double, double, double, double), (a[0].i, a[1].p, a[2].d, a[3].d, a[4].d, a[5].d)) break; /* IPDDDD */
    case 567: ZIGIMPORTS_CALL((int, void *, double, double, double, void *), (a[0].i, a[1].p, a[2].d, a[3].d, a[4].d, a[5].p)) break; /* IPDDDP */
    case 568: ZIGIMPORTS_CALL((int, void *, double, double, void *, int), (a[0].i, a[1].p, a[2].d, a[3].d, a[4].p, a[5].i)) break; /* IPDDPI */
    case 569: ZIGIMPORTS_CALL((int, void *, double, double, void *, double), (a[0].i, a[1].p, a[2].d, a[3].d, a[4].p, a[5].d)) break; /* IPDDPD */
    case 570: ZIGIMPORTS_CALL((int, void *, double, double, void *, void *), (a[0].i, a[1].p, a[2].d, a[3].d, a[4].p, a[5].p)) break; /* IPDDPP */
    case 571: ZIGIMPORTS_CALL((int, void *, double, void *, int, int), (a[0].i, a[1].p, a[2].d, a[3].p, a[4].i, a[5].i)) break; /* IPDPII */
    case 572: ZIGIMPORTS_CALL((int, void *, double, void *, int, double), (a[0].i, a[1].p, a[2].d, a[3].p, a[4].i, a[5].d)) break; /* IPDPID */
    case 573: ZIGIMPORTS_CALL((int, void *, double, void *, int, void *), (a[0].i, a[1].p, a[2].d, a[3].p, a[4].i, a[5].p)) break; /* IPDPIP */
    case 574: ZIGIMPORTS_CALL((int, void *, double, void *, double, int), (a[0].i, a[1].p, a[2].d, a[3].p, a[4].d, a[5].i)) break; /* IPDPDI */
    case 575: ZIGIMPORTS_CALL((int, void *, double, void *, double, double), (a[0].i, a[1].p, a[2].d, a[3].p, a[4].d, a[5].d)) break; /* IPDPDD */
    case 576: ZIGIMPORTS_CALL((int, void *, double, void *, double, void *), (a[0].i, a[1].p, a[2].d, a[3].p, a[4].d, a[5].p)) break; /* IPDPDP */
    case 577: ZIGIMPORTS_CALL((int, void *, double, void *, void *, int), (a[0].i, a[1].p, a[2].d, a[3].p, a[4].p, a[5].i)) break; /* IPDPPI */
    case 578: ZIGIMPORTS_CALL((int, void *, double, void *, void *, double), (a[0].i, a[1].p, a[2].d, a[3].p, a[4].p, a[5].d)) break; /* IPDPPD */
    case 579: ZIGIMPORTS_CALL((int, void *, double, void *, void *, void *), (a[0].i, a[1].p, a[2].d, a[3].p, a[4].p, a[5].p)) break; /* IPDPPP */
    case 580: ZIGIMPORTS_CALL((int, void *, void *, int, int, int), (a[0].i, a[1].p, a[2].p, a[3].i, a[4].i, a[5].i)) break; /* IPPIII */
    case 581: ZIGIMPORTS_CALL((int, void *, void *, int, int, double), (a[0].i, a[1].p, a[2].p, a[3].i, a[4].i, a[5].d)) break; /* IPPIID */
    case 582: ZIGIMPORTS_CALL((int, void *, void *, int, int, void *), (a[0].i, a[1].p, a[2].p, a[3].i, a[4].i, a[5].p)) break; /* IPPIIP */
    case 583: ZIGIMPORTS_CALL((int, void *, void *, int, double, int), (a[0].i, a[1].p, a[2].p, a[3].i, a[4].d, a[5].i)) break; /* IPPIDI */
    case 584: ZIGIMPORTS_CALL((int, void *, void *, int, double, double), (a[0].i, a[1].p, a[2].p, a[3].i, a[4].d, a[5].d)) break; /* IPPIDD */
    case 585: ZIGIMPORTS_CALL((int, void *, void *, int, double, void *), (a[0].i, a[1].p, a[2].p, a[3].i, a[4].d, a[5].p)) break; /* IPPIDP */
    case 586: ZIGIMPORTS_CALL((int, void *, void *, int, void *, int), (a[0].i, a[1].p, a[2].p, a[3].i, a[4].p, a[5].i)) break; /* IPPIPI */
    case 587: ZIGIMPORTS_CALL((int, void *, void *, int, void *, double), (a[0].i, a[1].p, a[2].p, a[3].i, a[4].p, a[5].d)) break; /* IPPIPD */
    case 588: ZIGIMPORTS_CALL((int, void *, void *, int, void *, void *), (a[0].i, a[1].p, a[2].p, a[3].i, a[4].p, a[5].p)) break; /* IPPIPP */
    case 589: ZIGIMPORTS_CALL((int, void *, void *, double, int, int), (a[0].i, a[1].p, a[2].p, a[3].d, a[4].i, a[5].i)) break; /* IPPDII */
    case 590: ZIGIMPORTS_CALL((int, void *, void *, double, int, double), (a[0].i, a[1].p, a[2].p, a[3].d, a[4].i, a[5].d)) break; /* IPPDID */
    case 591: ZIGIMPORTS_CALL((int, void *, void *, double, int, void *), (a[0].i, a[1].p, a[2].p, a[3].d, a[4].i, a[5].p)) break; /* IPPDIP */
    case 592: ZIGIMPORTS_CALL((int, void *, void *, double, double, int), (a[0].i, a[1].p, a[2].p, a[3].d, a[4].d, a[5].i)) break; /* IPPDDI */
    case 593: ZIGIMPORTS_CALL((int, void *, void *, double, double, double), (a[0].i, a[1].p, a[2].p, a[3].d, a[4].d, a[5].d)) break; /* IPPDDD */
    case 594: ZIGIMPORTS_CALL((int, void *, void *, double, double, void *), (a[0].i, a[1].p, a[2].p, a[3].d, a[4].d, a[5].p)) break; /* IPPDDP */
    case 595: ZIGIMPORTS_CALL((int, void *, void *, double, void *, int), (a[0].i, a[1].p, a[2].p, a[3].d, a[4].p, a[5].i)) break; /* IPPDPI */
    case 596: ZIGIMPORTS_CALL((int, void *, void *, double, void *, double), (a[0].i, a[1].p, a[2].p, a[3].d, a[4].p, a[5].d)) break; /* IPPDPD */
    case 597: ZIGIMPORTS_CALL((int, void *, void *, double, void *, void *), (a[0].i, a[1].p, a[2].p, a[3].d, a[4].p, a[5].p)) break; /* IPPDPP */
    case 598: ZIGIMPORTS_CALL((int, void *, void *, void *, int, int), (a[0].i, a[1].p, a[2].p, a[3].p, a[4].i, a[5].i)) break; /* IPPPII */
    case 599: ZIGIMPORTS_CALL((int, void *, void *, void *, int, double), (a[0].i, a[1].p, a[2].p, a[3].p, a[4].i, a[5].d)) break; /* IPPPID */
    case 600: ZIGIMPORTS_CALL((int, void *, void *, void *, int, void *), (a[0].i, a[1].p, a[2].p, a[3].p, a[4].i, a[5].p)) break; /* IPPPIP */
    case 601: ZIGIMPORTS_CALL((int, void *, void *, void *, double, int), (a[0].i, a[1].p, a[2].p, a[3].p, a[4].d, a[5].i)) break; /* IPPPDI */
    case 602: ZIGIMPORTS_CALL((int, void *, void *, void *, double, double), (a[0].i, a[1].p, a[2].p, a[3].p, a[4].d, a[5].d)) break; /* IPPPDD */
    case 603: ZIGIMPORTS_CALL((int, void *, void *, void *, double, void *), (a[0].i, a[1].p, a[2].p, a[3].p, a[4].d, a[5].p)) break; /* IPPPDP */
    case 604: ZIGIMPORTS_CALL((int, void *, void *, void *, void *, int), (a[0].i, a[1].p, a[2].p, a[3].p, a[4].p, a[5].i)) break; /* IPPPPI */
    case 605: ZIGIMPORTS_CALL((int, void *, void *, void *, void *, double), (a[0].i, a[1].p, a[2].p, a[3].p, a[4].p, a[5].d)) break; /* IPPPPD */
    case 606: ZIGIMPORTS_CALL((int, void *, void *, void *, void *, void *), (a[0].i, a[1].p, a[2].p, a[3].p, a[4].p, a[5].p)) break; /* IPPPPP */
    case 607: ZIGIMPORTS_CALL((double, int, int, int, int, int), (a[0].d, a[1].i, a[2].i, a[3].i, a[4].i, a[5].i)) break; /* DIIIII */
    case 608: ZIGIMPORTS_CALL((double, int, int, int, int, double), (a[0].d, a[1].i, a[2].i, a[3].i, a[4].i, a[5].d)) break; /* DIIIID */
    case 609: ZIGIMPORTS_CALL((double, int, int, int, int, void *), (a[0].d, a[1].i, a[2].i, a[3].i, a[4].i, a[5].p)) break; /* DIIIIP */
    case 610: ZIGIMPORTS_CALL((double, int, int, int, double, int), (a[0].d, a[1].i, a[2].i, a[3].i, a[4].d, a[5].i)) break; /* DIIIDI */
    case 611: ZIGIMPORTS_CALL((double, int, int, int, double, double), (a[0].d, a[1].i, a[2].i, a[3].i, a[4].d, a[5].d)) break; /* DIIIDD */
    case 612: ZIGIMPORTS_CALL((double, int, int, int, double, void *), (a[0].d, a[1].i, a[2].i, a[3].i, a[4].d, a[5].p)) break; /* DIIIDP */
    case 613: ZIGIMPORTS_CALL((double, int, int, int, void *, int), (a[0].d, a[1].i, a[2].i, a[3].i, a[4].p, a[5].i)) break; /* DIIIPI */
    case 614: ZIGIMPORTS_CALL((double, int, int, int, void *, double), (a[0].d, a[1].i, a[2].i, a[3].i, a[4].p, a[5].d)) break; /* DIIIPD */
    case 615: ZIGIMPORTS_CALL((double, int, int, int, void *, void *), (a[0].d, a[1].i, a[2].i, a[3].i, a[4].p, a[5].p)) break; /* DIIIPP */
    case 616: ZIGIMPORTS_CALL((double, int, int, double, int, int), (a[0].d, a[1].i, a[2].i, a[3].d, a[4].i, a[5].i)) break; /* DIIDII */
    case 617: ZIGIMPORTS_CALL((double, int, int, double, int, double), (a[0].d, a[1].i, a[2].i, a[3].d, a[4].i, a[5].d)) break; /* DIIDID */
    case 618: ZIGIMPORTS_CALL((double, int, int, double, int, void *), (a[0].d, a[1].i, a[2].i, a[3].d, a[4].i, a[5].p)) break; /* DIIDIP */
    case 619: ZIGIMPORTS_CALL((double, int, int, double, double, int), (a[0].d, a[1].i, a[2].i, a[3].d, a[4].d, a[5].i)) break; /* DIIDDI */
    case 620: ZIGIMPORTS_CALL((double, int, int, double, double, double), (a[0].d, a[1].i, a[2].i, a[3].d, a[4].d, a[5].d)) break; /* DIIDDD */
    case 621: ZIGIMPORTS_CALL((double, int, int, double, double, void *), (a[0].d, a[1].i, a[2].i, a[3].d, a[4].d, a[5].p)) break; /* DIIDDP */
    case 622: ZIGIMPORTS_CALL((double, int, int, double, void *, int), (a[0].d, a[1].i, a[2].i, a[3].d, a[4].p, a[5].i)) break; /* DIIDPI */
    case 623: ZIGIMPORTS_CALL((double, int, int, double, void *, double), (a[0].d, a[1].i, a[2].i, a[3].d, a[4].p, a[5].d)) break; /* DIIDPD */
    case 624: ZIGIMPORTS_CALL((double, int, int, double, void *, void *), (a[0].d, a[1].i, a[2].i, a[3].d, a[4].p, a[5].p)) break; /* DIIDPP */
    case 625: ZIGIMPORTS_CALL((double, int, int, void *, int, int), (a[0].d, a[1].i, a[2].i, a[3].p, a[4].i, a[5].i)) break; /* DIIPII */
    case 626: ZIGIMPORTS_CALL((double, int, int, void *, int, double), (a[0].d, a[1].i, a[2].i, a[3].p, a[4].i, a[5].d)) break; /* DIIPID */
    case 627: ZIGIMPORTS_CALL((double, int, int, void *, int, void *), (a[0].d, a[1].i, a[2].i, a[3].p, a[4].i, a[5].p)) break; /* DIIPIP */
    case 628: ZIGIMPORTS_CALL((double, int, int, void *, double, int), (a[0].d, a[1].i, a[2].i, a[3].p, a[4].d, a[5].i)) break; /* DIIPDI */
    case 629: ZIGIMPORTS_CALL((double, int, int, void *, double, double), (a[0].d, a[1].i, a[2].i, a[3].p, a[4].d, a[5].d)) break; /* DIIPDD */
    case 630: ZIGIMPORTS_CALL((double, int, int, void *, double, void *), (a[0].d, a[1].i, a[2].i, a[3].p, a[4].d, a[5].p)) break; /* DIIPDP */
    case 631: ZIGIMPORTS_CALL((double, int, int, void *, void *, int), (a[0].d, a[1].i, a[2].i, a[3].p, a[4].p, a[5].i)) break; /* DIIPPI */
    case 632: ZIGIMPORTS_CALL((double, int, int, void *, void *, double), (a[0].d, a[1].i, a[2].i, a[3].p, a[4].p, a[5].d)) break; /* DIIPPD */
    case 633: ZIGIMPORTS_CALL((double, int, int, void *, void *, void *), (a[0].d, a[1].i, a[2].i, a[3].p, a[4].p, a[5].p)) break; /* DIIPPP */
    case 634: ZIGIMPORTS_CALL((double, int, double, int, int, int), (a[0].d, a[1].i, a[2].d, a[3].i, a[4].i, a[5].i)) break; /* DIDIII */
    case 635: ZIGIMPORTS_CALL((double, int, double, int, int, double), (a[0].d, a[1].i, a[2].d, a[3].i, a[4].i, a[5].d)) break; /* DIDIID */
    case 636: ZIGIMPORTS_CALL((double, int, double, int, int, void *), (a[0].d, a[1].i, a[2].d, a[3].i, a[4].i, a[5].p)) break; /* DIDIIP */
    case 637: ZIGIMPORTS_CALL((double, int, double, int, double, int), (a[0].d, a[1].i, a[2].d, a[3].i, a[4].d, a[5].i)) break; /* DIDIDI */
    case 638: ZIGIMPORTS_CALL((double, int, double, int, double, double), (a[0].d, a[1].i, a[2].d, a[3].i, a[4].d, a[5].d)) break; /* DIDIDD */
    case 639: ZIGIMPORTS_CALL((double, int, double, int, double, void *), (a[0].d, a[1].i, a[2].d, a[3].i, a[4].d, a[5].p)) break; /* DIDIDP */
    case 640: ZIGIMPORTS_CALL((double, int, double, int, void *, int), (a[0].d, a[1].i, a[2].d, a[3].i, a[4].p, a[5].i)) break; /* DIDIPI */
    case 641: ZIGIMPORTS_CALL((double, int, double, int, void *, double), (a[0].d, a[1].i, a[2].d, a[3].i, a[4].p, a[5].d)) break; /* DIDIPD */
    case 642: ZIGIMPORTS_CALL((double, int, double, int, void *, void *), (a[0].d, a[1].i, a[2].d, a[3].i, a[4].p, a[5].p)) break; /* DIDIPP */
    case 643: ZIGIMPORTS_CALL((double, int, double, double, int, int), (a[0].d, a[1].i, a[2].d, a[3].d, a[4].i, a[5].i)) break; /* DIDDII */
    case 644: ZIGIMPORTS_CALL((double, int, double, double, int, double), (a[0].d, a[1].i, a[2].d, a[3].d, a[4].i, a[5].d)) break; /* DIDDID */
    case 645: ZIGIMPORTS_CALL((double, int, double, double, int, void *), (a[0].d, a[1].i, a[2].d, a[3].d, a[4].i, a[5].p)) break; /* DIDDIP */
    case 646: ZIGIMPORTS_CALL((double, int, double, double, double, int), (a[0].d, a[1].i, a[2].d, a[3].d, a[4].d, a[5].i)) break; /* DIDDDI */
    case 647: ZIGIMPORTS_CALL((double, int, double, double, double, double), (a[0].d, a[1].i, a[2].d, a[3].d, a[4].d, a[5].d)) break; /* DIDDDD */
    case 648: ZIGIMPORTS_CALL((double, int, double, double, double, void *), (a[0].d, a[1].i, a[2].d, a[3].d, a[4].d, a[5].p)) break; /* DIDDDP */
    case 649: ZIGIMPORTS_CALL((double, int, double, double, void *, int), (a[0].d, a[1].i, a[2].d, a[3].d, a[4].p, a[5].i)) break; /* DIDDPI */
    case 650: ZIGIMPORTS_CALL((double, int, double, double, void *, double), (a[0].d, a[1].i, a[2].d, a[3].d, a[4].p, a[5].d)) break; /* DIDDPD */
    case 651: ZIGIMPORTS_CALL((double, int, double, double, void *, void *), (a[0].d, a[1].i, a[2].d, a[3].d, a[4].p, a[5].p)) break; /* DIDDPP */
    case 652: ZIGIMPORTS_CALL((double, int, double, void *, int, int), (a[0].d, a[1].i, a[2].d, a[3].p, a[4].i, a[5].i)) break; /* DIDPII */
    case 653: ZIGIMPORTS_CALL((double, int, double, void *, int, double), (a[0].d, a[1].i, a[2].d, a[3].p, a[4].i, a[5].d)) break; /* DIDPID */
    case 654: ZIGIMPORTS_CALL((double, int, double, void *, int, void *), (a[0].d, a[1].i, a[2].d, a[3].p, a[4].i, a[5].p)) break; /* DIDPIP */
    case 655: ZIGIMPORTS_CALL((double, int, double, void *, double, int), (a[0].d, a[1].i, a[2].d, a[3].p, a[4].d, a[5].i)) break; /* DIDPDI */
    case 656: ZIGIMPORTS_CALL((double, int, double, void *, double, double), (a[0].d, a[1].i, a[2].d, a[3].p, a[4].d, a[5].d)) break; /* DIDPDD */
    case 657: ZIGIMPORTS_CALL((double, int, double, void *, double, void *), (a[0].d, a[1].i, a[2].d, a[3].p, a[4].d, a[5].p)) break; /* DIDPDP */
    case 658: ZIGIMPORTS_CALL((double, int, double, void *, void *, int), (a[0].d, a[1].i, a[2].d, a[3].p, a[4].p, a[5].i)) break; /* DIDPPI */
    case 659: ZIGIMPORTS_CALL((double, int, double, void *, void *, double), (a[0].d, a[1].i, a[2].d, a[3].p, a[4].p, a[5].d)) break; /* DIDPPD */
    case 660: ZIGIMPORTS_CALL((double, int, double, void *, void *, void *), (a[0].d, a[1].i, a[2].d, a[3].p, a[4].p, a[5].p)) break; /* DIDPPP */
    case 661: ZIGIMPORTS_CALL((double, int, void *, int, int, int), (a[0].d, a[1].i, a[2].p, a[3].i, a[4].i, a[5].i)) break; /* DIPIII */
    case 662: ZIGIMPORTS_CALL((double, int, void *, int, int, double), (a[0].d, a[1].i, a[2].p, a[3].i, a[4].i, a[5].d)) break; /* DIPIID */
    case 663: ZIGIMPORTS_CALL((double, int, void *, int, int, void *), (a[0].d, a[1].i, a[2].p, a[3].i, a[4].i, a[5].p)) break; /* DIPIIP */
    case 664: ZIGIMPORTS_CALL((double, int, void *, int, double, int), (a[0].d, a[1].i, a[2].p, a[3].i, a[4].d, a[5].i)) break; /* DIPIDI */
    case 665: ZIGIMPORTS_CALL((double, int, void *, int, double, double), (a[0].d, a[1].i, a[2].p, a[3].i, a[4].d, a[5].d)) break; /* DIPIDD */
    case 666: ZIGIMPORTS_CALL((double, int, void *, int, double, void *), (a[0].d, a[1].i, a[2].p, a[3].i, a[4].d, a[5].p)) break; /* DIPIDP */
    case 667: ZIGIMPORTS_CALL((double, int, void *, int, void *, int), (a[0].d, a[1].i, a[2].p, a[3].i, a[4].p, a[5].i)) break; /* DIPIPI */
    case 668: ZIGIMPORTS_CALL((double, int, void *, int, void *, double), (a[0].d, a[1].i, a[2].p, a[3].i, a[4].p, a[5].d)) break; /* DIPIPD */
    case 669: ZIGIMPORTS_CALL((double, int, void *, int, void *, void *), (a[0].d, a[1].i, a[2].p, a[3].i, a[4].p, a[5].p)) break; /* DIPIPP */
    case 670: ZIGIMPORTS_CALL((double, int, void *, double, int, int), (a[0].d, a[1].i, a[2].p, a[3].d, a[4].i, a[5].i)) break; /* DIPDII */
    case 671: ZIGIMPORTS_CALL((double, int, void *, double, int, double), (a[0].d, a[1].i, a[2].p, a[3].d, a[4].i, a[5].d)) break; /* DIPDID */
    case 672: ZIGIMPORTS_CALL((double, int, void *, double, int, void *), (a[0].d, a[1].i, a[2].p, a[3].d, a[4].i, a[5].p)) break; /* DIPDIP */
    case 673: ZIGIMPORTS_CALL((double, int, void *, double, double, int), (a[0].d, a[1].i, a[2].p, a[3].d, a[4].d, a[5].i)) break; /* DIPDDI */
    case 674: ZIGIMPORTS_CALL((double, int, void *, double, double, double), (a[0].d, a[1].i, a[2].p, a[3].d, a[4].d, a[5].d)) break; /* DIPDDD */
    case 675: ZIGIMPORTS_CALL((double, int, void *, double, double, void *), (a[0].d, a[1].i, a[2].p, a[3].d, a[4].d, a[5].p)) break; /* DIPDDP */
    case 676: ZIGIMPORTS_CALL((double, int, void *, double, void *, int), (a[0].d, a[1].i, a[2].p, a[3].d, a[4].p, a[5].i)) break; /* DIPDPI */
    case 677: ZIGIMPORTS_CALL((double, int, void *, double, void *, double), (a[0].d, a[1].i, a[2].p, a[3].d, a[4].p, a[5].d)) break; /* DIPDPD */
    case 678: ZIGIMPORTS_CALL((double, int, void *, double, void *, void *), (a[0].d, a[1].i, a[2].p, a[3].d, a[4].p, a[5].p)) break; /* DIPDPP */
    case 679: ZIGIMPORTS_CALL((double, int, void *, void *, int, int), (a[0].d, a[1].i, a[2].p, a[3].p, a[4].i, a[5].i)) break; /* DIPPII */
    case 680: ZIGIMPORTS_CALL((double, int, void *, void *, int, double), (a[0].d, a[1].i, a[2].p, a[3].p, a[4].i, a[5].d)) break; /* DIPPID */
    case 681: ZIGIMPORTS_CALL((double, int, void *, void *, int, void *), (a[0].d, a[1].i, a[2].p, a[3].p, a[4].i, a[5].p)) break; /* DIPPIP */
    case 682: ZIGIMPORTS_CALL((double, int, void *, void *, double, int), (a[0].d, a[1].i, a[2].p, a[3].p, a[4].d, a[5].i)) break; /* DIPPDI */
    case 683: ZIGIMPORTS_CALL((double, int, void *, void *, double, double), (a[0].d, a[1].i, a[2].p, a[3].p, a[4].d, a[5].d)) break; /* DIPPDD */
    case 684: ZIGIMPORTS_CALL((double, int, void *, void *, double, void *), (a[0].d, a[1].i, a[2].p, a[3].p, a[4].d, a[5].p)) break; /* DIPPDP */
    case 685: ZIGIMPORTS_CALL((double, int, void *, void *, void *, int), (a[0].d, a[1].i, a[2].p, a[3].p, a[4].p, a[5].i)) break; /* DIPPPI */
    case 686: ZIGIMPORTS_CALL((double, int, void *, void *, void *, double), (a[0].d, a[1].i, a[2].p, a[3].p, a[4].p, a[5].d)) break; /* DIPPPD */
    case 687: ZIGIMPORTS_CALL((double, int, void *, void *, void *, void *), (a[0].d, a[1].i, a[2].p, a[3].p, a[4].p, a[5].p)) break; /* DIPPPP */
    case 688: ZIGIMPORTS_CALL((double, double, int, int, int, int), (a[0].d, a[1].d, a[2].i, a[3].i, a[4].i, a[5].i)) break; /* DDIIII */
    case 689: ZIGIMPORTS_CALL((double, double, int, int, int, double), (a[0].d, a[1].d, a[2].i, a[3].i, a[4].i, a[5].d)) break; /* DDIIID */
    case 690: ZIGIMPORTS_CALL((double, double, int, int, int, void *), (a[0].d, a[1].d, a[2].i, a[3].i, a[4].i, a[5].p)) break; /* DDIIIP */
    case 691: ZIGIMPORTS_CALL((double, double, int, int, double, int), (a[0].d, a[1].d, a[2].i, a[3].i, a[4].d, a[5].i)) break; /* DDIIDI */
    case 692: ZIGIMPORTS_CALL((double, double, int, int, double, double), (a[0].d, a[1].d, a[2].i, a[3].i, a[4].d, a[5].d)) break; /* DDIIDD */
    case 693: ZIGIMPORTS_CALL((double, double, int, int, double, void *), (a[0].d, a[1].d, a[2].i, a[3].i, a[4].d, a[5].p)) break; /* DDIIDP */
    case 694: ZIGIMPORTS_CALL((double, double, int, int, void *, int), (a[0].d, a[1].d, a[2].i, a[3].i, a[4].p, a[5].i)) break; /* DDIIPI */
    case 695: ZIGIMPORTS_CALL((double, double, int, int, void *, double), (a[0].d, a[1].d, a[2].i, a[3].i, a[4].p, a[5].d)) break; /* DDIIPD */
    case 696: ZIGIMPORTS_CALL((double, double, int, int, void *, void *), (a[0].d, a[1].d, a[2].i, a[3].i, a[4].p, a[5].p)) break; /* DDIIPP */
    case 697: ZIGIMPORTS_CALL((double, double, int, double, int, int), (a[0].d, a[1].d, a[2].i, a[3].d, a[4].i, a[5].i)) break; /* DDIDII */
    case 698: ZIGIMPORTS_CALL((double, double, int, double, int, double), (a[0].d, a[1].d, a[2].i, a[3].d, a[4].i, a[5].d)) break; /* DDIDID */
    case 699: ZIGIMPORTS_CALL((double, double, int, double, int, void *), (a[0].d, a[1].d, a[2].i, a[3].d, a[4].i, a[5].p)) break; /* DDIDIP */
    case 700: ZIGIMPORTS_CALL((double, double, int, double, double, int), (a[0].d, a[1].d, a[2].i, a[3].d, a[4].d, a[5].i)) break; /* DDIDDI */
    case 701: ZIGIMPORTS_CALL((double, double, int, double, double, double), (a[0].d, a[1].d, a[2].i, a[3].d, a[4].d, a[5].d)) break; /* DDIDDD */
    case 702: ZIGIMPORTS_CALL((double, double, int, double, double, void *), (a[0].d, a[1].d, a[2].i, a[3].d, a[4].d, a[5].p)) break; /* DDIDDP */
    case 703: ZIGIMPORTS_CALL((double, double, int, double, void *, int), (a[0].d, a[1].d, a[2].i, a[3].d, a[4].p, a[5].i)) break; /* DDIDPI */
    case 704: ZIGIMPORTS_CALL((double, double, int, double, void *, double), (a[0].d, a[1].d, a[2].i, a[3].d, a[4].p, a[5].d)) break; /* DDIDPD */
    case 705: ZIGIMPORTS_CALL((double, double, int, double, void *, void *), (a[0].d, a[1].d, a[2].i, a[3].d, a[4].p, a[5].p)) break; /* DDIDPP */
    case 706: ZIGIMPORTS_CALL((double, double, int, void *, int, int), (a[0].d, a[1].d, a[2].i, a[3].p, a[4].i, a[5].i)) break; /* DDIPII */
    case 707: ZIGIMPORTS_CALL((double, double, int, void *, int, double), (a[0].d, a[1].d, a[2].i, a[3].p, a[4].i, a[5].d)) break; /* DDIPID */
    case 708: ZIGIMPORTS_CALL((double, double, int, void *, int, void *), (a[0].d, a[1].d, a[2].i, a[3].p, a[4].i, a[5].p)) break; /* DDIPIP */
    case 709: ZIGIMPORTS_CALL((double, double, int, void *, double, int), (a[0].d, a[1].d, a[2].i, a[3].p, a[4].d, a[5].i)) break; /* DDIPDI */
    case 710: ZIGIMPORTS_CALL((double, double, int, void *, double, double), (a[0].d, a[1].d, a[2].i, a[3].p, a[4].d, a[5].d)) break; /* DDIPDD */
    case 711: ZIGIMPORTS_CALL((double, double, int, void *, double, void *), (a[0].d, a[1].d, a[2].i, a[3].p, a[4].d, a[5].p)) break; /* DDIPDP */
    case 712: ZIGIMPORTS_CALL((double, double, int, void *, void *, int), (a[0].d, a[1].d, a[2].i, a[3].p, a[4].p, a[5].i)) break; /* DDIPPI */
    case 713: ZIGIMPORTS_CALL((double, double, int, void *, void *, double), (a[0].d, a[1].d, a[2].i, a[3].p, a[4].p, a[5].d)) break; /* DDIPPD */
    case 714: ZIGIMPORTS_CALL((double, double, int, void *, void *, void *), (a[0].d, a[1].d, a[2].i, a[3].p, a[4].p, a[5].p)) break; /* DDIPPP */
    case 715: ZIGIMPORTS_CALL((double, double, double, int, int, int), (a[0].d, a[1].d, a[2].d, a[3].i, a[4].i, a[5].i)) break; /* DDDIII */
    case 716: ZIGIMPORTS_CALL((double, double, double, int, int, double), (a[0].d, a[1].d, a[2].d, a[3].i, a[4].i, a[5].d)) break; /* DDDIID */
    case 717: ZIGIMPORTS_CALL((double, double, double, int, int, void *), (a[0].d, a[1].d, a[2].d, a[3].i, a[4].i, a[5].p)) break; /* DDDIIP */
    case 718: ZIGIMPORTS_CALL((double, double, double, int, double, int), (a[0].d, a[1].d, a[2].d, a[3].i, a[4].d, a[5].i)) break; /* DDDIDI */
    case 719: ZIGIMPORTS_CALL((double, double, double, int, double, double), (a[0].d, a[1].d, a[2].d, a[3].i, a[4].d, a[5].d)) break; /* DDDIDD */
    case 720: ZIGIMPORTS_CALL((double, double, double, int, double, void *), (a[0].d, a[1].d, a[2].d, a[3].i, a[4].d, a[5].p)) break; /* DDDIDP */
    case 721: ZIGIMPORTS_CALL((double, double, double, int, void *, int), (a[0].d, a[1].d, a[2].d, a[3].i, a[4].p, a[5].i)) break; /* DDDIPI */
    case 722: ZIGIMPORTS_CALL((double, double, double, int, void *, double), (a[0].d, a[1].d, a[2].d, a[3].i, a[4].p, a[5].d)) break; /* DDDIPD */
    case 723: ZIGIMPORTS_CALL((double, double, double, int, void *, void *), (a[0].d, a[1].d, a[2].d, a[3].i, a[4].p, a[5].p)) break; /* DDDIPP */
    case 724: ZIGIMPORTS_CALL((double, double, double, double, int, int), (a[0].d, a[1].d, a[2].d, a[3].d, a[4].i, a[5].i)) break; /* DDDDII */
    case 725: ZIGIMPORTS_CALL((double, double, double, double, int, double), (a[0].d, a[1].d, a[2].d, a[3].d, a[4].i, a[5].d)) break; /* DDDDID */
    case 726: ZIGIMPORTS_CALL((double, double, double, double, int, void *), (a[0].d, a[1].d, a[2].d, a[3].d, a[4].i, a[5].p)) break; /* DDDDIP */
    case 727: ZIGIMPORTS_CALL((double, double, double, double, double, int), (a[0].d, a[1].d, a[2].d, a[3].d, a[4].d, a[5].i)) break; /* DDDDDI */
    case 728: ZIGIMPORTS_CALL((double, double, double, double, double, double), (a[0].d, a[1].d, a[2].d, a[3].d, a[4].d, a[5].d)) break; /* DDDDDD */
    case 729: ZIGIMPORTS_CALL((double, double, double, double, double, void *), (a[0].d, a[1].d, a[2].d, a[3].d, a[4].d, a[5].p)) break; /* DDDDDP */
    case 730: ZIGIMPORTS_CALL((double, double, double, double, void *, int), (a[0].d, a[1].d, a[2].d, a[3].d, a[4].p, a[5].i)) break; /* DDDDPI */
    case 731: ZIGIMPORTS_CALL((double, double, double, double, void *, double), (a[0].d, a[1].d, a[2].d, a[3].d, a[4].p, a[5].d)) break; /* DDDDPD */
    case 732: ZIGIMPORTS_CALL((double, double, double, double, void *, void *), (a[0].d, a[1].d, a[2].d, a[3].d, a[4].p, a[5].p)) break; /* DDDDPP */
    case 733: ZIGIMPORTS_CALL((double, double, double, void *, int, int), (a[0].d, a[1].d, a[2].d, a[3].p, a[4].i, a[5].i)) break; /* DDDPII */
    case 734: ZIGIMPORTS_CALL((double, double, double, void *, int, double), (a[0].d, a[1].d, a[2].d, a[3].p, a[4].i, a[5].d)) break; /* DDDPID */
    case 735: ZIGIMPORTS_CALL((double, double, double, void *, int, void *), (a[0].d, a[1].d, a[2].d, a[3].p, a[4].i, a[5].p)) break; /* DDDPIP */
    case 736: ZIGIMPORTS_CALL((double, double, double, void *, double, int), (a[0].d, a[1].d, a[2].d, a[3].p, a[4].d, a[5].i)) break; /* DDDPDI */
    case 737: ZIGIMPORTS_CALL((double, double, double, void *, double, double), (a[0].d, a[1].d, a[2].d, a[3].p, a[4].d, a[5].d)) break; /* DDDPDD */
    case 738: ZIGIMPORTS_CALL((double, double, double, void *, double, void *), (a[0].d, a[1].d, a[2].d, a[3].p, a[4].d, a[5].p)) break; /* DDDPDP */
    case 739: ZIGIMPORTS_CALL((double, double, double, void *, void *, int), (a[0].d, a[1].d, a[2].d, a[3].p, a[4].p, a[5].i)) break; /* DDDPPI */
    case 740: ZIGIMPORTS_CALL((double, double, double, void *, void *, double), (a[0].d, a[1].d, a[2].d, a[3].p, a[4].p, a[5].d)) break; /* DDDPPD */
    case 741: ZIGIMPORTS_CALL((double, double, double, void *, void *, void *), (a[0].d, a[1].d, a[2].d, a[3].p, a[4].p, a[5].p)) break; /* DDDPPP */
    case 742: ZIGIMPORTS_CALL((double, double, void *, int, int, int), (a[0].d, a[1].d, a[2].p, a[3].i, a[4].i, a[5].i)) break; /* DDPIII */
    case 743: ZIGIMPORTS_CALL((double, double, void *, int, int, double), (a[0].d, a[1].d, a[2].p, a[3].i, a[4].i, a[5].d)) break; /* DDPIID */
    case 744: ZIGIMPORTS_CALL((double, double, void *, int, int, void *), (a[0].d, a[1].d, a[2].p, a[3].i, a[4].i, a[5].p)) break; /* DDPIIP */
    case 745: ZIGIMPORTS_CALL((double, double, void *, int, double, int), (a[0].d, a[1].d, a[2].p, a[3].i, a[4].d, a[5].i)) break; /* DDPIDI */
    case 746: ZIGIMPORTS_CALL((double, double, void *, int, double, double), (a[0].d, a[1].d, a[2].p, a[3].i, a[4].d, a[5].d)) break; /* DDPIDD */
    case 747: ZIGIMPORTS_CALL((double, double, void *, int, double, void *), (a[0].d, a[1].d, a[2].p, a[3].i, a[4].d, a[5].p)) break; /* DDPIDP */
    case 748: ZIGIMPORTS_CALL((double, double, void *, int, void *, int), (a[0].d, a[1].d, a[2].p, a[3].i, a[4].p, a[5].i)) break; /* DDPIPI */
    case 749: ZIGIMPORTS_CALL((double, double, void *, int, void *, double), (a[0].d, a[1].d, a[2].p, a[3].i, a[4].p, a[5].d)) break; /* DDPIPD */
    case 750: ZIGIMPORTS_CALL((double, double, void *, int, void *, void *), (a[0].d, a[1].d, a[2].p, a[3].i, a[4].p, a[5].p)) break; /* DDPIPP */
    case 751: ZIGIMPORTS_CALL((double, double, void *, double, int, int), (a[0].d, a[1].d, a[2].p, a[3].d, a[4].i, a[5].i)) break; /* DDPDII */
    case 752: ZIGIMPORTS_CALL((double, double, void *, double, int, double), (a[0].d, a[1].d, a[2].p, a[3].d, a[4].i, a[5].d)) break; /* DDPDID */
    case 753: ZIGIMPORTS_CALL((double, double, void *, double, int, void *), (a[0].d, a[1].d, a[2].p, a[3].d, a[4].i, a[5].p)) break; /* DDPDIP */
    case 754: ZIGIMPORTS_CALL((double, double, void *, double, double, int), (a[0].d, a[1].d, a[2].p, a[3].d, a[4].d, a[5].i)) break; /* DDPDDI */
    case 755: ZIGIMPORTS_CALL((double, double, void *, double, double, double), (a[0].d, a[1].d, a[2].p, a[3].d, a[4].d, a[5].d)) break; /* DDPDDD */
    case 756: ZIGIMPORTS_CALL((double, double, void *, double, double, void *), (a[0].d, a[1].d, a[2].p, a[3].d, a[4].d, a[5].p)) break; /* DDPDDP */
    case 757: ZIGIMPORTS_CALL((double, double, void *, double, void *, int), (a[0].d, a[1].d, a[2].p, a[3].d, a[4].p, a[5].i)) break; /* DDPDPI */
    case 758: ZIGIMPORTS_CALL((double, double, void *, double, void *, double), (a[0].d, a[1].d, a[2].p, a[3].d, a[4].p, a[5].d)) break; /* DDPDPD */
    case 759: ZIGIMPORTS_CALL((double, double, void *, double, void *, void *), (a[0].d, a[1].d, a[2].p, a[3].d, a[4].p, a[5].p)) break; /* DDPDPP */
    case 760: ZIGIMPORTS_CALL((double, double, void *, void *, int, int), (a[0].d, a[1].d, a[2].p, a[3].p, a[4].i, a[5].i)) break; /* DDPPII */
    case 761: ZIGIMPORTS_CALL((double, double, void *, void *, int, double), (a[0].d, a[1].d, a[2].p, a[3].p, a[4].i, a[5].d)) break; /* DDPPID */
    case 762: ZIGIMPORTS_CALL((double, double, void *, void *, int, void *), (a[0].d, a[1].d, a[2].p, a[3].p, a[4].i, a[5].p)) break; /* DDPPIP */
    case 763: ZIGIMPORTS_CALL((double, double, void *, void *, double, int), (a[0].d, a[1].d, a[2].p, a[3].p, a[4].d, a[5].i)) break; /* DDPPDI */
    case 764: ZIGIMPORTS_CALL((double, double, void *, void *, double, double), (a[0].d, a[1].d, a[2].p, a[3].p, a[4].d, a[5].d)) break; /* DDPPDD */
    case 765: ZIGIMPORTS_CALL((double, double, void *, void *, double, void *), (a[0].d, a[1].d, a[2].p, a[3].p, a[4].d, a[5].p)) break; /* DDPPDP */
    case 766: ZIGIMPORTS_CALL((double, double, void *, void *, void *, int), (a[0].d, a[1].d, a[2].p, a[3].p, a[4].p, a[5].i)) break; /* DDPPPI */
    case 767: ZIGIMPORTS_CALL((double, double, void *, void *, void *, double), (a[0].d, a[1].d, a[2].p, a[3].p, a[4].p, a[5].d)) break; /* DDPPPD */
    case 768: ZIGIMPORTS_CALL((double, double, void *, void *, void *, void *), (a[0].d, a[1].d, a[2].p, a[3].p, a[4].p, a[5].p)) break; /* DDPPPP */
    case 769: ZIGIMPORTS_CALL((double, void *, int, int, int, int), (a[0].d, a[1].p, a[2].i, a[3].i, a[4].i, a[5].i)) break; /* DPIIII */
    case 770: ZIGIMPORTS_CALL((double, void *, int, int, int, double), (a[0].d, a[1].p, a[2].i, a[3].i, a[4].i, a[5].d)) break; /* DPIIID */
    case 771: ZIGIMPORTS_CALL((double, void *, int, int, int, void *), (a[0].d, a[1].p, a[2].i, a[3].i, a[4].i, a[5].p)) break; /* DPIIIP */
    case 772: ZIGIMPORTS_CALL((double, void *, int, int, double, int), (a[0].d, a[1].p, a[2].i, a[3].i, a[4].d, a[5].i)) break; /* DPIIDI */
    case 773: ZIGIMPORTS_CALL((double, void *, int, int, double, double), (a[0].d, a[1].p, a[2].i, a[3].i, a[4].d, a[5].d)) break; /* DPIIDD */
    case 774: ZIGIMPORTS_CALL((double, void *, int, int, double, void *), (a[0].d, a[1].p, a[2].i, a[3].i, a[4].d, a[5].p)) break; /* DPIIDP */
    case 775: ZIGIMPORTS_CALL((double, void *, int, int, void *, int), (a[0].d, a[1].p, a[2].i, a[3].i, a[4].p, a[5].i)) break; /* DPIIPI */
    case 776: ZIGIMPORTS_CALL((double, void *, int, int, void *, double), (a[0].d, a[1].p, a[2].i, a[3].i, a[4].p, a[5].d)) break; /* DPIIPD */
    case 777: ZIGIMPORTS_CALL((double, void *, int, int, void *, void *), (a[0].d, a[1].p, a[2].i, a[3].i, a[4].p, a[5].p)) break; /* DPIIPP */
    case 778: ZIGIMPORTS_CALL((double, void *, int, double, int, int), (a[0].d, a[1].p, a[2].i, a[3].d, a[4].i, a[5].i)) break; /* DPIDII */
    case 779: ZIGIMPORTS_CALL((double, void *, int, double, int, double), (a[0].d, a[1].p, a[2].i, a[3].d, a[4].i, a[5].d)) break; /* DPIDID */
    case 780: ZIGIMPORTS_CALL((double, void *, int, double, int, void *), (a[0].d, a[1].p, a[2].i, a[3].d, a[4].i, a[5].p)) break; /* DPIDIP */
    case 781: ZIGIMPORTS_CALL((double, void *, int, double, double, int), (a[0].d, a[1].p, a[2].i, a[3].d, a[4].d, a[5].i)) break; /* DPIDDI */
    case 782: ZIGIMPORTS_CALL((double, void *, int, double, double, double), (a[0].d, a[1].p, a[2].i, a[3].d, a[4].d, a[5].d)) break; /* DPIDDD */
    case 783: ZIGIMPORTS_CALL((double, void *, int, double, double, void *), (a[0].d, a[1].p, a[2].i, a[3].d, a[4].d, a[5].p)) break; /* DPIDDP */
    case 784: ZIGIMPORTS_CALL((double, void *, int, double, void *, int), (a[0].d, a[1].p, a[2].i, a[3].d, a[4].p, a[5].i)) break; /* DPIDPI */
    case 785: ZIGIMPORTS_CALL((double, void *, int, double, void *, double), (a[0].d, a[1].p, a[2].i, a[3].d, a[4].p, a[5].d)) break; /* DPIDPD */
    case 786: ZIGIMPORTS_CALL((double, void *, int, double, void *, void *), (a[0].d, a[1].p, a[2].i, a[3].d, a[4].p, a[5].p)) break; /* DPIDPP */
    case 787: ZIGIMPORTS_CALL((double, void *, int, void *, int, int), (a[0].d, a[1].p, a[2].i, a[3].p, a[4].i, a[5].i)) break; /* DPIPII */
    case 788: ZIGIMPORTS_CALL((double, void *, int, void *, int, double), (a[0].d, a[1].p, a[2].i, a[3].p, a[4].i, a[5].d)) break; /* DPIPID */
    case 789: ZIGIMPORTS_CALL((double, void *, int, void *, int, void *), (a[0].d, a[1].p, a[2].i, a[3].p, a[4].i, a[5].p)) break; /* DPIPIP */
    case 790: ZIGIMPORTS_CALL((double, void *, int, void *, double, int), (a[0].d, a[1].p, a[2].i, a[3].p, a[4].d, a[5].i)) break; /* DPIPDI */
    case 791: ZIGIMPORTS_CALL((double, void *, int, void *, double, double), (a[0].d, a[1].p, a[2].i, a[3].p, a[4].d, a[5].d)) break; /* DPIPDD */
    case 792: ZIGIMPORTS_CALL((double, void *, int, void *, double, void *), (a[0].d, a[1].p, a[2].i, a[3].p, a[4].d, a[5].p)) break; /* DPIPDP */
    case 793: ZIGIMPORTS_CALL((double, void *, int, void *, void *, int), (a[0].d, a[1].p, a[2].i, a[3].p, a[4].p, a[5].i)) break; /* DPIPPI */
    case 794: ZIGIMPORTS_CALL((double, void *, int, void *, void *, double), (a[0].d, a[1].p, a[2].i, a[3].p, a[4].p, a[5].d)) break; /* DPIPPD */
    case 795: ZIGIMPORTS_CALL((double, void *, int, void *, void *, void *), (a[0].d, a[1].p, a[2].i, a[3].p, a[4].p, a[5].p)) break; /* DPIPPP */
    case 796: ZIGIMPORTS_CALL((double, void *, double, int, int, int), (a[0].d, a[1].p, a[2].d, a[3].i, a[4].i, a[5].i)) break; /* DPDIII */
    case 797: ZIGIMPORTS_CALL((double, void *, double, int, int, double), (a[0].d, a[1].p, a[2].d, a[3].i, a[4].i, a[5].d)) break; /* DPDIID */
    case 798: ZIGIMPORTS_CALL((double, void *, double, int, int, void *), (a[0].d, a[1].p, a[2].d, a[3].i, a[4].i, a[5].p)) break; /* DPDIIP */
    case 799: ZIGIMPORTS_CALL((double, void *, double, int, double, int), (a[0].d, a[1].p, a[2].d, a[3].i, a[4].d, a[5].i)) break; /* DPDIDI */
    case 800: ZIGIMPORTS_CALL((double, void *, double, int, double, double), (a[0].d, a[1].p, a[2].d, a[3].i, a[4].d, a[5].d)) break; /* DPDIDD */
    case 801: ZIGIMPORTS_CALL((double, void *, double, int, double, void *), (a[0].d, a[1].p, a[2].d, a[3].i, a[4].d, a[5].p)) break; /* DPDIDP */
    case 802: ZIGIMPORTS_CALL((double, void *, double, int, void *, int), (a[0].d, a[1].p, a[2].d, a[3].i, a[4].p, a[5].i)) break; /* DPDIPI */
    case 803: ZIGIMPORTS_CALL((double, void *, double, int, void *, double), (a[0].d, a[1].p, a[2].d, a[3].i, a[4].p, a[5].d)) break; /* DPDIPD */
    case 804: ZIGIMPORTS_CALL((double, void *, double, int, void *, void *), (a[0].d, a[1].p, a[2].d, a[3].i, a[4].p, a[5].p)) break; /* DPDIPP */
    case 805: ZIGIMPORTS_CALL((double, void *, double, double, int, int), (a[0].d, a[1].p, a[2].d, a[3].d, a[4].i, a[5].i)) break; /* DPDDII */
    case 806: ZIGIMPORTS_CALL((double, void *, double, double, int, double), (a[0].d, a[1].p, a[2].d, a[3].d, a[4].i, a[5].d)) break; /* DPDDID */
    case 807: ZIGIMPORTS_CALL((double, void *, double, double, int, void *), (a[0].d, a[1].p, a[2].d, a[3].d, a[4].i, a[5].p)) break; /* DPDDIP */
    case 808: ZIGIMPORTS_CALL((double, void *, double, double, double, int), (a[0].d, a[1].p, a[2].d, a[3].d, a[4].d, a[5].i)) break; /* DPDDDI */
    case 809: ZIGIMPORTS_CALL((double, void *, double, double, double, double), (a[0].d, a[1].p, a[2].d, a[3].d, a[4].d, a[5].d)) break; /* DPDDDD */
    case 810: ZIGIMPORTS_CALL((double, void *, double, double, double, void *), (a[0].d, a[1].p, a[2].d, a[3].d, a[4].d, a[5].p)) break; /* DPDDDP */
    case 811: ZIGIMPORTS_CALL((double, void *, double, double, void *, int), (a[0].d, a[1].p, a[2].d, a[3].d, a[4].p, a[5].i)) break; /* DPDDPI */
    case 812: ZIGIMPORTS_CALL((double, void *, double, double, void *, double), (a[0].d, a[1].p, a[2].d, a[3].d, a[4].p, a[5].d)) break; /* DPDDPD */
    case 813: ZIGIMPORTS_CALL((double, void *, double, double, void *, void *), (a[0].d, a[1].p, a[2].d, a[3].d, a[4].p, a[5].p)) break; /* DPDDPP */
    case 814: ZIGIMPORTS_CALL((double, void *, double, void *, int, int), (a[0].d, a[1].p, a[2].d, a[3].p, a[4].i, a[5].i)) break; /* DPDPII */
    case 815: ZIGIMPORTS_CALL((double, void *, double, void *, int, double), (a[0].d, a[1].p, a[2].d, a[3].p, a[4].i, a[5].d)) break; /* DPDPID */
    case 816: ZIGIMPORTS_CALL((double, void *, double, void *, int, void *), (a[0].d, a[1].p, a[2].d, a[3].p, a[4].i, a[5].p)) break; /* DPDPIP */
    case 817: ZIGIMPORTS_CALL((double, void *, double, void *, double, int), (a[0].d, a[1].p, a[2].d, a[3].p, a[4].d, a[5].i)) break; /* DPDPDI */
    case 818: ZIGIMPORTS_CALL((double, void *, double, void *, double, double), (a[0].d, a[1].p, a[2].d, a[3].p, a[4].d, a[5].d)) break; /* DPDPDD */
    case 819: ZIGIMPORTS_CALL((double, void *, double, void *, double, void *), (a[0].d, a[1].p, a[2].d, a[3].p, a[4].d, a[5].p)) break; /* DPDPDP */
    case 820: ZIGIMPORTS_CALL((double, void *, double, void *, void *, int), (a[0].d, a[1].p, a[2].d, a[3].p, a[4].p, a[5].i)) break; /* DPDPPI */
    case 821: ZIGIMPORTS_CALL((double, void *, double, void *, void *, double), (a[0].d, a[1].p, a[2].d, a[3].p, a[4].p, a[5].d)) break; /* DPDPPD */
    case 822: ZIGIMPORTS_CALL((double, void *, double, void *, void *, void *), (a[0].d, a[1].p, a[2].d, a[3].p, a[4].p, a[5].p)) break; /* DPDPPP */
    case 823: ZIGIMPORTS_CALL((double, void *, void *, int, int, int), (a[0].d, a[1].p, a[2].p, a[3].i, a[4].i, a[5].i)) break; /* DPPIII */
    case 824: ZIGIMPORTS_CALL((double, void *, void *, int, int, double), (a[0].d, a[1].p, a[2].p, a[3].i, a[4].i, a[5].d)) break; /* DPPIID */
    case 825: ZIGIMPORTS_CALL((double, void *, void *, int, int, void *), (a[0].d, a[1].p, a[2].p, a[3].i, a[4].i, a[5].p)) break; /* DPPIIP */
    case 826: ZIGIMPORTS_CALL((double, void *, void *, int, double, int), (a[0].d, a[1].p, a[2].p, a[3].i, a[4].d, a[5].i)) break; /* DPPIDI */
    case 827: ZIGIMPORTS_CALL((double, void *, void *, int, double, double), (a[0].d, a[1].p, a[2].p, a[3].i, a[4].d, a[5].d)) break; /* DPPIDD */
    case 828: ZIGIMPORTS_CALL((double, void *, void *, int, double, void *), (a[0].d, a[1].p, a[2].p, a[3].i, a[4].d, a[5].p)) break; /* DPPIDP */
    case 829: ZIGIMPORTS_CALL((double, void *, void *, int, void *, int), (a[0].d, a[1].p, a[2].p, a[3].i, a[4].p, a[5].i)) break; /* DPPIPI */
    case 830: ZIGIMPORTS_CALL((double, void *, void *, int, void *, double), (a[0].d, a[1].p, a[2].p, a[3].i, a[4].p, a[5].d)) break; /* DPPIPD */
    case 831: ZIGIMPORTS_CALL((double, void *, void *, int, void *, void *), (a[0].d, a[1].p, a[2].p, a[3].i, a[4].p, a[5].p)) break; /* DPPIPP */
    case 832: ZIGIMPORTS_CALL((double, void *, void *, double, int, int), (a[0].d, a[1].p, a[2].p, a[3].d, a[4].i, a[5].i)) break; /* DPPDII */
    case 833: ZIGIMPORTS_CALL((double, void *, void *, double, int, double), (a[0].d, a[1].p, a[2].p, a[3].d, a[4].i, a[5].d)) break; /* DPPDID */
    case 834: ZIGIMPORTS_CALL((double, void *, void *, double, int, void *), (a[0].d, a[1].p, a[2].p, a[3].d, a[4].i, a[5].p)) break; /* DPPDIP */
    case 835: ZIGIMPORTS_CALL((double, void *, void *, double, double, int), (a[0].d, a[1].p, a[2].p, a[3].d, a[4].d, a[5].i)) break; /* DPPDDI */
    case 836: ZIGIMPORTS_CALL((double, void *, void *, double, double, double), (a[0].d, a[1].p, a[2].p, a[3].d, a[4].d, a[5].d)) break; /* DPPDDD */
    case 837: ZIGIMPORTS_CALL((double, void *, void *, double, double, void *), (a[0].d, a[1].p, a[2].p, a[3].d, a[4].d, a[5].p)) break; /* DPPDDP */
    case 838: ZIGIMPORTS_CALL((double, void *, void *, double, void *, int), (a[0].d, a[1].p, a[2].p, a[3].d, a[4].p, a[5].i)) break; /* DPPDPI */
    case 839: ZIGIMPORTS_CALL((double, void *, void *, double, void *, double), (a[0].d, a[1].p, a[2].p, a[3].d, a[4].p, a[5].d)) break; /* DPPDPD */
    case 840: ZIGIMPORTS_CALL((double, void *, void *, double, void *, void *), (a[0].d, a[1].p, a[2].p, a[3].d, a[4].p, a[5].p)) break; /* DPPDPP */
    case 841: ZIGIMPORTS_CALL((double, void *, void *, void *, int, int), (a[0].d, a[1].p, a[2].p, a[3].p, a[4].i, a[5].i)) break; /* DPPPII */
    case 842: ZIGIMPORTS_CALL((double, void *, void *, void *, int, double), (a[0].d, a[1].p, a[2].p, a[3].p, a[4].i, a[5].d)) break; /* DPPPID */
    case 843: ZIGIMPORTS_CALL((double, void *, void *, void *, int, void *), (a[0].d, a[1].p, a[2].p, a[3].p, a[4].i, a[5].p)) break; /* DPPPIP */
    case 844: ZIGIMPORTS_CALL((double, void *, void *, void *, double, int), (a[0].d, a[1].p, a[2].p, a[3].p, a[4].d, a[5].i)) break; /* DPPPDI */
    case 845: ZIGIMPORTS_CALL((double, void *, void *, void *, double, double), (a[0].d, a[1].p, a[2].p, a[3].p, a[4].d, a[5].d)) break; /* DPPPDD */
    case 846: ZIGIMPORTS_CALL((double, void *, void *, void *, double, void *), (a[0].d, a[1].p, a[2].p, a[3].p, a[4].d, a[5].p)) break; /* DPPPDP */
    case 847: ZIGIMPORTS_CALL((double, void *, void *, void *, void *, int), (a[0].d, a[1].p, a[2].p, a[3].p, a[4].p, a[5].i)) break; /* DPPPPI */
    case 848: ZIGIMPORTS_CALL((double, void *, void *, void *, void *, double), (a[0].d, a[1].p, a[2].p, a[3].p, a[4].p, a[5].d)) break; /* DPPPPD */
    case 849: ZIGIMPORTS_CALL((double, void *, void *, void *, void *, void *), (a[0].d, a[1].p, a[2].p, a[3].p, a[4].p, a[5].p)) break; /* DPPPPP */
    case 850: ZIGIMPORTS_CALL((void *, int, int, int, int, int), (a[0].p, a[1].i, a[2].i, a[3].i, a[4].i, a[5].i)) break; /* PIIIII */
    case 851: ZIGIMPORTS_CALL((void *, int, int, int, int, double), (a[0].p, a[1].i, a[2].i, a[3].i, a[4].i, a[5].d)) break; /* PIIIID */
    case 852: ZIGIMPORTS_CALL((void *, int, int, int, int, void *), (a[0].p, a[1].i, a[2].i, a[3].i, a[4].i, a[5].p)) break; /* PIIIIP */
    case 853: ZIGIMPORTS_CALL((void *, int, int, int, double, int), (a[0].p, a[1].i, a[2].i, a[3].i, a[4].d, a[5].i)) break; /* PIIIDI */
    case 854: ZIGIMPORTS_CALL((void *, int, int, int, double, double), (a[0].p, a[1].i, a[2].i, a[3].i, a[4].d, a[5].d)) break; /* PIIIDD */
    case 855: ZIGIMPORTS_CALL((void *, int, int, int, double, void *), (a[0].p, a[1].i, a[2].i, a[3].i, a[4].d, a[5].p)) break; /* PIIIDP */
    case 856: ZIGIMPORTS_CALL((void *, int, int, int, void *, int), (a[0].p, a[1].i, a[2].i, a[3].i, a[4].p, a[5].i)) break; /* PIIIPI */
    case 857: ZIGIMPORTS_CALL((void *, int, int, int, void *, double), (a[0].p, a[1].i, a[2].i, a[3].i, a[4].p, a[5].d)) break; /* PIIIPD */
    case 858: ZIGIMPORTS_CALL((void *, int, int, int, void *, void *), (a[0].p, a[1].i, a[2].i, a[3].i, a[4].p, a[5].p)) break; /* PIIIPP */
    case 859: ZIGIMPORTS_CALL((void *, int, int, double, int, int), (a[0].p, a[1].i, a[2].i, a[3].d, a[4].i, a[5].i)) break; /* PIIDII */
    case 860: ZIGIMPORTS_CALL((void *, int, int, double, int, double), (a[0].p, a[1].i, a[2].i, a[3].d, a[4].i, a[5].d)) break; /* PIIDID */
    case 861: ZIGIMPORTS_CALL((void *, int, int, double, int, void *), (a[0].p, a[1].i, a[2].i, a[3].d, a[4].i, a[5].p)) break; /* PIIDIP */
    case 862: ZIGIMPORTS_CALL((void *, int, int, double, double, int), (a[0].p, a[1].i, a[2].i, a[3].d, a[4].d, a[5].i)) break; /* PIIDDI */
    case 863: ZIGIMPORTS_CALL((void *, int, int, double, double, double), (a[0].p, a[1].i, a[2].i, a[3].d, a[4].d, a[5].d)) break; /* PIIDDD */
    case 864: ZIGIMPORTS_CALL((void *, int, int, double, double, void *), (a[0].p, a[1].i, a[2].i, a[3].d, a[4].d, a[5].p)) break; /* PIIDDP */
    case 865: ZIGIMPORTS_CALL((void *, int, int, double, void *, int), (a[0].p, a[1].i, a[2].i, a[3].d, a[4].p, a[5].i)) break; /* PIIDPI */
    case 866: ZIGIMPORTS_CALL((void *, int, int, double, void *, double), (a[0].p, a[1].i, a[2].i, a[3].d, a[4].p, a[5].d)) break; /* PIIDPD */
    case 867: ZIGIMPORTS_CALL((void *, int, int, double, void *, void *), (a[0].p, a[1].i, a[2].i, a[3].d, a[4].p, a[5].p)) break; /* PIIDPP */
    case 868: ZIGIMPORTS_CALL((void *, int, int, void *, int, int), (a[0].p, a[1].i, a[2].i, a[3].p, a[4].i, a[5].i)) break; /* PIIPII */
    case 869: ZIGIMPORTS_CALL((void *, int, int, void *, int, double), (a[0].p, a[1].i, a[2].i, a[3].p, a[4].i, a[5].d)) break; /* PIIPID */
    case 870: ZIGIMPORTS_CALL((void *, int, int, void *, int, void *), (a[0].p, a[1].i, a[2].i, a[3].p, a[4].i, a[5].p)) break; /* PIIPIP */
    case 871: ZIGIMPORTS_CALL((void *, int, int, void *, double, int), (a[0].p, a[1].i, a[2].i, a[3].p, a[4].d, a[5].i)) break; /* PIIPDI */
    case 872: ZIGIMPORTS_CALL((void *, int, int, void *, double, double), (a[0].p, a[1].i, a[2].i, a[3].p, a[4].d, a[5].d)) break; /* PIIPDD */
    case 873: ZIGIMPORTS_CALL((void *, int, int, void *, double, void *), (a[0].p, a[1].i, a[2].i, a[3].p, a[4].d, a[5].p)) break; /* PIIPDP */
    case 874: ZIGIMPORTS_CALL((void *, int, int, void *, void *, int), (a[0].p, a[1].i, a[2].i, a[3].p, a[4].p, a[5].i)) break; /* PIIPPI */
    case 875: ZIGIMPORTS_CALL((void *, int, int, void *, void *, double), (a[0].p, a[1].i, a[2].i, a[3].p, a[4].p, a[5].d)) break; /* PIIPPD */
    case 876: ZIGIMPORTS_CALL((void *, int, int, void *, void *, void *), (a[0].p, a[1].i, a[2].i, a[3].p, a[4].p, a[5].p)) break; /* PIIPPP */
    case 877: ZIGIMPORTS_CALL((void *, int, double, int, int, int), (a[0].p, a[1].i, a[2].d, a[3].i, a[4].i, a[5].i)) break; /* PIDIII */
    case 878: ZIGIMPORTS_CALL((void *, int, double, int, int, double), (a[0].p, a[1].i, a[2].d, a[3].i, a[4].i, a[5].d)) break; /* PIDIID */
    case 879: ZIGIMPORTS_CALL((void *, int, double, int, int, void *), (a[0].p, a[1].i, a[2].d, a[3].i, a[4].i, a[5].p)) break; /* PIDIIP */
    case 880: ZIGIMPORTS_CALL((void *, int, double, int, double, int), (a[0].p, a[1].i, a[2].d, a[3].i, a[4].d, a[5].i)) break; /* PIDIDI */
    case 881: ZIGIMPORTS_CALL((void *, int, double, int, double, double), (a[0].p, a[1].i, a[2].d, a[3].i, a[4].d, a[5].d)) break; /* PIDIDD */
    case 882: ZIGIMPORTS_CALL((void *, int, double, int, double, void *), (a[0].p, a[1].i, a[2].d, a[3].i, a[4].d, a[5].p)) break; /* PIDIDP */
    case 883: ZIGIMPORTS_CALL((void *, int, double, int, void *, int), (a[0].p, a[1].i, a[2].d, a[3].i, a[4].p, a[5].i)) break; /* PIDIPI */
    case 884: ZIGIMPORTS_CALL((void *, int, double, int, void *, double), (a[0].p, a[1].i, a[2].d, a[3].i, a[4].p, a[5].d)) break; /* PIDIPD */
    case 885: ZIGIMPORTS_CALL((void *, int, double, int, void *, void *), (a[0].p, a[1].i, a[2].d, a[3].i, a[4].p, a[5].p)) break; /* PIDIPP */
    case 886: ZIGIMPORTS_CALL((void *, int, double, double, int, int), (a[0].p, a[1].i, a[2].d, a[3].d, a[4].i, a[5].i)) break; /* PIDDII */
    case 887: ZIGIMPORTS_CALL((void *, int, double, double, int, double), (a[0].p, a[1].i, a[2].d, a[3].d, a[4].i, a[5].d)) break; /* PIDDID */
    case 888: ZIGIMPORTS_CALL((void *, int, double, double, int, void *), (a[0].p, a[1].i, a[2].d, a[3].d, a[4].i, a[5].p)) break; /* PIDDIP */
    case 889: ZIGIMPORTS_CALL((void *, int, double, double, double, int), (a[0].p, a[1].i, a[2].d, a[3].d, a[4].d, a[5].i)) break; /* PIDDDI */
    case 890: ZIGIMPORTS_CALL((void *, int, double, double, double, double), (a[0].p, a[1].i, a[2].d, a[3].d, a[4].d, a[5].d)) break; /* PIDDDD */
    case 891: ZIGIMPORTS_CALL((void *, int, double, double, double, void *), (a[0].p, a[1].i, a[2].d, a[3].d, a[4].d, a[5].p)) break; /* PIDDDP */
    case 892: ZIGIMPORTS_CALL((void *, int, double, double, void *, int), (a[0].p, a[1].i, a[2].d, a[3].d, a[4].p, a[5].i)) break; /* PIDDPI */
    case 893: ZIGIMPORTS_CALL((void *, int, double, double, void *, double), (a[0].p, a[1].i, a[2].d, a[3].d, a[4].p, a[5].d)) break; /* PIDDPD */
    case 894: ZIGIMPORTS_CALL((void *, int, double, double, void *, void *), (a[0].p, a[1].i, a[2].d, a[3].d, a[4].p, a[5].p)) break; /* PIDDPP */
    case 895: ZIGIMPORTS_CALL((void *, int, double, void *, int, int), (a[0].p, a[1].i, a[2].d, a[3].p, a[4].i, a[5].i)) break; /* PIDPII */
    case 896: ZIGIMPORTS_CALL((void *, int, double, void *, int, double), (a[0].p, a[1].i, a[2].d, a[3].p, a[4].i, a[5].d)) break; /* PIDPID */
    case 897: ZIGIMPORTS_CALL((void *, int, double, void *, int, void *), (a[0].p, a[1].i, a[2].d, a[3].p, a[4].i, a[5].p)) break; /* PIDPIP */
    case 898: ZIGIMPORTS_CALL((void *, int, double, void *, double, int), (a[0].p, a[1].i, a[2].d, a[3].p, a[4].d, a[5].i)) break; /* PIDPDI */
    case 899: ZIGIMPORTS_CALL((void *, int, double, void *, double, double), (a[0].p, a[1].i, a[2].d, a[3].p, a[4].d, a[5].d)) break; /* PIDPDD */
    case 900: ZIGIMPORTS_CALL((void *, int, double, void *, double, void *), (a[0].p, a[1].i, a[2].d, a[3].p, a[4].d, a[5].p)) break; /* PIDPDP */
    case 901: ZIGIMPORTS_CALL((void *, int, double, void *, void *, int), (a[0].p, a[1].i, a[2].d, a[3].p, a[4].p, a[5].i)) break; /* PIDPPI */
    case 902: ZIGIMPORTS_CALL((void *, int, double, void *, void *, double), (a[0].p, a[1].i, a[2].d, a[3].p, a[4].p, a[5].d)) break; /* PIDPPD */
    case 903: ZIGIMPORTS_CALL((void *, int, double, void *, void *, void *), (a[0].p, a[1].i, a[2].d, a[3].p, a[4].p, a[5].p)) break; /* PIDPPP */
    case 904: ZIGIMPORTS_CALL((void *, int, void *, int, int, int), (a[0].p, a[1].i, a[2].p, a[3].i, a[4].i, a[5].i)) break; /* PIPIII */
    case 905: ZIGIMPORTS_CALL((void *, int, void *, int, int, double), (a[0].p, a[1].i, a[2].p, a[3].i, a[4].i, a[5].d)) break; /* PIPIID */
    case 906: ZIGIMPORTS_CALL((void *, int, void *, int, int, void *), (a[0].p, a[1].i, a[2].p, a[3].i, a[4].i, a[5].p)) break; /* PIPIIP */
    case 907: ZIGIMPORTS_CALL((void *, int, void *, int, double, int), (a[0].p, a[1].i, a[2].p, a[3].i, a[4].d, a[5].i)) break; /* PIPIDI */
    case 908: ZIGIMPORTS_CALL((void *, int, void *, int, double, double), (a[0].p, a[1].i, a[2].p, a[3].i, a[4].d, a[5].d)) break; /* PIPIDD */
    case 909: ZIGIMPORTS_CALL((void *, int, void *, int, double, void *), (a[0].p, a[1].i, a[2].p, a[3].i, a[4].d, a[5].p)) break; /* PIPIDP */
    case 910: ZIGIMPORTS_CALL((void *, int, void *, int, void *, int), (a[0].p, a[1].i, a[2].p, a[3].i, a[4].p, a[5].i)) break; /* PIPIPI */
    case 911: ZIGIMPORTS_CALL((void *, int, void *, int, void *, double), (a[0].p, a[1].i, a[2].p, a[3].i, a[4].p, a[5].d)) break; /* PIPIPD */
    case 912: ZIGIMPORTS_CALL((void *, int, void *, int, void *, void *), (a[0].p, a[1].i, a[2].p, a[3].i, a[4].p, a[5].p)) break; /* PIPIPP */
    case 913: ZIGIMPORTS_CALL((void *, int, void *, double, int, int), (a[0].p, a[1].i, a[2].p, a[3].d, a[4].i, a[5].i)) break; /* PIPDII */
    case 914: ZIGIMPORTS_CALL((void *, int, void *, double, int, double), (a[0].p, a[1].i, a[2].p, a[3].d, a[4].i, a[5].d)) break; /* PIPDID */
    case 915: ZIGIMPORTS_CALL((void *, int, void *, double, int, void *), (a[0].p, a[1].i, a[2].p, a[3].d, a[4].i, a[5].p)) break; /* PIPDIP */
    case 916: ZIGIMPORTS_CALL((void *, int, void *, double, double, int), (a[0].p, a[1].i, a[2].p, a[3].d, a[4].d, a[5].i)) break; /* PIPDDI */
    case 917: ZIGIMPORTS_CALL((void *, int, void *, double, double, double), (a[0].p, a[1].i, a[2].p, a[3].d, a[4].d, a[5].d)) break; /* PIPDDD */
    case 918: ZIGIMPORTS_CALL((void *, int, void *, double, double, void *), (a[0].p, a[1].i, a[2].p, a[3].d, a[4].d, a[5].p)) break; /* PIPDDP */
    case 919: ZIGIMPORTS_CALL((void *, int, void *, double, void *, int), (a[0].p, a[1].i, a[2].p, a[3].d, a[4].p, a[5].i)) break; /* PIPDPI */
    case 920: ZIGIMPORTS_CALL((void *, int, void *, double, void *, double), (a[0].p, a[1].i, a[2].p, a[3].d, a[4].p, a[5].d)) break; /* PIPDPD */
    case 921: ZIGIMPORTS_CALL((void *, int, void *, double, void *, void *), (a[0].p, a[1].i, a[2].p, a[3].d, a[4].p, a[5].p)) break; /* PIPDPP */
    case 922: ZIGIMPORTS_CALL((void *, int, void *, void *, int, int), (a[0].p, a[1].i, a[2].p, a[3].p, a[4].i, a[5].i)) break; /* PIPPII */
    case 923: ZIGIMPORTS_CALL((void *, int, void *, void *, int, double), (a[0].p, a[1].i, a[2].p, a[3].p, a[4].i, a[5].d)) break; /* PIPPID */
    case 924: ZIGIMPORTS_CALL((void *, int, void *, void *, int, void *), (a[0].p, a[1].i, a[2].p, a[3].p, a[4].i, a[5].p)) break; /* PIPPIP */
    case 925: ZIGIMPORTS_CALL((void *, int, void *, void *, double, int), (a[0].p, a[1].i, a[2].p, a[3].p, a[4].d, a[5].i)) break; /* PIPPDI */
    case 926: ZIGIMPORTS_CALL((void *, int, void *, void *, double, double), (a[0].p, a[1].i, a[2].p, a[3].p, a[4].d, a[5].d)) break; /* PIPPDD */
    case 927: ZIGIMPORTS_CALL((void *, int, void *, void *, double, void *), (a[0].p, a[1].i, a[2].p, a[3].p, a[4].d, a[5].p)) break; /* PIPPDP */
    case 928: ZIGIMPORTS_CALL((void *, int, void *, void *, void *, int), (a[0].p, a[1].i, a[2].p, a[3].p, a[4].p, a[5].i)) break; /* PIPPPI */
    case 929: ZIGIMPORTS_CALL((void *, int, void *, void *, void *, double), (a[0].p, a[1].i, a[2].p, a[3].p, a[4].p, a[5].d)) break; /* PIPPPD */
    case 930: ZIGIMPORTS_CALL((void *, int, void *, void *, void *, void *), (a[0].p, a[1].i, a[2].p, a[3].p, a[4].p, a[5].p)) break; /* PIPPPP */
    case 931: ZIGIMPORTS_CALL((void *, double, int, int, int, int), (a[0].p, a[1].d, a[2].i, a[3].i, a[4].i, a[5].i)) break; /* PDIIII */
    case 932: ZIGIMPORTS_CALL((void *, double, int, int, int, double), (a[0].p, a[1].d, a[2].i, a[3].i, a[4].i, a[5].d)) break; /* PDIIID */
    case 933: ZIGIMPORTS_CALL((void *, double, int, int, int, void *), (a[0].p, a[1].d, a[2].i, a[3].i, a[4].i, a[5].p)) break; /* PDIIIP */
    case 934: ZIGIMPORTS_CALL((void *, double, int, int, double, int), (a[0].p, a[1].d, a[2].i, a[3].i, a[4].d, a[5].i)) break; /* PDIIDI */
    case 935: ZIGIMPORTS_CALL((void *, double, int, int, double, double), (a[0].p, a[1].d, a[2].i, a[3].i, a[4].d, a[5].d)) break; /* PDIIDD */
    case 936: ZIGIMPORTS_CALL((void *, double, int, int, double, void *), (a[0].p, a[1].d, a[2].i, a[3].i, a[4].d, a[5].p)) break; /* PDIIDP */
    case 937: ZIGIMPORTS_CALL((void *, double, int, int, void *, int), (a[0].p, a[1].d, a[2].i, a[3].i, a[4].p, a[5].i)) break; /* PDIIPI */
    case 938: ZIGIMPORTS_CALL((void *, double, int, int, void *, double), (a[0].p, a[1].d, a[2].i, a[3].i, a[4].p, a[5].d)) break; /* PDIIPD */
    case 939: ZIGIMPORTS_CALL((void *, double, int, int, void *, void *), (a[0].p, a[1].d, a[2].i, a[3].i, a[4].p, a[5].p)) break; /* PDIIPP */
    case 940: ZIGIMPORTS_CALL((void *, double, int, double, int, int), (a[0].p, a[1].d, a[2].i, a[3].d, a[4].i, a[5].i)) break; /* PDIDII */
    case 941: ZIGIMPORTS_CALL((void *, double, int, double, int, double), (a[0].p, a[1].d, a[2].i, a[3].d, a[4].i, a[5].d)) break; /* PDIDID */
    case 942: ZIGIMPORTS_CALL((void *, double, int, double, int, void *), (a[0].p, a[1].d, a[2].i, a[3].d, a[4].i, a[5].p)) break; /* PDIDIP */
    case 943: ZIGIMPORTS_CALL((void *, double, int, double, double, int), (a[0].p, a[1].d, a[2].i, a[3].d, a[4].d, a[5].i)) break; /* PDIDDI */
    case 944: ZIGIMPORTS_CALL((void *, double, int, double, double, double), (a[0].p, a[1].d, a[2].i, a[3].d, a[4].d, a[5].d)) break; /* PDIDDD */
    case 945: ZIGIMPORTS_CALL((void *, double, int, double, double, void *), (a[0].p, a[1].d, a[2].i, a[3].d, a[4].d, a[5].p)) break; /* PDIDDP */
    case 946: ZIGIMPORTS_CALL((void *, double, int, double, void *, int), (a[0].p, a[1].d, a[2].i, a[3].d, a[4].p, a[5].i)) break; /* PDIDPI */
    case 947: ZIGIMPORTS_CALL((void *, double, int, double, void *, double), (a[0].p, a[1].d, a[2].i, a[3].d, a[4].p, a[5].d)) break; /* PDIDPD */
    case 948: ZIGIMPORTS_CALL((void *, double, int, double, void *, void *), (a[0].p, a[1].d, a[2].i, a[3].d, a[4].p, a[5].p)) break; /* PDIDPP */
    case 949: ZIGIMPORTS_CALL((void *, double, int, void *, int, int), (a[0].p, a[1].d, a[2].i, a[3].p, a[4].i, a[5].i)) break; /* PDIPII */
    case 950: ZIGIMPORTS_CALL((void *, double, int, void *, int, double), (a[0].p, a[1].d, a[2].i, a[3].p, a[4].i, a[5].d)) break; /* PDIPID */
    case 951: ZIGIMPORTS_CALL((void *, double, int, void *, int, void *), (a[0].p, a[1].d, a[2].i, a[3].p, a[4].i, a[5].p)) break; /* PDIPIP */
    case 952: ZIGIMPORTS_CALL((void *, double, int, void *, double, int), (a[0].p, a[1].d, a[2].i, a[3].p, a[4].d, a[5].i)) break; /* PDIPDI */
    case 953: ZIGIMPORTS_CALL((void *, double, int, void *, double, double), (a[0].p, a[1].d, a[2].i, a[3].p, a[4].d, a[5].d)) break; /* PDIPDD */
    case 954: ZIGIMPORTS_CALL((void *, double, int, void *, double, void *), (a[0].p, a[1].d, a[2].i, a[3].p, a[4].d, a[5].p)) break; /* PDIPDP */
    case 955: ZIGIMPORTS_CALL((void *, double, int, void *, void *, int), (a[0].p, a[1].d, a[2].i, a[3].p, a[4].p, a[5].i)) break; /* PDIPPI */
    case 956: ZIGIMPORTS_CALL((void *, double, int, void *, void *, double), (a[0].p, a[1].d, a[2].i, a[3].p, a[4].p, a[5].d)) break; /* PDIPPD */
    case 957: ZIGIMPORTS_CALL((void *, double, int, void *, void *, void *), (a[0].p, a[1].d, a[2].i, a[3].p, a[4].p, a[5].p)) break; /* PDIPPP */
    case 958: ZIGIMPORTS_CALL((void *, double, double, int, int, int), (a[0].p, a[1].d, a[2].d, a[3].i, a[4].i, a[5].i)) break; /* PDDIII */
    case 959: ZIGIMPORTS_CALL((void *, double, double, int, int, double), (a[0].p, a[1].d, a[2].d, a[3].i, a[4].i, a[5].d)) break; /* PDDIID */
    case 960: ZIGIMPORTS_CALL((void *, double, double, int, int, void *), (a[0].p, a[1].d, a[2].d, a[3].i, a[4].i, a[5].p)) break; /* PDDIIP */
    case 961: ZIGIMPORTS_CALL((void *, double, double, int, double, int), (a[0].p, a[1].d, a[2].d, a[3].i, a[4].d, a[5].i)) break; /* PDDIDI */
    case 962: ZIGIMPORTS_CALL((void *, double, double, int, double, double), (a[0].p, a[1].d, a[2].d, a[3].i, a[4].d, a[5].d)) break; /* PDDIDD */
    case 963: ZIGIMPORTS_CALL((void *, double, double, int, double, void *), (a[0].p, a[1].d, a[2].d, a[3].i, a[4].d, a[5].p)) break; /* PDDIDP */
    case 964: ZIGIMPORTS_CALL((void *, double, double, int, void *, int), (a[0].p, a[1].d, a[2].d, a[3].i, a[4].p, a[5].i)) break; /* PDDIPI */
    case 965: ZIGIMPORTS_CALL((void *, double, double, int, void *, double), (a[0].p, a[1].d, a[2].d, a[3].i, a[4].p, a[5].d)) break; /* PDDIPD */
    case 966: ZIGIMPORTS_CALL((void *, double, double, int, void *, void *), (a[0].p, a[1].d, a[2].d, a[3].i, a[4].p, a[5].p)) break; /* PDDIPP */
    case 967: ZIGIMPORTS_CALL((void *, double, double, double, int, int), (a[0].p, a[1].d, a[2].d, a[3].d, a[4].i, a[5].i)) break; /* PDDDII */
    case 968: ZIGIMPORTS_CALL((void *, double, double, double, int, double), (a[0].p, a[1].d, a[2].d, a[3].d, a[4].i, a[5].d)) break; /* PDDDID */
    case 969: ZIGIMPORTS_CALL((void *, double, double, double, int, void *), (a[0].p, a[1].d, a[2].d, a[3].d, a[4].i, a[5].p)) break; /* PDDDIP */
    case 970: ZIGIMPORTS_CALL((void *, double, double, double, double, int), (a[0].p, a[1].d, a[2].d, a[3].d, a[4].d, a[5].i)) break; /* PDDDDI */
    case 971: ZIGIMPORTS_CALL((void *, double, double, double, double, double), (a[0].p, a[1].d, a[2].d, a[3].d, a[4].d, a[5].d)) break; /* PDDDDD */
    case 972: ZIGIMPORTS_CALL((void *, double, double, double, double, void *), (a[0].p, a[1].d, a[2].d, a[3].d, a[4].d, a[5].p)) break; /* PDDDDP */
    case 973: ZIGIMPORTS_CALL((void *, double, double, double, void *, int), (a[0].p, a[1].d, a[2].d, a[3].d, a[4].p, a[5].i)) break; /* PDDDPI */
    case 974: ZIGIMPORTS_CALL((void *, double, double, double, void *, double), (a[0].p, a[1].d, a[2].d, a[3].d, a[4].p, a[5].d)) break; /* PDDDPD */
    case 975: ZIGIMPORTS_CALL((void *, double, double, double, void *, void *), (a[0].p, a[1].d, a[2].d, a[3].d, a[4].p, a[5].p)) break; /* PDDDPP */
    case 976: ZIGIMPORTS_CALL((void *, double, double, void *, int, int), (a[0].p, a[1].d, a[2].d, a[3].p, a[4].i, a[5].i)) break; /* PDDPII */
    case 977: ZIGIMPORTS_CALL((void *, double, double, void *, int, double), (a[0].p, a[1].d, a[2].d, a[3].p, a[4].i, a[5].d)) break; /* PDDPID */
    case 978: ZIGIMPORTS_CALL((void *, double, double, void *, int, void *), (a[0].p, a[1].d, a[2].d, a[3].p, a[4].i, a[5].p)) break; /* PDDPIP */
    case 979: ZIGIMPORTS_CALL((void *, double, double, void *, double, int), (a[0].p, a[1].d, a[2].d, a[3].p, a[4].d, a[5].i)) break; /* PDDPDI */
    case 980: ZIGIMPORTS_CALL((void *, double, double, void *, double, double), (a[0].p, a[1].d, a[2].d, a[3].p, a[4].d, a[5].d)) break; /* PDDPDD */
    case 981: ZIGIMPORTS_CALL((void *, double, double, void *, double, void *), (a[0].p, a[1].d, a[2].d, a[3].p, a[4].d, a[5].p)) break; /* PDDPDP */
    case 982: ZIGIMPORTS_CALL((void *, double, double, void *, void *, int), (a[0].p, a[1].d, a[2].d, a[3].p, a[4].p, a[5].i)) break; /* PDDPPI */
    case 983: ZIGIMPORTS_CALL((void *, double, double, void *, void *, double), (a[0].p, a[1].d, a[2].d, a[3].p, a[4].p, a[5].d)) break; /* PDDPPD */
    case 984: ZIGIMPORTS_CALL((void *, double, double, void *, void *, void *), (a[0].p, a[1].d, a[2].d, a[3].p, a[4].p, a[5].p)) break; /* PDDPPP */
    case 985: ZIGIMPORTS_CALL((void *, double, void *, int, int, int), (a[0].p, a[1].d, a[2].p, a[3].i, a[4].i, a[5].i)) break; /* PDPIII */
    case 986: ZIGIMPORTS_CALL((void *, double, void *, int, int, double), (a[0].p, a[1].d, a[2].p, a[3].i, a[4].i, a[5].d)) break; /* PDPIID */
    case 987: ZIGIMPORTS_CALL((void *, double, void *, int, int, void *), (a[0].p, a[1].d, a[2].p, a[3].i, a[4].i, a[5].p)) break; /* PDPIIP */
    case 988: ZIGIMPORTS_CALL((void *, double, void *, int, double, int), (a[0].p, a[1].d, a[2].p, a[3].i, a[4].d, a[5].i)) break; /* PDPIDI */
    case 989: ZIGIMPORTS_CALL((void *, double, void *, int, double, double), (a[0].p, a[1].d, a[2].p, a[3].i, a[4].d, a[5].d)) break; /* PDPIDD */
    case 990: ZIGIMPORTS_CALL((void *, double, void *, int, double, void *), (a[0].p, a[1].d, a[2].p, a[3].i, a[4].d, a[5].p)) break; /* PDPIDP */
    case 991: ZIGIMPORTS_CALL((void *, double, void *, int, void *, int), (a[0].p, a[1].d, a[2].p, a[3].i, a[4].p, a[5].i)) break; /* PDPIPI */
    case 992: ZIGIMPORTS_CALL((void *, double, void *, int, void *, double), (a[0].p, a[1].d, a[2].p, a[3].i, a[4].p, a[5].d)) break; /* PDPIPD */
    case 993: ZIGIMPORTS_CALL((void *, double, void *, int, void *, void *), (a[0].p, a[1].d, a[2].p, a[3].i, a[4].p, a[5].p)) break; /* PDPIPP */
    case 994: ZIGIMPORTS_CALL((void *, double, void *, double, int, int), (a[0].p, a[1].d, a[2].p, a[3].d, a[4].i, a[5].i)) break; /* PDPDII */
    case 995: ZIGIMPORTS_CALL((void *, double, void *, double, int, double), (a[0].p, a[1].d, a[2].p, a[3].d, a[4].i, a[5].d)) break; /* PDPDID */
    case 996: ZIGIMPORTS_CALL((void *, double, void *, double, int, void *), (a[0].p, a[1].d, a[2].p, a[3].d, a[4].i, a[5].p)) break; /* PDPDIP */
    case 997: ZIGIMPORTS_CALL((void *, double, void *, double, double, int), (a[0].p, a[1].d, a[2].p, a[3].d, a[4].d, a[5].i)) break; /* PDPDDI */
    case 998: ZIGIMPORTS_CALL((void *, double, void *, double, double, double), (a[0].p, a[1].d, a[2].p, a[3].d, a[4].d, a[5].d)) break; /* PDPDDD */
    case 999: ZIGIMPORTS_CALL((void *, double, void *, double, double, void *), (a[0].p, a[1].d, a[2].p, a[3].d, a[4].d, a[5].p)) break; /* PDPDDP */
    case 1000: ZIGIMPORTS_CALL((void *, double, void *, double, void *, int), (a[0].p, a[1].d, a[2].p, a[3].d, a[4].p, a[5].i)) break; /* PDPDPI */
    case 1001: ZIGIMPORTS_CALL((void *, double, void *, double, void *, double), (a[0].p, a[1].d, a[2].p, a[3].d, a[4].p, a[5].d)) break; /* PDPDPD */
    case 1002: ZIGIMPORTS_CALL((void *, double, void *, double, void *, void *), (a[0].p, a[1].d, a[2].p, a[3].d, a[4].p, a[5].p)) break; /* PDPDPP */
    case 1003: ZIGIMPORTS_CALL((void *, double, void *, void *, int, int), (a[0].p, a[1].d, a[2].p, a[3].p, a[4].i, a[5].i)) break; /* PDPPII */
    case 1004: ZIGIMPORTS_CALL((void *, double, void *, void *, int, double), (a[0].p, a[1].d, a[2].p, a[3].p, a[4].i, a[5].d)) break; /* PDPPID */
    case 1005: ZIGIMPORTS_CALL((void *, double, void *, void *, int, void *), (a[0].p, a[1].d, a[2].p, a[3].p, a[4].i, a[5].p)) break; /* PDPPIP */
    case 1006: ZIGIMPORTS_CALL((void *, double, void *, void *, double, int), (a[0].p, a[1].d, a[2].p, a[3].p, a[4].d, a[5].i)) break; /* PDPPDI */
    case 1007: ZIGIMPORTS_CALL((void *, double, void *, void *, double, double), (a[0].p, a[1].d, a[2].p, a[3].p, a[4].d, a[5].d)) break; /* PDPPDD */
    case 1008: ZIGIMPORTS_CALL((void *, double, void *, void *, double, void *), (a[0].p, a[1].d, a[2].p, a[3].p, a[4].d, a[5].p)) break; /* PDPPDP */
    case 1009: ZIGIMPORTS_CALL((void *, double, void *, void *, void *, int), (a[0].p, a[1].d, a[2].p, a[3].p, a[4].p, a[5].i)) break; /* PDPPPI */
    case 1010: ZIGIMPORTS_CALL((void *, double, void *, void *, void *, double), (a[0].p, a[1].d, a[2].p, a[3].p, a[4].p, a[5].d)) break; /* PDPPPD */
    case 1011: ZIGIMPORTS_CALL((void *, double, void *, void *, void *, void *), (a[0].p, a[1].d, a[2].p, a[3].p, a[4].p, a[5].p)) break; /* PDPPPP */
    case 1012: ZIGIMPORTS_CALL((void *, void *, int, int, int, int), (a[0].p, a[1].p, a[2].i, a[3].i, a[4].i, a[5].i)) break; /* PPIIII */
    case 1013: ZIGIMPORTS_CALL((void *, void *, int, int, int, double), (a[0].p, a[1].p, a[2].i, a[3].i, a[4].i, a[5].d)) break; /* PPIIID */
    case 1014: ZIGIMPORTS_CALL((void *, void *, int, int, int, void *), (a[0].p, a[1].p, a[2].i, a[3].i, a[4].i, a[5].p)) break; /* PPIIIP */
    case 1015: ZIGIMPORTS_CALL((void *, void *, int, int, double, int), (a[0].p, a[1].p, a[2].i, a[3].i, a[4].d, a[5].i)) break; /* PPIIDI */
    case 1016: ZIGIMPORTS_CALL((void *, void *, int, int, double, double), (a[0].p, a[1].p, a[2].i, a[3].i, a[4].d, a[5].d)) break; /* PPIIDD */
    case 1017: ZIGIMPORTS_CALL((void *, void *, int, int, double, void *), (a[0].p, a[1].p, a[2].i, a[3].i, a[4].d, a[5].p)) break; /* PPIIDP */
    case 1018: ZIGIMPORTS_CALL((void *, void *, int, int, void *, int), (a[0].p, a[1].p, a[2].i, a[3].i, a[4].p, a[5].i)) break; /* PPIIPI */
    case 1019: ZIGIMPORTS_CALL((void *, void *, int, int, void *, double), (a[0].p, a[1].p, a[2].i, a[3].i, a[4].p, a[5].d)) break; /* PPIIPD */
    case 1020: ZIGIMPORTS_CALL((void *, void *, int, int, void *, void *), (a[0].p, a[1].p, a[2].i, a[3].i, a[4].p, a[5].p)) break; /* PPIIPP */
    case 1021: ZIGIMPORTS_CALL((void *, void *, int, double, int, int), (a[0].p, a[1].p, a[2].i, a[3].d, a[4].i, a[5].i)) break; /* PPIDII */
    case 1022: ZIGIMPORTS_CALL((void *, void *, int, double, int, double), (a[0].p, a[1].p, a[2].i, a[3].d, a[4].i, a[5].d)) break; /* PPIDID */
    case 1023: ZIGIMPORTS_CALL((void *, void *, int, double, int, void *), (a[0].p, a[1].p, a[2].i, a[3].d, a[4].i, a[5].p)) break; /* PPIDIP */
    case 1024: ZIGIMPORTS_CALL((void *, void *, int, double, double, int), (a[0].p, a[1].p, a[2].i, a[3].d, a[4].d, a[5].i)) break; /* PPIDDI */
    case 1025: ZIGIMPORTS_CALL((void *, void *, int, double, double, double), (a[0].p, a[1].p, a[2].i, a[3].d, a[4].d, a[5].d)) break; /* PPIDDD */
    case 1026: ZIGIMPORTS_CALL((void *, void *, int, double, double, void *), (a[0].p, a[1].p, a[2].i, a[3].d, a[4].d, a[5].p)) break; /* PPIDDP */
    case 1027: ZIGIMPORTS_CALL((void *, void *, int, double, void *, int), (a[0].p, a[1].p, a[2].i, a[3].d, a[4].p, a[5].i)) break; /* PPIDPI */
    case 1028: ZIGIMPORTS_CALL((void *, void *, int, double, void *, double), (a[0].p, a[1].p, a[2].i, a[3].d, a[4].p, a[5].d)) break; /* PPIDPD */
    case 1029: ZIGIMPORTS_CALL((void *, void *, int, double, void *, void *), (a[0].p, a[1].p, a[2].i, a[3].d, a[4].p, a[5].p)) break; /* PPIDPP */
    case 1030: ZIGIMPORTS_CALL((void *, void *, int, void *, int, int), (a[0].p, a[1].p, a[2].i, a[3].p, a[4].i, a[5].i)) break; /* PPIPII */
    case 1031: ZIGIMPORTS_CALL((void *, void *, int, void *, int, double), (a[0].p, a[1].p, a[2].i, a[3].p, a[4].i, a[5].d)) break; /* PPIPID */
    case 1032: ZIGIMPORTS_CALL((void *, void *, int, void *, int, void *), (a[0].p, a[1].p, a[2].i, a[3].p, a[4].i, a[5].p)) break; /* PPIPIP */
    case 1033: ZIGIMPORTS_CALL((void *, void *, int, void *, double, int), (a[0].p, a[1].p, a[2].i, a[3].p, a[4].d, a[5].i)) break; /* PPIPDI */
    case 1034: ZIGIMPORTS_CALL((void *, void *, int, void *, double, double), (a[0].p, a[1].p, a[2].i, a[3].p, a[4].d, a[5].d)) break; /* PPIPDD */
    case 1035: ZIGIMPORTS_CALL((void *, void *, int, void *, double, void *), (a[0].p, a[1].p, a[2].i, a[3].p, a[4].d, a[5].p)) break; /* PPIPDP */
    case 1036: ZIGIMPORTS_CALL((void *, void *, int, void *, void *, int), (a[0].p, a[1].p, a[2].i, a[3].p, a[4].p, a[5].i)) break; /* PPIPPI */
    case 1037: ZIGIMPORTS_CALL((void *, void *, int, void *, void *, double), (a[0].p, a[1].p, a[2].i, a[3].p, a[4].p, a[5].d)) break; /* PPIPPD */
    case 1038: ZIGIMPORTS_CALL((void *, void *, int, void *, void *, void *), (a[0].p, a[1].p, a[2].i, a[3].p, a[4].p, a[5].p)) break; /* PPIPPP */
    case 1039: ZIGIMPORTS_CALL((void *, void *, double, int, int, int), (a[0].p, a[1].p, a[2].d, a[3].i, a[4].i, a[5].i)) break; /* PPDIII */
    case 1040: ZIGIMPORTS_CALL((void *, void *, double, int, int, double), (a[0].p, a[1].p, a[2].d, a[3].i, a[4].i, a[5].d)) break; /* PPDIID */
    case 1041: ZIGIMPORTS_CALL((void *, void *, double, int, int, void *), (a[0].p, a[1].p, a[2].d, a[3].i, a[4].i, a[5].p)) break; /* PPDIIP */
    case 1042: ZIGIMPORTS_CALL((void *, void *, double, int, double, int), (a[0].p, a[1].p, a[2].d, a[3].i, a[4].d, a[5].i)) break; /* PPDIDI */
    case 1043: ZIGIMPORTS_CALL((void *, void *, double, int, double, double), (a[0].p, a[1].p, a[2].d, a[3].i, a[4].d, a[5].d)) break; /* PPDIDD */
    case 1044: ZIGIMPORTS_CALL((void *, void *, double, int, double, void *), (a[0].p, a[1].p, a[2].d, a[3].i, a[4].d, a[5].p)) break; /* PPDIDP */
    case 1045: ZIGIMPORTS_CALL((void *, void *, double, int, void *, int), (a[0].p, a[1].p, a[2].d, a[3].i, a[4].p, a[5].i)) break; /* PPDIPI */
    case 1046: ZIGIMPORTS_CALL((void *, void *, double, int, void *, double), (a[0].p, a[1].p, a[2].d, a[3].i, a[4].p, a[5].d)) break; /* PPDIPD */
    case 1047: ZIGIMPORTS_CALL((void *, void *, double, int, void *, void *), (a[0].p, a[1].p, a[2].d, a[3].i, a[4].p, a[5].p)) break; /* PPDIPP */
    case 1048: ZIGIMPORTS_CALL((void *, void *, double, double, int, int), (a[0].p, a[1].p, a[2].d, a[3].d, a[4].i, a[5].i)) break; /* PPDDII */
    case 1049: ZIGIMPORTS_CALL((void *, void *, double, double, int, double), (a[0].p, a[1].p, a[2].d, a[3].d, a[4].i, a[5].d)) break; /* PPDDID */
    case 1050: ZIGIMPORTS_CALL((void *, void *, double, double, int, void *), (a[0].p, a[1].p, a[2].d, a[3].d, a[4].i, a[5].p)) break; /* PPDDIP */
    case 1051: ZIGIMPORTS_CALL((void *, void *, double, double, double, int), (a[0].p, a[1].p, a[2].d, a[3].d, a[4].d, a[5].i)) break; /* PPDDDI */
    case 1052: ZIGIMPORTS_CALL((void *, void *, double, double, double, double), (a[0].p, a[1].p, a[2].d, a[3].d, a[4].d, a[5].d)) break; /* PPDDDD */
    case 1053: ZIGIMPORTS_CALL((void *, void *, double, double, double, void *), (a[0].p, a[1].p, a[2].d, a[3].d, a[4].d, a[5].p)) break; /* PPDDDP */
    case 1054: ZIGIMPORTS_CALL((void *, void *, double, double, void *, int), (a[0].p, a[1].p, a[2].d, a[3].d, a[4].p, a[5].i)) break; /* PPDDPI */
    case 1055: ZIGIMPORTS_CALL((void *, void *, double, double, void *, double), (a[0].p, a[1].p, a[2].d, a[3].d, a[4].p, a[5].d)) break; /* PPDDPD */
    case 1056: ZIGIMPORTS_CALL((void *, void *, double, double, void *, void *), (a[0].p, a[1].p, a[2].d, a[3].d, a[4].p, a[5].p)) break; /* PPDDPP */
    case 1057: ZIGIMPORTS_CALL((void *, void *, double, void *, int, int), (a[0].p, a[1].p, a[2].d, a[3].p, a[4].i, a[5].i)) break; /* PPDPII */
    case 1058: ZIGIMPORTS_CALL((void *, void *, double, void *, int, double), (a[0].p, a[1].p, a[2].d, a[3].p, a[4].i, a[5].d)) break; /* PPDPID */
    case 1059: ZIGIMPORTS_CALL((void *, void *, double, void *, int, void *), (a[0].p, a[1].p, a[2].d, a[3].p, a[4].i, a[5].p)) break; /* PPDPIP */
    case 1060: ZIGIMPORTS_CALL((void *, void *, double, void *, double, int), (a[0].p, a[1].p, a[2].d, a[3].p, a[4].d, a[5].i)) break; /* PPDPDI */
    case 1061: ZIGIMPORTS_CALL((void *, void *, double, void *, double, double), (a[0].p, a[1].p, a[2].d, a[3].p, a[4].d, a[5].d)) break; /* PPDPDD */
    case 1062: ZIGIMPORTS_CALL((void *, void *, double, void *, double, void *), (a[0].p, a[1].p, a[2].d, a[3].p, a[4].d, a[5].p)) break; /* PPDPDP */
    case 1063: ZIGIMPORTS_CALL((void *, void *, double, void *, void *, int), (a[0].p, a[1].p, a[2].d, a[3].p, a[4].p, a[5].i)) break; /* PPDPPI */
    case 1064: ZIGIMPORTS_CALL((void *, void *, double, void *, void *, double), (a[0].p, a[1].p, a[2].d, a[3].p, a[4].p, a[5].d)) break; /* PPDPPD */
    case 1065: ZIGIMPORTS_CALL((void *, void *, double, void *, void *, void *), (a[0].p, a[1].p, a[2].d, a[3].p, a[4].p, a[5].p)) break; /* PPDPPP */
    case 1066: ZIGIMPORTS_CALL((void *, void *, void *, int, int, int), (a[0].p, a[1].p, a[2].p, a[3].i, a[4].i, a[5].i)) break; /* PPPIII */
    case 1067: ZIGIMPORTS_CALL((void *, void *, void *, int, int, double), (a[0].p, a[1].p, a[2].p, a[3].i, a[4].i, a[5].d)) break; /* PPPIID */
    case 1068: ZIGIMPORTS_CALL((void *, void *, void *, int, int, void *), (a[0].p, a[1].p, a[2].p, a[3].i, a[4].i, a[5].p)) break; /* PPPIIP */
    case 1069: ZIGIMPORTS_CALL((void *, void *, void *, int, double, int), (a[0].p, a[1].p, a[2].p, a[3].i, a[4].d, a[5].i)) break; /* PPPIDI */
    case 1070: ZIGIMPORTS_CALL((void *, void *, void *, int, double, double), (a[0].p, a[1].p, a[2].p, a[3].i, a[4].d, a[5].d)) break; /* PPPIDD */
    case 1071: ZIGIMPORTS_CALL((void *, void *, void *, int, double, void *), (a[0].p, a[1].p, a[2].p, a[3].i, a[4].d, a[5].p)) break; /* PPPIDP */
    case 1072: ZIGIMPORTS_CALL((void *, void *, void *, int, void *, int), (a[0].p, a[1].p, a[2].p, a[3].i, a[4].p, a[5].i)) break; /* PPPIPI */
    case 1073: ZIGIMPORTS_CALL((void *, void *, void *, int, void *, double), (a[0].p, a[1].p, a[2].p, a[3].i, a[4].p, a[5].d)) break; /* PPPIPD */
    case 1074: ZIGIMPORTS_CALL((void *, void *, void *, int, void *, void *), (a[0].p, a[1].p, a[2].p, a[3].i, a[4].p, a[5].p)) break; /* PPPIPP */
    case 1075: ZIGIMPORTS_CALL((void *, void *, void *, double, int, int), (a[0].p, a[1].p, a[2].p, a[3].d, a[4].i, a[5].i)) break; /* PPPDII */
    case 1076: ZIGIMPORTS_CALL((void *, void *, void *, double, int, double), (a[0].p, a[1].p, a[2].p, a[3].d, a[4].i, a[5].d)) break; /* PPPDID */
    case 1077: ZIGIMPORTS_CALL((void *, void *, void *, double, int, void *), (a[0].p, a[1].p, a[2].p, a[3].d, a[4].i, a[5].p)) break; /* PPPDIP */
    case 1078: ZIGIMPORTS_CALL((void *, void *, void *, double, double, int), (a[0].p, a[1].p, a[2].p, a[3].d, a[4].d, a[5].i)) break; /* PPPDDI */
    case 1079: ZIGIMPORTS_CALL((void *, void *, void *, double, double, double), (a[0].p, a[1].p, a[2].p, a[3].d, a[4].d, a[5].d)) break; /* PPPDDD */
    case 1080: ZIGIMPORTS_CALL((void *, void *, void *, double, double, void *), (a[0].p, a[1].p, a[2].p, a[3].d, a[4].d, a[5].p)) break; /* PPPDDP */
    case 1081: ZIGIMPORTS_CALL((void *, void *, void *, double, void *, int), (a[0].p, a[1].p, a[2].p, a[3].d, a[4].p, a[5].i)) break; /* PPPDPI */
    case 1082: ZIGIMPORTS_CALL((void *, void *, void *, double, void *, double), (a[0].p, a[1].p, a[2].p, a[3].d, a[4].p, a[5].d)) break; /* PPPDPD */
    case 1083: ZIGIMPORTS_CALL((void *, void *, void *, double, void *, void *), (a[0].p, a[1].p, a[2].p, a[3].d, a[4].p, a[5].p)) break; /* PPPDPP */
    case 1084: ZIGIMPORTS_CALL((void *, void *, void *, void *, int, int), (a[0].p, a[1].p, a[2].p, a[3].p, a[4].i, a[5].i)) break; /* PPPPII */
    case 1085: ZIGIMPORTS_CALL((void *, void *, void *, void *, int, double), (a[0].p, a[1].p, a[2].p, a[3].p, a[4].i, a[5].d)) break; /* PPPPID */
    case 1086: ZIGIMPORTS_CALL((void *, void *, void *, void *, int, void *), (a[0].p, a[1].p, a[2].p, a[3].p, a[4].i, a[5].p)) break; /* PPPPIP */
    case 1087: ZIGIMPORTS_CALL((void *, void *, void *, void *, double, int), (a[0].p, a[1].p, a[2].p, a[3].p, a[4].d, a[5].i)) break; /* PPPPDI */
    case 1088: ZIGIMPORTS_CALL((void *, void *, void *, void *, double, double), (a[0].p, a[1].p, a[2].p, a[3].p, a[4].d, a[5].d)) break; /* PPPPDD */
    case 1089: ZIGIMPORTS_CALL((void *, void *, void *, void *, double, void *), (a[0].p, a[1].p, a[2].p, a[3].p, a[4].d, a[5].p)) break; /* PPPPDP */
    case 1090: ZIGIMPORTS_CALL((void *, void *, void *, void *, void *, int), (a[0].p, a[1].p, a[2].p, a[3].p, a[4].p, a[5].i)) break; /* PPPPPI */
    case 1091: ZIGIMPORTS_CALL((void *, void *, void *, void *, void *, double), (a[0].p, a[1].p, a[2].p, a[3].p, a[4].p, a[5].d)) break; /* PPPPPD */
    case 1092: ZIGIMPORTS_CALL((void *, void *, void *, void *, void *, void *), (a[0].p, a[1].p, a[2].p, a[3].p, a[4].p, a[5].p)) break; /* PPPPPP */
    default: return -1;
    }
    return 0;
}
