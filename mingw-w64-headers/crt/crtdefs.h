/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC_CRTDEFS
#define _INC_CRTDEFS

#include <_mingw.h>
#include <sal.h>

#ifndef __WIDL__
#undef _CRT_PACKING
#define _CRT_PACKING 8
#pragma pack(push, _CRT_PACKING)
#endif  /* !__WIDL__ */

#include <vadefs.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef _CRT_STRINGIZE
#define __CRT_STRINGIZE(_Value) #_Value
#define _CRT_STRINGIZE(_Value) __CRT_STRINGIZE(_Value)
#endif  /* !_CRT_STRINGIZE */

#ifndef _CRT_WIDE
#define __CRT_WIDE(_String) L ## _String
#define _CRT_WIDE(_String) __CRT_WIDE(_String)
#endif  /* !_CRT_WIDE */

#ifndef _W64
#define _W64
#endif  /* !_W64 */

#ifndef _CRTIMP2
#define _CRTIMP2 _CRTIMP
#endif  /* !_CRTIMP2 */

#ifndef _CRTIMP_ALTERNATIVE
#define _CRTIMP_ALTERNATIVE _CRTIMP
#define _CRT_ALTERNATIVE_IMPORTED
#endif  /* !_CRTIMP_ALTERNATIVE */

#ifndef _MRTIMP2
#define _MRTIMP2 _CRTIMP
#endif  /* !_MRTIMP2 */

#ifndef _CRTIMP_PURE
#define _CRTIMP_PURE _CRTIMP
#endif  /* !_CRTIMP_PURE */

#ifndef _PGLOBAL
#define _PGLOBAL
#endif  /* !_PGLOBAL */

#ifndef _AGLOBAL
#define _AGLOBAL
#endif  /* !_AGLOBAL */

#define _CRT_DEPRECATE_TEXT(_Text)     __declspec(deprecated)

#ifndef _CRT_INSECURE_DEPRECATE_MEMORY
#define _CRT_INSECURE_DEPRECATE_MEMORY(_Replacement)
#endif  /* !_CRT_INSECURE_DEPRECATE_MEMORY */

#ifndef _CRT_INSECURE_DEPRECATE_GLOBALS
#define _CRT_INSECURE_DEPRECATE_GLOBALS(_Replacement)
#endif  /* !_CRT_INSECURE_DEPRECATE_GLOBALS */

#ifndef _CRT_MANAGED_HEAP_DEPRECATE
#define _CRT_MANAGED_HEAP_DEPRECATE
#endif  /* !_CRT_MANAGED_HEAP_DEPRECATE */

#define _SECURECRT_FILL_BUFFER_PATTERN 0xFD

#ifndef _CRT_OBSOLETE
#define _CRT_OBSOLETE(_NewItem)
#endif  /* !_CRT_OBSOLETE */

/* http://msdn.microsoft.com/en-us/library/ms175759%28v=VS.100%29.aspx */
#ifdef __cplusplus
#ifndef _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES          1  /* default to 1 */
#endif  /* !_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES */
#ifndef _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY   0  /* default to 0 */
#endif  /* !_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY */
#ifndef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES        0  /* default to 0 */
#endif  /* !_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES */
#ifndef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT  0  /* default to 0 */
#endif  /* !_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT */
#ifndef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY 0  /* default to 0 */
#endif  /* !_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY */
#else  /* __cplusplus */
/* Templates won't work in C, will break if secure API is not enabled, disabled */
#undef _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
#undef _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY
#undef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
#undef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT
#undef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES          0
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY   0
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES        0
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT  0
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY 0
#endif  /* __cplusplus */

#ifndef _CRT_SECURE_CPP_NOTHROW
#define _CRT_SECURE_CPP_NOTHROW throw()
#endif  /* !_CRT_SECURE_CPP_NOTHROW */


#ifdef __ERRCODE_DEFINED_MS
  typedef int errcode;
#endif  /* __ERRCODE_DEFINED_MS */

#ifndef _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
  __MINGW_EXTENSION typedef unsigned __int64 size_t;
#else  /* _WIN64 */
  typedef unsigned int size_t;
#endif  /* _WIN64 */
#define _SIZE_T_DEFINED
#endif  /* !_SIZE_T_DEFINED */

#ifndef _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
  __MINGW_EXTENSION typedef __int64 ssize_t;
#else  /* _WIN64 */
  typedef int ssize_t;
#endif  /* _WIN64 */
#define _SSIZE_T_DEFINED
#endif  /* !_SSIZE_T_DEFINED */

#ifndef _RSIZE_T_DEFINED
  typedef size_t rsize_t;
#define _RSIZE_T_DEFINED
#endif  /* !_RSIZE_T_DEFINED */

#ifndef _INTPTR_T_DEFINED
#ifndef __intptr_t_defined
#undef intptr_t
#ifdef _WIN64
  __MINGW_EXTENSION typedef __int64 intptr_t;
#else  /* _WIN64 */
  typedef int intptr_t;
