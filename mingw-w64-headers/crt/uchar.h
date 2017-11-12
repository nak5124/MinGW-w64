/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/* ISO C1x Unicode utilities
 * Based on ISO/IEC SC22/WG14 9899 TR 19769 (SC22 N1326)
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  This source code is offered for use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *  Date: 2011-09-27
 */

#ifndef __UCHAR_H
#define __UCHAR_H

#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint_leastXX_t */
#include <wchar.h>   /* mbstate_t */

/* Remember that g++ >= 4.4 defines these types only in c++0x mode */
#if !(defined(__cplusplus) && defined(__GXX_EXPERIMENTAL_CXX0X__)) || !defined(__GNUC__) || (!defined(__clang__) && (__GNUC__ < 4 || (__GNUC__ == 4 &&	__GNUC_MINOR__ < 4)))
  typedef uint_least16_t char16_t;
  typedef uint_least32_t char32_t;
#endif  /* !(defined(__cplusplus) && defined(__GXX_EXPERIMENTAL_CXX0X__)) || ... */

#ifndef __STDC_UTF_16__
#define __STDC_UTF_16__ 1
#endif
#ifndef __STDC_UTF_32__
#define __STDC_UTF_32__ 1
#endif

#define _UCHAR
  typedef unsigned short _Char16_t;
  typedef unsigned int   _Char32_t;

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#if __MSVCRT_VERSION__ >= 0x1400
  _CRTIMP size_t mbrtoc16(char16_t * __restrict__ _Pc16, const char * __restrict__ _S, size_t _N, mbstate_t * __restrict__ _Ps);
  _CRTIMP size_t c16rtomb(char * __restrict__ S, char16_t _C16, mbstate_t * __restrict__ _Ps);

  _CRTIMP size_t mbrtoc32(char32_t * __restrict__ _Pc32, const char * __restrict__ _S, size_t _N, mbstate_t * __restrict__ _Ps);
  _CRTIMP size_t c32rtomb(char * __restrict__ _S, char32_t _C32, mbstate_t * __restrict__ _Ps);
#else  /* __MSVCRT_VERSION__ >= 0x1400 */
  /* Provided in libmingwex. */
          size_t mbrtoc16(char16_t * __restrict__ _Pc16, const char * __restrict__ _S, size_t _N, mbstate_t * __restrict__ _Ps);
          size_t c16rtomb(char * __restrict__ S, char16_t _C16, mbstate_t * __restrict__ _Ps);

          size_t mbrtoc32(char32_t * __restrict__ _Pc32, const char * __restrict__ _S, size_t _N, mbstate_t * __restrict__ _Ps);
          size_t c32rtomb(char * __restrict__ _S, char32_t _C32, mbstate_t * __restrict__ _Ps);
#endif  /* __MSVCRT_VERSION__ >= 0x1400 */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __UCHAR_H */
