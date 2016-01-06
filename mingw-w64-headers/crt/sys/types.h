/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_TYPES
#define _INC_TYPES

#include <crtdefs.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif  /*!_WIN32 */

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
#endif  /* !_TIME_T_DEFINED */

#ifndef _TIMESPEC_DEFINED
  struct timespec {
    time_t  tv_sec;   /* Seconds */
    long    tv_nsec;  /* Nanoseconds */
  };

  struct itimerspec {
    struct timespec  it_interval;  /* Timer period */
    struct timespec  it_value;     /* Timer expiration */
  };
#define _TIMESPEC_DEFINED
#endif  /* !_TIMESPEC_DEFINED */

#ifndef _INO_T_DEFINED
  typedef unsigned short _ino_t;
#ifndef NO_OLDNAMES
  typedef unsigned short ino_t;
#endif  /* !NO_OLDNAMES */
#define _INO_T_DEFINED
#endif  /* !_INO_T_DEFINED */

#ifndef _DEV_T_DEFINED
  typedef unsigned int _dev_t;
#ifndef NO_OLDNAMES
  typedef unsigned int dev_t;
#endif  /* !NO_OLDNAMES */
#define _DEV_T_DEFINED
#endif  /* !_DEV_T_DEFINED */

#ifndef _OFF_T_DEFINED
#ifndef _OFF_T_
  typedef long _off_t;
#if !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long off32_t;
#endif  /* !defined(NO_OLDNAMES) || defined(_POSIX) */
#define _OFF_T_
#endif  /* _OFF_T_ */

#ifndef _OFF64_T_DEFINED
  __MINGW_EXTENSION typedef long long _off64_t;
#if !defined(NO_OLDNAMES) || defined(_POSIX)
  __MINGW_EXTENSION typedef long long off64_t;
#endif  /* !defined(NO_OLDNAMES) || defined(_POSIX) */
#define _OFF64_T_DEFINED
#endif  /* _OFF64_T_DEFINED */

#ifndef _FILE_OFFSET_BITS_SET_OFFT
#if !defined(NO_OLDNAMES) || defined(_POSIX)
#if defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64)
  typedef off64_t off_t;
#else  /* defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64) */
  typedef off32_t off_t;
#endif  /* defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64) */
#endif  /* #if !defined(NO_OLDNAMES) || defined(_POSIX) */
#define _FILE_OFFSET_BITS_SET_OFFT
#endif  /* _FILE_OFFSET_BITS_SET_OFFT */

#define _OFF_T_DEFINED
#endif  /* !_OFF_T_DEFINED */

#ifndef _PID_T_
#ifndef _WIN64
  typedef int _pid_t;
#else  /* !_WIN64 */
  __MINGW_EXTENSION typedef __int64 _pid_t;
#endif  /* !_WIN64 */

#ifndef NO_OLDNAMES
#undef pid_t
  typedef _pid_t pid_t;
#endif  /* !NO_OLDNAMES */
#define _PID_T_
#endif  /* !_PID_T_ */

#ifndef _MODE_T_
  typedef unsigned short _mode_t;
#ifndef NO_OLDNAMES
  typedef _mode_t mode_t;
#endif  /* !NO_OLDNAMES */
#define _MODE_T_
#endif  /* !_MODE_T_ */

  typedef unsigned int useconds_t;

#ifndef _SIGSET_T_
#ifndef _WIN64
  typedef unsigned long _sigset_t;
#else  /* !_WIN64 */
  __MINGW_EXTENSION typedef unsigned long long _sigset_t;
#endif  /* !_WIN64 */

#ifndef _POSIX
  typedef _sigset_t sigset_t;
#endif  /* !_POSIX */
#define _SIGSET_T_
#endif  /* !_SIGSET_T_ */

#endif  /* _INC_TYPES */