#endif  /* _WIN64 */
#define __intptr_t_defined
#endif  /* !__intptr_t_defined */
#define _INTPTR_T_DEFINED
#endif  /* !_INTPTR_T_DEFINED */

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

#ifndef _PTRDIFF_T_DEFINED
#ifndef _PTRDIFF_T_
#undef ptrdiff_t
#ifdef _WIN64
  __MINGW_EXTENSION typedef __int64 ptrdiff_t;
#else  /* _WIN64 */
  typedef int ptrdiff_t;
#endif  /* _WIN64 */
#define _PTRDIFF_T_
#endif  /* !_PTRDIFF_T_ */
#define _PTRDIFF_T_DEFINED
#endif  /* !_PTRDIFF_T_DEFINED */

#ifndef _WCHAR_T_DEFINED
#if !defined(__cplusplus) && !defined(__WIDL__)
  typedef unsigned short wchar_t;
#endif  /* !defined(__cplusplus) && !defined(__WIDL__) */
#define _WCHAR_T_DEFINED
#endif  /* !_WCHAR_T_DEFINED */

#ifndef _WCTYPE_T_DEFINED
#ifndef _WINT_T
  typedef unsigned short wint_t;
  typedef unsigned short wctype_t;
#define _WINT_T
#endif  /* !_WINT_T */
#define _WCTYPE_T_DEFINED
#endif  /* !_WCTYPE_T_DEFINED */

#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#error You cannot use 32-bit time_t (_USE_32BIT_TIME_T) with _WIN64
#undef _USE_32BIT_TIME_T
#endif  /* _WIN64 */
#endif  /* _USE_32BIT_TIME_T */

#ifndef _ERRCODE_DEFINED
  typedef int errno_t;
#define _ERRCODE_DEFINED
#endif  /* !_ERRCODE_DEFINED */

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


#ifndef __WIDL__

#ifdef __MINGW_USE_CONST_RETURN
#ifndef _CONST_RETURN
#ifdef __cplusplus
#define _CONST_RETURN const
#define _CRT_CONST_CORRECT_OVERLOADS
#else  /* __cplusplus */
#define _CONST_RETURN
#endif  /* __cplusplus */
#endif  /* !_CONST_RETURN */
#else  /* __MINGW_USE_CONST_RETURN */
#define _CONST_RETURN
#endif  /* __MINGW_USE_CONST_RETURN */

#ifndef UNALIGNED
#if defined(_M_IA64) || defined(_M_AMD64)
#define UNALIGNED __unaligned
#else  /* defined(_M_IA64) || defined(_M_AMD64) */
#define UNALIGNED
#endif  /* defined(_M_IA64) || defined(_M_AMD64) */
#endif  /* !UNALIGNED */

#ifndef _CRT_ALIGN
#define _CRT_ALIGN(x) __attribute__((__aligned__ (x)))
#endif  /* !_CRT_ALIGN */

#endif  /* !__WIDL__ */

#ifndef _CRTNOALIAS
#define _CRTNOALIAS
#endif  /* !_CRTNOALIAS */

#ifndef _CRTRESTRICT
#define _CRTRESTRICT
#endif  /* !_CRTRESTRICT */

#ifndef __CRTDECL
#define __CRTDECL __cdecl
#endif  /* !__CRTDECL */

#define _ARGMAX 100

#ifndef _TRUNCATE
#define _TRUNCATE ((size_t)-1)
#endif  /* !_TRUNCATE */

