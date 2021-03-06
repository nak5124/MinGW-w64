/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC__MINGW_H
#define _INC__MINGW_H

#define MINGW_HAS_SECURE_API 1

#include "_mingw_mac.h"

/* Include _cygwin.h if we're building a Cygwin application. */
#ifdef __CYGWIN__
#include "_cygwin.h"
#endif  /* __CYGWIN__ */

/* Target specific macro replacement for type "long".  In the Windows API,
   the type long is always 32 bit, even if the target is 64 bit (LLP64).
   On 64 bit Cygwin, the type long is 64 bit (LP64).  So, to get the right
   sized definitions and declarations, all usage of type long in the Windows
   headers have to be replaced by the below defined macro __LONG32. */
#ifndef __LP64__
#define __LONG32 long
#else  /* !__LP64__ */
#define __LONG32 int
#endif  /* !__LP64__ */

/* C/C++ specific language defines.  */
#ifdef _WIN64
#ifdef __stdcall
#undef __stdcall
#endif  /* __stdcall */
#define __stdcall
#endif  /* _WIN64 */

#ifndef __GNUC__
# ifndef __MINGW_IMPORT
#  define __MINGW_IMPORT __declspec(dllimport)
# endif  /* !__MINGW_IMPORT */
# ifndef _CRTIMP
#  define _CRTIMP __declspec(dllimport)
# endif  /* !_CRTIMP */
# define __DECLSPEC_SUPPORTED
# define __attribute__(x)  /* nothing */
#else  /* !__GNUC__ */
# ifdef __declspec
#  ifndef __MINGW_IMPORT
/* Note the extern. This is needed to work around GCC's
   limitations in handling dllimport attribute.  */
#   define __MINGW_IMPORT extern __attribute__((__dllimport__))
#  endif  /* __MINGW_IMPORT */
#  ifndef _CRTIMP
#   undef __USE_CRTIMP
#   if !defined(_CRTBLD) && !defined(_SYSCRT)
#    define __USE_CRTIMP 1
#   endif  /* !defined(_CRTBLD) && !defined(_SYSCRT) */
#   ifdef __USE_CRTIMP
#    define _CRTIMP __attribute__((__dllimport__))
#   else  /* __USE_CRTIMP */
#    define _CRTIMP
#   endif  /* __USE_CRTIMP */
#  endif  /* !_CRTIMP */
#  define __DECLSPEC_SUPPORTED
# else  /* __declspec */
#  undef __DECLSPEC_SUPPORTED
#  undef __MINGW_IMPORT
#  ifndef _CRTIMP
#   define _CRTIMP
#  endif  /* !_CRTIMP */
# endif  /* __declspec */
#endif  /* !__GNUC__ */

#define USE___UUIDOF 0

#ifndef _inline
#define _inline __inline
#endif  /* !_inline */

#ifdef __cplusplus
# define __CRT_INLINE inline
#else  /* __cplusplus */
# if (__MINGW_GNUC_PREREQ(4, 3) && __STDC_VERSION__ >= 199901L) || defined(__clang__)
#  define __CRT_INLINE extern inline __attribute__((__gnu_inline__))
# else  /* (__MINGW_GNUC_PREREQ(4, 3) && __STDC_VERSION__ >= 199901L) || defined(__clang__) */
#  define __CRT_INLINE extern __inline__
# endif  /* (__MINGW_GNUC_PREREQ(4, 3) && __STDC_VERSION__ >= 199901L) || defined(__clang__) */
#endif  /* __cplusplus */

#if !defined(__MINGW_INTRIN_INLINE) && defined(__GNUC__)
#define __MINGW_INTRIN_INLINE extern __inline__ __attribute__((__always_inline__, __gnu_inline__))
#endif  /* !defined(__MINGW_INTRIN_INLINE) && defined(__GNUC__) */

#ifndef __CYGWIN__
#ifdef __NO_INLINE__
#undef __CRT__NO_INLINE
#define __CRT__NO_INLINE 1
#endif  /* __NO_INLINE__ */
#endif  /* !__CYGWIN__ */

