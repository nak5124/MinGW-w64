/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#include <crtdefs.h>
#include <_mingw_print_push.h>

#if defined(__USE_MINGW_ANSI_STDIO) && ((__USE_MINGW_ANSI_STDIO + 0) != 0) && !defined(__USE_MINGW_STRTOX)
#define __USE_MINGW_STRTOX 1
#endif  /* defined(__USE_MINGW_ANSI_STDIO) && ((__USE_MINGW_ANSI_STDIO + 0) != 0) && !defined(__USE_MINGW_STRTOX) */

#pragma pack(push, _CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef WCHAR_MIN  /* also in stdint.h */
#define WCHAR_MIN 0U
#define WCHAR_MAX 0xffffU
#endif  /* !WCHAR_MIN */

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

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif  /* !WEOF */

#ifndef _FILE_DEFINED
  struct _iobuf {
    char *_ptr;
    int   _cnt;
    char *_base;
    int   _flag;
    int   _file;
    int   _charbuf;
    int   _bufsiz;
    char *_tmpfname;
  };
  typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif  /* !_FILE_DEFINED */

#ifndef _STDIO_DEFINED
  _CRTIMP FILE *__cdecl __acrt_iob_func(unsigned index);
#if __MSVCRT_VERSION__ >= 0x0800 || defined(_X86_)
  _CRTIMP extern FILE * __cdecl __p__iob(void);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 || defined(_X86_) */
  _CRTIMP extern FILE            _iob[];  /* A pointer to an array of FILE */
  _CRTIMP        FILE * __cdecl __iob_func(void);
#endif  /* !_STDIO_DEFINED */

#ifndef _STDSTREAM_DEFINED
#define stdin  (__acrt_iob_func(0))
#define stdout (__acrt_iob_func(1))
#define stderr (__acrt_iob_func(2))
#define _STDSTREAM_DEFINED
#endif  /* !_STDSTREAM_DEFINED */

#ifndef _FSIZE_T_DEFINED
  typedef unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif  /* !_FSIZE_T_DEFINED */

#ifndef _WFINDDATA_T_DEFINED

  struct _wfinddata32_t {
    unsigned   attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t   size;
    wchar_t    name[260];
  };

  struct _wfinddata32i64_t {
    unsigned                  attrib;
    __time32_t                time_create;
    __time32_t                time_access;
    __time32_t                time_write;
    __MINGW_EXTENSION __int64 size;
    wchar_t                   name[260];
  };

  struct _wfinddata64i32_t {
    unsigned   attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t   size;
    wchar_t    name[260];
  };

  struct _wfinddata64_t {
    unsigned                  attrib;
    __time64_t                time_create;
    __time64_t                time_access;
    __time64_t                time_write;
    __MINGW_EXTENSION __int64 size;
    wchar_t                   name[260];
  };

#ifdef _USE_32BIT_TIME_T
#define _wfinddata_t    _wfinddata32_t
#define _wfinddatai64_t _wfinddata32i64_t

#define _wfindfirst     _wfindfirst32
#define _wfindnext      _wfindnext32
#define _wfindfirsti64  _wfindfirst32i64
#define _wfindnexti64   _wfindnext32i64
#else  /* _USE_32BIT_TIME_T */
#define _wfinddata_t    _wfinddata64i32_t
#define _wfinddatai64_t _wfinddata64_t

#define _wfindfirst     _wfindfirst64i32
#define _wfindnext      _wfindnext64i32
#define _wfindfirsti64  _wfindfirst64
#define _wfindnexti64   _wfindnext64
#endif  /* _USE_32BIT_TIME_T */

#define _WFINDDATA_T_DEFINED
#endif  /* _WFINDDATA_T_DEFINED */

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

#define _WConst_return _CONST_RETURN

#ifndef _CRT_CTYPEDATA_DEFINED
#define _CRT_CTYPEDATA_DEFINED
#ifndef _CTYPE_DISABLE_MACROS
#if __MSVCRT_VERSION__ > 0x0800 || defined(_X86_)
  _CRTIMP const unsigned short ** __cdecl __p__pctype(void);
#endif  /* __MSVCRT_VERSION__ > 0x0800 || defined(_X86_) */

#ifndef __PCTYPE_FUNC
#define __PCTYPE_FUNC __pctype_func()
#endif  /* !__PCTYPE_FUNC */

  _CRTIMP        const unsigned short * __cdecl __pctype_func(void);
  _CRTIMP extern const unsigned short *          _pctype;
#endif  /* !_CTYPE_DISABLE_MACROS */
#endif  /* !_CRT_CTYPEDATA_DEFINED */

#ifndef _CRT_WCTYPEDATA_DEFINED
#define _CRT_WCTYPEDATA_DEFINED
#ifndef _CTYPE_DISABLE_MACROS
  _CRTIMP extern const unsigned short _wctype[];
#if __MSVCRT_VERSION__ > 0x0800 || defined(_X86_)
  _CRTIMP const wctype_t ** __cdecl __p__pwctype(void);
#endif  /* __MSVCRT_VERSION__ > 0x0800 || defined(_X86_) */

  _CRTIMP        const wctype_t * __cdecl __pwctype_func(void);
  _CRTIMP extern const wctype_t *          _pwctype;
#endif  /* !_CTYPE_DISABLE_MACROS */
#endif  /* !_CRT_WCTYPEDATA_DEFINED */

  extern const unsigned short __newctype[];  /* Internal CRT Global */

#define _UPPER    0x1
#define _LOWER    0x2
#define _DIGIT    0x4
#define _SPACE    0x8

#define _PUNCT    0x10
#define _CONTROL  0x20
#define _BLANK    0x40
#define _HEX      0x80

#define _LEADBYTE 0x8000
#define _ALPHA    (0x0100|_UPPER|_LOWER)

#if !defined(_UCRTBASE_STDIO_DEFINED) && __MSVCRT_VERSION__ >= 0x1400

#define UCRTBASE_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION (0x0001)
#define UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR      (0x0002)
#define UCRTBASE_PRINTF_LEGACY_WIDE_SPECIFIERS           (0x0004)
#define UCRTBASE_PRINTF_LEGACY_MSVCRT_COMPATIBILITY      (0x0008)
#define UCRTBASE_PRINTF_LEGACY_THREE_DIGIT_EXPONENTS     (0x0010)

#define UCRTBASE_SCANF_SECURECRT                         (0x0001)
#define UCRTBASE_SCANF_LEGACY_WIDE_SPECIFIERS            (0x0002)
#define UCRTBASE_SCANF_LEGACY_MSVCRT_COMPATIBILITY       (0x0004)

/* Default wide printfs and scanfs to the standard mode */
#ifndef UCRTBASE_PRINTF_DEFAULT_WIDE
#define UCRTBASE_PRINTF_DEFAULT_WIDE 0
#endif  /* !UCRTBASE_PRINTF_DEFAULT_WIDE */
#ifndef UCRTBASE_SCANF_DEFAULT_WIDE
#define UCRTBASE_SCANF_DEFAULT_WIDE 0
#endif  /* !UCRTBASE_SCANF_DEFAULT_WIDE */
#define _UCRTBASE_STDIO_DEFINED
#endif  /* !defined(_UCRTBASE_STDIO_DEFINED) && __MSVCRT_VERSION__ >= 0x1400 */

#ifndef _WCTYPE_DEFINED

  /* _CRTIMP */ int    __cdecl   iswalpha(wint_t _C);
  _CRTIMP       int    __cdecl  _iswalpha_l(wint_t _C, _locale_t _Locale);
  /* _CRTIMP */ int    __cdecl   iswupper(wint_t _C);
  _CRTIMP       int    __cdecl  _iswupper_l(wint_t _C, _locale_t _Locale);
  /* _CRTIMP */ int    __cdecl   iswlower(wint_t _C);
  _CRTIMP       int    __cdecl  _iswlower_l(wint_t _C, _locale_t _Locale);
  /* _CRTIMP */ int    __cdecl   iswdigit(wint_t _C);
  _CRTIMP       int    __cdecl  _iswdigit_l(wint_t _C, _locale_t _Locale);
  /* _CRTIMP */ int    __cdecl   iswxdigit(wint_t _C);
  _CRTIMP       int    __cdecl  _iswxdigit_l(wint_t _C, _locale_t _Locale);
  /* _CRTIMP */ int    __cdecl   iswspace(wint_t _C);
  _CRTIMP       int    __cdecl  _iswspace_l(wint_t _C, _locale_t _Locale);
  /* _CRTIMP */ int    __cdecl   iswpunct(wint_t _C);
  _CRTIMP       int    __cdecl  _iswpunct_l(wint_t _C, _locale_t _Locale);
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || _XOPEN_SOURCE >= 600 || _ISOC99_SOURCE || _POSIX_C_SOURCE >= 200112L || defined(__cplusplus)
                int    __cdecl   iswblank(wint_t _C);  /* Provided in libmingwex. */
#endif  /* (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || ... */
#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP       int    __cdecl  _iswblank_l(wint_t _C, _locale_t _Locale);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */
  /* _CRTIMP */ int    __cdecl   iswalnum(wint_t _C);
  _CRTIMP       int    __cdecl  _iswalnum_l(wint_t _C, _locale_t _Locale);
  /* _CRTIMP */ int    __cdecl   iswprint(wint_t _C);
  _CRTIMP       int    __cdecl  _iswprint_l(wint_t _C, _locale_t _Locale);
  /* _CRTIMP */ int    __cdecl   iswgraph(wint_t _C);
  _CRTIMP       int    __cdecl  _iswgraph_l(wint_t _C, _locale_t _Locale);
  /* _CRTIMP */ int    __cdecl   iswcntrl(wint_t _C);
  _CRTIMP       int    __cdecl  _iswcntrl_l(wint_t _C, _locale_t _Locale);
  /* _CRTIMP */ int    __cdecl   iswascii(wint_t _C);

  /* _CRTIMP */ int    __cdecl   isleadbyte(int _C);
  _CRTIMP       int    __cdecl  _isleadbyte_l(int _C, _locale_t _Locale);

  /* _CRTIMP */ wint_t __cdecl   towupper(wint_t _C);
  _CRTIMP       wint_t __cdecl  _towupper_l(wint_t _C, _locale_t _Locale);
  /* _CRTIMP */ wint_t __cdecl   towlower(wint_t _C);
  _CRTIMP       wint_t __cdecl  _towlower_l(wint_t _C, _locale_t _Locale);
  /* _CRTIMP */ int    __cdecl   iswctype(wint_t _C, wctype_t _Type);
  _CRTIMP       int    __cdecl  _iswctype_l(wint_t _C, wctype_t _Type, _locale_t _Locale);

  _CRTIMP       int    __cdecl __iswcsymf(wint_t _C);
  _CRTIMP       int    __cdecl  _iswcsymf_l(wint_t _C, _locale_t _Locale);
  _CRTIMP       int    __cdecl __iswcsym(wint_t _C);
  _CRTIMP       int    __cdecl  _iswcsym_l(wint_t _C, _locale_t _Locale);

  /* _CRTIMP */ int    __cdecl   is_wctype(wint_t _C, wctype_t _Type);