#ifndef RC_INVOKED
#if defined(__cplusplus) && _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(_ReturnType, _FuncName, _DstType, _Dst) \
  extern "C++" { \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_DstType (&_Dst)[_Size]) _CRT_SECURE_CPP_NOTHROW { \
      return _FuncName(_Dst, _Size); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(_ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1) \
  extern "C++" { \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_DstType (&_Dst)[_Size], _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      return _FuncName(_Dst, _Size, _TArg1); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(_ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  extern "C++" { \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_DstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      return _FuncName(_Dst, _Size, _TArg1, _TArg2); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(_ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  extern "C++" { \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_DstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      return _FuncName(_Dst, _Size, _TArg1, _TArg2, _TArg3); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_4(_ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4) \
  extern "C++" { \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_DstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4) _CRT_SECURE_CPP_NOTHROW { \
      return _FuncName(_Dst, _Size, _TArg1, _TArg2, _TArg3, _TArg4); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(_ReturnType, _FuncName, _HType1, _HArg1, _DstType, _Dst, _TType1, _TArg1) \
  extern "C++" { \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_HType1 _HArg1, _DstType (&_Dst)[_Size], _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      return _FuncName(_HArg1, _Dst, _Size, _TArg1); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_2(_ReturnType, _FuncName, _HType1, _HArg1, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  extern "C++" { \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_HType1 _HArg1, _DstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      return _FuncName(_HArg1, _Dst, _Size, _TArg1, _TArg2); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(_ReturnType, _FuncName, _HType1, _HArg1, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  extern "C++" { \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_HType1 _HArg1, _DstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      return _FuncName(_HArg1, _Dst, _Size, _TArg1, _TArg2, _TArg3); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_2_0(_ReturnType, _FuncName, _HType1, _HArg1, _HType2, _HArg2, _DstType, _Dst) \
  extern "C++" { \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_HType1 _HArg1, _HType2 _HArg2, _DstType (&_Dst)[_Size]) _CRT_SECURE_CPP_NOTHROW { \
      return _FuncName(_HArg1, _HArg2, _Dst, _Size); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(_ReturnType, _FuncName, _VFuncName, _DstType, _Dst, _TType1, _TArg1) \
  extern "C++" { \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_DstType (&_Dst)[_Size], _TType1 _TArg1, ...) _CRT_SECURE_CPP_NOTHROW { \
      va_list _ArgList; \
      _crt_va_start(_ArgList, _TArg1); \
      return _VFuncName(_Dst, _Size, _TArg1, _ArgList); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(_ReturnType, _FuncName, _VFuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  extern "C++" { \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_DstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2, ...) _CRT_SECURE_CPP_NOTHROW { \
      va_list _ArgList; \
      _crt_va_start(_ArgList, _TArg2); \
      return _VFuncName(_Dst, _Size, _TArg1, _TArg2, _ArgList); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_SPLITPATH(_ReturnType, _FuncName, _DstType, _Src) \
  extern "C++" { \
    template <size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize> \
    inline _ReturnType __CRTDECL _FuncName(const _DstType *_Src, _DstType (&_Drive)[_DriveSize], _DstType (&_Dir)[_DirSize], _DstType (&_Name)[_NameSize], _DstType (&_Ext)[_ExtSize]) _CRT_SECURE_CPP_NOTHROW { \
      return _FuncName(_Src, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize); \
    } \
  }

#else  /* defined(__cplusplus) && _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES */

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(_ReturnType, _FuncName, _DstType, _Dst)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(_ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(_ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(_ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_4(_ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(_ReturnType, _FuncName, _HType1, _HArg1, _DstType, _Dst, _TType1, _TArg1)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_2(_ReturnType, _FuncName, _HType1, _HArg1, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(_ReturnType, _FuncName, _HType1, _HArg1, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_2_0(_ReturnType, _FuncName, _HType1, _HArg1, _HType2, _HArg2, _DstType, _Dst)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(_ReturnType, _FuncName, _VFuncName, _DstType, _Dst, _TType1, _TArg1)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(_ReturnType, _FuncName, _VFuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_SPLITPATH(_ReturnType, _FuncName, _DstType, _Src)

#endif  /* defined(__cplusplus) && _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES */
#endif  /* !RC_INVOKED */

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _SalAttributeDst, _DstType, _Dst)

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4)

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_1_1(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_1_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_2_0(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_2_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst)

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_ARGLIST(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _VFuncName, _VFuncName##_s, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_ARGLIST(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _VFuncName##_s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_SIZE(_DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_SIZE_EX(_DeclSpec, _FuncName, _FuncName##_s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_SIZE(_DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_SIZE_EX(_DeclSpec, _FuncName, _FuncName##_s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)


#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst) \
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _SalAttributeDst, _DstType, _Dst) \

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _SalAttributeDst, _DstType, _DstType, _Dst, _TType1, _TArg1)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_4(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4) \
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_4_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_1_1(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_1_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_2_0(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst) \
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_2_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_ARGLIST(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName##_s, _VFuncName, _VFuncName##_s, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_SIZE(_DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_SIZE_EX(_DeclSpec, _FuncName, _FuncName##_s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_SIZE(_DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_SIZE_EX(_DeclSpec, _FuncName, _FuncName##_s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)


#ifndef RC_INVOKED
#if defined(__cplusplus) && _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES

#define __RETURN_POLICY_SAME(_FunctionCall, _Dst) return (_FunctionCall)
#define __RETURN_POLICY_DST(_FunctionCall, _Dst)  return ((_FunctionCall) == 0 ? _Dst : 0)
#define __RETURN_POLICY_VOID(_FunctionCall, _Dst) (_FunctionCall); return
#define __EMPTY_DECLSPEC

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst) \
  __inline _ReturnType __CRTDECL __insecure_##_FuncName(_SalAttributeDst _DstType *_Dst) { \
    _DeclSpec _ReturnType __cdecl _FuncName(_DstType *_Dst); \
    return _FuncName(_Dst); \
  } \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_T &_Dst) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst)); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(const _T &_Dst) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst)); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_DstType * &_Dst) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_Dst); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_DstType (&_Dst)[_Size]) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, _Size), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName<1>(_DstType (&_Dst)[1]) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, 1), _Dst); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_CGETS(_ReturnType, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst) \
  __inline _ReturnType __CRTDECL __insecure_##_FuncName(_SalAttributeDst _DstType *_Dst) { \
    _DeclSpec _ReturnType __cdecl _FuncName(_DstType *_Dst); \
    return _FuncName(_Dst); \
  } \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_FuncName##_s) _ReturnType __CRTDECL _FuncName(_T &_Dst) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst)); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_FuncName##_s) _ReturnType __CRTDECL _FuncName(const _T &_Dst) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst)); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_FuncName##_s) _ReturnType __CRTDECL _FuncName(_DstType * &_Dst) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_Dst); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_DstType (&_Dst)[_Size]) _CRT_SECURE_CPP_NOTHROW { \
      size_t _SizeRead = 0; \
      errno_t _Err = _FuncName##_s(_Dst + 2, (_Size - 2) < ((size_t)_Dst[0]) ? (_Size - 2) : ((size_t)_Dst[0]), &_SizeRead); \
      _Dst[1] = (_DstType)(_SizeRead); \
      return (_Err == 0 ? _Dst + 2 : 0); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_FuncName##_s) _ReturnType __CRTDECL _FuncName<1>(_DstType (&_Dst)[1]) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName((_DstType *)_Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_FuncName##_s) _ReturnType __CRTDECL _FuncName<2>(_DstType (&_Dst)[2]) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName((_DstType *)_Dst); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  __inline _ReturnType __CRTDECL __insecure_##_FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1) { \
    _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1); \
    return _FuncName(_Dst, _TArg1); \
  } \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_T &_Dst, _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(const _T &_Dst, _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_DstType * &_Dst, _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_Dst, _TArg1); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_SecureDstType (&_Dst)[_Size], _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, _Size, _TArg1), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName<1>(_DstType (&_Dst)[1], _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, 1, _TArg1), _Dst); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __inline _ReturnType __CRTDECL __insecure_##_FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
    _DeclSpec _ReturnType __cdecl _FuncName(_DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2); \
    return _FuncName(_Dst, _TArg1, _TArg2); \
  } \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_T &_Dst, _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(const _T &_Dst, _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_DstType * &_Dst, _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_Dst, _TArg1, _TArg2); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_SecureDstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, _Size, _TArg1, _TArg2), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName<1>(_DstType (&_Dst)[1], _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, 1, _TArg1, _TArg2), _Dst); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  __inline _ReturnType __CRTDECL __insecure_##_FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) { \
    _DeclSpec _ReturnType __cdecl _FuncName(_DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3); \
    return _FuncName(_Dst, _TArg1, _TArg2, _TArg3); \
  } \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_T &_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2, _TArg3); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(const _T &_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2, _TArg3); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_DstType * &_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_Dst, _TArg1, _TArg2, _TArg3); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_SecureDstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, _Size, _TArg1, _TArg2, _TArg3), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName<1>(_DstType (&_Dst)[1], _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, 1, _TArg1, _TArg2, _TArg3), _Dst); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4) \
  __inline _ReturnType __CRTDECL __insecure_##_FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4) { \
    _DeclSpec _ReturnType __cdecl _FuncName(_DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4); \
    return _FuncName(_Dst, _TArg1, _TArg2, _TArg3, _TArg4); \
  } \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_T &_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2, _TArg3, _TArg4); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(const _T &_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2, _TArg3, _TArg4); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_DstType * &_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_Dst, _TArg1, _TArg2, _TArg3, _TArg4); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_DstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, _Size, _TArg1, _TArg2, _TArg3, _TArg4), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName<1>(_DstType (&_Dst)[1], _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, 1, _TArg1, _TArg2, _TArg3, _TArg4), _Dst); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_1_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  __inline _ReturnType __CRTDECL __insecure_##_FuncName(_HType1 _HArg1, _SalAttributeDst _DstType *_Dst, _TType1 _TArg1) { \
    _DeclSpec _ReturnType __cdecl _FuncName(_HType1 _HArg1, _DstType *_Dst, _TType1 _TArg1); \
    return _FuncName(_HArg1, _Dst, _TArg1); \
  } \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_HType1 _HArg1, _T &_Dst, _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_HArg1, static_cast<_DstType *>(_Dst), _TArg1); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_HType1 _HArg1, const _T &_Dst, _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_HArg1, static_cast<_DstType *>(_Dst), _TArg1); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_HType1 _HArg1, _DstType * &_Dst, _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_HArg1, _Dst, _TArg1); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_HType1 _HArg1, _DstType (&_Dst)[_Size], _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_HArg1, _Dst, _Size, _TArg1), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName<1>(_HType1 _HArg1, _DstType (&_Dst)[1], _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_HArg1, _Dst, 1, _TArg1), _Dst); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_2_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst) \
  __inline _ReturnType __CRTDECL __insecure_##_FuncName(_HType1 _HArg1, _HType2 _HArg2, _SalAttributeDst _DstType *_Dst) { \
    _DeclSpec _ReturnType __cdecl _FuncName(_HType1 _HArg1, _HType2 _HArg2, _DstType *_Dst); \
    return _FuncName(_HArg1, _HArg2, _Dst); \
  } \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_HType1 _HArg1, _HType2 _HArg2, _T &_Dst) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_HArg1, _HArg2, static_cast<_DstType *>(_Dst)); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_HType1 _HArg1, _HType2 _HArg2, const _T &_Dst) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_HArg1, _HArg2, static_cast<_DstType *>(_Dst)); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_HType1 _HArg1, _HType2 _HArg2, _DstType * &_Dst) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_HArg1, _HArg2, _Dst); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_HType1 _HArg1, _HType2 _HArg2, _DstType (&_Dst)[_Size]) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_HArg1, _HArg2, _Dst, _Size), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName<1>(_HType1 _HArg1, _HType2 _HArg2, _DstType (&_Dst)[1]) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_HArg1, _HArg2, _Dst, 1), _Dst); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _VFuncName, _SecureVFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  __inline _ReturnType __CRTDECL __insecure_##_VFuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, va_list _ArgList) { \
    _DeclSpec _ReturnType __cdecl _VFuncName(_DstType *_Dst, _TType1 _TArg1, va_list _ArgList); \
    return _VFuncName(_Dst, _TArg1, _ArgList); \
  } \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_T &_Dst, _TType1 _TArg1, ...) _CRT_SECURE_CPP_NOTHROW { \
      va_list _ArgList; \
      _crt_va_start(_ArgList, _TArg1); \
      return __insecure_##_VFuncName(static_cast<_DstType *>(_Dst), _TArg1, _ArgList); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(const _T &_Dst, _TType1 _TArg1, ...) _CRT_SECURE_CPP_NOTHROW { \
      va_list _ArgList; \
      _crt_va_start(_ArgList, _TArg1); \
      return __insecure_##_VFuncName(static_cast<_DstType *>(_Dst), _TArg1, _ArgList); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_DstType * &_Dst, _TType1 _TArg1, ...) _CRT_SECURE_CPP_NOTHROW { \
      va_list _ArgList; \
      _crt_va_start(_ArgList, _TArg1); \
      return __insecure_##_VFuncName(_Dst, _TArg1, _ArgList); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_DstType (&_Dst)[_Size], _TType1 _TArg1, ...) _CRT_SECURE_CPP_NOTHROW { \
      va_list _ArgList; \
      _crt_va_start(_ArgList, _TArg1); \
      _ReturnPolicy(_SecureVFuncName(_Dst, _Size, _TArg1, _ArgList), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName<1>(_DstType (&_Dst)[1], _TType1 _TArg1, ...) _CRT_SECURE_CPP_NOTHROW { \
      va_list _ArgList; \
      _crt_va_start(_ArgList, _TArg1); \
      _ReturnPolicy(_SecureVFuncName(_Dst, 1, _TArg1, _ArgList), _Dst); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _ReturnType __CRTDECL _VFuncName(_T &_Dst, _TType1 _TArg1, va_list _ArgList) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_VFuncName(static_cast<_DstType *>(_Dst), _TArg1, _ArgList); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _ReturnType __CRTDECL _VFuncName(const _T &_Dst, _TType1 _TArg1, va_list _ArgList) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_VFuncName(static_cast<_DstType *>(_Dst), _TArg1, _ArgList); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _ReturnType __CRTDECL _VFuncName(_DstType *&_Dst, _TType1 _TArg1, va_list _ArgList) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_VFuncName(_Dst, _TArg1, _ArgList); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _VFuncName(_DstType (&_Dst)[_Size], _TType1 _TArg1, va_list _ArgList) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureVFuncName(_Dst, _Size, _TArg1, _ArgList), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _ReturnType __CRTDECL _VFuncName<1>(_DstType (&_Dst)[1], _TType1 _TArg1, va_list _ArgList) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureVFuncName(_Dst, 1, _TArg1, _ArgList), _Dst); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SecureVFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __inline _ReturnType __CRTDECL __insecure_##_VFuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _ArgList) { \
    _DeclSpec _ReturnType __cdecl _VFuncName(_DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _ArgList); \
    return _VFuncName(_Dst, _TArg1, _TArg2, _ArgList); \
  } \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_FuncName##_s) _ReturnType __CRTDECL _FuncName(_T &_Dst, _TType1 _TArg1, _TType2 _TArg2, ...) _CRT_SECURE_CPP_NOTHROW { \
      va_list _ArgList; \
      _crt_va_start(_ArgList, _TArg2); \
      return __insecure_##_VFuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2, _ArgList); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_FuncName##_s) _ReturnType __CRTDECL _FuncName(const _T &_Dst, _TType1 _TArg1, _TType2 _TArg2, ...) _CRT_SECURE_CPP_NOTHROW { \
      va_list _ArgList; \
      _crt_va_start(_ArgList, _TArg2); \
      return __insecure_##_VFuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2, _ArgList); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_FuncName##_s) _ReturnType __CRTDECL _FuncName(_DstType * &_Dst, _TType1 _TArg1, _TType2 _TArg2, ...) _CRT_SECURE_CPP_NOTHROW { \
      va_list _ArgList; \
      _crt_va_start(_ArgList, _TArg2); \
      return __insecure_##_VFuncName(_Dst, _TArg1, _TArg2, _ArgList); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_SecureDstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2, ...) _CRT_SECURE_CPP_NOTHROW { \
      va_list _ArgList; \
      _crt_va_start(_ArgList, _TArg2); \
      _ReturnPolicy(_SecureVFuncName(_Dst, _Size, _TArg1, _TArg2, _ArgList), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_FuncName##_s) _ReturnType __CRTDECL _FuncName<1>(_DstType (&_Dst)[1], _TType1 _TArg1, _TType2 _TArg2, ...) _CRT_SECURE_CPP_NOTHROW { \
      va_list _ArgList; \
      _crt_va_start(_ArgList, _TArg2); \
      _ReturnPolicy(_SecureVFuncName(_Dst, 1, _TArg1, _TArg2, _ArgList), _Dst); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _ReturnType __CRTDECL _VFuncName(_T &_Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _ArgList) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_VFuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2, _ArgList); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _ReturnType __CRTDECL _VFuncName(const _T &_Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _ArgList) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_VFuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2, _ArgList); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _ReturnType __CRTDECL _VFuncName(_DstType *&_Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _ArgList) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_VFuncName(_Dst, _TArg1, _TArg2, _ArgList); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _VFuncName(_SecureDstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2, va_list _ArgList) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureVFuncName(_Dst, _Size, _TArg1, _TArg2, _ArgList), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _ReturnType __CRTDECL _VFuncName<1>(_DstType (&_Dst)[1], _TType1 _TArg1, _TType2 _TArg2, va_list _ArgList) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureVFuncName(_Dst, 1, _TArg1, _TArg2, _ArgList), _Dst); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_SIZE_EX(_DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __inline size_t __CRTDECL __insecure_##_FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2) { \
    _DeclSpec size_t __cdecl _FuncName(_DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2); \
    return _FuncName(_Dst, _TArg1, _TArg2); \
  } \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) size_t __CRTDECL _FuncName(_T &_Dst, _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) size_t __CRTDECL _FuncName(const _T &_Dst, _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) size_t __CRTDECL _FuncName(_DstType * &_Dst, _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_Dst, _TArg1, _TArg2); \
    } \
    template <size_t _Size> \
    inline size_t __CRTDECL _FuncName(_SecureDstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      size_t _Ret = 0; \
      _SecureFuncName(&_Ret, _Dst, _Size, _TArg1, _TArg2); \
      return (_Ret > 0 ? (_Ret - 1) : _Ret); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) size_t __CRTDECL _FuncName<1>(_DstType (&_Dst)[1], _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      size_t _Ret = 0; \
      _SecureFuncName(&_Ret, _Dst, 1, _TArg1, _TArg2); \
      return (_Ret > 0 ? (_Ret - 1) : _Ret); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_SIZE_EX(_DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  __inline size_t __CRTDECL __insecure_##_FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) { \
    _DeclSpec size_t __cdecl _FuncName(_DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3); \
    return _FuncName(_Dst, _TArg1, _TArg2, _TArg3); \
  } \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) size_t __CRTDECL _FuncName(_T &_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2, _TArg3); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) size_t __CRTDECL _FuncName(const _T &_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2, _TArg3); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) size_t __CRTDECL _FuncName(_DstType * &_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_Dst, _TArg1, _TArg2, _TArg3); \
    } \
    template <size_t _Size> \
    inline size_t __CRTDECL _FuncName(_SecureDstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      size_t _Ret = 0; \
      _SecureFuncName(&_Ret, _Dst, _Size, _TArg1, _TArg2, _TArg3); \
      return (_Ret > 0 ? (_Ret - 1) : _Ret); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) size_t __CRTDECL _FuncName<1>(_DstType (&_Dst)[1], _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      size_t _Ret = 0; \
      _SecureFuncName(&_Ret, _Dst, 1, _TArg1, _TArg2, _TArg3); \
      return (_Ret > 0 ? (_Ret - 1) : _Ret); \
    } \
  }