#ifdef __cplusplus
# define __UNUSED_PARAM(x)
#else  /* __cplusplus */
# ifdef __GNUC__
#  define __UNUSED_PARAM(x) x __attribute__((__unused__))
# else  /* __GNUC__ */
#  define __UNUSED_PARAM(x) x
# endif  /* __GNUC__ */
#endif  /* __cplusplus */

#ifndef __GNUC__
#define __restrict__  /* nothing */
#endif  /* !__GNUC__ */

#if __MINGW_GNUC_PREREQ(3, 1) && !defined(__GNUG__)
# define __restrict_arr __restrict
#else  /* __MINGW_GNUC_PREREQ(3, 1) && !defined(__GNUG__) */
# ifdef __GNUC__
#  define __restrict_arr  /* Not supported in old GCC.  */
# else  /* __GNUC__ */
#  if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#   define __restrict_arr restrict
#  else  /* defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) */
#   define __restrict_arr /* Not supported.  */
#  endif  /* defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) */
# endif  /* __GNUC__ */
#endif  /* __MINGW_GNUC_PREREQ(3, 1) && !defined(__GNUG__) */

#ifdef __GNUC__
#define __MINGW_ATTRIB_NORETURN __attribute__((__noreturn__))
#define __MINGW_ATTRIB_CONST    __attribute__((__const__))
#elif __MINGW_MSC_PREREQ(12, 0)
#define __MINGW_ATTRIB_NORETURN __declspec(noreturn)
#define __MINGW_ATTRIB_CONST
#else  /* __MINGW_MSC_PREREQ(12, 0) */
#define __MINGW_ATTRIB_NORETURN
#define __MINGW_ATTRIB_CONST
#endif  /* __GNUC__ */

#if __MINGW_GNUC_PREREQ(3, 0)
#define __MINGW_ATTRIB_MALLOC __attribute__((__malloc__))
#define __MINGW_ATTRIB_PURE   __attribute__((__pure__))
#elif __MINGW_MSC_PREREQ(14, 0)
#define __MINGW_ATTRIB_MALLOC __declspec(noalias) __declspec(restrict)
#define __MINGW_ATTRIB_PURE
#else  /* __MINGW_MSC_PREREQ(14, 0) */
#define __MINGW_ATTRIB_MALLOC
#define __MINGW_ATTRIB_PURE
#endif  /* __MINGW_GNUC_PREREQ(3, 0) */

/* Attribute `nonnull' was valid as of gcc 3.3.  We don't use GCC's
   variadiac macro facility, because variadic macros cause syntax
   errors with  --traditional-cpp.  */
#if __MINGW_GNUC_PREREQ(3, 3)
#define __MINGW_ATTRIB_NONNULL(arg) __attribute__((__nonnull__ (arg)))
#else  /* __MINGW_GNUC_PREREQ(3, 3) */
#define __MINGW_ATTRIB_NONNULL(arg)
#endif  /* __MINGW_GNUC_PREREQ(3, 3) */

#ifdef __GNUC__
#define __MINGW_ATTRIB_UNUSED __attribute__((__unused__))
#else  /* __GNUC__ */
#define __MINGW_ATTRIB_UNUSED
#endif  /* __GNUC__ */

#if __MINGW_GNUC_PREREQ(3, 1)
#define __MINGW_ATTRIB_USED       __attribute__((__used__))
#define __MINGW_ATTRIB_DEPRECATED __attribute__((__deprecated__))
#elif __MINGW_MSC_PREREQ(12, 0)
#define __MINGW_ATTRIB_USED
#define __MINGW_ATTRIB_DEPRECATED __declspec(deprecated)
#else  /* __MINGW_MSC_PREREQ(12, 0) */
#define __MINGW_ATTRIB_USED __MINGW_ATTRIB_UNUSED
#define __MINGW_ATTRIB_DEPRECATED
#endif  /* __MINGW_GNUC_PREREQ(3, 1) */