#define _WCTYPE_DEFINED
#endif  /* !_WCTYPE_DEFINED */

#ifndef _WDIRECT_DEFINED

  _CRTIMP wchar_t * __cdecl _wgetcwd(wchar_t *_DstBuf, int _SizeInWords);
  _CRTIMP wchar_t * __cdecl _wgetdcwd(int _Drive, wchar_t *_DstBuf, int _SizeInWords);
#define _wgetdcwd_nolock _wgetdcwd

  _CRTIMP int       __cdecl _wchdir(const wchar_t *_Path);
  _CRTIMP int       __cdecl _wmkdir(const wchar_t *_Path);
  _CRTIMP int       __cdecl _wrmdir(const wchar_t *_Path);
#define _WDIRECT_DEFINED
#endif  /* !_WDIRECT_DEFINED */

#ifndef _WIO_DEFINED
  _CRTIMP int      __cdecl _waccess(const wchar_t *_Filename, int _AccessMode) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl _waccess_s(const wchar_t *_Filename, int _AccessMode);  /* We provide emu. */
  _CRTIMP int      __cdecl _wchmod(const wchar_t *_Filename, int _Mode);
  _CRTIMP int      __cdecl _wcreat(const wchar_t *_Filename, int _PermissionMode) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename, struct _wfinddata32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename, struct _wfinddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename, struct _wfinddata64i32_t *_FindData);
  _CRTIMP int      __cdecl _wfindnext32(intptr_t _FindHandle, struct _wfinddata32_t *_FindData);
  _CRTIMP int      __cdecl _wfindnext32i64(intptr_t _FindHandle, struct _wfinddata32i64_t *_FindData);
  _CRTIMP int      __cdecl _wfindnext64i32(intptr_t _FindHandle, struct _wfinddata64i32_t *_FindData);
#else  /* __MSVCRT_VERSION__ >= 0x0800 */
#ifdef _WIN64
          intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename, struct _wfinddata32_t *_FindData);        /* On WIN64, we porvide emu. */
          intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename, struct _wfinddata32i64_t *_FindData);  /* On WIN64, we porvide emu. */
  _CRTIMP intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename, struct _wfinddata64i32_t *_FindData);  /* On WIN64, we provide alias for _wfindfirst. */
          int      __cdecl _wfindnext32(intptr_t _FindHandle, struct _wfinddata32_t *_FindData);             /* On WIN64, we porvide emu. */
          int      __cdecl _wfindnext32i64(intptr_t _FindHandle, struct _wfinddata32i64_t *_FindData);       /* On WIN64, we porvide emu. */
  _CRTIMP int      __cdecl _wfindnext64i32(intptr_t _FindHandle, struct _wfinddata64i32_t *_FindData);       /* On WIN64, we provide alias for _wfindnext. */
#else  /* _WIN64 */
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename, struct _wfinddata32_t *_FindData);        /* On WIN32, we provide alias for _wfindfirst. */
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename, struct _wfinddata32i64_t *_FindData);  /* On WIN32, we provide alias for _wfindfirsti64. */
          intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename, struct _wfinddata64i32_t *_FindData);  /* On WIN32, we provide emu. */
  _CRTIMP int      __cdecl _wfindnext32(intptr_t _FindHandle, struct _wfinddata32_t *_FindData);             /* On WIN32, we provide alias for _wfindnext. */
  _CRTIMP int      __cdecl _wfindnext32i64(intptr_t _FindHandle, struct _wfinddata32i64_t *_FindData);       /* On WIN32, we provide alias for _wfindnexti64. */
          int      __cdecl _wfindnext64i32(intptr_t _FindHandle, struct _wfinddata64i32_t *_FindData);       /* On WIN32, we provide emu. */
