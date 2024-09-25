#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#define __SIMPL_TYPE_ONLY
#include "../simpl.h"
#undef __SIMPL_TYPE_ONLY

#if defined(__AVX2__)
#define __WARNING_FUNCTION_AVX_H__
#include "function_avx.h"
#endif
#define __WARNING_FUNCTION_SSE_H__
#include "function_sse.h"

#if defined(SIMPL_USE_AVX) && defined(__AVX2__)
#define __SIMPL_FUNC(x) _FUNC_AVX(x)
#define __SIMPL_VECTOR_SIZE 256
#define __SIMPL_TARGET "avx2"
#elif defined(SIMPL_USE_SSE)
#define __SIMPL_FUNC(x) _FUNC_SSE(x)
#define __SIMPL_VECTOR_SIZE 128
#define __SIMPL_TARGET "sse"
#elif defined(__AVX2__)
#define __SIMPL_FUNC(x) _FUNC_AVX(x)
#define __SIMPL_VECTOR_SIZE 256
#define __SIMPL_TARGET "avx2"
#else
#define __SIMPL_FUNC(x) _FUNC_SSE(x)
#define __SIMPL_VECTOR_SIZE 128
#define __SIMPL_TARGET "sse"
#endif

#define __SIMPL_ATTR                                                           \
  __attribute__((__always_inline__, __nodebug__, __target__(__SIMPL_TARGET),   \
                 __min_vector_width__(__SIMPL_VECTOR_SIZE)))

/* doesn't works for now sorry... */
/* #define __SIMPL_ATTR_WARNING(x, msg) __attribute__((__SIMPL_ALIAS(x),
 * __always_inline__, __nodebug__, __target__("avx2"),
 * __min_vector_width__(__SIMPL_VECTOR_SIZE), warning(msg))) */

// v32c_add
static inline __SIMPL_ATTR vec v32c_add(vec __a, vec __b) {
    return __SIMPL_FUNC(v32c_add)(__a, __b);
}

// v32c_cmpeq
static inline __SIMPL_ATTR vec v32c_cmpeq(vec __a, vec __b) {
    return __SIMPL_FUNC(v32c_cmpeq)(__a, __b);
}

// v256b_set_char
static inline __SIMPL_ATTR vec v256b_set_char(
    char __a, char __b, char __c, char __d, char __e, char __f, char __g,
    char __h, char __i, char __j, char __k, char __l, char __m, char __n,
    char __o, char __p, char __q, char __r, char __s, char __t, char __u,
    char __v, char __w, char __x, char __y, char __z, char __aa, char __bb,
    char __cc, char __dd, char __ee, char __ff) {
    return __SIMPL_FUNC(v256b_set_char)(__a, __b, __c, __d, __e, __f, __g, __h, 
                                        __i, __j, __k, __l, __m, __n, __o, __p, 
                                        __q, __r, __s, __t, __u, __v, __w, __x, 
                                        __y, __z, __aa, __bb, __cc, __dd, 
                                        __ee, __ff);
}

// v256b_set1_char
static inline __SIMPL_ATTR vec v256b_set1_char(char __a) {
    return __SIMPL_FUNC(v256b_set1_char)(__a);
}

// v32c_movemask
static inline __SIMPL_ATTR int v32c_movemask(vec __a) {
    return __SIMPL_FUNC(v32c_movemask)(__a);
}

// v256b_loadu
static inline __SIMPL_ATTR vec v256b_loadu(const uvec *__p) {
    return __SIMPL_FUNC(v256b_loadu)(__p);
}

#endif /* __FUNCTION_H__ */
