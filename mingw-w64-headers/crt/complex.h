/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
/*
 * complex.h
 *
 * This file is part of the Mingw32 package.
 *
 * Contributors:
 *  Created by Danny Smith <dannysmith@users.sourceforge.net>
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
 */

#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <crtdefs.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/* These macros are specified by C99 standard */
#ifndef __cplusplus
#define complex _Complex
#endif  /* !__cplusplus */

#define _Complex_I (__extension__ 1.0iF)

/* GCC doesn't support _Imaginary type yet, so we don't define _Imaginary_I */
#define I _Complex_I

  /* Provided in libmingwex. */
  double          __cdecl cabs(double _Complex _Z) __MINGW_ATTRIB_CONST __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  double _Complex __cdecl cacos(double _Complex _Z);
  double _Complex __cdecl cacosh(double _Complex _Z);
  double          __cdecl carg(double _Complex _Z) __MINGW_ATTRIB_CONST;
  double _Complex __cdecl casin(double _Complex _Z);
  double _Complex __cdecl casinh(double _Complex _Z);
  double _Complex __cdecl catan(double _Complex _Z);
  double _Complex __cdecl catanh(double _Complex _Z);
  double _Complex __cdecl ccos(double _Complex _Z);
  double _Complex __cdecl ccosh(double _Complex _Z);
  double _Complex __cdecl cexp(double _Complex _Z);
  double          __cdecl cimag(double _Complex _Z) __MINGW_ATTRIB_CONST;
  double _Complex __cdecl clog(double _Complex _Z);
#ifdef _GNU_SOURCE
  double _Complex __cdecl clog10(double _Complex _Z);
#endif  /* _GNU_SOURCE */
  double _Complex __cdecl conj(double _Complex _Z) __MINGW_ATTRIB_CONST;
  double _Complex __cdecl cpow(double _Complex _X, double _Complex _Y);
  double _Complex __cdecl cproj(double _Complex _Z) __MINGW_ATTRIB_CONST;
  double          __cdecl creal(double _Complex _Z) __MINGW_ATTRIB_CONST;
  double _Complex __cdecl csin(double _Complex _Z);
  double _Complex __cdecl csinh(double _Complex _Z);
  double _Complex __cdecl csqrt(double _Complex _Z);
  double _Complex __cdecl ctan(double _Complex _Z);
  double _Complex __cdecl ctanh(double _Complex _Z);
#if __MSVCRT_VERSION__ >= 0x1200
  /* _CRTIMP */ double __cdecl norm(double _Complex _Z);
#endif  /* __MSVCRT_VERSION__ >= 0x1200 */

  /* Provided in libmingwex. */
  float          __cdecl cabsf(float _Complex _Z) __MINGW_ATTRIB_CONST;
  float _Complex __cdecl cacosf(float _Complex _Z);
  float _Complex __cdecl cacoshf(float _Complex _Z);
  float          __cdecl cargf(float _Complex _Z) __MINGW_ATTRIB_CONST;
  float _Complex __cdecl casinf(float _Complex _Z);
  float _Complex __cdecl casinhf(float _Complex _Z);
  float _Complex __cdecl catanf(float _Complex _Z);
  float _Complex __cdecl catanhf(float _Complex _Z);
  float _Complex __cdecl ccosf(float _Complex _Z);
  float _Complex __cdecl ccoshf(float _Complex _Z);
  float _Complex __cdecl cexpf(float _Complex _Z);
  float          __cdecl cimagf(float _Complex _Z) __MINGW_ATTRIB_CONST;
  float _Complex __cdecl clogf(float _Complex _Z);
#ifdef _GNU_SOURCE
  float _Complex __cdecl clog10f(float _Complex _Z);