#if __MINGW_GNUC_PREREQ(3, 3)
#define __MINGW_NOTHROW __attribute__((__nothrow__))
#elif __MINGW_MSC_PREREQ(12, 0) && defined(__cplusplus)
#define __MINGW_NOTHROW __declspec(nothrow)
#else  /* __MINGW_MSC_PREREQ(12, 0) && defined(__cplusplus) */
#define __MINGW_NOTHROW
#endif  /* __MINGW_GNUC_PREREQ(3, 3) */

#if __MINGW_GNUC_PREREQ(4, 4)
#define __MINGW_ATTRIB_NO_OPTIMIZE __attribute__((__optimize__ ("0")))
#else  /* __MINGW_GNUC_PREREQ(4, 4) */
#define __MINGW_ATTRIB_NO_OPTIMIZE
#endif  /* __MINGW_GNUC_PREREQ(4, 4) */

#if __MINGW_GNUC_PREREQ(4, 4)
#define __MINGW_PRAGMA_PARAM(x) _Pragma(#x)
#elif __MINGW_MSC_PREREQ(13, 1)
#define __MINGW_PRAGMA_PARAM(x) __pragma(x)
#else  /* __MINGW_MSC_PREREQ(13, 1) */
#define __MINGW_PRAGMA_PARAM(x)
#endif  /* __MINGW_GNUC_PREREQ(4, 4) */

#define __MINGW_BROKEN_INTERFACE(x) __MINGW_PRAGMA_PARAM(message ("Interface " _CRT_STRINGIZE(x) " has unverified layout."))

#ifndef __MSVCRT_VERSION__
/*  High byte is the major version, low byte is the minor. */
#define __MSVCRT_VERSION__ 0x0700
#endif  /* !__MSVCRT_VERSION__ */

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00
#endif  /* !_WIN32_WINNT */

#ifndef _INT128_DEFINED
#ifdef __GNUC__
#define __int8  char
#define __int16 short
#define __int32 int
#define __int64 long long
#ifdef _WIN64
#if (__clang_major__ > 3 || (__clang_major__ == 3 && __clang_minor__ >= 1)) && \
  !defined(__SIZEOF_INT128__)  /* clang >= 3.1 has __int128 but no size macro */
#define __SIZEOF_INT128__ 16
#endif  /* (__clang_major__ > 3 || (__clang_major__ == 3 && __clang_minor__ >= 1)) ... */
#ifndef __SIZEOF_INT128__
  typedef int __int128 __attribute__((__mode__ (TI)));
#endif  /* !__SIZEOF_INT128__ */
#endif  /* _WIN64 */
#endif  /* __GNUC__ */
#define _INT128_DEFINED
#endif  /* !_INT128_DEFINED */

#ifdef __GNUC__
#define __ptr32
#define __ptr64
#ifndef __unaligned
#define __unaligned
#endif  /* !__unaligned */
#ifndef __w64
#define __w64
#endif  /* !__w64 */
#ifdef __cplusplus
#define __forceinline inline __attribute__((__always_inline__))
#else  /* __cplusplus */
#define __forceinline extern __inline__ __attribute__((__always_inline__, __gnu_inline__))
#endif  /* __cplusplus */
#endif  /* __GNUC__ */

#if !defined(_WIN32) && !defined(__CYGWIN__)
#error Only Win32 target is supported!
#endif  /* !defined(_WIN32) && !defined(__CYGWIN__) */

#ifndef __nothrow
#ifdef __cplusplus
#define __nothrow __MINGW_NOTHROW
#else  /* __cplusplus */
#define __nothrow
#endif  /* __cplusplus */
#endif  /* !__nothrow */

#ifndef _CRTIMP_NOIA64
#define _CRTIMP_NOIA64 _CRTIMP
#endif  /* !_CRTIMP_NOIA64 */

