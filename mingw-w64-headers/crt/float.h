/*
 * float.h
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within the package.
 *
 * Constants related to floating point arithmetic.
 *
 * Also included here are some non-ANSI bits for accessing the floating
 * point controller.
 *
 */

#if (defined(__GNUC__) && defined(__GNUC_MINOR__)) || (defined(__clang__) && defined(__clang_major__))
#if (__GNUC__ < 4  || (__GNUC__ == 4 && __GNUC_MINOR__ < 6)) || (__clang_major__ >=3)
#if !defined(_FLOAT_H___) && !defined(__FLOAT_H)
#include_next <float.h>
#endif  /* !defined(_FLOAT_H___) && !defined(__FLOAT_H) */
#elif !defined(_FLOAT_H___)
#if __GNUC__ < 4
#error Corrupt install of gcc-s internal headers, or search order was changed.
#else  /* __GNUC__ < 4 */
/* #include_next <float_ginclude.h> */

/* Number of decimal digits, q, such that any floating-point number with q
   decimal digits can be rounded into a floating-point number with p radix b
   digits and back again without change to the q decimal digits,
   p * log10(b) if b is a power of 10
   floor((p - 1) * log10(b)) otherwise
*/
#undef FLT_DIG
#undef DBL_DIG
#undef LDBL_DIG
#define FLT_DIG  __FLT_DIG__
#define DBL_DIG  __DBL_DIG__
#define LDBL_DIG __LDBL_DIG__

/* Maximum representable finite floating-point number,
   (1 - b**-p) * b**emax
*/
#undef FLT_MAX
#undef DBL_MAX
#undef LDBL_MAX
#define FLT_MAX  __FLT_MAX__
#define DBL_MAX  __DBL_MAX__
#define LDBL_MAX __LDBL_MAX__

/* Minimum normalized positive floating-point number, b**(emin - 1).  */
#undef FLT_MIN
#undef DBL_MIN
#undef LDBL_MIN
#define FLT_MIN  __FLT_MIN__
#define DBL_MIN  __DBL_MIN__
#define LDBL_MIN __LDBL_MIN__

/* Needed for libjava building - Victor K. */
/* Radix of exponent representation, b. */
#undef FLT_RADIX
#define FLT_RADIX __FLT_RADIX__

/* Minimum int x such that FLT_RADIX**(x-1) is a normalized float, emin */
#undef FLT_MIN_EXP
#undef DBL_MIN_EXP
#undef LDBL_MIN_EXP
#define FLT_MIN_EXP  __FLT_MIN_EXP__
#define DBL_MIN_EXP  __DBL_MIN_EXP__
#define LDBL_MIN_EXP __LDBL_MIN_EXP__

/* Minimum negative integer such that 10 raised to that power is in the
   range of normalized floating-point numbers,
   ceil(log10(b) * (emin - 1))
*/
#undef FLT_MIN_10_EXP
#undef DBL_MIN_10_EXP
#undef LDBL_MIN_10_EXP
#define FLT_MIN_10_EXP  __FLT_MIN_10_EXP__
#define DBL_MIN_10_EXP  __DBL_MIN_10_EXP__
#define LDBL_MIN_10_EXP __LDBL_MIN_10_EXP__

/* Maximum int x such that FLT_RADIX**(x-1) is a representable float, emax.  */
#undef FLT_MAX_EXP
#undef DBL_MAX_EXP
#undef LDBL_MAX_EXP
#define FLT_MAX_EXP  __FLT_MAX_EXP__
#define DBL_MAX_EXP  __DBL_MAX_EXP__
#define LDBL_MAX_EXP __LDBL_MAX_EXP__

/* Maximum integer such that 10 raised to that power is in the range of
   representable finite floating-point numbers,
   floor(log10((1 - b**-p) * b**emax))
*/
#undef FLT_MAX_10_EXP
#undef DBL_MAX_10_EXP
#undef LDBL_MAX_10_EXP
#define FLT_MAX_10_EXP  __FLT_MAX_10_EXP__
#define DBL_MAX_10_EXP  __DBL_MAX_10_EXP__
#define LDBL_MAX_10_EXP __LDBL_MAX_10_EXP__

/* Addition rounds to 0: zero, 1: nearest, 2: +inf, 3: -inf, -1: unknown.  */
/* ??? This is supposed to change with calls to fesetround in <fenv.h>.  */
#undef FLT_ROUNDS
#define FLT_ROUNDS 1
   
#define _FLOAT_H___
#endif  /* __GNUC__ < 4 */
#endif  /* (__GNUC__ < 4  || (__GNUC__ == 4 && __GNUC_MINOR__ < 6)) || (__clang_major__ >=3) */
#endif  /* (defined(__GNUC__) && defined(__GNUC_MINOR__)) || (defined(__clang__) && defined(__clang_major__)) */

#ifndef _MINGW_FLOAT_H_
#define _MINGW_FLOAT_H_