#endif  /* _WIN64 */
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */
  _CRTIMP intptr_t __cdecl _wfindfirst64(const wchar_t *_Filename, struct _wfinddata64_t *_FindData);
  _CRTIMP int      __cdecl _wfindnext64(intptr_t _FindHandle, struct _wfinddata64_t *_FindData);
  _CRTIMP int      __cdecl _wunlink(const wchar_t *_Filename);
  _CRTIMP int      __cdecl _wrename(const wchar_t *_OldFilename, const wchar_t *_NewFilename);
  _CRTIMP wchar_t* __cdecl _wmktemp(wchar_t *_TemplateName) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl _wmktemp_s(wchar_t *_TemplateName, size_t _SizeInWords);  /* We provide emu. */

  _CRTIMP errno_t  __cdecl _wsopen_s(int *_FileHandle, const wchar_t *_Filename, int _OpenFlag, int _ShareFlag, int _PermissionFlag);

  _CRTIMP int      __cdecl _wopen(const wchar_t *_Filename, int _OpenFlag, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int      __cdecl _wsopen(const wchar_t *_Filename, int _OpenFlag, int _ShareFlag, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

#define _WIO_DEFINED
#endif  /* !_WIO_DEFINED */

#ifndef _WLOCALE_DEFINED
  _CRTIMP wchar_t * __cdecl _wsetlocale(int _Category, const wchar_t *_Locale);
#if __MSVCRT_VERSION__ >= 0x1100
  _CRTIMP _locale_t __cdecl _wcreate_locale(int _Category, const wchar_t *_Locale);
#endif  /* __MSVCRT_VERSION__ >= 0x1100 */
#define _WLOCALE_DEFINED
#endif  /* !_WLOCALE_DEFINED */

#ifndef _WEXEC_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wexecle(const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wexeclp(const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wexeclpe(const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wexecv(const wchar_t *_Filename, const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(const wchar_t *_Filename, const wchar_t *const *_ArgList, const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(const wchar_t *_Filename, const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(const wchar_t *_Filename, const wchar_t *const *_ArgList, const wchar_t *const *_Env);
#define _WEXEC_DEFINED
#endif  /* !_WEXEC_DEFINED */

#ifndef _WSPAWN_DEFINED
  _CRTIMP intptr_t __cdecl _wspawnl(int _Mode, const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wspawnle(int _Mode, const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wspawnlp(int _Mode, const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(int _Mode, const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wspawnv(int _Mode, const wchar_t *_Filename, const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(int _Mode, const wchar_t *_Filename, const wchar_t *const *_ArgList, const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(int _Mode, const wchar_t *_Filename, const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(int _Mode, const wchar_t *_Filename, const wchar_t *const *_ArgList, const wchar_t *const *_Env);
#define _WSPAWN_DEFINED
#endif  /* !_WSPAWN_DEFINED */

#ifndef _CRT_WSYSTEM_DEFINED
  _CRTIMP int __cdecl _wsystem(const wchar_t *_Command);
#define _CRT_WSYSTEM_DEFINED
#endif  /* !_CRT_WSYSTEM_DEFINED */

#ifndef _WCTYPE_INLINE_DEFINED

#undef _CRT_WCTYPE_NOINLINE

#ifndef __cplusplus
#define iswalpha(_c)         (iswctype(_c, _ALPHA))
#define iswupper(_c)         (iswctype(_c, _UPPER))
#define iswlower(_c)         (iswctype(_c, _LOWER))
#define iswdigit(_c)         (iswctype(_c, _DIGIT))
#define iswxdigit(_c)        (iswctype(_c, _HEX))
#define iswspace(_c)         (iswctype(_c, _SPACE))
#define iswpunct(_c)         (iswctype(_c, _PUNCT))
#define iswblank(_c)         (((_c) == '\t') ? _BLANK : iswctype(_c,_BLANK))
#define iswalnum(_c)         (iswctype(_c, _ALPHA|_DIGIT))
#define iswprint(_c)         (iswctype(_c, _BLANK|_PUNCT|_ALPHA|_DIGIT))
#define iswgraph(_c)         (iswctype(_c, _PUNCT|_ALPHA|_DIGIT))
#define iswcntrl(_c)         (iswctype(_c, _CONTROL))
#define iswascii(_c)         ((unsigned)(_c) < 0x80)

#define _iswalpha_l(_c, _p)  (_iswctype_l(_c, _ALPHA,_p))
#define _iswupper_l(_c, _p)  (_iswctype_l(_c, _UPPER,_p))
#define _iswlower_l(_c, _p)  (_iswctype_l(_c, _LOWER,_p))
#define _iswdigit_l(_c, _p)  (_iswctype_l(_c, _DIGIT,_p))
#define _iswxdigit_l(_c, _p) (_iswctype_l(_c, _HEX,_p))
#define _iswspace_l(_c, _p)  (_iswctype_l(_c, _SPACE,_p))
#define _iswpunct_l(_c, _p)  (_iswctype_l(_c, _PUNCT,_p))
#define _iswblank_l(_c,_p)   (((_c) == '\t') ? _BLANK : iswctype(_c, _BLANK))
#define _iswalnum_l(_c, _p)  (_iswctype_l(_c, _ALPHA|_DIGIT, _p))
#define _iswprint_l(_c, _p)  (_iswctype_l(_c, _BLANK|_PUNCT|_ALPHA|_DIGIT, _p))
#define _iswgraph_l(_c, _p)  (_iswctype_l(_c, _PUNCT|_ALPHA|_DIGIT, _p))
#define _iswcntrl_l(_c, _p)  (_iswctype_l(_c, _CONTROL, _p))

#ifndef _CTYPE_DISABLE_MACROS
#define isleadbyte(_c)       (__PCTYPE_FUNC[(unsigned char)(_c)] & _LEADBYTE)
#endif  /* !_CTYPE_DISABLE_MACROS */

#endif  /* !__cplusplus */
#define _WCTYPE_INLINE_DEFINED
#endif  /* !_WCTYPE_INLINE_DEFINED */

#ifdef __GNUC__
#ifndef _INO_T_DEFINED
  typedef unsigned short _ino_t;
#ifndef NO_OLDNAMES
  typedef unsigned short  ino_t;
#endif  /* !NO_OLDNAMES */
#define _INO_T_DEFINED
#endif  /* !_INO_T_DEFINED */

#ifndef _DEV_T_DEFINED
  typedef unsigned int _dev_t;
#ifndef NO_OLDNAMES
  typedef unsigned int  dev_t;
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

#ifndef _STAT_DEFINED

  struct _stat32 {
    _dev_t         st_dev;
    _ino_t         st_ino;
    unsigned short st_mode;
    short          st_nlink;
    short          st_uid;
    short          st_gid;
    _dev_t         st_rdev;
    _off_t         st_size;
    __time32_t     st_atime;
    __time32_t     st_mtime;
    __time32_t     st_ctime;
  };

#ifndef NO_OLDNAMES
  struct stat {
    _dev_t         st_dev;
    _ino_t         st_ino;
    unsigned short st_mode;
    short          st_nlink;
    short          st_uid;
    short          st_gid;
    _dev_t         st_rdev;
    _off_t         st_size;
    time_t         st_atime;
    time_t         st_mtime;
    time_t         st_ctime;
  };
#endif  /* !NO_OLDNAMES */

  struct _stat32i64 {
    _dev_t                    st_dev;
    _ino_t                    st_ino;
    unsigned short            st_mode;
    short                     st_nlink;
    short                     st_uid;
    short                     st_gid;
    _dev_t                    st_rdev;
    __MINGW_EXTENSION __int64 st_size;
    __time32_t                st_atime;
    __time32_t                st_mtime;
    __time32_t                st_ctime;
  };

  struct _stat64i32 {
    _dev_t         st_dev;
    _ino_t         st_ino;
    unsigned short st_mode;
    short          st_nlink;
    short          st_uid;
    short          st_gid;
    _dev_t         st_rdev;
    _off_t         st_size;
    __time64_t     st_atime;
    __time64_t     st_mtime;
    __time64_t     st_ctime;
  };

  struct _stat64 {
    _dev_t                    st_dev;
    _ino_t                    st_ino;
    unsigned short            st_mode;
    short                     st_nlink;
    short                     st_uid;
    short                     st_gid;
    _dev_t                    st_rdev;
    __MINGW_EXTENSION __int64 st_size;
    __time64_t                st_atime;
    __time64_t                st_mtime;
    __time64_t                st_ctime;
  };

#define __stat64 _stat64

/* The structure name and function name are the same.*/
#ifdef _USE_32BIT_TIME_T
#define _fstat    _fstat32
#define _fstati64 _fstat32i64
#define _stat     _stat32
#define _stati64  _stat32i64
#define _wstat    _wstat32
#define _wstati64 _wstat32i64
#else  /* _USE_32BIT_TIME_T */
#define _fstat    _fstat64i32
#define _fstati64 _fstat64
#define _stat     _stat64i32
#define _stati64  _stat64
#define _wstat    _wstat64i32
#define _wstati64 _wstat64
#endif  /* _USE_32BIT_TIME_T */

/* for POSIX */
#define fstat64 _fstat64
#define stat64  _stat64
#define wstat64 _wstat64  /* not POSIX, but we define this. */

#define _STAT_DEFINED
#endif  /* !_STAT_DEFINED */

#ifndef _WSTAT_DEFINED

  /* We provide emu in libmingwex for trailing slash bug of MSVCR*.DLL _stat*. */
  int __cdecl _wstat32(const wchar_t *_Filename, struct _stat32 *_Stat);
  int __cdecl _wstat64(const wchar_t *_Filename, struct _stat64 *_Stat);
  int __cdecl _wstat32i64(const wchar_t *_Filename, struct _stat32i64 *_Stat);
  int __cdecl _wstat64i32(const wchar_t *_Filename, struct _stat64i32 *_Stat);

#define _WSTAT_DEFINED
#endif  /* !_WSTAT_DEFINED */

#endif  /* __GNUC__ */

#ifndef _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif  /* !WEOF */

  _CRTIMP wchar_t * __cdecl _cgetws(wchar_t *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t   __cdecl _cgetws_s(wchar_t *_Buffer, size_t _SizeInWords, size_t *_SizeRead);  /* We provide emu. */
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _cgetws_s, wchar_t, _Buffer, size_t *, _SizeRead)
  _CRTIMP wint_t    __cdecl _getwch(void);
  _CRTIMP wint_t    __cdecl _getwche(void);
  _CRTIMP wint_t    __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t    __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP int       __cdecl _cputws(const wchar_t *_String);
  _CRTIMP int       __cdecl _cwprintf(const wchar_t * __restrict__ _Format, ...);
  _CRTIMP int       __cdecl _cwprintf_s(const wchar_t *_Format, ...);  /* We provide emu. */
  _CRTIMP int       __cdecl _cwscanf(const wchar_t * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int       __cdecl _cwscanf_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int       __cdecl _cwscanf_s(const wchar_t *_Format, ...);
  _CRTIMP int       __cdecl _cwscanf_s_l(const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP int       __cdecl _vcwprintf(const wchar_t * __restrict__ _Format, va_list _ArgList);
  _CRTIMP int       __cdecl _vcwprintf_s(const wchar_t *_Format, va_list _ArgList);  /* We provide emu. */

  _CRTIMP int       __cdecl _cwprintf_p(const wchar_t * __restrict__ _Format, ...);
  _CRTIMP int       __cdecl _vcwprintf_p(const wchar_t * __restrict__ _Format, va_list _ArgList);

  _CRTIMP int       __cdecl _cwprintf_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, ...);
  _CRTIMP int       __cdecl _cwprintf_s_l(const wchar_t *_Format, _locale_t _Locale, ...);  /* We provide emu. */
  _CRTIMP int       __cdecl _vcwprintf_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int       __cdecl _vcwprintf_s_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);  /* We provide emu. */
  _CRTIMP int       __cdecl _cwprintf_p_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, ...);
  _CRTIMP int       __cdecl _vcwprintf_p_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList);

#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(void);
  _CRTIMP wint_t __cdecl _getwche_nolock(void);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */

#define _WCONIO_DEFINED
#endif  /* !_WCONIO_DEFINED */

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif  /* !WEOF */

  /* __attribute__((__format__(gnu_wscanf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_swscanf(const wchar_t * __restrict__ _Src, const wchar_t * __restrict__ _Format, ...);
  /* __attribute__((__format__(gnu_wscanf, 1, 2))) */ __MINGW_ATTRIB_NONNULL(1)
    int __cdecl __mingw_wscanf(const wchar_t * __restrict__ _Format, ...);
  /* __attribute__((__format__(gnu_wscanf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_fwscanf(FILE * __restrict__ _File, const wchar_t * __restrict__ _Format, ...);
  /* __attribute__((__format__(gnu_wscanf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_vswscanf(const wchar_t * __restrict__ _Str, const wchar_t * __restrict__ Format, va_list argp);
  /* __attribute__((__format__(gnu_wscanf, 1, 0))) */ __MINGW_ATTRIB_NONNULL(1)
    int __cdecl __mingw_vwscanf(const wchar_t * __restrict__ Format, va_list argp);
  /* __attribute__((__format__(gnu_wscanf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_vfwscanf(FILE * __restrict__ fp, const wchar_t * __restrict__ Format, va_list argp);
  /* __attribute__((__format__(gnu_wprintf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_fwprintf(FILE * __restrict__ _File, const wchar_t * __restrict__ _Format, ...);
  /* __attribute__((__format__(gnu_wprintf, 1, 2))) */ __MINGW_ATTRIB_NONNULL(1)
    int __cdecl __mingw_wprintf(const wchar_t * __restrict__ _Format, ...);
  /* __attribute__((__format__(gnu_wprintf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_swprintf(wchar_t * __restrict__ buf, const wchar_t * __restrict__ fmt, ...);
  /* __attribute__((__format__(gnu_wprintf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_vfwprintf(FILE * __restrict__ _File, const wchar_t * __restrict__ _Format, va_list _ArgList);
  /*__attribute__((__format__(gnu_wprintf, 1, 0))) */ __MINGW_ATTRIB_NONNULL(1)
    int __cdecl __mingw_vwprintf(const wchar_t * __restrict__ _Format, va_list _ArgList);
  /* __attribute__((__format__(gnu_wprintf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_vswprintf(wchar_t * __restrict__ buf, const wchar_t * __restrict__ fmt, va_list argv);
  /* __attribute__((__format__(gnu_wprintf, 3, 4))) */ __MINGW_ATTRIB_NONNULL(3)
    int __cdecl __mingw_snwprintf(wchar_t * __restrict__ s, size_t n, const wchar_t * __restrict__ format, ...);
  /* __attribute__((__format__(gnu_wprintf, 3, 0))) */ __MINGW_ATTRIB_NONNULL(3)
    int __cdecl __mingw_vsnwprintf(wchar_t * __restrict__ _DstBuf, size_t _MaxCount, const wchar_t * __restrict__ _Format, va_list _ArgList);

#if __MSVCRT_VERSION__ >= 0x1400
  _CRTIMP int __cdecl __stdio_common_vswprintf(unsigned __int64 _Options, wchar_t * _Buffer, size_t _BufferCount, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vswprintf_s(unsigned __int64 _Options, wchar_t * _Buffer, size_t _BufferCount, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vsnwprintf_s(unsigned __int64 _Options, wchar_t * _Buffer, size_t _BufferCount, size_t _MaxCount, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vswprintf_p(unsigned __int64 _Options, wchar_t * _Buffer, size_t _BufferCount, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfwprintf(unsigned __int64 _Options, FILE * _Stream, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfwprintf_s(unsigned __int64 _Options, FILE * _Stream, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfwprintf_p(unsigned __int64 _Options, FILE * _Stream, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vswscanf(unsigned __int64 _Options, const wchar_t * _Buffer, size_t _BufferCount, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfwscanf(unsigned __int64 _Options, FILE * _Stream, const wchar_t * _Format, _locale_t _Locale, va_list _ArgList);
#endif  /* __MSVCRT_VERSION__ >= 0x1400 */

#if __USE_MINGW_ANSI_STDIO
/*
 * User has expressed a preference for C99 conformance...
 */

  __mingw_ovr /* __attribute__((__format__(gnu_wscanf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
    int swscanf(const wchar_t *__source, const wchar_t *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __mingw_vswscanf(__source, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  __mingw_ovr /* __attribute__((__format__(gnu_wscanf, 1, 2))) */ __MINGW_ATTRIB_NONNULL(1)
    int wscanf(const wchar_t *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __mingw_vfwscanf(stdin, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  __mingw_ovr /* __attribute__((__format__(gnu_wscanf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
    int fwscanf(FILE *__stream, const wchar_t *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __mingw_vfwscanf(__stream, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  __mingw_ovr /* __attribute__((__format__(gnu_wscanf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
    int vswscanf(const wchar_t * __restrict__ __source, const wchar_t * __restrict__ __format, __builtin_va_list __local_argv) {
      return __mingw_vswscanf(__source, __format, __local_argv);
    }
  __mingw_ovr /* __attribute__((__format__(gnu_wscanf, 1, 0))) */ __MINGW_ATTRIB_NONNULL(1)
    int vwscanf(const wchar_t *__format, __builtin_va_list __local_argv) {
      return __mingw_vfwscanf(stdin, __format, __local_argv);
    }
  __mingw_ovr /* __attribute__((__format__(gnu_wscanf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
    int vfwscanf(FILE *__stream, const wchar_t *__format, __builtin_va_list __local_argv) {
      return __mingw_vfwscanf(__stream, __format, __local_argv);
    }
  __mingw_ovr /* __attribute__((__format__(gnu_wprintf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
    int fwprintf(FILE *__stream, const wchar_t *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __mingw_vfwprintf(__stream, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  __mingw_ovr /* __attribute__((__format__(gnu_wprintf, 1, 2))) */ __MINGW_ATTRIB_NONNULL(1)
    int wprintf(const wchar_t *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __mingw_vfwprintf(stdout, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  __mingw_ovr /* __attribute__((__format__(gnu_wprintf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
    int vfwprintf(FILE *__stream, const wchar_t *__format, __builtin_va_list __local_argv) {
      return __mingw_vfwprintf(__stream, __format, __local_argv);
    }
  __mingw_ovr /* __attribute__((__format__(gnu_wprintf, 1, 0))) */ __MINGW_ATTRIB_NONNULL(1)
    int vwprintf(const wchar_t *__format, __builtin_va_list __local_argv) {
      return __mingw_vfwprintf(stdout, __format, __local_argv);
    }
  __mingw_ovr /* __attribute__((__format__(gnu_wprintf, 3, 4))) */ __MINGW_ATTRIB_NONNULL(3)
    int snwprintf (wchar_t *__stream, size_t __n, const wchar_t *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __mingw_vsnwprintf(__stream, __n, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  __mingw_ovr /* __attribute__((__format__(gnu_wprintf, 3, 0))) */ __MINGW_ATTRIB_NONNULL(3)
    int vsnwprintf(wchar_t *__stream, size_t __n, const wchar_t *__format, __builtin_va_list __local_argv) {
      return __mingw_vsnwprintf(__stream, __n, __format, __local_argv);
    }

#else  /* __USE_MINGW_ANSI_STDIO */

#if __MSVCRT_VERSION__ >= 0x1400
  __mingw_ovr
    int swscanf(const wchar_t * __restrict__ _Src, const wchar_t * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vswscanf(UCRTBASE_SCANF_DEFAULT_WIDE, _Src, (size_t)-1, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int wscanf(const wchar_t * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfwscanf(UCRTBASE_SCANF_DEFAULT_WIDE, stdin, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int fwscanf(FILE * __restrict__ _File, const wchar_t * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfwscanf(UCRTBASE_SCANF_DEFAULT_WIDE, _File, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr __MINGW_ATTRIB_NONNULL(2)
    int vswscanf(const wchar_t * __restrict__ __source, const wchar_t * __restrict__ __format, va_list __local_argv) {
      return __stdio_common_vswscanf(UCRTBASE_SCANF_DEFAULT_WIDE, __source, (size_t)-1, __format, NULL, __local_argv);
    }
  __mingw_ovr __MINGW_ATTRIB_NONNULL(1)
    int vwscanf(const wchar_t *__format, va_list __local_argv) {
      return __stdio_common_vfwscanf(UCRTBASE_SCANF_DEFAULT_WIDE, stdin, __format, NULL, __local_argv);
    }
  __mingw_ovr __MINGW_ATTRIB_NONNULL(2)
    int vfwscanf(FILE *__stream, const wchar_t *__format, va_list __local_argv) {
      return __stdio_common_vfwscanf(UCRTBASE_SCANF_DEFAULT_WIDE, __stream, __format, NULL, __local_argv);
    }
  __mingw_static_ovr
    int fwprintf(FILE * __restrict__ _File, const wchar_t * __restrict__ _Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfwprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, _File, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int wprintf(const wchar_t * __restrict__ _Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfwprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, stdout, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int vfwprintf(FILE * __restrict__ _File, const wchar_t * __restrict__ _Format, va_list _ArgList) {
      return __stdio_common_vfwprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, _File, _Format, NULL, _ArgList);
    }
  __mingw_ovr
    int vwprintf(const wchar_t * __restrict__ _Format, va_list _ArgList) {
      return __stdio_common_vfwprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, stdout, _Format, NULL, _ArgList);
    }

#pragma push_macro("snwprintf")
#pragma push_macro("vsnwprintf")
#undef snwprintf
#undef vsnwprintf
  __mingw_ovr
    int snwprintf(wchar_t * __restrict__ s, size_t n, const wchar_t * __restrict__ format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, format);
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE | UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, s, n, format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int vsnwprintf(wchar_t * __restrict__ s, size_t n, const wchar_t * __restrict__ format, va_list arg) {
      return __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE | UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, s, n, format, NULL, arg);
    }
#pragma pop_macro("snwprintf")
#pragma pop_macro("vsnwprintf")

#else  /* __MSVCRT_VERSION__ >= 0x1400 */

  /* _CRTIMP */ int __cdecl swscanf(const wchar_t * __restrict__ _Src,const wchar_t * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ int __cdecl wscanf(const wchar_t * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ int __cdecl fwscanf(FILE * __restrict__ _File, const wchar_t * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
                int __cdecl __ms_vswscanf(const wchar_t * __restrict__ s, const wchar_t * __restrict__ format, va_list arg);  /* Provided in libmingwex. */
                int __cdecl __ms_vwscanf(const wchar_t * __restrict__ format, va_list arg);                                   /* Provided in libmingwex. */
                int __cdecl __ms_vfwscanf(FILE * __restrict__ stream, const wchar_t * __restrict__ format, va_list arg);      /* Provided in libmingwex. */
  __mingw_ovr __MINGW_ATTRIB_NONNULL(2)
    int vswscanf(const wchar_t * __restrict__ __source, const wchar_t * __restrict__ __format, __builtin_va_list __local_argv) {
      return __ms_vswscanf(__source, __format, __local_argv);
    }
  __mingw_ovr __MINGW_ATTRIB_NONNULL(1)
    int vwscanf(const wchar_t *__format, __builtin_va_list __local_argv) {
      return __ms_vwscanf(__format, __local_argv);
    }
  __mingw_ovr __MINGW_ATTRIB_NONNULL(2)
    int vfwscanf(FILE *__stream, const wchar_t *__format, __builtin_va_list __local_argv) {
      return __ms_vfwscanf(__stream, __format, __local_argv);
    }
  /* _CRTIMP */ int __cdecl fwprintf(FILE * __restrict__ _File, const wchar_t * __restrict__ _Format, ...);
  /* _CRTIMP */ int __cdecl wprintf(const wchar_t * __restrict__ _Format, ...);
  /* _CRTIMP */ int __cdecl vfwprintf(FILE * __restrict__ _File, const wchar_t * __restrict__ _Format, va_list _ArgList);
  /* _CRTIMP */ int __cdecl vwprintf(const wchar_t * __restrict__ _Format, va_list _ArgList);

#pragma push_macro("snwprintf")
#pragma push_macro("vsnwprintf")
#undef snwprintf
#undef vsnwprintf
  /* Provided in libmingwex. */
  int __cdecl __ms_snwprintf(wchar_t * __restrict__ s, size_t n, const wchar_t * __restrict__ format, ...);
  int __cdecl __ms_vsnwprintf(wchar_t * __restrict__ s, size_t n, const wchar_t * __restrict__ format, va_list arg);
  __mingw_ovr  __MINGW_ATTRIB_NONNULL(3)
    int snwprintf(wchar_t * __restrict__ s, size_t n, const wchar_t * __restrict__ format, ...) {
      int r;
      va_list argp;
      __builtin_va_start(argp, format);
      r = __ms_vsnwprintf(s, n, format, argp);
      __builtin_va_end(argp);
      return r;
    }
  __mingw_ovr __MINGW_ATTRIB_NONNULL(3)
    int vsnwprintf(wchar_t * __restrict__ s, size_t n, const wchar_t * __restrict__ format, va_list arg) {
      return __ms_vsnwprintf(s, n, format, arg);
    }
#pragma pop_macro("snwprintf")
#pragma pop_macro("vsnwprintf")

#endif  /* __MSVCRT_VERSION__ >= 0x1400 */
#endif  /* __USE_MINGW_ANSI_STDIO */

#if __MSVCRT_VERSION__ >= 0x1400
  __mingw_ovr
    int _swprintf(wchar_t * __restrict__ _Dest, const wchar_t * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, _Dest, (size_t)-1, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vswprintf(wchar_t * __restrict__ _Dest, const wchar_t * __restrict__ _Format, va_list _Args) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, _Dest, (size_t)-1, _Format, NULL, _Args);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vswprintf_c_l(wchar_t * __restrict__ _DstBuf, size_t _MaxCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, _DstBuf, _MaxCount, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int __swprintf_l(wchar_t * __restrict__ _Dest, const wchar_t * __restrict__ _Format, _locale_t _Plocinfo, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, _Dest, (size_t)-1, _Format, _Plocinfo, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vswprintf_l(wchar_t * __restrict__ _Dest, size_t _Count, const wchar_t * __restrict__ _Format, _locale_t _Plocinfo, va_list _Ap) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, _Dest, _Count, _Format, _Plocinfo, _Ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int __vswprintf_l(wchar_t * __restrict__ _Dest, const wchar_t * __restrict__ _Format, _locale_t _Plocinfo, va_list _Ap) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, _Dest, (size_t)-1, _Format, _Plocinfo, _Ap);
      return ret < 0 ? -1 : ret;
    }
#else  /* __MSVCRT_VERSION__ >= 0x1400 */
  _CRTIMP int __cdecl _swprintf(wchar_t * __restrict__ _Dest, const wchar_t * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _vswprintf(wchar_t * __restrict__ _Dest, const wchar_t * __restrict__ _Format, va_list _Args) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _vswprintf_c_l(wchar_t * __restrict__ _DstBuf, size_t _MaxCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl __swprintf_l(wchar_t * __restrict__ _Dest, const wchar_t * __restrict__ _Format, _locale_t _Plocinfo, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _vswprintf_l(wchar_t * __restrict__ _Dest, size_t _Count, const wchar_t * __restrict__ _Format, _locale_t _Plocinfo, va_list _Ap) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl __vswprintf_l(wchar_t * __restrict__ _Dest, const wchar_t * __restrict__ _Format, _locale_t _Plocinfo, va_list _Ap) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif  /* __MSVCRT_VERSION__ >= 0x1400 */

#ifndef RC_INVOKED
#include <swprintf.inl>
#endif  /* !RC_INVOKED */

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#if __USE_MINGW_ANSI_STDIO
#define swprintf  __mingw_swprintf
#define vswprintf __mingw_vswprintf
#else  /* __USE_MINGW_ANSI_STDIO */
#define swprintf  _swprintf
#define vswprintf _vswprintf
#endif  /* __USE_MINGW_ANSI_STDIO */
#define _swprintf_l  __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif  /* !__cplusplus */
#endif  /* _CRT_NON_CONFORMING_SWPRINTFS */

  _CRTIMP       FILE *    __cdecl _wfsopen(const wchar_t *_Filename, const wchar_t *_Mode, int _ShFlag);

  /* _CRTIMP */ wint_t    __cdecl  fgetwc(FILE *_File);
  _CRTIMP       wint_t    __cdecl _fgetwchar(void);
  /* _CRTIMP */ wint_t    __cdecl  fputwc(wchar_t _Ch, FILE *_File);
  _CRTIMP       wint_t    __cdecl _fputwchar(wchar_t _Ch);
  /* _CRTIMP */ wint_t    __cdecl  getwc(FILE *_File);
  /* _CRTIMP */ wint_t    __cdecl  getwchar(void);
  /* _CRTIMP */ wint_t    __cdecl  putwc(wchar_t _Ch, FILE *_File);
  /* _CRTIMP */ wint_t    __cdecl  putwchar(wchar_t _Ch);
  /* _CRTIMP */ wint_t    __cdecl  ungetwc(wint_t _Ch, FILE *_File);

  /* _CRTIMP */ wchar_t * __cdecl  fgetws(wchar_t * __restrict__ _Dst, int _SizeInWords, FILE * __restrict__ _File);
  /* _CRTIMP */ int       __cdecl  fputws(const wchar_t * __restrict__ _Str, FILE * __restrict__ _File);
  _CRTIMP       wchar_t * __cdecl _getws_s(wchar_t *_Str, size_t _SizeInWords);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(wchar_t *, _getws_s, wchar_t, _String)
  _CRTIMP       wchar_t * __cdecl _getws(wchar_t *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       int       __cdecl _putws(const wchar_t *_Str);
#if __MSVCRT_VERSION__ >= 0x1400
  __mingw_ovr
    int fwprintf_s(FILE *_File, const wchar_t *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfwprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, _File, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int wprintf_s(const wchar_t *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfwprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, stdout, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _scwprintf(const wchar_t * __restrict__ _Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE | UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int vfwprintf_s(FILE *_File, const wchar_t *_Format, va_list _ArgList) {
      return __stdio_common_vfwprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, _File, _Format, NULL, _ArgList);
    }
  __mingw_ovr
    int vfwscanf_s(FILE *_File, const wchar_t *_Format, va_list _ArgList) {
      return __stdio_common_vfwscanf(UCRTBASE_SCANF_DEFAULT_WIDE | UCRTBASE_SCANF_SECURECRT, _File, _Format, NULL, _ArgList);
    }
  __mingw_ovr
    int vwprintf_s(const wchar_t *_Format, va_list _ArgList) {
      return __stdio_common_vfwprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, stdout, _Format, NULL, _ArgList);
    }
  __mingw_ovr
    int vwscanf_s(const wchar_t *_Format, va_list _ArgList) {
      return __stdio_common_vfwscanf(UCRTBASE_SCANF_DEFAULT_WIDE | UCRTBASE_SCANF_SECURECRT, stdin, _Format, NULL, _ArgList);
    }

  __mingw_ovr
    int swprintf_s(wchar_t *_Dst, size_t _SizeInWords, const wchar_t *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vswprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, _Dst, _SizeInWords, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(int, swprintf_s, vswprintf_s, wchar_t, _Dest, const wchar_t *, _Format)
  __mingw_ovr
    int vswprintf_s(wchar_t *_Dst, size_t _SizeInWords, const wchar_t *_Format, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vswprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, _Dst, _SizeInWords, _Format, NULL, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vswprintf_s, wchar_t, _Dest, const wchar_t *, _Format, va_list, _ArgList)
  __mingw_ovr
    int vswscanf_s(const wchar_t *_Src, const wchar_t *_Format, va_list _ArgList) {
      return __stdio_common_vswscanf(UCRTBASE_SCANF_DEFAULT_WIDE | UCRTBASE_SCANF_SECURECRT, _Src, (size_t)-1, _Format, NULL, _ArgList);
    }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vswscanf_s, wchar_t, _Dest, const wchar_t *, _Format, va_list, _Args)

  __mingw_ovr
    int _swprintf_c(wchar_t * __restrict__ _DstBuf, size_t _SizeInWords, const wchar_t * __restrict__ _Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, _DstBuf, _SizeInWords, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vswprintf_c(wchar_t * __restrict__ _DstBuf, size_t _SizeInWords, const wchar_t * __restrict__ _Format, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, _DstBuf, _SizeInWords, _Format, NULL, _ArgList);
      return ret < 0 ? -1 : ret;
    }

  __mingw_ovr
    int _snwprintf_s(wchar_t *_DstBuf, size_t _SizeInWords, size_t _MaxCount, const wchar_t *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vsnwprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, _DstBuf, _SizeInWords, _MaxCount, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(int, _snwprintf_s, _vsnwprintf_s, wchar_t, _Dest, size_t, _Count, const wchar_t *, _Format)
  __mingw_ovr
    int _vsnwprintf_s(wchar_t *_DstBuf, size_t _SizeInWords, size_t _MaxCount, const wchar_t *_Format, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vsnwprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, _DstBuf, _SizeInWords, _MaxCount, _Format, NULL, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int, _vsnwprintf_s, wchar_t, _Dest, size_t, _Count, const wchar_t *, _Format, va_list, _ArgList)
  __mingw_static_ovr
    int _snwprintf(wchar_t * __restrict__ _Dest, size_t _Count, const wchar_t * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE | UCRTBASE_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Dest, _Count, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _vsnwprintf(wchar_t * __restrict__ _Dest, size_t _Count, const wchar_t * __restrict__ _Format, va_list _Args) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      return __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE | UCRTBASE_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Dest, _Count, _Format, NULL, _Args);
    }

  __mingw_ovr
    int _fwprintf_p(FILE *_File, const wchar_t *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfwprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE, _File, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _wprintf_p(const wchar_t *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfwprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE, stdout, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _vfwprintf_p(FILE *_File, const wchar_t *_Format, va_list _ArgList) {
      return __stdio_common_vfwprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE, _File, _Format, NULL, _ArgList);
    }
  __mingw_ovr
    int _vwprintf_p(const wchar_t *_Format, va_list _ArgList) {
      return __stdio_common_vfwprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE, stdout, _Format, NULL, _ArgList);
    }
  __mingw_ovr
    int _swprintf_p(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vswprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE, _DstBuf, _MaxCount, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vswprintf_p(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vswprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE, _DstBuf, _MaxCount, _Format, NULL, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _scwprintf_p(const wchar_t *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vswprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE | UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vscwprintf_p(const wchar_t *_Format, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vswprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE | UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, NULL, _ArgList);
      return ret < 0 ? -1 : ret;
    }

  __mingw_ovr
    int _wprintf_l(const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfwprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, stdout, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _wprintf_p_l(const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfwprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE, stdout, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _wprintf_s_l(const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfwprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, stdout, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _vwprintf_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList) {
      return __stdio_common_vfwprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, stdout, _Format, _Locale, _ArgList);
    }
  __mingw_ovr
    int _vwprintf_p_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList) {
      return __stdio_common_vfwprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE, stdout, _Format, _Locale, _ArgList);
    }
  __mingw_ovr
    int _vwprintf_s_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList) {
      return __stdio_common_vfwprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, stdout, _Format, _Locale, _ArgList);
    }

  __mingw_ovr
    int _fwprintf_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfwprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, _File, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _fwprintf_p_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfwprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE, _File, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _fwprintf_s_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfwprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, _File, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _vfwprintf_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList) {
      return __stdio_common_vfwprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, _File, _Format, _Locale, _ArgList);
    }
  __mingw_ovr
    int _vfwprintf_p_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList) {
      return __stdio_common_vfwprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE, _File, _Format, _Locale, _ArgList);
    }
  __mingw_ovr
    int _vfwprintf_s_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList) {
      return __stdio_common_vfwprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, _File, _Format, _Locale, _ArgList);
    }

  __mingw_ovr
    int _swprintf_c_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE, _DstBuf, _MaxCount, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _swprintf_p_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vswprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE, _DstBuf, _MaxCount, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _swprintf_s_l(wchar_t *_DstBuf, size_t _DstSize, const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vswprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, _DstBuf, _DstSize, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vswprintf_p_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vswprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE, _DstBuf, _MaxCount, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vswprintf_s_l(wchar_t *_DstBuf, size_t _DstSize, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vswprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, _DstBuf, _DstSize, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }

  __mingw_ovr
    int _scwprintf_l(const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE | UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _scwprintf_p_l(const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vswprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE | UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vscwprintf_p_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vswprintf_p(UCRTBASE_PRINTF_DEFAULT_WIDE | UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }

  __mingw_ovr
    int _snwprintf_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format ,_locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE | UCRTBASE_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _DstBuf, _MaxCount, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _snwprintf_s_l(wchar_t *_DstBuf, size_t _DstSize, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vsnwprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, _DstBuf, _DstSize, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vsnwprintf_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE | UCRTBASE_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _DstBuf, _MaxCount, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vsnwprintf_s_l(wchar_t *_DstBuf, size_t _DstSize, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vsnwprintf_s(UCRTBASE_PRINTF_DEFAULT_WIDE, _DstBuf, _DstSize, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }
#else  /* __MSVCRT_VERSION__ >= 0x1400 */
  /* _CRTIMP */ int       __cdecl  fwprintf_s(FILE *_File, const wchar_t *_Format, ...);
  /* _CRTIMP */ int       __cdecl  wprintf_s(const wchar_t *_Format, ...);
  _CRTIMP       int       __cdecl _scwprintf(const wchar_t * __restrict__ _Format, ...);
  /* _CRTIMP */ int       __cdecl  vfwprintf_s(FILE *_File, const wchar_t *_Format, va_list _ArgList);
#if __MSVCRT_VERSION__ >= 0x1200
  /* _CRTIMP */ int       __cdecl  vfwscanf_s(FILE *_File, const wchar_t *_Format, va_list _ArgList);
#endif  /* __MSVCRT_VERSION__ >= 0x1200 */
  /* _CRTIMP */ int       __cdecl  vwprintf_s(const wchar_t *_Format, va_list _ArgList);
#if __MSVCRT_VERSION__ >= 0x1200
  /* _CRTIMP */ int       __cdecl  vwscanf_s(const wchar_t *_Format, va_list _ArgList);
#endif  /* __MSVCRT_VERSION__ >= 0x1200 */

  /* _CRTIMP */ int       __cdecl  swprintf_s(wchar_t *_Dst, size_t _SizeInWords, const wchar_t *_Format, ...);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(int, swprintf_s, vswprintf_s, wchar_t, _Dest, const wchar_t *, _Format)
  /* _CRTIMP */ int       __cdecl  vswprintf_s(wchar_t *_Dst, size_t _SizeInWords, const wchar_t *_Format, va_list _ArgList);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vswprintf_s, wchar_t, _Dest, const wchar_t *, _Format, va_list, _ArgList)
#if __MSVCRT_VERSION__ >= 0x1200
  /* _CRTIMP */ int       __cdecl  vswscanf_s(const wchar_t *_Src, const wchar_t *_Format, va_list _ArgList);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vswscanf_s, wchar_t, _Dest, const wchar_t *, _Format, va_list, _Args)
#endif  /* __MSVCRT_VERSION__ >= 0x1200 */

  _CRTIMP       int       __cdecl _swprintf_c(wchar_t * __restrict__ _DstBuf, size_t _SizeInWords, const wchar_t * __restrict__ _Format, ...);
  _CRTIMP       int       __cdecl _vswprintf_c(wchar_t * __restrict__ _DstBuf, size_t _SizeInWords, const wchar_t * __restrict__ _Format, va_list _ArgList);

  _CRTIMP       int       __cdecl _snwprintf_s(wchar_t *_DstBuf, size_t _SizeInWords, size_t _MaxCount, const wchar_t *_Format, ...);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(int, _snwprintf_s, _vsnwprintf_s, wchar_t, _Dest, size_t, _Count, const wchar_t *, _Format)
  _CRTIMP       int       __cdecl _vsnwprintf_s(wchar_t *_DstBuf, size_t _SizeInWords, size_t _MaxCount, const wchar_t *_Format, va_list _ArgList);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int, _vsnwprintf_s, wchar_t, _Dest, size_t, _Count, const wchar_t *, _Format, va_list, _ArgList)
  _CRTIMP       int       __cdecl _snwprintf(wchar_t * __restrict__ _Dest, size_t _Count, const wchar_t * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       int       __cdecl _vsnwprintf(wchar_t * __restrict__ _Dest, size_t _Count, const wchar_t * __restrict__ _Format, va_list _Args) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  _CRTIMP       int       __cdecl _fwprintf_p(FILE *_File, const wchar_t *_Format, ...);
  _CRTIMP       int       __cdecl _wprintf_p(const wchar_t *_Format, ...);
  _CRTIMP       int       __cdecl _vfwprintf_p(FILE *_File, const wchar_t *_Format, va_list _ArgList);
  _CRTIMP       int       __cdecl _vwprintf_p(const wchar_t *_Format, va_list _ArgList);
  _CRTIMP       int       __cdecl _swprintf_p(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, ...);
  _CRTIMP       int       __cdecl _vswprintf_p(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, va_list _ArgList);  /* We provide emu. */
  _CRTIMP       int       __cdecl _scwprintf_p(const wchar_t *_Format, ...);
  _CRTIMP       int       __cdecl _vscwprintf_p(const wchar_t *_Format, va_list _ArgList);

  _CRTIMP       int       __cdecl _wprintf_l(const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _wprintf_p_l(const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _wprintf_s_l(const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _vwprintf_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP       int       __cdecl _vwprintf_p_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP       int       __cdecl _vwprintf_s_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);

  _CRTIMP       int       __cdecl _fwprintf_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _fwprintf_p_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _fwprintf_s_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _vfwprintf_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP       int       __cdecl _vfwprintf_p_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP       int       __cdecl _vfwprintf_s_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);

  _CRTIMP       int       __cdecl _swprintf_c_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _swprintf_p_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _swprintf_s_l(wchar_t *_DstBuf, size_t _DstSize, const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _vswprintf_p_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP       int       __cdecl _vswprintf_s_l(wchar_t *_DstBuf, size_t _DstSize, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);

  _CRTIMP       int       __cdecl _scwprintf_l(const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _scwprintf_p_l(const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _vscwprintf_p_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);

  _CRTIMP       int       __cdecl _snwprintf_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format ,_locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _snwprintf_s_l(wchar_t *_DstBuf, size_t _DstSize, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _vsnwprintf_l(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP       int       __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf, size_t _DstSize, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
#endif  /* __MSVCRT_VERSION__ >= 0x1400 */

  _CRTIMP       wchar_t * __cdecl _wtempnam(const wchar_t *_Directory, const wchar_t *_FilePrefix);

#if __MSVCRT_VERSION__ >= 0x1400
  __mingw_ovr
    int _vscwprintf(const wchar_t * __restrict__ _Format, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE | UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, NULL, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vscwprintf_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vswprintf(UCRTBASE_PRINTF_DEFAULT_WIDE | UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _fwscanf_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfwscanf(UCRTBASE_SCANF_DEFAULT_WIDE, _File, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int fwscanf_s(FILE *_File, const wchar_t *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfwscanf(UCRTBASE_SCANF_DEFAULT_WIDE | UCRTBASE_SCANF_SECURECRT, _File, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _fwscanf_s_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfwscanf(UCRTBASE_SCANF_DEFAULT_WIDE | UCRTBASE_SCANF_SECURECRT, _File, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _swscanf_l(const wchar_t *_Src, const wchar_t *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vswscanf(UCRTBASE_SCANF_DEFAULT_WIDE, _Src, (size_t)-1, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int swscanf_s(const wchar_t *_Src, const wchar_t *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vswscanf(UCRTBASE_SCANF_DEFAULT_WIDE | UCRTBASE_SCANF_SECURECRT, _Src, (size_t)-1, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _swscanf_s_l(const wchar_t *_Src, const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vswscanf(UCRTBASE_SCANF_DEFAULT_WIDE | UCRTBASE_SCANF_SECURECRT, _Src, (size_t)-1, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _snwscanf(const wchar_t * __restrict__ _Src, size_t _MaxCount, const wchar_t * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vswscanf(UCRTBASE_SCANF_DEFAULT_WIDE, _Src, _MaxCount, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _snwscanf_l(const wchar_t *_Src, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vswscanf(UCRTBASE_SCANF_DEFAULT_WIDE, _Src, _MaxCount, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _snwscanf_s(const wchar_t *_Src, size_t _MaxCount, const wchar_t *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vswscanf(UCRTBASE_SCANF_DEFAULT_WIDE | UCRTBASE_SCANF_SECURECRT, _Src, _MaxCount, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _snwscanf_s_l(const wchar_t *_Src, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vswscanf(UCRTBASE_SCANF_DEFAULT_WIDE | UCRTBASE_SCANF_SECURECRT, _Src, _MaxCount, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _wscanf_l(const wchar_t *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfwscanf(UCRTBASE_SCANF_DEFAULT_WIDE, stdin, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int wscanf_s(const wchar_t *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfwscanf(UCRTBASE_SCANF_DEFAULT_WIDE | UCRTBASE_SCANF_SECURECRT, stdin, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _wscanf_s_l(const wchar_t *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfwscanf(UCRTBASE_SCANF_DEFAULT_WIDE | UCRTBASE_SCANF_SECURECRT, stdin, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
#else  /* __MSVCRT_VERSION__ >= 0x1400 */
  _CRTIMP       int       __cdecl _vscwprintf(const wchar_t * __restrict__ _Format, va_list _ArgList);
  _CRTIMP       int       __cdecl _vscwprintf_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP       int       __cdecl _fwscanf_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#if __MSVCRT_VERSION__ >= 0x1200
  /* _CRTIMP */ int       __cdecl  fwscanf_s(FILE *_File, const wchar_t *_Format, ...);
#endif  /* __MSVCRT_VERSION__ >= 0x1200 */
  _CRTIMP       int       __cdecl _fwscanf_s_l(FILE *_File, const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _swscanf_l(const wchar_t *_Src, const wchar_t *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ int       __cdecl  swscanf_s(const wchar_t *_Src, const wchar_t *_Format, ...);
  _CRTIMP       int       __cdecl _swscanf_s_l(const wchar_t *_Src, const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _snwscanf(const wchar_t * __restrict__ _Src, size_t _MaxCount, const wchar_t * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       int       __cdecl _snwscanf_l(const wchar_t *_Src, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       int       __cdecl _snwscanf_s(const wchar_t *_Src, size_t _MaxCount, const wchar_t *_Format, ...);
  _CRTIMP       int       __cdecl _snwscanf_s_l(const wchar_t *_Src, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP       int       __cdecl _wscanf_l(const wchar_t *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ int       __cdecl  wscanf_s(const wchar_t *_Format, ...);
  _CRTIMP       int       __cdecl _wscanf_s_l(const wchar_t *_Format, _locale_t _Locale, ...);
#endif  /* __MSVCRT_VERSION__ >= 0x1400 */

  _CRTIMP       FILE *    __cdecl _wfdopen(int _FileHandle ,const wchar_t *_Mode);
  _CRTIMP       FILE *    __cdecl _wfopen(const wchar_t * __restrict__ _Filename, const wchar_t *__restrict__  _Mode) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t   __cdecl _wfopen_s(FILE **_File, const wchar_t *_Filename, const wchar_t *_Mode);
  _CRTIMP       FILE *    __cdecl _wfreopen(const wchar_t * __restrict__ _Filename, const wchar_t * __restrict__ _Mode, FILE * __restrict__ _OldFile) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t   __cdecl _wfreopen_s(FILE **_File, const wchar_t *_Filename, const wchar_t *_Mode, FILE *_OldFile);

#ifndef _CRT_WPERROR_DEFINED
  _CRTIMP       void      __cdecl _wperror(const wchar_t *_ErrMsg);
#define _CRT_WPERROR_DEFINED
#endif  /* !_CRT_WPERROR_DEFINED */
  _CRTIMP       FILE *    __cdecl _wpopen(const wchar_t *_Command, const wchar_t *_Mode);
#if !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen _wpopen
#endif  /* !defined(NO_OLDNAMES) && !defined(wpopen) */
  _CRTIMP       int       __cdecl _wremove(const wchar_t *_Filename);
  _CRTIMP       errno_t   __cdecl _wtmpnam_s(wchar_t *_DstBuf, size_t _SizeInWords);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _wtmpnam_s, wchar_t, _DstBuf)
  _CRTIMP       wchar_t * __cdecl _wtmpnam(wchar_t *_Buffer);

  _CRTIMP       wint_t    __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP       wint_t    __cdecl _fputwc_nolock(wchar_t _Ch, FILE *_File);
  _CRTIMP       wint_t    __cdecl _ungetwc_nolock(wint_t _Ch, FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#if !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE) || defined(__CRT__NO_INLINE)
#define getwchar()   fgetwc(stdin)
#define putwchar(_c) fputwc((_c), stdout)
#else  /* !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE) || defined(__CRT__NO_INLINE) */
  __CRT_INLINE wint_t __cdecl getwchar() {
    return (fgetwc(stdin));
  }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {
    return (fputwc(_C, stdout));
  }
#endif  /* !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE) || defined(__CRT__NO_INLINE) */

#define getwc(_stm)              fgetwc(_stm)
#define putwc(_c, _stm)          fputwc(_c, _stm)
#define _putwc_nolock(_c, _stm) _fputwc_nolock(_c, _stm)
#define _getwc_nolock(_c)       _fgetwc_nolock(_c)

#define _WSTDIO_DEFINED
#endif  /* !_WSTDIO_DEFINED */

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

#ifndef _WSTRING_DEFINED

  _CRTIMP                     wchar_t * __cdecl  _wcsdup(const wchar_t *_Str);

  _CRTIMP                     errno_t   __cdecl   wcscat_s(wchar_t *_Dst, rsize_t _SizeInWords, const wchar_t *_Src);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, wcscat_s, wchar_t, _Dest, const wchar_t *, _Source)
#ifndef RC_INVOKED
  /* _CRTIMP */               wchar_t * __cdecl   wcscat(wchar_t * __restrict__ _Dest, const wchar_t * __restrict__ _Source) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif  /* !RC_INVOKED */
  /* _CRTIMP */ _CONST_RETURN wchar_t * __cdecl   wcschr(const wchar_t *_Str, wchar_t _Ch);
  /* _CRTIMP */               int       __cdecl   wcscmp(const wchar_t *_Str1, const wchar_t *_Str2);
  /* _CRTIMP */               errno_t   __cdecl   wcscpy_s(wchar_t *_Dst, rsize_t _SizeInWords, const wchar_t *_Src);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t,  wcscpy_s, wchar_t, _Dest, const wchar_t *, _Source)
  /* _CRTIMP */               wchar_t * __cdecl   wcscpy(wchar_t * __restrict__ _Dest, const wchar_t * __restrict__ _Source) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */               size_t    __cdecl   wcscspn(const wchar_t *_Str, const wchar_t *_Control);
  /* _CRTIMP */               size_t    __cdecl   wcslen(const wchar_t *_Str);
  /* _CRTIMP */               size_t    __cdecl   wcsnlen(const wchar_t *_Src, size_t _MaxCount);
  __forceinline size_t __cdecl wcsnlen_s(const wchar_t *_Src, size_t _MaxCount) {
    return (_Src == NULL) ? 0 : wcsnlen(_Src, _MaxCount);
  }
  /* _CRTIMP */               errno_t   __cdecl   wcsncat_s(wchar_t *_Dst, rsize_t _SizeInWords, const wchar_t *_Src, rsize_t _MaxCount);
  /* _CRTIMP */               wchar_t * __cdecl   wcsncat(wchar_t * __restrict__ _Dest, const wchar_t * __restrict__ _Source, size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */               int       __cdecl   wcsncmp(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount);
  /* _CRTIMP */               errno_t   __cdecl   wcsncpy_s(wchar_t *_Dst, rsize_t _SizeInChars, const wchar_t *_Src, rsize_t _MaxCount);
  /* _CRTIMP */               wchar_t * __cdecl   wcsncpy(wchar_t * __restrict__ _Dest, const wchar_t * __restrict__ _Source, size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ _CONST_RETURN wchar_t * __cdecl   wcspbrk(const wchar_t *_Str, const wchar_t *_Control);
  /* _CRTIMP */ _CONST_RETURN wchar_t * __cdecl   wcsrchr(const wchar_t *_Str, wchar_t _Ch);
  /* _CRTIMP */               size_t    __cdecl   wcsspn(const wchar_t *_Str, const wchar_t *_Control);
  /* _CRTIMP */ _CONST_RETURN wchar_t * __cdecl   wcsstr(const wchar_t *_Str, const wchar_t *_SubStr);
  /* _CRTIMP */               wchar_t * __cdecl   wcstok(wchar_t * __restrict__ _Str, const wchar_t * __restrict__ _Delim) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */               wchar_t * __cdecl   wcstok_s(wchar_t *_Str, const wchar_t *_Delim, wchar_t **_Context);
  _CRTIMP                     wchar_t * __cdecl  _wcserror(int _ErrNum) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP                     errno_t   __cdecl  _wcserror_s(wchar_t *_Buf, size_t _SizeInWords, int _ErrNum);
  _CRTIMP                     wchar_t * __cdecl __wcserror(const wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP                     errno_t   __cdecl __wcserror_s(wchar_t *_Buffer, size_t _SizeInWords, const wchar_t *_ErrMsg);

  _CRTIMP                     int       __cdecl  _wcsicmp(const wchar_t *_Str1, const wchar_t *_Str2);
  _CRTIMP                     int       __cdecl  _wcsicmp_l(const wchar_t *_Str1, const wchar_t *_Str2, _locale_t _Locale);
  _CRTIMP                     int       __cdecl  _wcsnicmp(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount);
  _CRTIMP                     int       __cdecl  _wcsnicmp_l(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount, _locale_t _Locale);
  _CRTIMP                     errno_t   __cdecl  _wcsnset_s(wchar_t *_Dst, size_t _SizeInWords, wchar_t _Val, size_t _MaxCount);
  _CRTIMP                     wchar_t * __cdecl  _wcsnset(wchar_t *_Str, wchar_t _Val, size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP                     wchar_t * __cdecl  _wcsrev(wchar_t *_Str);
  _CRTIMP                     errno_t   __cdecl  _wcsset_s(wchar_t *_Dst, size_t _SizeInWords, wchar_t _Val);
  _CRTIMP                     wchar_t * __cdecl  _wcsset(wchar_t *_Str, wchar_t _Val) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  _CRTIMP                     errno_t   __cdecl  _wcslwr_s(wchar_t *_Str, size_t _SizeInWords);
  _CRTIMP                     wchar_t * __cdecl  _wcslwr(wchar_t *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP                     errno_t   __cdecl  _wcslwr_s_l(wchar_t *_Str, size_t _SizeInWords, _locale_t _Locale);
  _CRTIMP                     wchar_t * __cdecl  _wcslwr_l(wchar_t *_String, _locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP                     errno_t   __cdecl  _wcsupr_s(wchar_t *_Str, size_t _Size);
  _CRTIMP                     wchar_t * __cdecl  _wcsupr(wchar_t *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP                     errno_t   __cdecl  _wcsupr_s_l(wchar_t *_Str, size_t _Size, _locale_t _Locale);
  _CRTIMP                     wchar_t * __cdecl  _wcsupr_l(wchar_t *_String, _locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */               size_t    __cdecl   wcsxfrm(wchar_t * __restrict__ _Dst, const wchar_t * __restrict__ _Src, size_t _MaxCount);
  _CRTIMP                     size_t    __cdecl  _wcsxfrm_l(wchar_t * __restrict__ _Dst, const wchar_t * __restrict__ _Src, size_t _MaxCount, _locale_t _Locale);
  /* _CRTIMP */               int       __cdecl   wcscoll(const wchar_t *_Str1, const wchar_t *_Str2);
  _CRTIMP                     int       __cdecl  _wcscoll_l(const wchar_t *_Str1, const wchar_t *_Str2, _locale_t _Locale);
  _CRTIMP                     int       __cdecl  _wcsicoll(const wchar_t *_Str1, const wchar_t *_Str2);
  _CRTIMP                     int       __cdecl  _wcsicoll_l(const wchar_t *_Str1, const wchar_t *_Str2, _locale_t _Locale);
  _CRTIMP                     int       __cdecl  _wcsncoll(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount);
  _CRTIMP                     int       __cdecl  _wcsncoll_l(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount, _locale_t _Locale);
  _CRTIMP                     int       __cdecl  _wcsnicoll(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount);
  _CRTIMP                     int       __cdecl  _wcsnicoll_l(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount, _locale_t _Locale);

#ifndef NO_OLDNAMES
  /* _CRTIMP */ wchar_t * __cdecl wcsdup(const wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;

#define wcswcs wcsstr

  /* _CRTIMP */ int       __cdecl wcsicmp(const wchar_t *_Str1, const wchar_t *_Str2) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int       __cdecl wcsnicmp(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ wchar_t * __cdecl wcsnset(wchar_t *_Str, wchar_t _Val, size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ wchar_t * __cdecl wcsrev(wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ wchar_t * __cdecl wcsset(wchar_t *_Str, wchar_t _Val) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ wchar_t * __cdecl wcslwr(wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ wchar_t * __cdecl wcsupr(wchar_t *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int       __cdecl wcsicoll(const wchar_t *_Str1, const wchar_t *_Str2) __MINGW_ATTRIB_DEPRECATED_MSVC2005;

#endif  /* !NO_OLDNAMES */

#define _WSTRING_DEFINED
#endif  /* !_WSTRING_DEFINED */

#ifndef _TM_DEFINED
  struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
  };
#define _TM_DEFINED
#endif  /* !_TM_DEFINED */

#ifndef _WTIME_DEFINED

  _CRTIMP       wchar_t * __cdecl _wasctime(const struct tm *_Tm) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t   __cdecl _wasctime_s(wchar_t *_Buf, size_t _SizeInWords, const struct tm *_Tm);  /* We provide emu. */

  _CRTIMP       wchar_t * __cdecl _wctime32(const __time32_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t   __cdecl _wctime32_s(wchar_t *_Buf, size_t _SizeInWords, const __time32_t *_Time);  /* We provide emu. */

  /* _CRTIMP */ size_t    __cdecl  wcsftime(wchar_t * __restrict__ _Buf, size_t _SizeInWords, const wchar_t * __restrict__ _Format, const struct tm * __restrict__ _Tm);
  _CRTIMP       size_t    __cdecl _wcsftime_l(wchar_t * __restrict__ _Buf, size_t _SizeInWords, const wchar_t * __restrict__ _Format, const struct tm * __restrict__ _Tm, _locale_t _Locale);

  _CRTIMP       errno_t   __cdecl _wstrdate_s(wchar_t *_Buf, size_t _SizeInWords);  /* We provide emu. */
  _CRTIMP       wchar_t * __cdecl _wstrdate(wchar_t *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  _CRTIMP       errno_t   __cdecl _wstrtime_s(wchar_t *_Buf, size_t _SizeInWords);  /* We provide emu. */
  _CRTIMP       wchar_t * __cdecl _wstrtime(wchar_t *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  _CRTIMP       wchar_t * __cdecl _wctime64(const __time64_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t   __cdecl _wctime64_s(wchar_t *_Buf, size_t _SizeInWords, const __time64_t *_Time);  /* We provide emu. */

#if !defined(RC_INVOKED) && !defined(_INC_WTIME_INL)
  _CRTIMP       wchar_t * __cdecl _wctime(const time_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t   __cdecl _wctime_s(wchar_t *_Buffer, size_t _SizeInWords, const time_t *_Time);
#ifndef __CRT__NO_INLINE
#ifdef _USE_32BIT_TIME_T
  __CRT_INLINE wchar_t * __cdecl _wctime(const time_t *_Time) {
    return _wctime32(_Time);
  }
  __CRT_INLINE errno_t   __cdecl _wctime_s(wchar_t *_Buffer, size_t _SizeInWords, const time_t *_Time) {
    return _wctime32_s(_Buffer, _SizeInWords, _Time);
  }
#else  /* _USE_32BIT_TIME_T */
  __CRT_INLINE wchar_t * __cdecl _wctime(const time_t *_Time) {
    return _wctime64(_Time);
  }
  __CRT_INLINE errno_t   __cdecl _wctime_s(wchar_t *_Buffer, size_t _SizeInWords, const time_t *_Time) {
    return _wctime64_s(_Buffer, _SizeInWords, _Time);
  }
#endif  /* _USE_32BIT_TIME_T */
#endif  /* !__CRT__NO_INLINE */
#define _INC_WTIME_INL
#endif  /* !defined(RC_INVOKED) && !defined(_INC_WTIME_INL) */

#define _WTIME_DEFINED
#endif  /* !_WTIME_DEFINED */

  typedef int      mbstate_t;
  typedef wchar_t _Wint_t;

                wint_t    __cdecl btowc(int);  /* Provided in libmingwex. */
                size_t    __cdecl mbrlen(const char * __restrict__ _Ch, size_t _SizeInBytes, mbstate_t * __restrict__ _State);  /* Provided in libmingwex. */
                size_t    __cdecl mbrtowc(wchar_t * __restrict__ _DstCh, const char * __restrict__ _SrcCh, size_t _SizeInBytes, mbstate_t * __restrict__ _State);  /* Provided in libmingwex. */
  /* _CRTIMP */ errno_t   __cdecl mbsrtowcs_s(size_t *_Retval, wchar_t *_Dst, size_t _Size, const char ** _PSrc, size_t _N, mbstate_t *_State);
                size_t    __cdecl mbsrtowcs(wchar_t * __restrict__ _Dest, const char ** __restrict__ _PSrc, size_t _Count, mbstate_t * __restrict__ _State) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;  /* Provided in libmingwex. */

  /* _CRTIMP */ errno_t   __cdecl wcrtomb_s(size_t *_Retval, char *_Dst, size_t _SizeInBytes, wchar_t _Ch, mbstate_t * _State);
                size_t    __cdecl wcrtomb(char * __restrict__ _Dest, wchar_t _Source, mbstate_t * __restrict__ _State) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;  /* Provided in libmingwex. */
  /* _CRTIMP */ errno_t   __cdecl wcsrtombs_s(size_t *_Retval, char *_Dst, size_t _SizeInBytes, const wchar_t ** _Src, size_t _Size, mbstate_t * _State);
                size_t    __cdecl wcsrtombs(char * __restrict__ _Dest, const wchar_t ** __restrict__ _PSource, size_t _Count, mbstate_t * __restrict__ _State) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;  /* Provided in libmingwex. */
                int       __cdecl wctob(wint_t _WCh);  /* Provided in libmingwex. */

  /* _CRTIMP */ void *    __cdecl memmove(void *_Dst, const void *_Src, size_t _Size) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
                void *    __cdecl memcpy(void * __restrict__ _Dst, const void * __restrict__ _Src, size_t _Size) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ errno_t   __cdecl memcpy_s(void *_Dst, rsize_t _DstSize, const void *_Src, rsize_t _MaxCount);   /* We provide emu. */
  /* _CRTIMP */ errno_t   __cdecl memmove_s(void *_Dst, rsize_t _DstSize, const void *_Src, rsize_t _MaxCount);  /* We provide emu. */
  /* Provided in libmingwex. */
                int       __cdecl fwide(FILE *stream, int mode);
                int       __cdecl mbsinit(const mbstate_t *ps);
  _CONST_RETURN wchar_t * __cdecl wmemchr(const wchar_t *s, wchar_t c, size_t n);
                int       __cdecl wmemcmp(const wchar_t *s1, const wchar_t *s2,size_t n);
                wchar_t * __cdecl wmemcpy(wchar_t * __restrict__ s1, const wchar_t * __restrict__ s2,size_t n) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
                wchar_t * __cdecl wmemmove(wchar_t *s1, const wchar_t *s2, size_t n) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifndef __CRT__NO_INLINE
  __CRT_INLINE int __cdecl fwide(FILE *_F, int _M) {
    (void)_F;
    return (_M);
  }
  __CRT_INLINE int __cdecl mbsinit(const mbstate_t *_P) {
    return (!_P || *_P == 0);
  }
  __CRT_INLINE _CONST_RETURN wchar_t * __cdecl wmemchr(const wchar_t *_S, wchar_t _C, size_t _N) {
    if (_S) {
      for ( ; 0 < _N; ++_S, --_N)
        if (*_S == _C)
          return (_CONST_RETURN wchar_t *)(_S);
    }
    return (_CONST_RETURN wchar_t *)NULL;
  }
  __CRT_INLINE int __cdecl wmemcmp(const wchar_t *_S1, const wchar_t *_S2, size_t _N) {
    if (_N == 0 || _S1 == _S2)
      return 0;  /* even for NULL pointers.  */
    if ((_S1 && !(_S2)) || (_S2 && !(_S1)))
      return !(_S2) ? 1 : -1;  /* robust.  */
    for ( ; 0 < _N; ++_S1, ++_S2, --_N)
      if (*_S1 != *_S2)
        return (*_S1 < *_S2 ? -1 : +1);
    return 0;
  }
  __CRT_INLINE wchar_t * __cdecl wmemcpy(wchar_t * __restrict__ _S1, const wchar_t * __restrict__ _S2, size_t _N) {
    return (wchar_t *)memcpy(_S1, _S2, _N * sizeof(wchar_t));
  }
  __CRT_INLINE wchar_t * __cdecl wmemmove(wchar_t *_S1, const wchar_t *_S2, size_t _N) {
    return (wchar_t *)memmove(_S1, _S2, _N * sizeof(wchar_t));
  }
#endif  /* !__CRT__NO_INLINE */
  /* We provide emu. */
  errno_t   __cdecl wmemcpy_s(wchar_t *_S1, rsize_t _N1, const wchar_t *_S2, rsize_t _N);
  errno_t   __cdecl wmemmove_s(wchar_t *_S1, rsize_t _N1, const wchar_t *_S2, rsize_t _N);

  /* Provided in libmingwex. */
  wchar_t * __cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  wchar_t * __cdecl wmempcpy(wchar_t *_Dst, const wchar_t *_Src, size_t _Size);
#ifndef __CRT__NO_INLINE
  __CRT_INLINE wchar_t * __cdecl wmemset(wchar_t *_S, wchar_t _C, size_t _N) {
    wchar_t *_Su = _S;
    for (;0<_N; ++_Su, --_N) {
      *_Su = _C;
    }
    return _S;
  }
  __CRT_INLINE wchar_t * __cdecl wmempcpy(wchar_t *d, const wchar_t *s, size_t len) {
    wchar_t *r = d + len;
    if (len != 0)
      memcpy(d, s, len * sizeof(wchar_t));
    return r;
  }
#endif  /* !__CRT__NO_INLINE */

#ifdef _XOPEN_SOURCE
  int wcwidth(wchar_t c);
  int wcswidth(const wchar_t *s, size_t n);
  int wcwidth_cjk(wchar_t c);
  int wcswidth_cjk(const wchar_t *s, size_t n);
#endif  /* _XOPEN_SOURCE */

#ifndef __MINGW_MBWC_CONVERT_DEFINED
/* Provided in libmingwex. */

/**
 * __mingw_str_wide_utf8
 * Converts a null terminated UCS-2 string to a multibyte (UTF-8) equivalent.
 * Caller is supposed to free allocated buffer with __mingw_str_free().
 * @param[in] wptr Pointer to wide string.
 * @param[out] mbptr Pointer to multibyte string.
 * @param[out] buflen Optional parameter for length of allocated buffer.
 * @return bytes written by WideCharToMultiByte conversion, 0 for failure.
 *
 * WideCharToMultiByte - http://msdn.microsoft.com/en-us/library/dd374130(VS.85).aspx
 */
  int __cdecl __mingw_str_wide_utf8(const wchar_t * const wptr, char **mbptr, size_t * buflen);

/**
 * __mingw_str_utf8_wide
 * Converts a null terminated UTF-8 string to a UCS-2 equivalent.
 * Caller is supposed to free allocated buffer with __mingw_str_free().
 * @param[out] mbptr Pointer to multibyte string.
 * @param[in] wptr Pointer to wide string.
 * @param[out] buflen Optional parameter for length of allocated buffer.
 * @return bytes written by WideCharToMultiByte conversion, 0 for failure.
 *
 * MultiByteToWideChar - http://msdn.microsoft.com/en-us/library/dd319072(VS.85).aspx
 */
  int __cdecl __mingw_str_utf8_wide(const char *const mbptr, wchar_t ** wptr, size_t * buflen);

/**
 * __mingw_str_free
 * Frees buffer create by __mingw_str_wide_utf8 and __mingw_str_utf8_wide.
 * @param[in] ptr memory block to free.
 *
 */
  void __cdecl __mingw_str_free(void *ptr);

#define __MINGW_MBWC_CONVERT_DEFINED
#endif  /* !__MINGW_MBWC_CONVERT_DEFINED */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#pragma pack(pop)

#include <_mingw_print_pop.h>

#endif  /* _INC_WCHAR */