#endif  /* _GNU_SOURCE */
  float _Complex __cdecl conjf(float _Complex _Z) __MINGW_ATTRIB_CONST;
  float _Complex __cdecl cpowf(float _Complex _X, float _Complex _Y);
  float _Complex __cdecl cprojf(float _Complex _Z) __MINGW_ATTRIB_CONST;
  float          __cdecl crealf(float _Complex _Z) __MINGW_ATTRIB_CONST;
  float _Complex __cdecl csinf(float _Complex _Z);
  float _Complex __cdecl csinhf(float _Complex _Z);
  float _Complex __cdecl csqrtf(float _Complex _Z);
  float _Complex __cdecl ctanf(float _Complex _Z);
  float _Complex __cdecl ctanhf(float _Complex _Z);
#if __MSVCRT_VERSION__ >= 0x1200
  /* _CRTIMP */ float __cdecl normf(float _Complex _Z);
#endif  /* __MSVCRT_VERSION__ >= 0x1200 */

  /* Provided in libmingwex. */
  long double          __cdecl cabsl(long double _Complex _Z) __MINGW_ATTRIB_CONST;
  long double _Complex __cdecl cacosl(long double _Complex _Z);
  long double _Complex __cdecl cacoshl(long double _Complex _Z);
  long double          __cdecl cargl(long double _Complex _Z) __MINGW_ATTRIB_CONST;
  long double _Complex __cdecl casinl(long double _Complex _Z);
  long double _Complex __cdecl casinhl(long double _Complex _Z);
  long double _Complex __cdecl catanl(long double _Complex _Z);
  long double _Complex __cdecl catanhl(long double _Complex _Z);
  long double _Complex __cdecl ccosl(long double _Complex _Z);
  long double _Complex __cdecl ccoshl(long double _Complex _Z);
  long double _Complex __cdecl cexpl(long double _Complex _Z);
  long double          __cdecl cimagl(long double _Complex _Z) __MINGW_ATTRIB_CONST;
  long double _Complex __cdecl clogl(long double _Complex _Z);
#ifdef _GNU_SOURCE
  long double _Complex __cdecl clog10l(long double _Complex _Z);
#endif  /* _GNU_SOURCE */
  long double _Complex __cdecl conjl(long double _Complex _Z) __MINGW_ATTRIB_CONST;
  long double _Complex __cdecl cpowl(long double _Complex _X, long double _Complex _Y);
  long double _Complex __cdecl cprojl(long double _Complex _Z) __MINGW_ATTRIB_CONST;
  long double          __cdecl creall(long double _Complex _Z) __MINGW_ATTRIB_CONST;
  long double _Complex __cdecl csinl(long double _Complex _Z);
  long double _Complex __cdecl csinhl(long double _Complex _Z);
  long double _Complex __cdecl csqrtl(long double _Complex _Z);
  long double _Complex __cdecl ctanl(long double _Complex _Z);
  long double _Complex __cdecl ctanhl(long double _Complex _Z);
#if __MSVCRT_VERSION__ >= 0x1200
  /* _CRTIMP */ long double __cdecl norml(long double _Complex _Z);
#endif  /* __MSVCRT_VERSION__ >= 0x1200 */

#if __MSVCRT_VERSION__ >= 0x1200
  _CRTIMP double      _Complex __cdecl _Cbuild(double _X, double _Y);
  _CRTIMP float       _Complex __cdecl _FCbuild(float _X, float _Y);
  _CRTIMP long double _Complex __cdecl _LCbuild(long double _X, long double _Y);
#endif  /* __MSVCRT_VERSION__ >= 0x1200 */

#if __MSVCRT_VERSION__ >= 0x1400
  _CRTIMP double      _Complex __cdecl _Cmulcc(double _Complex _X, double _Complex _Y);
  _CRTIMP double      _Complex __cdecl _Cmulcr(double _Complex _X, double _Y);
  _CRTIMP float       _Complex __cdecl _FCmulcc(float _Complex _X, float _Complex _Y);
  _CRTIMP float       _Complex __cdecl _FCmulcr(float _Complex _X, float _Y);
  _CRTIMP long double _Complex __cdecl _LCmulcc(long double _Complex _X, long double _Complex _Y);
  _CRTIMP long double _Complex __cdecl _LCmulcr(long double _Complex _X, long double _Y);
#endif  /* __MSVCRT_VERSION__ >= 0x1400 */

