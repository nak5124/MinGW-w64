/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _TIME_H_
#define _TIME_H_

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

#ifndef _WCHAR_T_DEFINED
  typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif  /* !_WCHAR_T_DEFINED */

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
#endif  /* !_TIME_T_DEFINED */

#ifndef _CLOCK_T_DEFINED
  typedef long clock_t;
#define _CLOCK_T_DEFINED
#endif  /* !_CLOCK_T_DEFINED */

#ifndef _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
  __MINGW_EXTENSION typedef unsigned __int64 size_t;
#else  /* _WIN64 */
                    typedef unsigned int     size_t;
#endif  /* _WIN64 */
#define _SIZE_T_DEFINED
#endif  /* !_SIZE_T_DEFINED */

#ifndef _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
  __MINGW_EXTENSION typedef __int64 ssize_t;
#else  /* _WIN64 */
                    typedef int     ssize_t;
#endif  /* _WIN64 */
#define _SSIZE_T_DEFINED
#endif  /* !_SSIZE_T_DEFINED */

#ifndef NULL
#ifdef __cplusplus
#ifndef _WIN64
#define NULL 0
#else  /* !_WIN64 */
#define NULL 0LL
#endif  /* !_WIN64 */
#else  /* __cplusplus */
#define NULL ((void *)0)
#endif  /* __cplusplus */
#endif  /* !NULL */

#ifndef _TM_DEFINED
  struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
  };
#define _TM_DEFINED
#endif  /* !_TM_DEFINED */

#define CLOCKS_PER_SEC 1000

