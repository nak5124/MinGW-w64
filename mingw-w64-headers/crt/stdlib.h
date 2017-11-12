/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#include <crtdefs.h>
#include <limits.h>

#if defined(__USE_MINGW_ANSI_STDIO) && ((__USE_MINGW_ANSI_STDIO + 0) != 0) && !defined(__USE_MINGW_STRTOX)
#define __USE_MINGW_STRTOX 1
#endif  /* defined(__USE_MINGW_ANSI_STDIO) && ((__USE_MINGW_ANSI_STDIO + 0) != 0) && !defined(__USE_MINGW_STRTOX) */

#pragma pack(push, _CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

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

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _ONEXIT_T_DEFINED

  typedef int (__cdecl *_onexit_t)(void);

#ifndef NO_OLDNAMES
#define onexit_t _onexit_t
#endif  /* !NO_OLDNAMES */
#define _ONEXIT_T_DEFINED
#endif  /* !_ONEXIT_T_DEFINED */

#ifndef _DIV_T_DEFINED

  typedef struct _div_t {
    int quot;
    int rem;
  } div_t;

  typedef struct _ldiv_t {
    long quot;
    long rem;
  } ldiv_t;

  typedef struct _lldiv_t {
    long long quot;
    long long rem;
  } lldiv_t;

#define _DIV_T_DEFINED
#endif  /* !_DIV_T_DEFINED */

#ifndef _CRT_DOUBLE_DEC

#ifndef _LDSUPPORT

#pragma pack(4)
  typedef struct {
    unsigned char ld[10];
  } _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((unsigned char *)(&(x)->ld))

#else  /* !_LDSUPPORT */

#pragma push_macro("long")
#undef long
  typedef long double _LDOUBLE;
#pragma pop_macro("long")

#define _PTR_LD(x) ((unsigned char  *)(x))

#endif  /* !_LDSUPPORT */

  typedef struct {
    double x;
  } _CRT_DOUBLE;

  typedef struct {
    float f;
  } _CRT_FLOAT;

#pragma push_macro("long")
#undef long

  typedef struct {
    long double x;
  } _LONGDOUBLE;

#pragma pop_macro("long")

#pragma pack(4)
  typedef struct {
    unsigned char ld12[12];
  } _LDBL12;
#pragma pack()

#define _CRT_DOUBLE_DEC
#endif  /* !_CRT_DOUBLE_DEC */

#define RAND_MAX 0x7fff

#ifndef MB_CUR_MAX
#if __MSVCRT_VERSION__ >= 0x0800 || defined(_X86_)
  _CRTIMP int * __cdecl __p___mb_cur_max(void);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 || defined(_X86_) */
#define __MB_CUR_MAX(ptloci) (ptloci)->mb_cur_max
#define   MB_CUR_MAX         ___mb_cur_max_func()
  _CRTIMP extern int          __mb_cur_max;
  _CRTIMP        int __cdecl ___mb_cur_max_func(void);
  _CRTIMP        int __cdecl ___mb_cur_max_l_func(_locale_t);
#endif  /* !MB_CUR_MAX */

#define __max(a, b) (((a) > (b)) ? (a) : (b))
#define __min(a, b) (((a) < (b)) ? (a) : (b))

#define _MAX_PATH         260
#define _MAX_DRIVE        3
#define _MAX_DIR          256
#define _MAX_FNAME        256
#define _MAX_EXT          256

#define _OUT_TO_DEFAULT   0
#define _OUT_TO_STDERR    1
#define _OUT_TO_MSGBOX    2
#define _REPORT_ERRMODE   3

#define _WRITE_ABORT_MSG  0x1
#define _CALL_REPORTFAULT 0x2

#define _MAX_ENV          32767

  typedef void (__cdecl *_purecall_handler)(void);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);  /* We provide emu. */
#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(void);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */

  typedef void (__cdecl *_invalid_parameter_handler)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, uintptr_t);

  _CRTIMP _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _CRTIMP _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(void);

#ifndef _CRT_ERRNO_DEFINED
  _CRTIMP extern int * __cdecl _errno(void);
#define errno (*_errno())

  _CRTIMP errno_t __cdecl _set_errno(int _Value);
  _CRTIMP errno_t __cdecl _get_errno(int *_Value);
#define _CRT_ERRNO_DEFINED
#endif  /* !_CRT_ERRNO_DEFINED */

  _CRTIMP unsigned long * __cdecl __doserrno(void);
#define _doserrno (*__doserrno())

  errno_t __cdecl _set_doserrno(unsigned long _Value);
  errno_t __cdecl _get_doserrno(unsigned long *_Value);