#define __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_0_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst) \
  __inline _ReturnType __CRTDECL __insecure_##_FuncName(_DstType *_Dst)

#define __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_0_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst) \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_T &_Dst) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst)); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(const _T &_Dst) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst)); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_DstType * &_Dst) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_Dst); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_SecureDstType (&_Dst)[_Size]) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, _Size), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName<1>(_DstType (&_Dst)[1]) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, 1), _Dst); \
    } \
  }

#define __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_1_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1) \
  __inline _ReturnType __CRTDECL __insecure_##_FuncName(_DstType *_Dst, _TType1 _TArg1)

#define __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_1_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1) \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_T &_Dst, _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(const _T &_Dst, _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_DstType * &_Dst, _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_Dst, _TArg1); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_SecureDstType (&_Dst)[_Size], _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, _Size, _TArg1), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName<1>(_DstType (&_Dst)[1], _TType1 _TArg1) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, 1, _TArg1), _Dst); \
    } \
  }

#define __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_2_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __inline _ReturnType __CRTDECL __insecure_##_FuncName(_DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2)

#define __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_2_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_T &_Dst, _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(const _T &_Dst, _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_DstType * &_Dst, _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_Dst, _TArg1, _TArg2); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_SecureDstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, _Size, _TArg1, _TArg2), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName<1>(_DstType (&_Dst)[1], _TType1 _TArg1, _TType2 _TArg2) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, 1, _TArg1, _TArg2), _Dst); \
    } \
  }