#if __MSVCRT_VERSION__ >= 0x0800 || defined(_X86_)
  _CRTIMP int *   __cdecl __p__daylight(void);
  _CRTIMP long *  __cdecl __p__dstbias(void);
  _CRTIMP long *  __cdecl __p__timezone(void);
  _CRTIMP char ** __cdecl __p__tzname(void);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 || defined(_X86_) */

  _CRTIMP int *   __cdecl __daylight(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#define _daylight (*__daylight())
  _CRTIMP long *  __cdecl __dstbias(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#define _dstbias  (*__dstbias())
#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP long *  __cdecl __timezone(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
# define _timezone (*__timezone())
  _CRTIMP char ** __cdecl __tzname(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
# define _tzname   (__tzname())
#else  /* __MSVCRT_VERSION__ >= 0x0800 */
  __MINGW_IMPORT long   _timezone;
  __MINGW_IMPORT char * _tzname[2];
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */

  _CRTIMP       errno_t     __cdecl _get_daylight(int *_Daylight);
  _CRTIMP       errno_t     __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP       errno_t     __cdecl _get_timezone(long *_Timezone);
  _CRTIMP       errno_t     __cdecl _get_tzname(size_t *_ReturnValue, char *_Buffer, size_t _SizeInBytes, int _Index);

  /* _CRTIMP */ char *      __cdecl  asctime(const struct tm *_Tm) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ errno_t     __cdecl  asctime_s(char *_Buf, size_t _SizeInWords, const struct tm *_Tm);

  _CRTIMP       char *      __cdecl _ctime32(const __time32_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t     __cdecl _ctime32_s(char *_Buf, size_t _SizeInBytes, const __time32_t *_Time);

  /* _CRTIMP */ clock_t     __cdecl  clock(void);
  _CRTIMP       double      __cdecl _difftime32(__time32_t _Time1, __time32_t _Time2);

  _CRTIMP       struct tm * __cdecl _gmtime32(const __time32_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t     __cdecl _gmtime32_s(struct tm *_Tm, const __time32_t *_Time);

  _CRTIMP       struct tm * __cdecl _localtime32(const __time32_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t     __cdecl _localtime32_s(struct tm *_Tm, const __time32_t *_Time);

  /* _CRTIMP */ size_t      __cdecl  strftime(char * __restrict__ _Buf, size_t _SizeInBytes, const char * __restrict__ _Format, const struct tm * __restrict__ _Tm);
  _CRTIMP       size_t      __cdecl _strftime_l(char * __restrict__ _Buf, size_t _Max_size, const char * __restrict__ _Format, const struct tm * __restrict__ _Tm, _locale_t _Locale);

  _CRTIMP       errno_t     __cdecl _strdate_s(char *_Buf, size_t _SizeInBytes);
  _CRTIMP       char *      __cdecl _strdate(char *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  _CRTIMP       errno_t     __cdecl _strtime_s(char *_Buf, size_t _SizeInBytes);
  _CRTIMP       char *      __cdecl _strtime(char *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  _CRTIMP       __time32_t  __cdecl _time32(__time32_t *_Time);
  _CRTIMP       __time32_t  __cdecl _mktime32(struct tm *_Tm);
  _CRTIMP       __time32_t  __cdecl _mkgmtime32(struct tm *_Tm);

#ifdef __GNUC__
  /* _CRTIMP */ void        __cdecl  tzset(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif  /* __GNUC__ */
  _CRTIMP       void        __cdecl _tzset(void);

  _CRTIMP       double      __cdecl _difftime64(__time64_t _Time1, __time64_t _Time2);
  _CRTIMP       char *      __cdecl _ctime64(const __time64_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t     __cdecl _ctime64_s(char *_Buf, size_t _SizeInBytes, const __time64_t *_Time);

  _CRTIMP       struct tm * __cdecl _gmtime64(const __time64_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t     __cdecl _gmtime64_s(struct tm *_Tm, const __time64_t *_Time);

  _CRTIMP       struct tm * __cdecl _localtime64(const __time64_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t     __cdecl _localtime64_s(struct tm *_Tm, const __time64_t *_Time);

  _CRTIMP       __time64_t  __cdecl _mktime64(struct tm *_Tm);
  _CRTIMP       __time64_t  __cdecl _mkgmtime64(struct tm *_Tm);
  _CRTIMP       __time64_t  __cdecl _time64(__time64_t *_Time);

                unsigned    __cdecl _getsystime(struct tm *_Tm) __MINGW_ATTRIB_DEPRECATED;
                unsigned    __cdecl _setsystime(struct tm *_Tm, unsigned _MilliSec) __MINGW_ATTRIB_DEPRECATED;

#ifndef _WTIME_DEFINED

  _CRTIMP       wchar_t * __cdecl _wasctime(const struct tm *_Tm) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t   __cdecl _wasctime_s(wchar_t *_Buf, size_t _SizeInWords, const struct tm *_Tm);

  _CRTIMP       wchar_t * __cdecl _wctime32(const __time32_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t   __cdecl _wctime32_s(wchar_t *_Buf, size_t _SizeInWords, const __time32_t *_Time);

  /* _CRTIMP */ size_t    __cdecl  wcsftime(wchar_t * __restrict__ _Buf, size_t _SizeInWords, const wchar_t * __restrict__ _Format, const struct tm * __restrict__ _Tm);
  _CRTIMP       size_t    __cdecl _wcsftime_l(wchar_t * __restrict__ _Buf, size_t _SizeInWords, const wchar_t * __restrict__ _Format, const struct tm * __restrict__ _Tm, _locale_t _Locale);

  _CRTIMP       errno_t   __cdecl _wstrdate_s(wchar_t *_Buf, size_t _SizeInWords);
  _CRTIMP       wchar_t * __cdecl _wstrdate(wchar_t *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  _CRTIMP       errno_t   __cdecl _wstrtime_s(wchar_t *_Buf, size_t _SizeInWords);
  _CRTIMP       wchar_t * __cdecl _wstrtime(wchar_t *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  _CRTIMP       wchar_t * __cdecl _wctime64(const __time64_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t   __cdecl _wctime64_s(wchar_t *_Buf, size_t _SizeInWords, const __time64_t *_Time);

#if !defined(RC_INVOKED) && !defined(_INC_WTIME_INL)
  _CRTIMP       wchar_t * __cdecl _wctime(const time_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t   __cdecl _wctime_s(wchar_t *_Buffer, size_t _SizeInWords, const time_t *_Time);
#ifndef __CRT__NO_INLINE
#ifdef _USE_32BIT_TIME_T
  __CRT_INLINE wchar_t * __cdecl _wctime(const time_t *_Time) {
    return _wctime32(_Time);
  }
  __CRT_INLINE errno_t   __cdecl _wctime_s(wchar_t *_Buffer, size_t _SizeInWords, const time_t *_Time) {
    return _wctime32_s(_Buffer, _SizeInWords, _Time);
  }
#else  /* _USE_32BIT_TIME_T */
  __CRT_INLINE wchar_t * __cdecl _wctime(const time_t *_Time) {
    return _wctime64(_Time);
  }
  __CRT_INLINE errno_t   __cdecl _wctime_s(wchar_t *_Buffer, size_t _SizeInWords, const time_t *_Time) {
    return _wctime64_s(_Buffer, _SizeInWords, _Time);
  }
#endif  /* _USE_32BIT_TIME_T */
#endif  /* !__CRT__NO_INLINE */
#define _INC_WTIME_INL
#endif  /* !defined(RC_INVOKED) && !defined(_INC_WTIME_INL) */

#define _WTIME_DEFINED
#endif  /* !_WTIME_DEFINED */

#ifndef RC_INVOKED
  /* _CRTIMP */ double      __cdecl  difftime(time_t _Time1, time_t _Time2);
  /* _CRTIMP */ char *      __cdecl  ctime(const time_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ errno_t     __cdecl  ctime_s(char *_Buf, size_t _SizeInBytes, const time_t *_Time);
  /* _CRTIMP */ struct tm * __cdecl  gmtime(const time_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ errno_t     __cdecl  gmtime_s(struct tm *_Tm, const time_t *_Time);
  /* _CRTIMP */ struct tm * __cdecl  localtime(const time_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ errno_t     __cdecl  localtime_s(struct tm *_Tm, const time_t *_Time);
  /* _CRTIMP */ time_t      __cdecl  mktime(struct tm *_Tm);
  _CRTIMP       time_t      __cdecl _mkgmtime(struct tm *_Tm);
  /* _CRTIMP */ time_t      __cdecl  time(time_t *_Time);

#ifndef __CRT__NO_INLINE
#ifdef _USE_32BIT_TIME_T
  __CRT_INLINE double __cdecl difftime(time_t _Time1,time_t _Time2) {
    return _difftime32(_Time1, _Time2);
  }
  __CRT_INLINE char * __cdecl ctime(const time_t *_Time) {
    return _ctime32(_Time);
  }
  __CRT_INLINE errno_t __cdecl ctime_s(char *_Buf, size_t _SizeInBytes, const time_t *_Time) {
    return _ctime32_s(_Buf, _SizeInBytes, _Time);
  }
  __CRT_INLINE struct tm * __cdecl gmtime(const time_t *_Time) {
    return _gmtime32(_Time);
  }
  __CRT_INLINE errno_t __cdecl gmtime_s(struct tm *_Tm, const time_t *_Time) {
    return _gmtime32_s(_Tm, _Time);
  }
  __CRT_INLINE struct tm * __cdecl localtime(const time_t *_Time) {
    return _localtime32(_Time);
  }
  __CRT_INLINE errno_t __cdecl localtime_s(struct tm *_Tm, const time_t *_Time) {
    return _localtime32_s(_Tm, _Time);
  }
  __CRT_INLINE time_t __cdecl mktime(struct tm *_Tm) {
    return _mktime32(_Tm);
  }
  __CRT_INLINE time_t __cdecl _mkgmtime(struct tm *_Tm) {
    return _mkgmtime32(_Tm);
  }
  __CRT_INLINE time_t __cdecl time(time_t *_Time) {
    return _time32(_Time);
  }
#else  /* _USE_32BIT_TIME_T */
  __CRT_INLINE double __cdecl difftime(time_t _Time1,time_t _Time2) {
    return _difftime64(_Time1, _Time2);
  }
  __CRT_INLINE char * __cdecl ctime(const time_t *_Time) {
    return _ctime64(_Time);
  }
  __CRT_INLINE errno_t __cdecl ctime_s(char *_Buf, size_t _SizeInBytes, const time_t *_Time) {
    return _ctime64_s(_Buf, _SizeInBytes, _Time);
  }
  __CRT_INLINE struct tm * __cdecl gmtime(const time_t *_Time) {
    return _gmtime64(_Time);
  }
  __CRT_INLINE errno_t __cdecl gmtime_s(struct tm *_Tm, const time_t *_Time) {
    return _gmtime64_s(_Tm, _Time);
  }
  __CRT_INLINE struct tm * __cdecl localtime(const time_t *_Time) {
    return _localtime64(_Time);
  }
  __CRT_INLINE errno_t __cdecl localtime_s(struct tm *_Tm, const time_t *_Time) {
    return _localtime64_s(_Tm, _Time);
  }
  __CRT_INLINE time_t __cdecl mktime(struct tm *_Tm) {
    return _mktime64(_Tm);
  }
  __CRT_INLINE time_t __cdecl _mkgmtime(struct tm *_Tm) {
    return _mkgmtime64(_Tm);
  }
  __CRT_INLINE time_t __cdecl time(time_t *_Time) {
    return _time64(_Time);
  }
#endif  /* _USE_32BIT_TIME_T */
#endif  /* !__CRT__NO_INLINE */

#endif  /* !RC_INVOKED */

#if !defined(NO_OLDNAMES) || defined(_POSIX)

#define CLK_TCK CLOCKS_PER_SEC

  _CRTIMP extern int   daylight;
  _CRTIMP extern long  timezone;
  _CRTIMP extern char *tzname[2];

  /* _CRTIMP */ void __cdecl tzset(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif  /* !defined(NO_OLDNAMES) || defined(_POSIX) */

#include <_timeval.h>

#ifndef _TIMEZONE_DEFINED  /* also in sys/time.h */
  struct timezone {
    int tz_minuteswest;
    int tz_dsttime;
  };

  /* Provided in libmingwex. */
  extern int __cdecl mingw_gettimeofday(struct timeval *p, struct timezone *z);
#define _TIMEZONE_DEFINED
#endif  /* _TIMEZONE_DEFINED */

#if defined(_POSIX_C_SOURCE) && !defined(_POSIX_THREAD_SAFE_FUNCTIONS)
#define _POSIX_THREAD_SAFE_FUNCTIONS 200112L
#endif  /* defined(_POSIX_C_SOURCE) && !defined(_POSIX_THREAD_SAFE_FUNCTIONS) */

#ifdef _POSIX_THREAD_SAFE_FUNCTIONS
  char *      __cdecl asctime_r(const struct tm *_Tm, char * _Str);
  char *      __cdecl ctime_r(const time_t *_Time, char * _Str);
  struct tm * __cdecl gmtime_r(const time_t *_Time, struct tm *_Tm);
  struct tm * __cdecl localtime_r(const time_t *_Time, struct tm *_Tm);

#ifndef __CRT__NO_INLINE
  __forceinline char * __cdecl asctime_r(const struct tm *_Tm, char *_Str) {
    return asctime_s(_Str, 0x7fffffff, _Tm) ? NULL : _Str;
  }
  __forceinline char * __cdecl ctime_r(const time_t *_Time, char *_Str) {
    return ctime_s(_Str, 0x7fffffff, _Time) ? NULL : _Str;
  }
  __forceinline struct tm * __cdecl gmtime_r(const time_t *_Time, struct tm *_Tm) {
    return gmtime_s(_Tm, _Time) ? NULL : _Tm;
  }
  __forceinline struct tm * __cdecl localtime_r(const time_t *_Time, struct tm *_Tm) {
    return localtime_s(_Tm, _Time) ? NULL : _Tm;
  }
#endif  /* !__CRT__NO_INLINE */
#endif  /* _POSIX_THREAD_SAFE_FUNCTIONS */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#pragma pack(pop)

/* Adding timespec definition.  */
#include <sys/timeb.h>

/* POSIX 2008 says clock_gettime and timespec are defined in time.h header,
   but other systems - like Linux, Solaris, etc - tend to declare such
   recent extensions only if the following guards are met.  */
#if !defined(IN_WINPTHREAD) && ((!defined(_STRICT_STDC) && !defined(__XOPEN_OR_POSIX)) || (_POSIX_C_SOURCE > 2) || defined(__EXTENSIONS__))
#include <pthread_time.h>
#endif  /* !defined(IN_WINPTHREAD) && ... */

#endif  /* _TIME_H_ */
