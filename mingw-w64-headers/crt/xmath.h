/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _XMATH
#define _XMATH
#include <ymath.h>
#include <errno.h>
#include <math.h>
#include <stddef.h>

_C_STD_BEGIN

#define _D0    3
#define _D1    2
#define _D2    1
#define _D3    0

#define _DBIAS 0x3fe
#define _DOFF  4

#define _FBIAS 0x7e
#define _FOFF  7
#define _FRND  1

#define _DLONG 0
#define _LBIAS 0x3fe
#define _LOFF  4

#define _V0    0
#define _VBIAS 0x0e
#define _VOFF  10

#define _DFRAC ((unsigned short)((1 << _DOFF) - 1))
#define _DMASK ((unsigned short)(0x7fff & ~_DFRAC))
#define _DMAX  ((unsigned short)((1 << (15 - _DOFF)) - 1))
#define _DSIGN ((unsigned short)0x8000)

#define HUGE_EXP  (int)(_DMAX * 900L / 1000)

#define VHUGE_EXP (int)(_VMAX * 900L / 1000)

#define _FFRAC ((unsigned short)((1 << _FOFF) - 1))
#define _FMASK ((unsigned short)(0x7fff & ~_FFRAC))
#define _FMAX  ((unsigned short)((1 << (15 - _FOFF)) - 1))
#define _FSIGN ((unsigned short)0x8000)

#define FHUGE_EXP (int)(_FMAX * 900L / 1000)

#define _F0 1
#define _F1 0

#define _LFRAC ((unsigned short)(-1))
#define _LMASK ((unsigned short)0x7fff)
#define _LMAX  ((unsigned short)0x7fff)
#define _LSIGN ((unsigned short)0x8000)

#define LHUGE_EXP (int)(_LMAX * 900L / 1000)

#define _L0 3
#define _L1 2
#define _L2 1
#define _L3 0
#define _Lg _L3
#define _L4 xxx
#define _L5 xxx
#define _L6 xxx
#define _L7 xxx

#define DSIGN(x) (((unsigned short *)&(x))[_D0] & _DSIGN)
#define FSIGN(x) (((unsigned short *)&(x))[_F0] & _FSIGN)
#define LSIGN(x) (((unsigned short *)&(x))[_L0] & _LSIGN)

#define _Fg _F1
#define _Dg _D3

#define FL_ERR 0
#define FL_DEC 1
#define FL_HEX 2
#define FL_INF 3
#define FL_NAN 4
#define FL_NEG 8

#define HUGE_RAD 2.73e9
#define SAFE_EXP ((unsigned short)(_DMAX >> 1))

#define FHUGE_RAD 31.8
#define FSAFE_EXP ((unsigned short)(_FMAX >> 1))

#define LHUGE_RAD 2.73e9
#define LSAFE_EXP ((unsigned short)(_LMAX >> 1))

#define FINITE _FINITE
#define INF    _INFCODE
#define NAN    _NANCODE


_C_LIB_DECL

  _CRTIMP int    __cdecl _Stopfx(const char **, char **);
  _CRTIMP int    __cdecl _Stoflt(const char *, const char *, char **, long[], int);
  _CRTIMP int    __cdecl _Stoxflt(const char *, const char *, char **, long[], int);
  _CRTIMP int    __cdecl _WStopfx(const wchar_t **, wchar_t **);
  _CRTIMP int    __cdecl _WStoflt(const wchar_t *, const wchar_t *, wchar_t **, long[], int);
  _CRTIMP int    __cdecl _WStoxflt(const wchar_t *, const wchar_t *, wchar_t **, long[], int);
  _CRTIMP short  __cdecl _Dnorm(unsigned short *);
  _CRTIMP short  __cdecl _Dscale(double *, long);
  _CRTIMP short  __cdecl _Dunscale(short *, double *);
  _CRTIMP double __cdecl _Poly(double, const double *, int);

  extern __declspec(dllimport) _Dconst _Eps, _Rteps;
  extern __declspec(dllimport) double _Xbig;

  _CRTIMP short __cdecl _FDnorm(unsigned short *);
  _CRTIMP short __cdecl _FDscale(float *, long);
  _CRTIMP short __cdecl _FDunscale(short *, float *);

  extern __declspec(dllimport) _Dconst _FEps, _FRteps;
  extern __declspec(dllimport) float _FXbig;

  _CRTIMP short __cdecl _LDnorm(unsigned short *);
  _CRTIMP short __cdecl _LDscale(long double *, long);
  _CRTIMP short __cdecl _LDunscale(short *, long double *);
  _CRTIMP long double __cdecl _LPoly(long double, const long double *, int);

  extern __declspec(dllimport) _Dconst _LEps, _LRteps;
  extern __declspec(dllimport) long double _LXbig;
_END_C_LIB_DECL
_C_STD_END

#endif  /* _XMATH */