#define __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_3_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  __inline _ReturnType __CRTDECL __insecure_##_FuncName(_DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3)

#define __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_3_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  extern "C++" { \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_T &_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2, _TArg3); \
    } \
    template <typename _T> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(const _T &_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(static_cast<_DstType *>(_Dst), _TArg1, _TArg2, _TArg3); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName(_DstType * &_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      return __insecure_##_FuncName(_Dst, _TArg1, _TArg2, _TArg3); \
    } \
    template <size_t _Size> \
    inline _ReturnType __CRTDECL _FuncName(_SecureDstType (&_Dst)[_Size], _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, _Size, _TArg1, _TArg2, _TArg3), _Dst); \
    } \
    template <> \
    inline _CRT_INSECURE_DEPRECATE(_SecureFuncName) _ReturnType __CRTDECL _FuncName<1>(_DstType (&_Dst)[1], _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) _CRT_SECURE_CPP_NOTHROW { \
      _ReturnPolicy(_SecureFuncName(_Dst, 1, _TArg1, _TArg2, _TArg3), _Dst); \
    } \
  }

#ifdef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_CGETS(_ReturnType, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_CGETS(_ReturnType, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_4_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_1_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_1_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_2_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_2_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _VFuncName, _SecureVFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _VFuncName, _SecureVFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_ARGLIST(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_ARGLIST(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _VFuncName##_s, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_SIZE_EX(_DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_SIZE_EX(_DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_SIZE_EX(_DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_SIZE_EX(_DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)


