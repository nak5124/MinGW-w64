/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC_SWPRINTF_INL
#define _INC_SWPRINTF_INL

#include <vadefs.h>

#undef __mingw_ovr
#ifdef __GNUC__
#define __mingw_ovr static __attribute__((__unused__)) __inline__ __cdecl
#elif defined(__cplusplus)
#define __mingw_ovr inline __cdecl
#else  /* __cplusplus */
#define __mingw_ovr static __cdecl
#endif  /* __GNUC__ */

  __mingw_ovr /* __attribute__((__format__(gnu_wprintf, 3, 0))) */ __MINGW_ATTRIB_NONNULL(3)
    int vswprintf(wchar_t *__stream, size_t __count, const wchar_t *__format, __builtin_va_list __local_argv) {
      return vsnwprintf(__stream, __count, __format, __local_argv);
    }
  __mingw_ovr /* __attribute__((__format__(gnu_wprintf, 3, 4))) */ __MINGW_ATTRIB_NONNULL(3)
    int swprintf(wchar_t *__stream, size_t __count, const wchar_t *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = vswprintf(__stream, __count, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  static __inline__ int _swprintf_l(wchar_t *_String, size_t _Count, const wchar_t *_Format, _locale_t _Plocinfo, ...) {
    va_list _Arglist;
    int _Ret;
    _crt_va_start(_Arglist, _Plocinfo);
    _Ret = _vswprintf_c_l(_String, _Count, _Format, _Plocinfo, _Arglist);
    _crt_va_end(_Arglist);
    return _Ret;
  }
/*
  __inline__ int __cdecl _vswprintf_l(wchar_t *_String, size_t _Count, const wchar_t *_Format, _locale_t _Plocinfo, va_list _Ap) {
    return _vswprintf_c_l(_String, _Count, _Format, _Plocinfo, _Ap);
  }
*/

#ifdef __cplusplus

extern "C++" {

  __mingw_ovr /* __attribute__((__format__(gnu_wprintf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
    int vswprintf(wchar_t *__stream, const wchar_t *__format, __builtin_va_list __local_argv) {
#if __USE_MINGW_ANSI_STDIO
      return __mingw_vswprintf(__stream, __format, __local_argv);
#else  /* __USE_MINGW_ANSI_STDIO */
      return _vswprintf(__stream, __format, __local_argv);
#endif  /* __USE_MINGW_ANSI_STDIO */
    }
  __mingw_ovr /* __attribute__((__format__(gnu_wprintf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
    int swprintf (wchar_t *__stream, const wchar_t *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = vswprintf(__stream, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  inline int _swprintf_l(wchar_t *_String, const wchar_t *_Format, _locale_t _Plocinfo, ...) {
    va_list _Arglist;
    _crt_va_start(_Arglist, _Plocinfo);
    int _Ret = __vswprintf_l(_String, _Format, _Plocinfo, _Arglist);
    _crt_va_end(_Arglist);
    return _Ret;
  }
  __mingw_ovr int _vswprintf_l(wchar_t *_String, const wchar_t *_Format, _locale_t _Plocinfo, va_list _Ap) {
    return __vswprintf_l(_String, _Format, _Plocinfo, _Ap);
  }

}

#endif  /* __cplusplus */

#endif  /* _INC_SWPRINTF_INL */