/* We have to define _DLL for gcc based mingw version. This define is set
   by VC, when DLL-based runtime is used. So, gcc based runtime just have
   DLL-base runtime, therefore this define has to be set.
   As our headers are possibly used by windows compiler having a static
   C-runtime, we make this definition gnu compiler specific here.  */
#if !defined(_DLL) && defined (__GNUC__)
#define _DLL
#endif  /* !defined(_DLL) && defined (__GNUC__) */

#ifndef _MT
#define _MT
#endif  /* !_MT */

#ifndef _MCRTIMP
#define _MCRTIMP _CRTIMP
#endif  /* !_MCRTIMP */

/* MSVC defines _NATIVE_NULLPTR_SUPPORTED when nullptr is supported. We emulate it here for GCC. */
#if __MINGW_GNUC_PREREQ(4, 6)
#if defined(__GNUC__) && (defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L)
#define _NATIVE_NULLPTR_SUPPORTED
#endif  /* defined(__GNUC__) && (defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L) */
#endif  /* __MINGW_GNUC_PREREQ(4, 6) */

/* We are activating __USE_MINGW_ANSI_STDIO for various define indicators.
   Note that we enable it also for _GNU_SOURCE in C++, but not for C case. */
#if (defined(_POSIX) || defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
  || defined(_ISOC99_SOURCE) \
  || defined(_XOPEN_SOURCE) || defined(_XOPEN_SOURCE_EXTENDED) \
  || (defined(_GNU_SOURCE) && defined(__cplusplus)) \
  || defined(_SVID_SOURCE)) \
  && !defined(__USE_MINGW_ANSI_STDIO)
/* Enable __USE_MINGW_ANSI_STDIO if _POSIX defined
 * and If user did _not_ specify it explicitly... */
#define __USE_MINGW_ANSI_STDIO 1
#endif  /* (defined(_POSIX) || defined(_POSIX_SOURCE) || ...) && !defined(__USE_MINGW_ANSI_STDIO) */

/* _dowildcard is an int that controls the globbing of the command line.
 * The MinGW32 (mingw.org) runtime calls it _CRT_glob, so we are adding
 * a compatibility definition here:  you can use either of _CRT_glob or
 * _dowildcard .
 * If _dowildcard is non-zero, the command line will be globbed:  *.*
 * will be expanded to be all files in the startup directory.
 * In the mingw-w64 library a _dowildcard variable is defined as being
 * 0, therefore command line globbing is DISABLED by default. To turn it
 * on and to leave wildcard command line processing MS's globbing code,
 * include a line in one of your source modules defining _dowildcard and
 * setting it to -1, like so:
 * int _dowildcard = -1;
 */
#undef _CRT_glob
#define _CRT_glob _dowildcard

#if defined(NONAMELESSSTRUCT) && !defined(NONAMELESSUNION)
#define NONAMELESSUNION 1
#endif  /* defined(NONAMELESSSTRUCT) && !defined(NONAMELESSUNION) */
#if defined(NONAMELESSUNION) && !defined(NONAMELESSSTRUCT)
#define NONAMELESSSTRUCT 1
#endif  /* defined(NONAMELESSUNION) && !defined(NONAMELESSSTRUCT) */

#ifndef __ANONYMOUS_DEFINED
#define _ANONYMOUS_UNION  __MINGW_EXTENSION
#define _ANONYMOUS_STRUCT __MINGW_EXTENSION
#ifndef NONAMELESSUNION
#define _UNION_NAME(x)
#define _STRUCT_NAME(x)
#else  /* !NONAMELESSUNION */
#define _UNION_NAME(x)  x
#define _STRUCT_NAME(x) x
#endif  /* !NONAMELESSUNION */
#define __ANONYMOUS_DEFINED
#endif  /* __ANONYMOUS_DEFINED */

