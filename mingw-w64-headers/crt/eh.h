/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <crtdefs.h>

#ifndef _EH_H_
#define _EH_H_

#ifndef RC_INVOKED

#pragma pack(push, _CRT_PACKING)

#ifndef __cplusplus
#error eh.h is only for C++!
#endif  /* __cplusplus */

  typedef void (__cdecl *terminate_function)();
  typedef void (__cdecl *terminate_handler)();
  typedef void (__cdecl *unexpected_function)();
  typedef void (__cdecl *unexpected_handler)();

  struct _EXCEPTION_POINTERS;
  typedef void (__cdecl *_se_translator_function)(unsigned int, struct _EXCEPTION_POINTERS *);

  _CRTIMP void __cdecl terminate(void) __MINGW_ATTRIB_NORETURN;
  _CRTIMP void __cdecl unexpected(void) __MINGW_ATTRIB_NORETURN;

#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP int  __cdecl _is_exception_typeof(const std::type_info &_Type, struct _EXCEPTION_POINTERS *_ExceptionPtr);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */

             _CRTIMP terminate_function  __cdecl  set_terminate(terminate_function _NewPtFunc);
#if __MSVCRT_VERSION__ >= 0x0800
  extern "C" _CRTIMP terminate_function  __cdecl _get_terminate(void);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */
             _CRTIMP unexpected_function __cdecl  set_unexpected(unexpected_function _NewPtFunc);
#if __MSVCRT_VERSION__ >= 0x0800
  extern "C" _CRTIMP unexpected_function __cdecl _get_unexpected(void);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */

  _CRTIMP _se_translator_function __cdecl  _set_se_translator(_se_translator_function _NewPtFunc);
  _CRTIMP bool                    __cdecl __uncaught_exception();

#pragma pack(pop)

#endif  /* !RC_INVOKED */

#endif  /* _EH_H_ */
