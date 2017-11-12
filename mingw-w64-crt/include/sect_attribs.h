/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifdef __GNUC__
#define _CRTALLOC(x) __attribute__ ((section (x) ))
#else  /* __GNUC__ */
#error Your compiler is not supported.
#endif  /* __GNUC__ */