#ifdef __GNUC__
#if !defined(__CRT__NO_INLINE) && defined(_MATH_H_)
  /* double */
  __CRT_INLINE double __cdecl __MINGW_ATTRIB_CONST cabs(double _Complex _Z) {
    return hypot(__real__ _Z, __imag__ _Z);
  }
  __CRT_INLINE double __cdecl __MINGW_ATTRIB_CONST carg(double _Complex _Z) {
    return atan2(__imag__ _Z, __real__ _Z);
  }
  __CRT_INLINE double __cdecl __MINGW_ATTRIB_CONST cimag(double _Complex _Z) {
    return __imag__ _Z;
  }
  __CRT_INLINE double _Complex __cdecl __MINGW_ATTRIB_CONST conj(double _Complex _Z) {
    return __extension__ ~_Z;
  }
  __CRT_INLINE double _Complex __cdecl __MINGW_ATTRIB_CONST cproj(double _Complex _Z) {
    __complex__ double ret;
    if (isinf(__real__ _Z) || isinf(__imag__ _Z)) {
      __real__ ret = INFINITY;
      __imag__ ret = copysign(0.0, __imag__ _Z);
      return ret;
    }
    return _Z;
  }
  __CRT_INLINE double __cdecl __MINGW_ATTRIB_CONST creal(double _Complex _Z) {
    return __real__ _Z;
  }

  /* float */
  __CRT_INLINE float __cdecl __MINGW_ATTRIB_CONST cabsf(float _Complex _Z) {
    return hypotf(__real__ _Z, __imag__ _Z);
  }
  __CRT_INLINE float __cdecl __MINGW_ATTRIB_CONST cargf(float _Complex _Z) {
    return atan2f(__imag__ _Z, __real__ _Z);
  }
  __CRT_INLINE float __cdecl __MINGW_ATTRIB_CONST cimagf(float _Complex _Z) {
    return __imag__ _Z;
  }
  __CRT_INLINE float _Complex __cdecl __MINGW_ATTRIB_CONST conjf(float _Complex _Z) {
    return __extension__ ~_Z;
  }
  __CRT_INLINE float _Complex __cdecl __MINGW_ATTRIB_CONST cprojf(float _Complex _Z) {
    __complex__ float ret;
    if (isinf(__real__ _Z) || isinf(__imag__ _Z)) {
      __real__ ret = INFINITY;
      __imag__ ret = copysignf(0.0F, __imag__ _Z);
      return ret;
    }
    return _Z;
  }
  __CRT_INLINE float __cdecl __MINGW_ATTRIB_CONST crealf(float _Complex _Z) {
    return __real__ _Z;
  }

  /* long double */
  __CRT_INLINE long double __cdecl __MINGW_ATTRIB_CONST cabsl(long double _Complex _Z) {
    return hypotl(__real__ _Z, __imag__ _Z);
  }
  __CRT_INLINE long double __cdecl __MINGW_ATTRIB_CONST cargl(long double _Complex _Z) {
    return atan2l(__imag__ _Z, __real__ _Z);
  }
  __CRT_INLINE long double __cdecl __MINGW_ATTRIB_CONST cimagl(long double _Complex _Z) {
    return __imag__ _Z;
  }
  __CRT_INLINE long double _Complex __cdecl __MINGW_ATTRIB_CONST conjl(long double _Complex _Z) {
    return __extension__ ~_Z;
  }
  __CRT_INLINE long double _Complex __cdecl __MINGW_ATTRIB_CONST cprojl(long double _Complex _Z) {
    __complex__ long double ret;
    if (isinf(__real__ _Z) || isinf(__imag__ _Z)) {
      __real__ ret = INFINITY;
      __imag__ ret = copysignl(0.0L, __imag__ _Z);
      return ret;
    }
    return _Z;
  }
  __CRT_INLINE long double __cdecl __MINGW_ATTRIB_CONST creall(long double _Complex _Z) {
    return __real__ _Z;
  }

#endif  /* !defined(__CRT__NO_INLINE) && defined(_MATH_H_) */
#endif  /* __GNUC__ */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* _COMPLEX_H_ */
