/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <crtdefs.h>

#ifndef _INC_LIMITS
#define _INC_LIMITS

/*
 * File system limits
 *
 * NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
 *       required for the NUL. TODO: Test?
 * NOTE: PATH_MAX is the POSIX equivalent for Microsoft's MAX_PATH; the two
 *       are semantically identical, with a limit of 259 characters for the
 *       path name, plus one for a terminating NUL, for a total of 260.
 */
#define PATH_MAX 260

#define CHAR_BIT  8
#define SCHAR_MIN (-128)
#define SCHAR_MAX 127
#define UCHAR_MAX 0xff

#ifdef __CHAR_UNSIGNED__
#define CHAR_MIN 0
#define CHAR_MAX UCHAR_MAX
#else  /* __CHAR_UNSIGNED__ */
#define CHAR_MIN SCHAR_MIN
#define CHAR_MAX SCHAR_MAX
#endif  /* __CHAR_UNSIGNED__ */

#define MB_LEN_MAX 5
#define SHRT_MIN   (-32768)
#define SHRT_MAX   32767
#define USHRT_MAX  0xffffU
#define INT_MIN    (-2147483647 - 1)
#define INT_MAX    2147483647
#define UINT_MAX   0xffffffffU
#define LONG_MIN   (-2147483647L - 1)
#define LONG_MAX   2147483647L
#define ULONG_MAX  0xffffffffUL
#define LLONG_MAX  9223372036854775807ll
#define LLONG_MIN  (-9223372036854775807ll - 1)
#define ULLONG_MAX 0xffffffffffffffffull

#define _I8_MIN    (-127 - 1)
#define _I8_MAX    127
#define _UI8_MAX   0xffu

#define _I16_MIN   (-32767 - 1)
#define _I16_MAX   32767
#define _UI16_MAX  0xffffu

#define _I32_MIN   (-2147483647 - 1)
#define _I32_MAX   2147483647
#define _UI32_MAX  0xffffffffu

#ifdef __GNUC__
#undef LONG_LONG_MAX
#define LONG_LONG_MAX  9223372036854775807ll
#undef LONG_LONG_MIN
#define LONG_LONG_MIN  (-LONG_LONG_MAX - 1)
#undef ULONG_LONG_MAX
#define ULONG_LONG_MAX (2ull * LONG_LONG_MAX + 1ull)
#endif  /* __GNUC__ */

#define _I64_MIN  (-9223372036854775807ll - 1)
#define _I64_MAX  9223372036854775807ll
#define _UI64_MAX 0xffffffffffffffffull

#ifndef SIZE_MAX
#ifdef _WIN64
#define SIZE_MAX _UI64_MAX
#else  /* _WIN64 */
#define SIZE_MAX UINT_MAX
#endif  /* _WIN64 */
#endif  /* !SIZE_MAX */

#ifndef SSIZE_MAX
#ifdef _WIN64
#define SSIZE_MAX _I64_MAX
#else  /* _WIN64 */
#define SSIZE_MAX INT_MAX
#endif  /* _WIN64 */
#endif  /* !SSIZE_MAX */

#endif /* _INC_LIMITS */
