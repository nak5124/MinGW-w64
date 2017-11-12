/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/* According to C99 standard (section 7.2) the assert
   macro shall be redefined each time assert.h gets
   included depending on the status of NDEBUG macro.  */
#undef assert

#ifndef __ASSERT_H_
#define __ASSERT_H_

#include <crtdefs.h>
#ifdef __cplusplus
#include <stdlib.h>
#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef _CRT_TERMINATE_DEFINED
#pragma push_macro("exit")
#undef exit
  /* _CRTIMP */ void __cdecl exit(int _Code) __MINGW_NOTHROW __MINGW_ATTRIB_NORETURN;
#pragma pop_macro("exit")
  /* _CRTIMP */ void __cdecl _exit(int _Code) __MINGW_NOTHROW __MINGW_ATTRIB_NORETURN;

#if __MSVCRT_VERSION__ >= 0x1400
  _CRTIMP void __cdecl _Exit(int _Code) __MINGW_ATTRIB_NORETURN;
#else  /* __MSVCRT_VERSION__ >= 0x1400 */
/* Provided in libmingwex.
 * C99 function name */
  void __cdecl _Exit(int _Code) __MINGW_ATTRIB_NORETURN;
#ifndef __CRT__NO_INLINE
  __CRT_INLINE void __cdecl __MINGW_ATTRIB_NORETURN _Exit(int status) {
    _exit(status);
  }
#endif  /* !__CRT__NO_INLINE */
#endif  /* __MSVCRT_VERSION__ >= 0x1400 */

#pragma push_macro("abort")
#undef abort
  /* _CRTIMP */ void __cdecl abort(void) __MINGW_ATTRIB_NORETURN;
#pragma pop_macro("abort")
#define _CRT_TERMINATE_DEFINED
#endif  /* !_CRT_TERMINATE_DEFINED */

  /* Provided in libmingwex. */
  extern void __cdecl _assert(const char *_Message, const char *_File, unsigned _Line);
  extern void __cdecl _wassert(const wchar_t *_Message, const wchar_t *_File, unsigned _Line);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __ASSERT_H_ */

#if (defined(_ISOC11_SOURCE) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112L)) && !defined (__cplusplus)
/* Static assertion.  Requires support in the compiler.  */
#undef static_assert
#define static_assert _Static_assert
#endif  /* (defined(_ISOC11_SOURCE) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112L)) && !defined (__cplusplus) */

#ifdef NDEBUG
#define assert(_Expression) ((void)0)
#else  /* NDEBUG */
#if defined(_UNICODE) || defined(UNICODE)
#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression), _CRT_WIDE(__FILE__), __LINE__), 0))
#else  /* defined(_UNICODE) || defined(UNICODE) */
#define assert(_Expression) (void)((!!(_Expression)) || (_assert(#_Expression, __FILE__, __LINE__), 0))
#endif  /* defined(_UNICODE) || defined(UNICODE) */
#endif  /* NDEBUG */
