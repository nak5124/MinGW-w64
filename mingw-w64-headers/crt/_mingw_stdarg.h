/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC_STDARG
#define _INC_STDARG

#ifndef _WIN32
#error Only Win32 target is supported!
#endif  /* !_WIN32 */

#include <vadefs.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef va_start
#define va_start _crt_va_start
#endif  /* !va_start */

#ifndef va_arg
#define va_arg _crt_va_arg
#endif  /* !va_arg */

#ifndef va_end
#define va_end _crt_va_end
#endif  /* !va_end */

#ifndef __va_copy
#define __va_copy _crt_va_copy
#endif  /* !__va_copy */

#if __MSVCRT_VERSION__ == 0x1200
  _CRTIMP void __cdecl _vacopy(va_list *, va_list);
#endif /* __MSVCRT_VERSION__ >= 0x1200 */

#if !defined(va_copy) && (!defined(__STRICT_ANSI__) || __STDC_VERSION__ + 0 >= 199900L || defined(__GXX_EXPERIMENTAL_CXX0X__))
#define va_copy _crt_va_copy
#endif  /* !defined(va_copy) && (!defined(__STRICT_ANSI__) || ...) */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* _INC_STDARG */