#ifndef DUMMYUNIONNAME
#ifdef NONAMELESSUNION
#define DUMMYUNIONNAME  u
#define DUMMYUNIONNAME1 u1  /* Wine uses this variant */
#define DUMMYUNIONNAME2 u2
#define DUMMYUNIONNAME3 u3
#define DUMMYUNIONNAME4 u4
#define DUMMYUNIONNAME5 u5
#define DUMMYUNIONNAME6 u6
#define DUMMYUNIONNAME7 u7
#define DUMMYUNIONNAME8 u8
#define DUMMYUNIONNAME9 u9
#else  /* NONAMELESSUNION */
#define DUMMYUNIONNAME
#define DUMMYUNIONNAME1  /* Wine uses this variant */
#define DUMMYUNIONNAME2
#define DUMMYUNIONNAME3
#define DUMMYUNIONNAME4
#define DUMMYUNIONNAME5
#define DUMMYUNIONNAME6
#define DUMMYUNIONNAME7
#define DUMMYUNIONNAME8
#define DUMMYUNIONNAME9
#endif  /* NONAMELESSUNION */
#endif  /* !DUMMYUNIONNAME */

#ifndef DUMMYSTRUCTNAME
#ifdef NONAMELESSUNION
#define DUMMYSTRUCTNAME  s
#define DUMMYSTRUCTNAME1 s1  /* Wine uses this variant */
#define DUMMYSTRUCTNAME2 s2
#define DUMMYSTRUCTNAME3 s3
#define DUMMYSTRUCTNAME4 s4
#define DUMMYSTRUCTNAME5 s5
#else  /* NONAMELESSUNION */
#define DUMMYSTRUCTNAME
#define DUMMYSTRUCTNAME1  /* Wine uses this variant */
#define DUMMYSTRUCTNAME2
#define DUMMYSTRUCTNAME3
#define DUMMYSTRUCTNAME4
#define DUMMYSTRUCTNAME5
#endif  /* NONAMELESSUNION */
#endif  /* !DUMMYSTRUCTNAME */

/* Macros for __uuidof template-based emulation */
#if defined(__cplusplus) && (USE___UUIDOF == 0)

#define __CRT_UUID_DECL(type, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)            \
  extern "C++" {                                                                    \
    template<> inline const GUID &__mingw_uuidof<type>() {                          \
      static const IID __uuid_inst = {l, w1, w2, {b1, b2, b3, b4, b5, b6, b7, b8}}; \
      return __uuid_inst;                                                           \
    }                                                                               \
    template<> inline const GUID &__mingw_uuidof<type*>() {                         \
      return __mingw_uuidof<type>();                                                \
    }                                                                               \
  }

#define __uuidof(type) __mingw_uuidof<__typeof(type)>()

#else  /* defined(__cplusplus) && (USE___UUIDOF == 0) */

#define __CRT_UUID_DECL(type, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)

#endif  /* defined(__cplusplus) && (USE___UUIDOF == 0) */

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */


#ifndef __has_builtin
#  define __has_builtin(x) 0
#endif

#ifdef __MINGW_INTRIN_INLINE
#if !defined (__clang__) || !__has_builtin(__debugbreak)
  void __cdecl __debugbreak(void);
  __MINGW_INTRIN_INLINE void __cdecl __debugbreak(void)
  {
    __asm__ __volatile__("int {$}3":);
  }
#endif  /* !defined (__clang__) || !__has_builtin(__debugbreak) */
#endif  /* __MINGW_INTRIN_INLINE */

/* mingw-w64 specific functions: */
  const char *__mingw_get_crt_info(void);  /* Provided in libmingw32. */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* _INC__MINGW_H */

#ifndef MINGW_SDK_INIT

#define __STDC_SECURE_LIB__ 200411L
#define __GOT_SECURE_LIB__  __STDC_SECURE_LIB__

#ifndef __WIDL__
#include "sdks/_mingw_directx.h"
#include "sdks/_mingw_ddk.h"
#endif  /* !__WIDL__ */

#define MINGW_SDK_INIT
#endif  /* MINGW_SDK_INIT */