#define __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_0_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst) \
  __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_0_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType _DstType, _Dst)

#define __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_0_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst) \
  __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_0_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst)

#define __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_1_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1) \
  __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_1_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType _DstType, _Dst, _TType1, _TArg1)

#define __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_1_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1) \
  __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_1_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1)

#define __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_2_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_2_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)

#define __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_2_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_2_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)

#define __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_3_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_3_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)

#define __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_3_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_3_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)

#else  /* _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT */

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_GETS(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _DstType, _Dst) \
  _CRT_INSECURE_DEPRECATE(_FuncName##_s) _DeclSpec _ReturnType __cdecl _FuncName(_DstType *_Dst);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_4_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_1_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_HType1 _HArg1, _SalAttributeDst _DstType *_Dst, _TType1 _TArg1);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_2_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_HType1 _HArg1, _HType2 _HArg2, _SalAttributeDst _DstType *_Dst);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName,_VFuncName, _SecureVFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, ...); \
  _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _DeclSpec _ReturnType __cdecl _VFuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, va_list _Args);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_ARGLIST(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  _CRT_INSECURE_DEPRECATE(_FuncName##_s) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, ...); \
  _CRT_INSECURE_DEPRECATE(_VFuncName##_s) _DeclSpec _ReturnType __cdecl _VFuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _Args);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  _CRT_INSECURE_DEPRECATE(_FuncName##_s) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, ...); \
  _CRT_INSECURE_DEPRECATE(_VFuncName##_s) _DeclSpec _ReturnType __cdecl _VFuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _Args);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_SIZE_EX(_DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec size_t __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_SIZE_EX(_DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec size_t __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3);


#define __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_0_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName(_DstType *_Dst)

#define __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_0_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst)

#define __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_1_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName(_DstType *_Dst, _TType1 _TArg1)

#define __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_1_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1)

#define __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_2_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName(_DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2)

#define __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_2_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)

#define __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_3_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName(_DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3)

#define __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_3_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)

#endif  /* _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT */

#else  /* defined(__cplusplus) && _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES */

#define __RETURN_POLICY_SAME(_FunctionCall)
#define __RETURN_POLICY_DST(_FunctionCall)
#define __RETURN_POLICY_VOID(_FunctionCall)
#define __EMPTY_DECLSPEC

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst);

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_CGETS(_ReturnType, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst) \
  _CRT_INSECURE_DEPRECATE(_FuncName##_s) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst);

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1);

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2);

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3);

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4);

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_1_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_HType1 _HArg1, _SalAttributeDst _DstType *_Dst, _TType1 _TArg1);

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_2_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_HType1 _HArg1, _HType2 _HArg2, _SalAttributeDst _DstType *_Dst);

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _VFuncName, _SecureVFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, ...); \
  _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _DeclSpec _ReturnType __cdecl _VFuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, va_list _Args);

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SecureVFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  _CRT_INSECURE_DEPRECATE(_FuncName##_s) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, ...); \
  _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _DeclSpec _ReturnType __cdecl _VFuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _Args);

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_SIZE_EX(_DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec size_t __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2);