#include <crtdefs.h>

/*
 * Functions and definitions for controlling the FPU.
 */
#ifndef __STRICT_ANSI__

/* TODO: These constants are only valid for x86 machines */

/* Control word masks for unMask */
#define _MCW_DN 0x03000000  /* Denormal control */
#define _MCW_EM 0x0008001F  /* Error masks */
#define _MCW_IC 0x00040000  /* Infinity */
#define _MCW_RC 0x00000300  /* Rounding */
#define _MCW_PC 0x00030000  /* Precision */

/* Number of base-FLT_RADIX digits in the significand, p.  */
#undef FLT_MANT_DIG
#undef DBL_MANT_DIG
#undef LDBL_MANT_DIG
#define FLT_MANT_DIG  __FLT_MANT_DIG__
#define DBL_MANT_DIG  __DBL_MANT_DIG__
#define LDBL_MANT_DIG __LDBL_MANT_DIG__

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/* The floating-point expression evaluation method.
      -1  indeterminate
       0  evaluate all operations and constants just to the range and
    precision of the type
       1  evaluate operations and constants of type float and double
    to the range and precision of the double type, evaluate
    long double operations and constants to the range and
    precision of the long double type
       2  evaluate all operations and constants to the range and
    precision of the long double type

   ??? This ought to change with the setting of the fp control word;
   the value provided by the compiler assumes the widest setting.  */
#undef FLT_EVAL_METHOD
#define FLT_EVAL_METHOD __FLT_EVAL_METHOD__
#endif  /* defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L */

/* Control word values for unNew (use with related unMask above) */
#define _DN_SAVE       0x00000000
#define _DN_FLUSH      0x01000000
#define _EM_INVALID    0x00000010
#define _EM_DENORMAL   0x00080000
#define _EM_ZERODIVIDE 0x00000008
#define _EM_OVERFLOW   0x00000004
#define _EM_UNDERFLOW  0x00000002
#define _EM_INEXACT    0x00000001
#define _IC_AFFINE     0x00040000
#define _IC_PROJECTIVE 0x00000000
#define _RC_CHOP       0x00000300
#define _RC_UP         0x00000200
#define _RC_DOWN       0x00000100
#define _RC_NEAR       0x00000000
#define _PC_24         0x00020000
#define _PC_53         0x00010000
#define _PC_64         0x00000000

/* These are also defined in Mingw math.h, needed to work around
   GCC build issues. */
/* Return values for fpclass. */
#ifndef __MINGW_FPCLASS_DEFINED
#define _FPCLASS_SNAN           0x0001  /* Signaling "Not a Number" */
#define _FPCLASS_QNAN           0x0002  /* Quiet "Not a Number" */
#define _FPCLASS_NINF           0x0004  /* Negative Infinity */
#define _FPCLASS_NN             0x0008  /* Negative Normal */
#define _FPCLASS_ND             0x0010  /* Negative Denormal */
#define _FPCLASS_NZ             0x0020  /* Negative Zero */
#define _FPCLASS_PZ             0x0040  /* Positive Zero */
#define _FPCLASS_PD             0x0080  /* Positive Denormal */
#define _FPCLASS_PN             0x0100  /* Positive Normal */
#define _FPCLASS_PINF           0x0200  /* Positive Infinity */
#define __MINGW_FPCLASS_DEFINED 1
#endif /* __MINGW_FPCLASS_DEFINED */

/* invalid subconditions (_SW_INVALID also set) */
#define _SW_UNEMULATED     0x0040  /* unemulated instruction */
#define _SW_SQRTNEG        0x0080  /* square root of a neg number */
#define _SW_STACKOVERFLOW  0x0200  /* FP stack overflow */
#define _SW_STACKUNDERFLOW 0x0400  /* FP stack underflow */

/*  Floating point error signals and return codes */
#define _FPE_INVALID        0x81
#define _FPE_DENORMAL       0x82
#define _FPE_ZERODIVIDE     0x83
#define _FPE_OVERFLOW       0x84
#define _FPE_UNDERFLOW      0x85
#define _FPE_INEXACT        0x86
#define _FPE_UNEMULATED     0x87
#define _FPE_SQRTNEG        0x88
#define _FPE_STACKOVERFLOW  0x8a
#define _FPE_STACKUNDERFLOW 0x8b
#define _FPE_EXPLICITGEN    0x8c  /* raise( SIGFPE ); */

#define CW_DEFAULT _CW_DEFAULT
#define MCW_PC     _MCW_PC
#define PC_24      _PC_24
#define PC_53      _PC_53
#define PC_64      _PC_64