#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP char ** __cdecl __sys_errlist(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#define _sys_errlist (__sys_errlist())
  _CRTIMP int *   __cdecl __sys_nerr(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#define _sys_nerr    (*__sys_nerr())

#else  /* __MSVCRT_VERSION__ >= 0x0800 */

  _CRTIMP extern char *_sys_errlist[];
  _CRTIMP extern int   _sys_nerr;
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */

  /* We have a fallback definition of __p___argv for msvcrt versions that lack it. */
  _CRTIMP char ***    __cdecl __p___argv(void);
#if __MSVCRT_VERSION__ >= 0x0800 || defined(_X86_)
  _CRTIMP int *       __cdecl __p___argc(void);
  _CRTIMP wchar_t *** __cdecl __p___wargv(void);

  _CRTIMP char ***    __cdecl __p__environ(void);
  _CRTIMP wchar_t *** __cdecl __p__wenviron(void);

  _CRTIMP char **     __cdecl __p__pgmptr(void);
  _CRTIMP wchar_t **  __cdecl __p__wpgmptr(void);

  _CRTIMP int *       __cdecl __p__fmode(void);

#ifndef __argc
#define __argc  (* __p___argc())
#endif  /* !__argc */
#ifndef __wargv
#define __wargv (* __p___wargv())
#endif  /* !__wargv */

#ifndef _environ
#define _environ  (* __p__environ())
#endif  /* !_environ */
#ifndef _wenviron
#define _wenviron (* __p__wenviron())
#endif  /* !_wenviron */

#ifndef _pgmptr
#define _pgmptr  (* __p__pgmptr())
#endif  /* !_pgmptr */
#ifndef _wpgmptr
#define _wpgmptr (* __p__wpgmptr())
#endif  /* !_wpgmptr */

#ifndef _fmode
#define _fmode (* __p__fmode())
#endif  /* !_fmode */
#else  /* __MSVCRT_VERSION__ >= 0x0800 || defined(_X86_) */
  _CRTIMP extern int        __argc;
  _CRTIMP extern char **    __argv;
  _CRTIMP extern wchar_t ** __wargv;

  _CRTIMP extern char **     _environ;
  _CRTIMP extern wchar_t **  _wenviron;

  _CRTIMP extern char *      _pgmptr;
  _CRTIMP extern wchar_t *   _wpgmptr;

  _CRTIMP extern int         _fmode;
#endif  /* __MSVCRT_VERSION__ >= 0x0800 || defined(_X86_) */
#ifndef __argv
#define __argv  (* __p___argv())
#endif  /* !__argv */

  _CRTIMP errno_t __cdecl _get_pgmptr(char **_Value);
  _CRTIMP errno_t __cdecl _get_wpgmptr(wchar_t **_Value);

  _CRTIMP errno_t __cdecl _set_fmode(int _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(int *_PMode);

#if __MSVCRT_VERSION__ == 0x0700
  _CRTIMP extern unsigned int _osplatform;
  _CRTIMP extern unsigned int _osver;
  _CRTIMP extern unsigned int _winver;
  _CRTIMP extern unsigned int _winmajor;
  _CRTIMP extern unsigned int _winminor;

  _CRTIMP errno_t __cdecl _get_osplatform(unsigned int *_Value);
  _CRTIMP errno_t __cdecl _get_osver(unsigned int *_Value);
  _CRTIMP errno_t __cdecl _get_winver(unsigned int *_Value);
  _CRTIMP errno_t __cdecl _get_winmajor(unsigned int *_Value);
  _CRTIMP errno_t __cdecl _get_winminor(unsigned int *_Value);
#endif  /* __MSVCRT_VERSION__ == 0x0700 */

#ifndef _countof
#ifndef __cplusplus
#define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))
#else  /* !__cplusplus */
extern "C++" {
  template <typename _CountofType, size_t _SizeOfArray>
    char (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#define _countof(_Array) (sizeof(*__countof_helper(_Array)) + 0)
}
#endif  /* !__cplusplus */
#endif  /* !_countof */

#ifndef _CRT_TERMINATE_DEFINED
#pragma push_macro("exit")
#undef exit
  /* _CRTIMP */ void __cdecl __MINGW_NOTHROW  exit(int _Code) __MINGW_ATTRIB_NORETURN;
#pragma pop_macro("exit")
  /* _CRTIMP */ void __cdecl __MINGW_NOTHROW _exit(int _Code) __MINGW_ATTRIB_NORETURN;

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
#endif  /* _CRT_TERMINATE_DEFINED */

  _CRTIMP unsigned int __cdecl _set_abort_behavior(unsigned int _Flags, unsigned int _Mask);

#ifndef _CRT_ABS_DEFINED
                    int       __cdecl abs(int _X);
                    long      __cdecl labs(long _X);
#define _CRT_ABS_DEFINED
#endif  /* !_CRT_ABS_DEFINED */
  __MINGW_EXTENSION long long __cdecl llabs(long long _X);  /* Provided in libmingwex. */
#ifndef __CRT__NO_INLINE
  __MINGW_EXTENSION __CRT_INLINE long long __cdecl llabs(long long _j) {
    return (_j >= 0 ? _j : -_j);
  }
#endif  /* !__CRT__NO_INLINE */

  /* Provided in libmingwex. */
  __MINGW_EXTENSION __int64 __cdecl _abs64(__int64);
#ifdef __MINGW_INTRIN_INLINE
  __MINGW_INTRIN_INLINE __int64 __cdecl _abs64(__int64 x) {
    return __builtin_llabs(x);
  }
#endif  /* __MINGW_INTRIN_INLINE */

                int    __cdecl  atexit(void (__cdecl *)(void));  /* Provided in libmingw32. */
#ifndef _CRT_ATOF_DEFINED
  /* _CRTIMP */ double __cdecl  atof(const char *_String);
  _CRTIMP       double __cdecl _atof_l(const char *_String, _locale_t _Locale);
#define _CRT_ATOF_DEFINED
#endif  /* !_CRT_ATOF_DEFINED */
                    /* _CRTIMP */ int       __cdecl  atoi(const char *_Str);
                    _CRTIMP       int       __cdecl _atoi_l(const char *_Str, _locale_t _Locale);
                    /* _CRTIMP */ long      __cdecl  atol(const char *_Str);
                    _CRTIMP       long      __cdecl _atol_l(const char *_Str, _locale_t _Locale);
#if __MSVCRT_VERSION__ >= 0x1200
  __MINGW_EXTENSION _CRTIMP       long long __cdecl  atoll(const char *_Str);
  __MINGW_EXTENSION _CRTIMP       long long __cdecl _atoll_l(const char *_Str, _locale_t _Locale);
#else  /* __MSVCRT_VERSION__ >= 0x1200 */
  __MINGW_EXTENSION               long long __cdecl  atoll(const char *_Str);  /* Provided in libmingwex. */
#endif  /* __MSVCRT_VERSION__ >= 0x1200 */
#ifndef _CRT_ALGO_DEFINED
  /* _CRTIMP */ void * __cdecl  bsearch_s(const void *_Key, const void *_Base, rsize_t _NumOfElements, rsize_t _SizeOfElements, int (__cdecl *_PtFuncCompare)(void *, const void *, const void *), void * _Context);
  /* _CRTIMP */ void * __cdecl  bsearch(const void *_Key, const void *_Base, size_t _NumOfElements, size_t _SizeOfElements, int (__cdecl *_PtFuncCompare)(const void *, const void *));

  /* _CRTIMP */ void   __cdecl  qsort_s(void *_Base, rsize_t _NumOfElements, rsize_t _SizeOfElements, int (__cdecl *_PtFuncCompare)(void *, const void *, const void *), void *_Context);
  /* _CRTIMP */ void   __cdecl  qsort(void *_Base, size_t _NumOfElements, size_t _SizeOfElements, int (__cdecl *_PtFuncCompare)(const void *, const void *));
#define _CRT_ALGO_DEFINED
#endif  /* !_CRT_ALGO_DEFINED */
#if __MSVCRT_VERSION__ >= 0x0800
                    _CRTIMP       unsigned short   __cdecl _byteswap_ushort(unsigned short _Short);
                    _CRTIMP       unsigned long    __cdecl _byteswap_ulong(unsigned long _Long);
  __MINGW_EXTENSION _CRTIMP       unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#else  /* __MSVCRT_VERSION__ >= 0x0800 */
  /* Provided in libmingwex. */
                                  unsigned short   __cdecl _byteswap_ushort(unsigned short _Short);
                                  unsigned long    __cdecl _byteswap_ulong(unsigned long _Long);
  __MINGW_EXTENSION               unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */
                    /* _CRTIMP */ div_t            __cdecl  div(int _Numerator, int _Denominator);

                    /* _CRTIMP */ char *           __cdecl  getenv(const char *_VarName) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
                    /* _CRTIMP */ errno_t          __cdecl  getenv_s(size_t *_ReturnSize, char *_DstBuf, rsize_t _DstSize, const char *_VarName);

                    _CRTIMP       errno_t          __cdecl _dupenv_s(char **_PBuffer, size_t *_PBufferSizeInBytes, const char *_VarName);

                    _CRTIMP       errno_t          __cdecl _itoa_s(int _Value, char *_DstBuf, size_t _Size, int _Radix);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(errno_t, _itoa_s, int, _Value, char, _Dest, int, _Radix)
                    _CRTIMP       char *           __cdecl _itoa(int _Value, char *_Dest, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_EXTENSION _CRTIMP       errno_t          __cdecl _i64toa_s(__int64 _Val, char *_DstBuf, size_t _Size, int _Radix);
  __MINGW_EXTENSION _CRTIMP       char *           __cdecl _i64toa(__int64 _Val, char *_DstBuf, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_EXTENSION _CRTIMP       errno_t          __cdecl _ui64toa_s(unsigned __int64 _Val, char *_DstBuf, size_t _Size, int _Radix);
  __MINGW_EXTENSION _CRTIMP       char *           __cdecl _ui64toa(unsigned __int64 _Val, char *_DstBuf, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_EXTENSION _CRTIMP       __int64          __cdecl _atoi64(const char *_String);
  __MINGW_EXTENSION _CRTIMP       __int64          __cdecl _atoi64_l(const char *_String, _locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP       __int64          __cdecl _strtoi64(const char *_String, char **_EndPtr, int _Radix);
  __MINGW_EXTENSION _CRTIMP       __int64          __cdecl _strtoi64_l(const char *_String, char **_EndPtr, int _Radix, _locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP       unsigned __int64 __cdecl _strtoui64(const char *_String, char **_EndPtr, int _Radix);
  __MINGW_EXTENSION _CRTIMP       unsigned __int64 __cdecl _strtoui64_l(const char *_String, char **_EndPtr, int _Radix, _locale_t _Locale);
                    /* _CRTIMP */ ldiv_t           __cdecl  ldiv(long _Numerator, long _Denominator);
  __MINGW_EXTENSION /* _CRTIMP */ lldiv_t          __cdecl  lldiv(long long _Numerator, long long _Denominator);  /* Provided in libmingwex. */
                    _CRTIMP       errno_t          __cdecl _ltoa_s(long _Val, char *_DstBuf, size_t _Size, int _Radix);
                    _CRTIMP       char *           __cdecl _ltoa(long _Value, char *_Dest, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
                    /* _CRTIMP */ int              __cdecl  mblen(const char *_Ch, size_t _MaxCount);
                    _CRTIMP       int              __cdecl _mblen_l(const char *_Ch, size_t _MaxCount, _locale_t _Locale);
                    _CRTIMP       size_t           __cdecl _mbstrlen(const char *_Str);
                    _CRTIMP       size_t           __cdecl _mbstrlen_l(const char *_Str, _locale_t _Locale);
                    _CRTIMP       size_t           __cdecl _mbstrnlen(const char *_Str, size_t _MaxCount);
                    _CRTIMP       size_t           __cdecl _mbstrnlen_l(const char *_Str, size_t _MaxCount, _locale_t _Locale);
                    /* _CRTIMP */ int              __cdecl  mbtowc(wchar_t * __restrict__ _DstCh, const char * __restrict__ _SrcCh, size_t _SrcSizeInBytes);
                    _CRTIMP       int              __cdecl _mbtowc_l(wchar_t * __restrict__ _DstCh, const char * __restrict__ _SrcCh, size_t _SrcSizeInBytes, _locale_t _Locale);
                    /* _CRTIMP */ errno_t          __cdecl  mbstowcs_s(size_t *_PtNumOfCharConverted, wchar_t *_DstBuf, size_t _SizeInWords, const char *_SrcBuf, size_t _MaxCount);
                    /* _CRTIMP */ size_t           __cdecl  mbstowcs(wchar_t * __restrict__ _Dest, const char * __restrict__ _Source, size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

                    _CRTIMP       errno_t          __cdecl _mbstowcs_s_l(size_t *_PtNumOfCharConverted, wchar_t *_DstBuf, size_t _SizeInWords, const char *_SrcBuf, size_t _MaxCount, _locale_t _Locale);
                    _CRTIMP       size_t           __cdecl _mbstowcs_l(wchar_t * __restrict__ _Dest, const char * __restrict__ _Source, size_t _MaxCount, _locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

                                  int              __cdecl  mkstemp(char *template_name);  /* Provided in libmingwex. */

#ifndef __CRT__NO_INLINE
  __MINGW_EXTENSION __CRT_INLINE long long __cdecl atoll(const char *_c) {
    return _atoi64(_c);
  }
#endif  /* !__CRT__NO_INLINE */

  /* _CRTIMP */ int     __cdecl rand(void);
#ifdef _CRT_RAND_S
  _CRTIMP       errno_t __cdecl rand_s(unsigned int *_RandomValue);  /* We provide emu. */
#endif  /* _CRT_RAND_S */
#if defined(_POSIX) || defined(_POSIX_THREAD_SAFE_FUNCTIONS)
#ifndef rand_r
#define rand_r(__seed) (__seed == __seed ? rand() : rand())
#endif  /* !rand_r */
#endif  /* defined(_POSIX) || defined(_POSIX_THREAD_SAFE_FUNCTIONS) */

  _CRTIMP       int         __cdecl _set_error_mode(int _Mode);

  /* _CRTIMP */ void        __cdecl  srand(unsigned int _Seed);

  /* _CRTIMP */ double      __cdecl  strtod(const char * __restrict__ _Str, char ** __restrict__ _EndPtr) __MINGW_NOTHROW;
                float       __cdecl  strtof(const char * __restrict__ nptr, char ** __restrict__ endptr) __MINGW_NOTHROW;  /* Provided in libmingwex. */
                long double __cdecl  strtold(const char * __restrict__ s, char ** __restrict__ se) __MINGW_NOTHROW;        /* Provided in libmingwex. */

  /* Provided in libmingwex. */
  double      __cdecl __mingw_strtod(const char * __restrict__ src, char ** __restrict__ endptr);
  float       __cdecl __mingw_strtof(const char * __restrict__ src, char ** __restrict__ endptr);
  long double __cdecl __mingw_strtold(const char * __restrict__ src, char ** __restrict__ endptr);
#if __USE_MINGW_STRTOX
  __CRT_INLINE double __cdecl __MINGW_NOTHROW strtod(const char * __restrict__ _Str, char ** __restrict__ _EndPtr) {
    return __mingw_strtod(_Str, _EndPtr);
  }
  __CRT_INLINE float __cdecl __MINGW_NOTHROW strtof(const char * __restrict__ _Str, char ** __restrict__ _EndPtr) {
    return __mingw_strtof(_Str, _EndPtr);
  }
  __CRT_INLINE long double __cdecl __MINGW_NOTHROW strtold(const char * __restrict__ _Str, char ** __restrict__ _EndPtr) {
    return __mingw_strtold(_Str, _EndPtr);
  }
#endif  /* __USE_MINGW_STRTOX */
                    _CRTIMP       double             __cdecl _strtod_l(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, _locale_t _Locale);
                    /* _CRTIMP */ long               __cdecl  strtol(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, int _Radix);
                    _CRTIMP       long               __cdecl _strtol_l(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, int _Radix, _locale_t _Locale);
  __MINGW_EXTENSION               long long          __cdecl  strtoll(const char * __restrict__ nptr, char ** __restrict__ endptr, int base);  /* Provided in libmingwex. */
  __MINGW_EXTENSION _CRTIMP       long long          __cdecl _strtoll_l(const char *_Str, char ** _EndPtr, int _Radix, _locale_t _Locale);
                    /* _CRTIMP */ unsigned long      __cdecl  strtoul(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, int _Radix);  /* Provided in libmingwex. */
                    _CRTIMP       unsigned long      __cdecl _strtoul_l(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, int _Radix, _locale_t _Locale);
  __MINGW_EXTENSION               unsigned long long __cdecl  strtoull(const char * __restrict__ nptr, char ** __restrict__ endptr, int base);  /* Provided in libmingwex. */
  __MINGW_EXTENSION _CRTIMP       unsigned long long __cdecl _strtoull_l(const char *_Str, char ** _EndPtr, int _Radix, _locale_t _Locale);
                    _CRTIMP       long double        __cdecl _strtold_l(const char *_Str, char ** _EndPtr, _locale_t _Locale);
                    _CRTIMP       float              __cdecl _strtof_l(const char *_Str, char ** _EndPtr, _locale_t _Locale);

  /* libmingwex.a provides a c99-compliant strto{d,f,ld}() exported as __strto{d,f,ld}() */
  extern double      __cdecl __strtod(const char * __restrict__ src, char ** __restrict__ endptr) __MINGW_NOTHROW;
  extern float       __cdecl __strtof(const char * __restrict__ src, char ** __restrict__ endptr) __MINGW_NOTHROW;
  extern long double __cdecl __strtold(const char * __restrict__ src, char ** __restrict__ endptr) __MINGW_NOTHROW;
/* The ucrtbase version of strtod is C99 compliant, so we don't need to redirect it to the mingw version. */
#if !defined(__USE_MINGW_STRTOX) && __MSVCRT_VERSION__ < 0x1400
#define strtod __strtod
#endif  /* !defined(__USE_MINGW_STRTOX) && __MSVCRT_VERSION__ < 0x1400 */

#ifndef _CRT_SYSTEM_DEFINED
  /* _CRTIMP */ int     __cdecl  system(const char *_Command);
#define _CRT_SYSTEM_DEFINED
#endif  /* !_CRT_SYSTEM_DEFINED */

  _CRTIMP       errno_t __cdecl _ultoa_s(unsigned long _Val, char *_DstBuf, size_t _Size, int _Radix);
  _CRTIMP       char *  __cdecl _ultoa(unsigned long _Value, char *_Dest, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ int     __cdecl  wctomb(char *_MbCh, wchar_t _WCh) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       int     __cdecl _wctomb_l(char *_MbCh, wchar_t _WCh, _locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t __cdecl  wctomb_s(int *_SizeConverted, char *_MbCh, rsize_t _SizeInBytes, wchar_t _WCh);
  _CRTIMP       errno_t __cdecl _wctomb_s_l(int *_SizeConverted, char *_MbCh, size_t _SizeInBytes, wchar_t _WCh, _locale_t _Locale);
  _CRTIMP       errno_t __cdecl  wcstombs_s(size_t *_PtNumOfCharConverted, char *_Dst, size_t _DstSizeInBytes, const wchar_t *_Src, size_t _MaxCountInBytes);
  /* _CRTIMP */ size_t  __cdecl  wcstombs(char * __restrict__ _Dest, const wchar_t * __restrict__ _Source, size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t __cdecl _wcstombs_s_l(size_t *_PtNumOfCharConverted, char *_Dst, size_t _DstSizeInBytes, const wchar_t *_Src, size_t _MaxCountInBytes, _locale_t _Locale);
  _CRTIMP       size_t  __cdecl _wcstombs_l(char * __restrict__ _Dest, const wchar_t * __restrict__ _Source, size_t _MaxCount, _locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

#ifndef _CRT_ALLOCATION_DEFINED
  /* _CRTIMP */ void * __cdecl  calloc(size_t _Count, size_t _Size);
  /* _CRTIMP */ void   __cdecl  free(void *_Memory);
  /* _CRTIMP */ void * __cdecl  malloc(size_t _Size);
  /* _CRTIMP */ void * __cdecl  realloc(void *_Memory, size_t _NewSize);
  _CRTIMP       void * __cdecl _recalloc(void *_Memory, size_t _Count, size_t _Size);  /* We provide emu. */
/* Make sure that X86intrin.h doesn't produce here collisions. */
#if (!defined(_XMMINTRIN_H_INCLUDED) && !defined(_MM_MALLOC_H_INCLUDED)) || defined(_aligned_malloc)
#pragma push_macro("_aligned_free")
#pragma push_macro("_aligned_malloc")
#undef _aligned_free
#undef _aligned_malloc
  _CRTIMP void   __cdecl _aligned_free(void *_Memory);
  _CRTIMP void * __cdecl _aligned_malloc(size_t _Size, size_t _Alignment);
#pragma pop_macro("_aligned_free")
#pragma pop_macro("_aligned_malloc")
#endif  /* (!defined(_XMMINTRIN_H_INCLUDED) && !defined(_MM_MALLOC_H_INCLUDED)) || defined(_aligned_malloc) */
  _CRTIMP void * __cdecl _aligned_offset_malloc(size_t _Size, size_t _Alignment, size_t _Offset);
  _CRTIMP void * __cdecl _aligned_realloc(void *_Memory, size_t _NewSize, size_t _Alignment);
  _CRTIMP void * __cdecl _aligned_offset_realloc(void *_Memory, size_t _Size, size_t _Alignment, size_t _Offset);
#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP void * __cdecl _aligned_recalloc(void *_Memory, size_t _Count, size_t _Size, size_t _Alignment);
  _CRTIMP void * __cdecl _aligned_offset_recalloc(void *_Memory, size_t _Count, size_t _Size, size_t _Alignment, size_t _Offset);
  _CRTIMP size_t __cdecl _aligned_msize(void *_Memory, size_t _Alignment, size_t _Offset);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */
#define _CRT_ALLOCATION_DEFINED
#endif  /* !_CRT_ALLOCATION_DEFINED */

#ifndef _WSTDLIB_DEFINED

  _CRTIMP errno_t   __cdecl _itow_s(int _Val, wchar_t *_DstBuf, size_t _SizeInWords, int _Radix);
  _CRTIMP wchar_t * __cdecl _itow(int _Value, wchar_t *_Dest, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t   __cdecl _ltow_s(long _Val, wchar_t *_DstBuf, size_t _SizeInWords, int _Radix);
  _CRTIMP wchar_t * __cdecl _ltow(long _Value, wchar_t *_Dest, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t   __cdecl _ultow_s(unsigned long _Val, wchar_t *_DstBuf, size_t _SizeInWords, int _Radix);
  _CRTIMP wchar_t * __cdecl _ultow(unsigned long _Value, wchar_t *_Dest, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  /* Provided in libmingwex. */
  double      __cdecl __mingw_wcstod(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr);
  float       __cdecl __mingw_wcstof(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr);
  long double __cdecl __mingw_wcstold(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr);
#if __USE_MINGW_STRTOX
  __mingw_ovr double __cdecl wcstod(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr) {
    return __mingw_wcstod(_Str, _EndPtr);
  }
  __mingw_ovr float __cdecl wcstof(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr) {
    return __mingw_wcstof(_Str, _EndPtr);
  }
  __mingw_ovr long double __cdecl wcstold(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr) {
    return __mingw_wcstold(_Str, _EndPtr);
  }
#else  /* __USE_MINGW_STRTOX */
                    /* _CRTIMP */ double             __cdecl  wcstod(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr);
                                  float              __cdecl  wcstof(const wchar_t * __restrict__ wcs, wchar_t ** __restrict__ wcse);   /* Provided in libmingwex. */
                                  long double        __cdecl  wcstold(const wchar_t * __restrict__ wcs, wchar_t ** __restrict__ wcse);  /* Provided in libmingwex. */
#endif  /* __USE_MINGW_STRTOX */
                    _CRTIMP       double             __cdecl _wcstod_l(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr, _locale_t _Locale);
                    /* _CRTIMP */ long               __cdecl  wcstol(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr, int _Radix);
                    _CRTIMP       long               __cdecl _wcstol_l(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr, int _Radix, _locale_t _Locale);
  __MINGW_EXTENSION /* _CRTIMP */ long long          __cdecl  wcstoll(const wchar_t *_Str, wchar_t **_EndPtr, int _Radix);
  __MINGW_EXTENSION _CRTIMP       long long          __cdecl _wcstoll_l(const wchar_t *_Str, wchar_t **_EndPtr, int _Radix, _locale_t _Locale);
                    /* _CRTIMP */ unsigned long      __cdecl  wcstoul(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr, int _Radix);
                    _CRTIMP       unsigned long      __cdecl _wcstoul_l(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr, int _Radix, _locale_t _Locale);
  __MINGW_EXTENSION /* _CRTIMP */ unsigned long long __cdecl  wcstoull(const wchar_t *_Str, wchar_t ** _EndPtr, int _Radix);
  __MINGW_EXTENSION _CRTIMP       unsigned long long __cdecl _wcstoull_l(const wchar_t *_Str, wchar_t ** _EndPtr, int _Radix, _locale_t _Locale);
                    _CRTIMP       long double        __cdecl _wcstold_l(const wchar_t * _Str, wchar_t ** _EndPtr, _locale_t _Locale);
                    _CRTIMP       float              __cdecl _wcstof_l(const wchar_t *_Str, wchar_t ** _EndPtr, _locale_t _Locale);

  _CRTIMP wchar_t * __cdecl _wgetenv(const wchar_t *_VarName) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t   __cdecl _wgetenv_s(size_t *_ReturnSize, wchar_t *_DstBuf, size_t _DstSizeInWords, const wchar_t *_VarName);

  _CRTIMP errno_t   __cdecl _wdupenv_s(wchar_t **_Buffer, size_t *_BufferSizeInWords, const wchar_t *_VarName);

#ifndef _CRT_WSYSTEM_DEFINED
  _CRTIMP int __cdecl _wsystem(const wchar_t *_Command);
#define _CRT_WSYSTEM_DEFINED
#endif  /* !_CRT_WSYSTEM_DEFINED */

                    _CRTIMP double           __cdecl _wtof(const wchar_t *_Str);
                    _CRTIMP double           __cdecl _wtof_l(const wchar_t *_Str, _locale_t _Locale);
                    _CRTIMP int              __cdecl _wtoi(const wchar_t *_Str);
                    _CRTIMP int              __cdecl _wtoi_l(const wchar_t *_Str, _locale_t _Locale);
                    _CRTIMP long             __cdecl _wtol(const wchar_t *_Str);
                    _CRTIMP long             __cdecl _wtol_l(const wchar_t *_Str, _locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP long long        __cdecl _wtoll(const wchar_t *_Str);
  __MINGW_EXTENSION _CRTIMP long long        __cdecl _wtoll_l(const wchar_t *_Str, _locale_t _Locale);

  __MINGW_EXTENSION _CRTIMP errno_t          __cdecl _i64tow_s(__int64 _Val, wchar_t *_DstBuf, size_t _SizeInWords, int _Radix);
  __MINGW_EXTENSION _CRTIMP wchar_t *        __cdecl _i64tow(__int64 _Val, wchar_t *_DstBuf, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_EXTENSION _CRTIMP errno_t          __cdecl _ui64tow_s(unsigned __int64 _Val, wchar_t *_DstBuf, size_t _SizeInWords, int _Radix);
  __MINGW_EXTENSION _CRTIMP wchar_t *        __cdecl _ui64tow(unsigned __int64 _Val, wchar_t *_DstBuf, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_EXTENSION _CRTIMP __int64          __cdecl _wtoi64(const wchar_t *_Str);
  __MINGW_EXTENSION _CRTIMP __int64          __cdecl _wtoi64_l(const wchar_t *_Str, _locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP __int64          __cdecl _wcstoi64(const wchar_t *_Str, wchar_t **_EndPtr, int _Radix);
  __MINGW_EXTENSION _CRTIMP __int64          __cdecl _wcstoi64_l(const wchar_t *_Str, wchar_t **_EndPtr, int _Radix, _locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP unsigned __int64 __cdecl _wcstoui64(const wchar_t *_Str, wchar_t **_EndPtr, int _Radix);
  __MINGW_EXTENSION _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(const wchar_t *_Str, wchar_t **_EndPtr, int _Radix, _locale_t _Locale);

#define _WSTDLIB_DEFINED
#endif  /* !_WSTDLIB_DEFINED */

#define _CVTBUFSIZE (309 + 40)

  _CRTIMP char *  __cdecl _fullpath(char *_FullPath, const char *_Path, size_t _SizeInBytes);

  _CRTIMP errno_t __cdecl _ecvt_s(char *_DstBuf, size_t _Size, double _Val, int _NumOfDights, int *_PtDec, int *_PtSign);
  _CRTIMP char *  __cdecl _ecvt(double _Val, int _NumOfDigits, int *_PtDec, int *_PtSign) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _fcvt_s(char *_DstBuf, size_t _Size, double _Val, int _NumOfDec, int *_PtDec, int *_PtSign);
  _CRTIMP char *  __cdecl _fcvt(double _Val, int _NumOfDec, int *_PtDec, int *_PtSign) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _gcvt_s(char *_DstBuf, size_t _Size, double _Val, int _NumOfDigits);
  _CRTIMP char *  __cdecl _gcvt(double _Val, int _NumOfDigits, char *_DstBuf) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  _CRTIMP int     __cdecl _atodbl(_CRT_DOUBLE *_Result, char *_Str);
  _CRTIMP int     __cdecl _atoldbl(_LDOUBLE *_Result, char *_Str);
  _CRTIMP int     __cdecl _atoflt(_CRT_FLOAT *_Result, char *_Str);
  _CRTIMP int     __cdecl _atodbl_l(_CRT_DOUBLE *_Result, char *_Str, _locale_t _Locale);
  _CRTIMP int     __cdecl _atoldbl_l(_LDOUBLE *_Result, char *_Str, _locale_t _Locale);
  _CRTIMP int     __cdecl _atoflt_l(_CRT_FLOAT *_Result, char *_Str, _locale_t _Locale);
#if defined(__INTRIN_H_) || (defined(_X86INTRIN_H_INCLUDED) && ((__MINGW_GCC_VERSION >= 40902) || defined(__LP64__) || defined(_X86_)))
/* We already have bug-free prototypes and inline definitions for _lrotr
 * and _lrotl from either intrin.h or x86intrin.h. */
#else  /* defined(__INTRIN_H_) || ... */
/* Remove buggy x86intrin.h definitions if present (see gcc bug 61662). */
#undef _lrotl
#undef _lrotr
/* These prototypes work for x86, x64 (native Windows), and cyginwin64. */
          unsigned long __cdecl _lrotl(unsigned long _Val, int _Shift);
          unsigned long __cdecl _lrotr(unsigned long _Val, int _Shift);
#endif  /* defined(__INTRIN_H_) || ... */
  _CRTIMP errno_t       __cdecl _makepath_s(char *_PathResult, size_t _SizeInWords, const char *_Drive, const char *_Dir, const char *_Filename, const char *_Ext);
  _CRTIMP void          __cdecl _makepath(char *_Path, const char *_Drive, const char *_Dir, const char *_Filename, const char *_Ext);

          _onexit_t     __cdecl _onexit(_onexit_t _Func);

#ifndef _CRT_PERROR_DEFINED
  /* _CRTIMP */ void __cdecl perror(const char *_ErrMsg);
#define _CRT_PERROR_DEFINED
#endif  /* !_CRT_PERROR_DEFINED */

  _CRTIMP int     __cdecl _putenv(const char *_EnvString);
  _CRTIMP errno_t __cdecl _putenv_s(const char *_Name, const char *_Value);

#pragma push_macro ("_rotl")
#pragma push_macro ("_rotl64")
#pragma push_macro ("_rotr")
#pragma push_macro ("_rotr64")
#undef _rotl
#undef _rotl64
#undef _rotr
#undef _rotr64
                    unsigned int     __cdecl _rotl(unsigned int _Val, int _Shift);
  __MINGW_EXTENSION unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val, int _Shift);
                    unsigned int     __cdecl _rotr(unsigned int _Val, int _Shift);
  __MINGW_EXTENSION unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val, int Shift);
#pragma pop_macro ("_rotl")
#pragma pop_macro ("_rotl64")
#pragma pop_macro ("_rotr")
#pragma pop_macro ("_rotr64")

  _CRTIMP errno_t __cdecl _searchenv_s(const char *_Filename, const char *_EnvVar, char *_ResultPath, size_t _SizeInBytes);
  _CRTIMP void    __cdecl _searchenv(const char *_Filename, const char *_EnvVar, char *_ResultPath) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  _CRTIMP void    __cdecl _splitpath(const char *_FullPath, char *_Drive, char *_Dir, char *_Filename, char *_Ext) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _splitpath_s(const char *_FullPath, char *_Drive, size_t _DriveSize, char *_Dir, size_t _DirSize, char *_Filename, size_t _FilenameSize, char *_Ext, size_t _ExtSize);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_SPLITPATH(errno_t, _splitpath_s, char, _Dest)

  _CRTIMP void    __cdecl _swab(char *_Buf1, char *_Buf2, int _SizeInBytes);

#ifndef _WSTDLIBP_DEFINED
  _CRTIMP wchar_t * __cdecl _wfullpath(wchar_t *_FullPath, const wchar_t *_Path, size_t _SizeInWords);

  _CRTIMP errno_t   __cdecl _wmakepath_s(wchar_t *_PathResult, size_t _SIZE, const wchar_t *_Drive, const wchar_t *_Dir, const wchar_t *_Filename, const wchar_t *_Ext);
  _CRTIMP void      __cdecl _wmakepath(wchar_t *_ResultPath, const wchar_t *_Drive, const wchar_t *_Dir, const wchar_t *_Filename, const wchar_t *_Ext) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifndef _CRT_WPERROR_DEFINED
  _CRTIMP void      __cdecl _wperror(const wchar_t *_ErrMsg);
#define _CRT_WPERROR_DEFINED
#endif  /* !_CRT_WPERROR_DEFINED */

  _CRTIMP int     __cdecl _wputenv(const wchar_t *_EnvString);
  _CRTIMP errno_t __cdecl _wputenv_s(const wchar_t *_Name, const wchar_t *_Value);
  _CRTIMP errno_t __cdecl _wsearchenv_s(const wchar_t *_Filename, const wchar_t *_EnvVar, wchar_t *_ResultPath, size_t _SizeInWords);
  _CRTIMP void    __cdecl _wsearchenv(const wchar_t *_Filename, const wchar_t *_EnvVar, wchar_t *_ResultPath) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  _CRTIMP void    __cdecl _wsplitpath(const wchar_t *_FullPath, wchar_t *_Drive, wchar_t *_Dir, wchar_t *_Filename, wchar_t *_Ext) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _wsplitpath_s(const wchar_t *_FullPath, wchar_t *_Drive, size_t _DriveSize, wchar_t *_Dir, size_t _DirSize, wchar_t *_Filename, size_t _FilenameSize, wchar_t *_Ext, size_t _ExtSize);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_SPLITPATH(errno_t, _wsplitpath_s, wchar_t, _Dest)

#define _WSTDLIBP_DEFINED
#endif  /* !_WSTDLIBP_DEFINED */

  /* Not to be confused with  _set_error_mode (int). */
  _CRTIMP void __cdecl _seterrormode(int _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP void __cdecl _beep(unsigned _Frequency, unsigned _Duration) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP void __cdecl _sleep(unsigned long _Duration) __MINGW_ATTRIB_DEPRECATED;

#ifndef NO_OLDNAMES
#if 0
#ifndef __cplusplus
#ifndef NOMINMAX
#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif  /* !max */
#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif  /* !min */
#endif  /* !NOMINMAX */
#endif  /* !__cplusplus */
#endif  /* 0 */

#define sys_errlist _sys_errlist
#define sys_nerr    _sys_nerr

#define environ     _environ

  /* _CRTIMP */ char *   __cdecl ecvt(double _Val, int _NumOfDigits, int *_PtDec, int *_PtSign) __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ char *   __cdecl fcvt(double _Val, int _NumOfDec, int *_PtDec, int *_PtSign) __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ char *   __cdecl gcvt(double _Val, int _NumOfDigits, char *_DstBuf) __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ char *   __cdecl itoa(int _Val, char *_DstBuf, int _Radix) __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ char *   __cdecl ltoa(long _Val, char *_DstBuf, int _Radix) __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  /* _CRTIMP */ int      __cdecl putenv(const char *_EnvString) __MINGW_ATTRIB_DEPRECATED_MSVC2005;

#ifndef _CRT_SWAB_DEFINED
  /* _CRTIMP */ void     __cdecl swab(char *_Buf1, char *_Buf2, int _SizeInBytes) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#define _CRT_SWAB_DEFINED  /* Also in unistd.h */
#endif  /* !_CRT_SWAB_DEFINED */
  /* _CRTIMP */ char *   __cdecl ultoa(unsigned long _Val, char *_Dstbuf, int _Radix) __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
                onexit_t __cdecl onexit(onexit_t _Func);
#endif  /* !NO_OLDNAMES */

#ifndef __STRICT_ANSI__
  __MINGW_EXTENSION long long __cdecl wtoll(const wchar_t *_w);
  __MINGW_EXTENSION char *    __cdecl lltoa(long long _n, char *_c, int _i);
  __MINGW_EXTENSION char *    __cdecl ulltoa(unsigned long long _n, char *_c, int _i);
  __MINGW_EXTENSION wchar_t * __cdecl lltow(long long _n, wchar_t *_w, int _i);
  __MINGW_EXTENSION wchar_t * __cdecl ulltow(unsigned long long _n, wchar_t *_w, int _i);

/* __CRT_INLINE using non-ansi functions */
#ifndef __CRT__NO_INLINE
  __MINGW_EXTENSION __CRT_INLINE long long __cdecl wtoll(const wchar_t *_w) {
    return _wtoi64(_w);
  }
  __MINGW_EXTENSION __CRT_INLINE char * __cdecl lltoa(long long _n, char *_c, int _i) {
    return _i64toa(_n, _c, _i);
  }
  __MINGW_EXTENSION __CRT_INLINE char * __cdecl ulltoa(unsigned long long _n, char *_c, int _i) {
    return _ui64toa(_n, _c, _i);
  }
  __MINGW_EXTENSION __CRT_INLINE wchar_t * __cdecl lltow(long long _n, wchar_t *_w, int _i) {
    return _i64tow(_n, _w, _i);
  }
  __MINGW_EXTENSION __CRT_INLINE wchar_t * __cdecl ulltow(unsigned long long _n, wchar_t *_w, int _i) {
    return _ui64tow(_n, _w, _i);
  }
#endif  /* !__CRT__NO_INLINE */
#endif  /* !__STRICT_ANSI__ */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#pragma pack(pop)

#include <malloc.h>

#endif  /* _INC_STDLIB */
