/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _TIMEB_H_
#define _TIMEB_H_

#include <crtdefs.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif  /* !_WIN32 */

#pragma pack(push, _CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif  /* !_CRTIMP */

#if defined(_USE_32BIT_TIME_T) && defined(_WIN64)
#undef _USE_32BIT_TIME_T
#endif  /* defined(_USE_32BIT_TIME_T) && defined(_WIN64) */

#ifndef _TIME32_T_DEFINED
  typedef long __time32_t;
#define _TIME32_T_DEFINED
#endif  /* !_TIME32_T_DEFINED */

#ifndef _TIME64_T_DEFINED
  __MINGW_EXTENSION typedef __int64 __time64_t;
#define _TIME64_T_DEFINED
#endif  /* !_TIME64_T_DEFINED */

#ifndef _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  typedef __time32_t time_t;
#else  /* _USE_32BIT_TIME_T */
  typedef __time64_t time_t;
#endif  /* _USE_32BIT_TIME_T */
#define _TIME_T_DEFINED
#endif  /* _TIME_T_DEFINED */

#ifndef _TIMEB_DEFINED
  struct __timeb32 {
    __time32_t     time;
    unsigned short millitm;
    short          timezone;
    short          dstflag;
  };

#ifndef NO_OLDNAMES
  struct timeb {
    time_t         time;
    unsigned short millitm;
    short          timezone;
    short          dstflag;
  };
#endif  /* !NO_OLDNAMES */

  struct __timeb64 {
    __time64_t     time;
    unsigned short millitm;
    short          timezone;
    short          dstflag;
  };

#if __MSVCRT_VERSION__ > 0x0700
#ifdef _USE_32BIT_TIME_T
#define _timeb   __timeb32
#define _ftime    _ftime32
#define _ftime_s  _ftime32_s
#else  /* _USE_32BIT_TIME_T */
#define _timeb   __timeb64
#define _ftime    _ftime64
#define _ftime_s  _ftime64_s
#endif  /* _USE_32BIT_TIME_T */
#else  /* __MSVCRT_VERSION__ > 0x0700 */
#ifdef _WIN64
#define _timeb __timeb64
  /* _ftime in MSVCRT.DLL of WIN64 has the same entry point as _ftime64. */
  _CRTIMP void    __cdecl _ftime(struct __timeb64 *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _ftime_s on WIN64 is alias for _ftime64_s. */
  _CRTIMP errno_t __cdecl _ftime_s(struct __timeb64 *_Time);
#else  /* _WIN64 */
#define _timeb __timeb32
  /* _ftime in MSVCRT.DLL of WIN32 has the same entry point as _ftime32. */
  _CRTIMP void    __cdecl _ftime(struct __timeb32 *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _ftime_s on WIN32 is alias for _ftime32_s. */
  _CRTIMP errno_t __cdecl _ftime_s(struct __timeb32 *_Time);
#endif  /* _WIN64 */
#endif  /* __MSVCRT_VERSION__ > 0x0700 */

#define _TIMEB_DEFINED
#endif  /* !_TIMEB_DEFINED */

#include <crtdefs.h>

  _CRTIMP void    __cdecl _ftime32(struct __timeb32 *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _ftime32_s(struct __timeb32 *_Time);
  _CRTIMP void    __cdecl _ftime64(struct __timeb64 *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _ftime64_s(struct __timeb64 *_Time);

#ifndef _TIMESPEC_DEFINED
  struct timespec {
    time_t tv_sec;   /* Seconds */
    long   tv_nsec;  /* Nanoseconds */
  };

  struct itimerspec {
    struct timespec it_interval;  /* Timer period */
    struct timespec it_value;     /* Timer expiration */
  };
#define _TIMESPEC_DEFINED
#endif  /* !_TIMESPEC_DEFINED */

#if !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
  /* Provided in libmingwex.
   * FIXME!: We assume that _USE_32BIT_TIME_T is not defined. */
  void __cdecl ftime(struct timeb *);

#ifndef __CRT__NO_INLINE

#ifndef _STATIC_ASSERT
#ifdef _MSC_VER
#define _STATIC_ASSERT(expr) typedef char __static_assert_t[(expr)]
#else  /* _MSC_VER */
#define _STATIC_ASSERT(expr) extern void __static_assert_t(int [(expr)?1:-1])
#endif  /* _MSC_VER */
#endif  /* !_STATIC_ASSERT */

#ifdef _USE_32BIT_TIME_T
  __CRT_INLINE void __cdecl ftime(struct timeb *_Tmb) {
    _STATIC_ASSERT( sizeof(struct timeb) == sizeof(struct __timeb32) );
    _ftime32((struct __timeb32 *)_Tmb);
  }
#else  /* _USE_32BIT_TIME_T */
  __CRT_INLINE void __cdecl ftime(struct timeb *_Tmb) {
    _STATIC_ASSERT( sizeof(struct timeb) == sizeof(struct __timeb64) );
    _ftime64((struct __timeb64 *)_Tmb);
  }
#endif  /* _USE_32BIT_TIME_T */

#endif  /* !__CRT__NO_INLINE */
#endif  /* !defined (RC_INVOKED) && !defined (NO_OLDNAMES) */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#pragma pack(pop)

#endif  /* _TIMEB_H_ */
