/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_UTIME
#define _INC_UTIME

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

#ifndef _UTIMBUF_DEFINED

  struct _utimbuf {
    time_t actime;
    time_t modtime;
  };

  struct __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

  struct __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };

#ifndef NO_OLDNAMES
  struct utimbuf {
    time_t actime;
    time_t modtime;
  };

  struct utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#endif  /* !NO_OLDNAMES */

#define _UTIMBUF_DEFINED
#endif  /* !_UTIMBUF_DEFINED */

  _CRTIMP int __cdecl _utime32(const char *_Filename, struct __utimbuf32 *_Time);
  _CRTIMP int __cdecl _futime32(int _FileDes, struct __utimbuf32 *_Time);
  _CRTIMP int __cdecl _wutime32(const wchar_t *_Filename, struct __utimbuf32 *_Time);
  _CRTIMP int __cdecl _utime64(const char *_Filename, struct __utimbuf64 *_Time);
  _CRTIMP int __cdecl _futime64(int _FileDes, struct __utimbuf64 *_Time);
  _CRTIMP int __cdecl _wutime64(const wchar_t *_Filename, struct __utimbuf64 *_Time);

#ifndef RC_INVOKED
  _CRTIMP int __cdecl _utime(const char *_Filename, struct _utimbuf *_Time);
  _CRTIMP int __cdecl _futime(int _FileDes, struct _utimbuf *_Time);
  _CRTIMP int __cdecl _wutime(const wchar_t *_Filename, struct _utimbuf *_Time);

#ifndef __CRT__NO_INLINE

#ifndef _STATIC_ASSERT
#define _STATIC_ASSERT(expr) extern void __static_assert_t(int [(expr)?1:-1])
#endif  /* !_STATIC_ASSERT */

#ifdef _USE_32BIT_TIME_T
  __CRT_INLINE int __cdecl _utime(const char *_Filename, struct _utimbuf *_Time) {
    _STATIC_ASSERT( sizeof(struct _utimbuf) == sizeof(struct __utimbuf32) );
    return _utime32(_Filename, (struct __utimbuf32 *)_Time);
  }
  __CRT_INLINE int __cdecl _futime(int _FileDes, struct _utimbuf *_Time) {
    _STATIC_ASSERT( sizeof(struct _utimbuf) == sizeof(struct __utimbuf32) );
    return _futime32(_FileDes, (struct __utimbuf32 *)_Time);
  }
  __CRT_INLINE int __cdecl _wutime(const wchar_t *_Filename, struct _utimbuf *_Time) {
    _STATIC_ASSERT( sizeof(struct _utimbuf) == sizeof(struct __utimbuf32) );
    return _wutime32(_Filename, (struct __utimbuf32 *)_Time);
  }
#else  /* _USE_32BIT_TIME_T */
  __CRT_INLINE int __cdecl _utime(const char *_Filename, struct _utimbuf *_Time) {
    _STATIC_ASSERT( sizeof(struct _utimbuf) == sizeof(struct __utimbuf64) );
    return _utime64(_Filename, (struct __utimbuf64 *)_Time);
  }
  __CRT_INLINE int __cdecl _futime(int _FileDes, struct _utimbuf *_Time) {
    _STATIC_ASSERT( sizeof(struct _utimbuf) == sizeof(struct __utimbuf64) );
    return _futime64(_FileDes, (struct __utimbuf64 *)_Time);
  }
  __CRT_INLINE int __cdecl _wutime(const wchar_t *_Filename, struct _utimbuf *_Time) {
    _STATIC_ASSERT( sizeof(struct _utimbuf) == sizeof(struct __utimbuf64) );
    return _wutime64(_Filename, (struct __utimbuf64 *)_Time);
  }
#endif  /* _USE_32BIT_TIME_T */

#endif  /* !__CRT__NO_INLINE */

#ifndef NO_OLDNAMES

  /* utime in MSVCRT.DLL has the same entry point as _utime. */
  /* _CRTIMP */ int __cdecl utime(const char *_Filename, struct utimbuf * _Time);


#ifndef __CRT__NO_INLINE

#ifdef _USE_32BIT_TIME_T
  __CRT_INLINE int __cdecl utime(const char *_Filename, struct utimbuf *_Time) {
    _STATIC_ASSERT( sizeof(struct utimbuf) == sizeof(struct __utimbuf32) );
    return _utime32(_Filename, (struct __utimbuf32 *)_Time);
  }
#else  /* _USE_32BIT_TIME_T */
  __CRT_INLINE int __cdecl utime(const char *_Filename, struct utimbuf *_Time) {
    _STATIC_ASSERT( sizeof(struct utimbuf) == sizeof(struct __utimbuf64) );
    return _utime64(_Filename, (struct __utimbuf64 *)_Time);
  }
#endif  /* _USE_32BIT_TIME_T */

#endif  /* !__CRT__NO_INLINE */
#endif  /* !NO_OLDNAMES */

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#pragma pack(pop)

#endif  /* _INC_UTIME */
