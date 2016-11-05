/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_VADEFS
#define _INC_VADEFS

#include <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif  /* !_WIN32 */

#ifndef __WIDL__
#undef _CRT_PACKING
#define _CRT_PACKING 8
#pragma pack(push, _CRT_PACKING)
#endif  /* !__WIDL__ */

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef _UINTPTR_T_DEFINED
#ifndef __uintptr_t_defined
#undef uintptr_t
#ifdef _WIN64
  __MINGW_EXTENSION typedef unsigned __int64 uintptr_t;
#else  /* _WIN64 */
  typedef unsigned int uintptr_t;
#endif  /* _WIN64 */
#define __uintptr_t_defined
#endif  /* !__uintptr_t_defined */
#define _UINTPTR_T_DEFINED
#endif  /* !_UINTPTR_T_DEFINED */

#ifdef __GNUC__
#ifndef __GNUC_VA_LIST
  typedef __builtin_va_list __gnuc_va_list;
#define __GNUC_VA_LIST
#endif  /* !__GNUC_VA_LIST */
#endif  /* __GNUC__ */

#ifndef _VA_LIST_DEFINED  /* if stdargs.h didn't define it */
#ifdef __GNUC__
  typedef __gnuc_va_list va_list;
#elif defined(_MSC_VER)
  typedef char *         va_list;
#elif !defined(__WIDL__)
#error VARARGS not implemented for this compiler
#endif  /* __GNUC__ */
#define _VA_LIST_DEFINED
#endif  /* !_VA_LIST_DEFINED */

#ifdef __cplusplus
#define _ADDRESSOF(v) (&reinterpret_cast<const char &>(v))
#else  /* __cplusplus */
#define _ADDRESSOF(v) (&(v))
#endif  /* __cplusplus */

#ifdef __GNUC__
/* Use GCC builtins */

#define _crt_va_start(v, l) __builtin_va_start(v, l)
#define _crt_va_arg(v, l)   __builtin_va_arg(v, l)
#define _crt_va_end(v)      __builtin_va_end(v)
#define _crt_va_copy(d, s)  __builtin_va_copy(d, s)

#elif defined(_MSC_VER)
/* MSVC specific */

#ifdef _M_IA64
#define _VA_ALIGN        8
#define _SLOTSIZEOF(t)   ((sizeof(t) + _VA_ALIGN - 1) & ~(_VA_ALIGN - 1))
#define _VA_STRUCT_ALIGN 16
#define _ALIGNOF(ap)     ((((ap) + _VA_STRUCT_ALIGN - 1) & ~(_VA_STRUCT_ALIGN - 1)) - (ap))
#define _APALIGN(t, ap)  (__alignof(t) > 8 ? _ALIGNOF((uintptr_t) ap) : 0)
#else  /* _M_IA64 */
#define _SLOTSIZEOF(t)   (sizeof(t))
#define _APALIGN(t, ap)  (__alignof(t))
#endif  /* _M_IA64 */

#ifdef _M_IX86

#define _INTSIZEOF(n)       ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define _crt_va_start(v, l) ((v) = (va_list)_ADDRESSOF(l) + _INTSIZEOF(l))
#define _crt_va_arg(v, l)   (*(l *)(((v) += _INTSIZEOF(l)) - _INTSIZEOF(l)))
#define _crt_va_end(v)      ((v) = (va_list)0)
#define _crt_va_copy(d, s)  ((d) = (s))

#elif defined(_M_AMD64)

#define _PTRSIZEOF(n) ((sizeof(n) + sizeof(void*) - 1) & ~(sizeof(void*) - 1))
#define _ISSTRUCT(t)  ((sizeof(t) > sizeof(void*)) || (sizeof(t) & (sizeof(t) - 1)) != 0)

#define _crt_va_start(v, l) ((v) = (va_list)_ADDRESSOF(l) + _PTRSIZEOF(l))
#define _crt_va_arg(v, t)   _ISSTRUCT(t) ? (**(t**)(((v) += sizeof(void*)) - sizeof(void*))) \
                                         : ( *(t *)(((v) += sizeof(void*)) - sizeof(void*)))
#define _crt_va_end(v)      ((v) = (va_list)0)
#define _crt_va_copy(d, s)  (d) = (s))

#else  /* defined(_M_AMD64) */

#define _INTSIZEOF(n)       ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define _crt_va_start(v, l) ((v) = (va_list)_ADDRESSOF(l) + _INTSIZEOF(l))
#define _crt_va_arg(v, l)   (*(l *)(((v) += _INTSIZEOF(l)) - _INTSIZEOF(l)))
#define _crt_va_end(v)      ((v) = (va_list)0)
#define _crt_va_copy(d, s)  ((d) = (s))

#endif  /* _M_IX86 */

#endif  /* __GNUC__ */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#ifndef __WIDL__
#pragma pack(pop)
#endif  /* !__WIDL__ */

#endif  /* _INC_VADEFS */