#ifdef _M_IX86
#define _CW_DEFAULT (_RC_NEAR + _PC_53 + _EM_INVALID + _EM_ZERODIVIDE + _EM_OVERFLOW + _EM_UNDERFLOW + _EM_INEXACT + _EM_DENORMAL)
#elif defined(_M_IA64)
#define _CW_DEFAULT (_RC_NEAR + _PC_64 + _EM_INVALID + _EM_ZERODIVIDE + _EM_OVERFLOW + _EM_UNDERFLOW + _EM_INEXACT + _EM_DENORMAL)
#elif defined(_M_AMD64)
#define _CW_DEFAULT (_RC_NEAR +          _EM_INVALID + _EM_ZERODIVIDE + _EM_OVERFLOW + _EM_UNDERFLOW + _EM_INEXACT + _EM_DENORMAL)
#endif  /* _M_IX86 */

#ifndef RC_INVOKED

#ifdef  __cplusplus
extern "C" {
#endif  /* __cplusplus */

/* Set the FPU control word as cw = (cw & ~_Mask) | (_NewValue & _Mask),
 * i.e. change the bits in _Mask to have the values they have in _NewValue,
 * leaving other bits unchanged. */
  _CRTIMP unsigned int __cdecl _clearfp(void) __MINGW_NOTHROW;  /* Clear the FPU status word */
  _CRTIMP unsigned int __cdecl _controlfp(unsigned int _NewValue, unsigned int _Mask) __MINGW_NOTHROW __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP void         __cdecl _set_controlfp(unsigned int _NewValue, unsigned int _Mask);
  _CRTIMP errno_t      __cdecl _controlfp_s(unsigned int *_CurrentState, unsigned int _NewValue, unsigned int _Mask);  /* We provide emu. */
  _CRTIMP unsigned int __cdecl _statusfp(void) __MINGW_NOTHROW;  /* Report the FPU status word */
/*
   MSVCRT.dll _fpreset initializes the control register to 0x27f,
   the status register to zero and the tag word to 0FFFFh.
   This differs from asm instruction finit/fninit which set control
   word to 0x37f (64 bit mantissa precison rather than 53 bit).
   By default, the mingw version of _fpreset sets fp control as
   per fninit. To use the MSVCRT.dll _fpreset, include CRT_fp8.o when
   building your application.   
*/
  /* Provided in libmingw32. */
  void __cdecl _fpreset(void) __MINGW_NOTHROW;
  void __cdecl  fpreset(void) __MINGW_NOTHROW;

#if defined(_X86_) && !defined(__x86_64) && __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP void __cdecl _statusfp2(unsigned int *_X86_status, unsigned int *_SSE2_status);
#endif  /* defined(_X86_) && !defined(__x86_64) && __MSVCRT_VERSION__ >= 0x0800 */

#define _clear87  _clearfp
#define _status87 _statusfp

  _CRTIMP       unsigned int __cdecl _control87(unsigned int _NewValue, unsigned int _Mask) __MINGW_NOTHROW;
#ifndef NO_OLDNAMES
  /* _CRTIMP */ unsigned int __cdecl control87(unsigned int _NewValue, unsigned int _Mask) __MINGW_NOTHROW;
#endif  /* !NO_OLDNAMES */

#if defined(_X86_) && !defined(__x86_64) && __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP int __cdecl __control87_2(unsigned int _NewValue, unsigned int _Mask, unsigned int *_X86_cw, unsigned int *_Sse2_cw);
#endif  /* defined(_X86_) && !defined(__x86_64) && __MSVCRT_VERSION__ >= 0x0800 */

/* Global 'variable' for the current floating point error code. */
  _CRTIMP int * __cdecl __fpecode(void) __MINGW_NOTHROW;
#define _fpecode (*(__fpecode()))

/*
 * IEEE recommended functions.  MS puts them in float.h
 * but they really belong in math.h.
 */

#ifndef _SIGN_DEFINED
  _CRTIMP double __cdecl _copysign(double _Number, double _Sign) __MINGW_NOTHROW;
  _CRTIMP double __cdecl _chgsign(double _X) __MINGW_NOTHROW;
  _CRTIMP double __cdecl _scalb(double _X, long _Y) __MINGW_NOTHROW;
  _CRTIMP double __cdecl _logb(double _X) __MINGW_NOTHROW;
  _CRTIMP double __cdecl _nextafter(double _X, double _Y) __MINGW_NOTHROW;
  _CRTIMP int    __cdecl _finite(double _X) __MINGW_NOTHROW;
  _CRTIMP int    __cdecl _isnan(double _X) __MINGW_NOTHROW;
  _CRTIMP int    __cdecl _fpclass(double _X) __MINGW_NOTHROW;

#ifdef __x86_64
  _CRTIMP float  __cdecl _scalbf(float _X, long _Y);
#endif  /* __x86_64 */

  extern long double __cdecl _chgsignl(long double _X);  /* Provided in libmingwex. */
#define _copysignl copysignl
#define _SIGN_DEFINED
#endif  /* !_SIGN_DEFINED */

#ifdef  __cplusplus
}
#endif  /* __cplusplus */

#endif  /* !RC_INVOKED */

#endif  /* !__STRICT_ANSI__ */

#endif  /* _MINGW_FLOAT_H_ */