#define __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_SIZE_EX(_DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec size_t __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_GETS(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _DstType, _Dst) \
  _CRT_INSECURE_DEPRECATE(_FuncName##_s) _DeclSpec _ReturnType __cdecl _FuncName(_DstType *_Dst);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_4_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_1_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_HType1 _HArg1, _SalAttributeDst _DstType *_Dst, _TType1 _TArg1);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_2_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_HType1 _HArg1, _HType2 _HArg2, _SalAttributeDst _DstType *_Dst);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _VFuncName, _SecureVFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, ...); \
  _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _DeclSpec _ReturnType __cdecl _VFuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, va_list _Args);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_ARGLIST(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  _CRT_INSECURE_DEPRECATE(_FuncName##_s) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, ...); \
  _CRT_INSECURE_DEPRECATE(_VFuncName##_s) _DeclSpec _ReturnType __cdecl _VFuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _Args);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  _CRT_INSECURE_DEPRECATE(_FuncName##_s) _DeclSpec _ReturnType __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, ...); \
  _CRT_INSECURE_DEPRECATE(_VFuncName##_s) _DeclSpec _ReturnType __cdecl _VFuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _Args);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_SIZE_EX(_DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec size_t __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2);

#define __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_SIZE_EX(_DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec size_t __cdecl _FuncName(_SalAttributeDst _DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3);


#define __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_0_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName(_DstType *_Dst)

#define __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_0_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst)

#define __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_1_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName(_DstType *_Dst, _TType1 _TArg1)

#define __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_1_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1)

#define __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_2_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName(_DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2)

#define __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_2_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)

#define __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_3_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName(_DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3)

#define __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_3_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)

#define __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_0_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName(_DstType *_Dst)

#define __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_0_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst)

#define __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_1_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName(_DstType *_Dst, _TType1 _TArg1)

#define __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_1_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1)

#define __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_2_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName(_DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2)

#define __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_2_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)

#define __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_3_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3) \
  _CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName(_DstType *_Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3)

#define __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_3_EX(_ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)

#endif  /* defined(__cplusplus) && _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES */
#endif  /* !RC_INVOKED */

  struct threadlocaleinfostruct;
  struct threadmbcinfostruct;
  typedef struct threadlocaleinfostruct *pthreadlocinfo;
  typedef struct threadmbcinfostruct    *pthreadmbcinfo;
  struct __lc_time_data;

  typedef struct localeinfo_struct {
    pthreadlocinfo locinfo;
    pthreadmbcinfo mbcinfo;
  } _locale_tstruct, *_locale_t;

#if __MSVCRT_VERSION__ >= 0x0800
#ifndef _THREADLOCALEINFO
  typedef struct localerefcount {
    char    *locale;
    wchar_t *wlocale;
    int     *refcount;
    int     *wrefcount;
  } locrefcount;

  typedef struct threadlocaleinfostruct {
    int                    refcount;
    unsigned int           lc_codepage;
    unsigned int           lc_collate_cp;
    unsigned int           lc_time_cp;
    locrefcount            lc_category[6];
    int                    lc_clike;
    int                    mb_cur_max;
    int                   *lconv_intl_refcount;
    int                   *lconv_num_refcount;
    int                   *lconv_mon_refcount;
    struct lconv          *lconv;
    int                   *ctype1_refcount;
    unsigned short        *ctype1;
    const unsigned short  *pctype;
    const unsigned char   *pclmap;
    const unsigned char   *pcumap;
    struct __lc_time_data *lc_time_curr;
    wchar_t               *locale_name[6];
  } threadlocinfo;
#define _THREADLOCALEINFO
#endif  /* !_THREADLOCALEINFO */
#else  /* __MSVCRT_VERSION__ >= 0x0800 */
#ifndef _TAGLC_ID_DEFINED
  typedef struct tagLC_ID {
    unsigned short wLanguage;
    unsigned short wCountry;
    unsigned short wCodePage;
  } LC_ID, *LPLC_ID;
#define _TAGLC_ID_DEFINED
#endif  /* !_TAGLC_ID_DEFINED */

#ifndef _THREADLOCALEINFO
  typedef struct threadlocaleinfostruct {
    int refcount;
    unsigned int           lc_codepage;
    unsigned int           lc_collate_cp;
    unsigned long          lc_handle[6];
    LC_ID                  lc_id[6];
    struct {
      char                *locale;
      wchar_t             *wlocale;
      int                 *refcount;
      int                 *wrefcount;
    } lc_category[6];
    int                    lc_clike;
    int                    mb_cur_max;
    int                   *lconv_intl_refcount;
    int                   *lconv_num_refcount;
    int                   *lconv_mon_refcount;
    struct lconv          *lconv;
    int                   *ctype1_refcount;
    unsigned short        *ctype1;
    const unsigned short  *pctype;
    const unsigned char   *pclmap;
    const unsigned char   *pcumap;
    struct __lc_time_data *lc_time_curr;
  } threadlocinfo;
#define _THREADLOCALEINFO
#endif  /* !_THREADLOCALEINFO */
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#ifndef __crt_typefix
#define __crt_typefix(ctype)
#endif  /* !__crt_typefix */

#ifndef _CRT_UNUSED
#define _CRT_UNUSED(x) (void)x
#endif  /* !_CRT_UNUSED */

#ifndef __WIDL__
#pragma pack(pop)
#endif  /* !__WIDL__ */

#endif /* _INC_CRTDEFS */
