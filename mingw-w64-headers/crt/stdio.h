/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_STDIO
#define _INC_STDIO

#include <crtdefs.h>

#include <_mingw_print_push.h>

#pragma pack(push, _CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#define BUFSIZ       512
#define _NFILE       _NSTREAM_
#define _NSTREAM_    512
#define _IOB_ENTRIES 20
#define EOF          (-1)

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

#define _P_tmpdir   "\\"
#define _wP_tmpdir L"\\"

#define L_tmpnam   (sizeof(_P_tmpdir) + 12)
#define L_tmpnam_s (sizeof(_P_tmpdir) + 16)

#define SEEK_CUR      1
#define SEEK_END      2
#define SEEK_SET      0

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define FILENAME_MAX  260
#define FOPEN_MAX     20
#define _SYS_OPEN     20
#define TMP_MAX       32767
#define TMP_MAX_S     _TMP_MAX_S
#define _TMP_MAX_S    2147483647

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

#ifndef _STDIO_DEFINED
  _CRTIMP FILE *__cdecl __acrt_iob_func(unsigned index);
#if (__MSVCRT_VERSION__ >= 0x0800) || defined(_X86_)
  _CRTIMP extern FILE * __cdecl __p__iob(void);
#endif  /* (__MSVCRT_VERSION__ >= 0x0800) || defined(_X86_) */
  _CRTIMP extern FILE            _iob[];  /* A pointer to an array of FILE */
  _CRTIMP        FILE * __cdecl __iob_func(void);
#endif  /* !_STDIO_DEFINED */

#ifndef _FPOS_T_DEFINED
#undef _FPOSOFF
  __MINGW_EXTENSION typedef __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#define _FPOS_T_DEFINED
#endif  /* !_FPOS_T_DEFINED */

#ifndef _STDSTREAM_DEFINED
#define stdin  (__acrt_iob_func(0))
#define stdout (__acrt_iob_func(1))
#define stderr (__acrt_iob_func(2))
#define _STDSTREAM_DEFINED
#endif  /* !_STDSTREAM_DEFINED */

#define _IOREAD   0x0001
#define _IOWRT    0x0002

#define _IOFBF    0x0000
#define _IOLBF    0x0040
#define _IONBF    0x0004

#define _IOMYBUF  0x0008
#define _IOEOF    0x0010
#define _IOERR    0x0020
#define _IOSTRG   0x0040
#define _IORW     0x0080

#define _TWO_DIGIT_EXPONENT 0x1

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

#ifndef _STDIO_DEFINED
  /* Provided in libmingwex. */
  extern __attribute__((__format__(gnu_printf, 2, 3))) __attribute__((nonnull(1, 2)))
    int __cdecl __mingw_asprintf(char ** __restrict__ ret, const char * __restrict__ format, ...) __MINGW_NOTHROW;
  extern __attribute__((__format__(gnu_printf, 2, 0))) __attribute__((nonnull(1, 2)))
    int __cdecl __mingw_vasprintf(char ** __restrict__ ret, const char * __restrict__ format, va_list ap) __MINGW_NOTHROW;
  extern __attribute__((__format__(gnu_scanf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_sscanf(const char * __restrict__ _Src, const char * __restrict__ _Format, ...);
  extern __attribute__((__format__(gnu_scanf, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
    int __cdecl __mingw_scanf(const char * __restrict__ _Format, ...);
  extern __attribute__((__format__(gnu_scanf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_fscanf(FILE * __restrict__ _File, const char * __restrict__ _Format, ...);
  extern __attribute__((__format__(gnu_scanf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_vsscanf(const char * __restrict__ _Str, const char * __restrict__ Format, va_list argp);
  extern __attribute__((__format__(gnu_scanf, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
    int __cdecl __mingw_vscanf(const char * __restrict__ Format, va_list argp);
  extern __attribute__((__format__(gnu_scanf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_vfscanf(FILE * __restrict__ fp, const char * __restrict__ Format, va_list argp);
  extern __attribute__((__format__(gnu_printf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_fprintf(FILE * __restrict__ stream, const char * __restrict__ fmt, ...) __MINGW_NOTHROW;
  extern __attribute__((__format__(gnu_printf, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
    int __cdecl __mingw_printf(const char * __restrict__ fmt, ... ) __MINGW_NOTHROW;
  extern __attribute__((__format__(gnu_printf, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_sprintf(char * __restrict__ buf, const char * __restrict__ fmt, ...) __MINGW_NOTHROW;
  extern __attribute__((__format__(gnu_printf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_vfprintf(FILE * __restrict__ stream, const char * __restrict__ fmt, va_list argv) __MINGW_NOTHROW;
  extern __attribute__((__format__(gnu_printf, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
    int __cdecl __mingw_vprintf(const char * __restrict__ fmt, va_list argv) __MINGW_NOTHROW;
  extern __attribute__((__format__(gnu_printf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
    int __cdecl __mingw_vsprintf(char * __restrict__ buf, const char * __restrict__ fmt, va_list argv) __MINGW_NOTHROW;
  extern __attribute__((__format__(gnu_printf, 3, 4))) __MINGW_ATTRIB_NONNULL(3)
    int __cdecl __mingw_snprintf(char * __restrict__ s, size_t n, const char * __restrict__  format, ...);
  extern __attribute__((__format__(gnu_printf, 3, 0))) __MINGW_ATTRIB_NONNULL(3)
    int __cdecl __mingw_vsnprintf(char * __restrict__ _DstBuf, size_t _MaxCount, const char * __restrict__ _Format, va_list _ArgList);

#if __MSVCRT_VERSION__ >= 0x1400
  _CRTIMP int __cdecl __stdio_common_vsprintf(unsigned __int64 _Options, char * _Buffer, size_t _BufferCount, const char * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vsprintf_s(unsigned __int64 _Options, char * _Buffer, size_t _BufferCount, const char * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vsnprintf_s(unsigned __int64 _Options, char * _Buffer, size_t _BufferCount, size_t _MaxCount, const char * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vsprintf_p(unsigned __int64 _Options, char * _Buffer, size_t _BufferCount, const char * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfprintf(unsigned __int64 _Options, FILE * _Stream, const char * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfprintf_s(unsigned __int64 _Options, FILE * _Stream, const char * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfprintf_p(unsigned __int64 _Options, FILE * _Stream, const char * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vsscanf(unsigned __int64 _Options, const char * _Buffer, size_t _BufferCount, const char * _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfscanf(unsigned __int64 _Options, FILE * _Stream, const char * _Format, _locale_t _Locale, va_list _ArgList);
#endif

#if __USE_MINGW_ANSI_STDIO
/*
 * User has expressed a preference for C99 conformance...
 */
#undef __MINGW_PRINTF_FORMAT
#undef __MINGW_SCANF_FORMAT
#define __MINGW_PRINTF_FORMAT gnu_printf
#define __MINGW_SCANF_FORMAT  gnu_scanf

#ifdef _GNU_SOURCE
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 3))) __attribute__((nonnull(1, 2)))
    int asprintf(char **__ret, const char *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __mingw_vasprintf(__ret, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 0))) __attribute__((nonnull(1, 2)))
    int vasprintf(char **__ret, const char *__format, __builtin_va_list __local_argv) {
      return __mingw_vasprintf(__ret, __format, __local_argv);
    }
#endif  /* _GNU_SOURCE */

/* There seems to be a bug about builtins and static overrides of them
   in g++.  So we need to do here some trickery.  */
#ifdef __cplusplus
extern "C++" {
#endif  /* __cplusplus */

  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
    int sscanf(const char *__source, const char *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __mingw_vsscanf(__source, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
    int scanf(const char *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __mingw_vfscanf(stdin, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
    int fscanf(FILE *__stream, const char *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __mingw_vfscanf(__stream, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#endif  /* __GNUC__ */
  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
    int vsscanf (const char *__source, const char *__format, __builtin_va_list __local_argv) {
      return __mingw_vsscanf(__source, __format, __local_argv);
    }
  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
    int vscanf(const char *__format, __builtin_va_list __local_argv) {
      return __mingw_vfscanf(stdin, __format, __local_argv);
    }
  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
    int vfscanf(FILE *__stream, const char *__format, __builtin_va_list __local_argv) {
      return __mingw_vfscanf(__stream, __format, __local_argv);
    }
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  /* __GNUC__ */
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
    int fprintf(FILE *__stream, const char *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __mingw_vfprintf(__stream, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
    int printf(const char *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __mingw_vfprintf(stdout, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
    int sprintf(char *__stream, const char *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __mingw_vsprintf(__stream, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
    int vfprintf(FILE *__stream, const char *__format, __builtin_va_list __local_argv) {
      return __mingw_vfprintf(__stream, __format, __local_argv);
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
    int vprintf(const char *__format, __builtin_va_list __local_argv) {
      return __mingw_vfprintf(stdout, __format, __local_argv);
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
    int vsprintf(char *__stream, const char *__format, __builtin_va_list __local_argv) {
      return __mingw_vsprintf(__stream, __format, __local_argv);
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 3, 4))) __MINGW_ATTRIB_NONNULL(3)
    int snprintf(char *__stream, size_t __n, const char *__format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __mingw_vsnprintf(__stream, __n, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 3, 0))) __MINGW_ATTRIB_NONNULL(3)
    int vsnprintf(char *__stream, size_t __n, const char *__format, __builtin_va_list __local_argv) {
      return __mingw_vsnprintf(__stream, __n, __format, __local_argv);
    }

/* Override __builtin_printf-routines ... Kludge for libstdc++ ...*/
#define __builtin_vsnprintf __mingw_vsnprintf
#define __builtin_vsprintf  __mingw_vsprintf

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#else  /* __USE_MINGW_ANSI_STDIO */

#undef __MINGW_PRINTF_FORMAT
#undef __MINGW_SCANF_FORMAT
#define __MINGW_PRINTF_FORMAT ms_printf
#define __MINGW_SCANF_FORMAT  ms_scanf
#undef __builtin_vsnprintf
#undef __builtin_vsprintf

/*
 * Default configuration: simply direct all calls to MSVCRT...
 */
#if __MSVCRT_VERSION__ >= 0x1400
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#endif  /* __GNUC__ */

#ifdef _GNU_SOURCE
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 0))) __attribute__((nonnull(1, 2)))
    int vasprintf(char ** __restrict__ _Ret,const char * __restrict__ _Format,va_list _Args) {
    int _Len = __stdio_common_vsprintf(UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, NULL, _Args);
    if (_Len < 0)
      return _Len;
    *_Ret = malloc(_Len + 1);
    if (!*_Ret)
        return -1;
      return __stdio_common_vsprintf(UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, *_Ret, _Len + 1, _Format, NULL, _Args);
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 3))) __attribute__((nonnull(1, 2)))
    int asprintf(char ** __restrict__ _Ret,const char * __restrict__ _Format,...) {
    int _N;
    __builtin_va_list _Args;
    __builtin_va_start(_Args, _Format);
    _N = vasprintf(_Ret, _Format, _Args);
    __builtin_va_end(_Args);
    return _N;
    }
#endif  /* _GNU_SOURCE */
  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
    int sscanf(const char * __restrict__ _Src, const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vsscanf(0, _Src, (size_t)-1, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
    int scanf(const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfscanf(0, stdin, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
    int fscanf(FILE * __restrict__ _File, const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfscanf(0, _File, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
    int vsscanf(const char * __restrict__ __source, const char * __restrict__ __format, __builtin_va_list __local_argv) {
      return __stdio_common_vsscanf(0, __source, (size_t)-1, __format, NULL, __local_argv);
    }
  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
    int vscanf(const char *__format, __builtin_va_list __local_argv) {
      return __stdio_common_vfscanf(0, stdin, __format, NULL, __local_argv);
    }
  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
    int vfscanf(FILE *__stream, const char *__format, __builtin_va_list __local_argv) {
      return __stdio_common_vfscanf(0, __stream, __format, NULL, __local_argv);
    }
  __mingw_static_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
    int fprintf(FILE * __restrict__ _File, const char * __restrict__ _Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfprintf(0, _File, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
    int printf(const char * __restrict__ _Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfprintf(0, stdout, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
    int sprintf(char * __restrict__ _Dest, const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vsprintf(UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, _Dest, (size_t)-1, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_static_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
    int vfprintf(FILE * __restrict__ _File, const char * __restrict__ _Format, va_list _ArgList) {
      return __stdio_common_vfprintf(0, _File, _Format, NULL, _ArgList);
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
    int vprintf(const char * __restrict__ _Format, va_list _ArgList) {
      return __stdio_common_vfprintf(0, stdout, _Format, NULL, _ArgList);
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
    int vsprintf(char * __restrict__ _Dest, const char * __restrict__ _Format, va_list _Args) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      return __stdio_common_vsprintf(UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, _Dest, (size_t)-1, _Format, NULL, _Args);
    }

#pragma push_macro("snprintf")
#pragma push_macro("vsnprintf")
#undef snprintf
#undef vsnprintf
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 3, 4))) __MINGW_ATTRIB_NONNULL(3)
    int snprintf(char * __restrict__ __stream, size_t __n, const char * __restrict__ __format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, __format);
      ret = __stdio_common_vsprintf(UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, __stream, __n, __format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 3, 0))) __MINGW_ATTRIB_NONNULL(3)
    int vsnprintf(char * __restrict__ __stream, size_t __n, const char * __restrict__ __format, va_list __local_argv) {
      return __stdio_common_vsprintf(UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, __stream, __n, __format, NULL, __local_argv);
    }
#pragma pop_macro ("snprintf")
#pragma pop_macro ("vsnprintf")
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  /* __GNUC__ */

#else  /* __MSVCRT_VERSION__ >= 0x1400 */

#ifdef _GNU_SOURCE
  /* Provided in libmingwex. */
  int __cdecl vasprintf(char ** __restrict__ ret, const char * __restrict__ format, va_list ap) __attribute__((format(__MINGW_PRINTF_FORMAT, 2, 0)));
  int __cdecl  asprintf(char ** __restrict__ ret, const char * __restrict__ format, ...)        __attribute__((format(__MINGW_PRINTF_FORMAT, 2, 3)));
#endif  /*_GNU_SOURCE */
  __attribute__((__format__(__MINGW_SCANF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
  /* _CRTIMP */ int __cdecl   sscanf(const char * __restrict__ _Src, const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __attribute__((__format__(__MINGW_SCANF_FORMAT, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
  /* _CRTIMP */ int __cdecl   scanf(const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __attribute__((__format__(__MINGW_SCANF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
  /* _CRTIMP */ int __cdecl   fscanf(FILE * __restrict__ _File, const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#endif  /* __GNUC__ */
  __attribute__((__format__(__MINGW_SCANF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
                int __cdecl __ms_vsscanf(const char * __restrict__ _Str, const char * __restrict__ Format, va_list argp);  /* Provided in libmingwex. */
  __attribute__((__format__(__MINGW_SCANF_FORMAT, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
                int __cdecl __ms_vscanf(const char * __restrict__ Format, va_list argp);                                   /* Provided in libmingwex. */
  __attribute__((__format__(__MINGW_SCANF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
                int __cdecl __ms_vfscanf(FILE * __restrict__ fp, const char * __restrict__ Format, va_list argp);          /* Provided in libmingwex. */
  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
    int vsscanf(const char * __restrict__ __source, const char * __restrict__ __format, __builtin_va_list __local_argv) {
      return __ms_vsscanf(__source, __format, __local_argv);
    }
  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
    int vscanf(const char *__format, __builtin_va_list __local_argv) {
      return __ms_vscanf(__format, __local_argv);
    }
  __mingw_ovr __attribute__((__format__(__MINGW_SCANF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
    int vfscanf(FILE *__stream, const char *__format, __builtin_va_list __local_argv) {
      return __ms_vfscanf(__stream, __format, __local_argv);
    }
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  /* __GNUC__ */
  __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
  /* _CRTIMP */ int __cdecl fprintf(FILE * __restrict__ _File, const char * __restrict__ _Format, ...);
  __attribute__((__format__(__MINGW_PRINTF_FORMAT, 1, 2))) __MINGW_ATTRIB_NONNULL(1)
  /* _CRTIMP */ int __cdecl printf(const char * __restrict__ _Format, ...);
  __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 3))) __MINGW_ATTRIB_NONNULL(2)
  /* _CRTIMP */ int __cdecl sprintf(char * __restrict__ _Dest, const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
  /* _CRTIMP */ int __cdecl vfprintf(FILE * __restrict__ _File, const char * __restrict__ _Format, va_list _ArgList);
  __attribute__((__format__(__MINGW_PRINTF_FORMAT, 1, 0))) __MINGW_ATTRIB_NONNULL(1)
  /* _CRTIMP */ int __cdecl vprintf(const char * __restrict__ _Format, va_list _ArgList);
  __attribute__((__format__(__MINGW_PRINTF_FORMAT, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
  /* _CRTIMP */ int __cdecl vsprintf(char * __restrict__ _Dest, const char * __restrict__ _Format, va_list _Args) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#endif  /* __GNUC__ */
/* These are here to deal with software defining (v)snprintf as _(v)snprintf, eg. libxml2. */
#pragma push_macro("snprintf")
#pragma push_macro("vsnprintf")
#undef snprintf
#undef vsnprintf
  /* Provided in libmingwex. */
  __attribute__((__format__(__MINGW_PRINTF_FORMAT, 3, 4))) __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __ms_snprintf(char * __restrict__ s, size_t n, const char * __restrict__ format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __attribute__((__format__(__MINGW_PRINTF_FORMAT, 3, 0))) __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __ms_vsnprintf(char * __restrict__ d, size_t n, const char * __restrict__ format, va_list arg) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 3, 4))) __MINGW_ATTRIB_NONNULL(3)
    int snprintf(char * __restrict__ __stream, size_t __n, const char * __restrict__ __format, ...) {
      register int __retval;
      __builtin_va_list __local_argv;
      __builtin_va_start(__local_argv, __format);
      __retval = __ms_vsnprintf(__stream, __n, __format, __local_argv);
      __builtin_va_end(__local_argv);
      return __retval;
    }
  __mingw_ovr __attribute__((__format__(__MINGW_PRINTF_FORMAT, 3, 0))) __MINGW_ATTRIB_NONNULL(3)
    int vsnprintf(char * __restrict__ __stream, size_t __n, const char * __restrict__ __format, va_list __local_argv) {
      return __ms_vsnprintf (__stream, __n, __format, __local_argv);
    }
#pragma pop_macro ("snprintf")
#pragma pop_macro ("vsnprintf")
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  /* __GNUC__ */

#endif  /* __MSVCRT_VERSION__ >= 0x1400 */
#endif  /* __USE_MINGW_ANSI_STDIO */

  _CRTIMP       int     __cdecl _filbuf(FILE *_File);
  _CRTIMP       int     __cdecl _flsbuf(int _Ch, FILE *_File);
  _CRTIMP       FILE *  __cdecl _fsopen(const char *_Filename, const char *_Mode, int _ShFlag);
  /* _CRTIMP */ void    __cdecl  clearerr(FILE *_File);
  _CRTIMP       errno_t __cdecl  clearerr_s(FILE *_File);
  /* _CRTIMP */ int     __cdecl  fclose(FILE *_File);
  _CRTIMP       int     __cdecl _fcloseall(void);

  _CRTIMP       FILE *  __cdecl _fdopen(int _FileHandle, const char *_Mode);

  /* _CRTIMP */ int     __cdecl  feof(FILE *_File);
  /* _CRTIMP */ int     __cdecl  ferror(FILE *_File);
  /* _CRTIMP */ int     __cdecl  fflush(FILE *_File);
  /* _CRTIMP */ int     __cdecl  fgetc(FILE *_File);
  _CRTIMP       int     __cdecl _fgetchar(void);
  /* _CRTIMP */ int     __cdecl  fgetpos(FILE * __restrict__ _File, fpos_t * __restrict__ _Pos);  /* 64bit only, no 32bit version */
                int     __cdecl  fgetpos64(FILE * __restrict__ _File, fpos_t * __restrict__ _Pos);  /* fgetpos already 64bit, Provided in libmingwex. */
  /* _CRTIMP */ char *  __cdecl  fgets(char * __restrict__ _Buf,int _MaxCount, FILE * __restrict__ _File);

  _CRTIMP       int     __cdecl _fileno(FILE *_File);

  _CRTIMP       char *  __cdecl _tempnam(const char *_DirName, const char *_FilePrefix);

  _CRTIMP       int     __cdecl _flushall(void);
  /* _CRTIMP */ FILE *  __cdecl  fopen(const char * __restrict__ _Filename, const char * __restrict__ _Mode) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t __cdecl  fopen_s(FILE **_File, const char *_Filename, const char *_Mode);
                FILE *           fopen64(const char * __restrict__ filename, const char * __restrict__ mode);  /* Provided in libmingwex. */
#if __MSVCRT_VERSION__ >= 0x1400
  __mingw_ovr
    int fprintf_s(FILE *_File, const char *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfprintf_s(0, _File, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
#else  /* __MSVCRT_VERSION__ >= 0x1400 */
  /* _CRTIMP */ int     __cdecl  fprintf_s(FILE *_File, const char *_Format, ...);
#endif  /* __MSVCRT_VERSION__ >= 0x1400 */
  /* _CRTIMP */ int     __cdecl  fputc(int _Ch, FILE *_File);
  _CRTIMP       int     __cdecl _fputchar(int _Ch);
  /* _CRTIMP */ int     __cdecl  fputs(const char * __restrict__ _Str, FILE * __restrict__ _File);
  /* _CRTIMP */ size_t  __cdecl  fread(void * __restrict__ _DstBuf, size_t _ElementSize, size_t _Count, FILE * __restrict__ _File);
  /* _CRTIMP */ size_t  __cdecl  fread_s(void *_DstBuf, size_t _DstSize, size_t _ElementSize, size_t _Count, FILE *_File);
  /* _CRTIMP */ FILE *  __cdecl  freopen(const char * __restrict__ _Filename, const char * __restrict__ _Mode, FILE * __restrict__ _File) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t __cdecl  freopen_s(FILE **_File, const char *_Filename, const char *_Mode, FILE *_OldFile);
#if __MSVCRT_VERSION__ >= 0x1400
  __mingw_ovr
    int _fscanf_l(FILE *_File, const char *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfscanf(0, _File, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int fscanf_s(FILE *_File, const char *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfscanf(UCRTBASE_SCANF_SECURECRT, _File, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _fscanf_s_l(FILE *_File, const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfscanf(UCRTBASE_SCANF_SECURECRT, _File, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
#else  /* __MSVCRT_VERSION__ >= 0x1400 */
  _CRTIMP       int     __cdecl _fscanf_l(FILE *_File, const char *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       int     __cdecl  fscanf_s(FILE *_File, const char *_Format, ...);
  _CRTIMP       int     __cdecl _fscanf_s_l(FILE *_File, const char *_Format, _locale_t _Locale, ...);
#endif  /* __MSVCRT_VERSION__ >= 0x1400 */

              /* _CRTIMP */ int     __cdecl  fsetpos(FILE *_File, const fpos_t *_Pos);
                            int     __cdecl  fsetpos64(FILE *_File, const fpos_t *_Pos);  /* fsetpos already 64bit, Provided in libmingwex. */
              /* _CRTIMP */ int     __cdecl  fseek(FILE *_File, long _Offset, int _Origin);
              /* _CRTIMP */ long    __cdecl  ftell(FILE *_File);
  __MINGW_EXTENSION _CRTIMP int     __cdecl _fseeki64(FILE *_File, __int64 _Offset, int _Origin);
#if __MSVCRT_VERSION__ >= 0x0800
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _ftelli64(FILE *_File);
#else  /* __MSVCRT_VERSION__ >= 0x0800 */
  __MINGW_EXTENSION         __int64 __cdecl _ftelli64(FILE *_File);  /* Provided in libmingwex. */
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */
#if __MSVCRT_VERSION__ >= 0x1400
  __mingw_static_ovr int fseeko(FILE *_File, _off_t _Offset, int _Origin) {
    return fseek(_File, (_off_t)_Offset, _Origin);
  }
  __mingw_static_ovr int fseeko64(FILE *_File, _off64_t _Offset, int _Origin) {
    return _fseeki64(_File, (_off64_t)_Offset, _Origin);
  }
  __mingw_static_ovr _off_t ftello(FILE *_File) {
    return (_off_t)ftell(_File);
  }
  __mingw_static_ovr _off64_t ftello64(FILE *_File) {
    return (_off64_t)_ftelli64(_File);
  }
#else  /*  __MSVCRT_VERSION__ >= 0x1400 */
  /* Provided in libmingwex. */
  int      fseeko(FILE *stream, _off_t offset, int whence);
  int      fseeko64(FILE *stream, _off64_t offset, int whence);
  /* Returns truncated 64bit off_t */
  _off_t   ftello(FILE * stream);
  _off64_t ftello64(FILE * stream);
#endif  /*  __MSVCRT_VERSION__ >= 0x1400 */

#ifndef _FILE_OFFSET_BITS_SET_FSEEKO
#if defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64)
#undef fseeko
#define fseeko fseeko64
#endif  /* defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64) */
#define _FILE_OFFSET_BITS_SET_FSEEKO
#endif  /* !_FILE_OFFSET_BITS_SET_FSEEKO */

#ifndef _FILE_OFFSET_BITS_SET_FTELLO
#if defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64)
#undef ftello
#define ftello ftello64
#endif  /* defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64) */
#define _FILE_OFFSET_BITS_SET_FTELLO
#endif  /* !_FILE_OFFSET_BITS_SET_FTELLO */

  /* _CRTIMP */ size_t __cdecl  fwrite(const void * __restrict__ _Str, size_t _Size, size_t _Count, FILE * __restrict__ _File);
  /* _CRTIMP */ int    __cdecl  getc(FILE *_File);
  /* _CRTIMP */ int    __cdecl  getchar(void);
  _CRTIMP       int    __cdecl _getmaxstdio(void);
  /* _CRTIMP */ char * __cdecl  gets_s(char *_Buf, rsize_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(char *, get_s, char, _Buffer)
  /* _CRTIMP */ char * __cdecl  gets(char *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
                int    __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
  /* _CRTIMP */ void   __cdecl  perror(const char *_ErrMsg);
#define _CRT_PERROR_DEFINED
#endif  /* !_CRT_PERROR_DEFINED */
  _CRTIMP       int    __cdecl _pclose(FILE *_File);
  _CRTIMP       FILE * __cdecl _popen(const char *_Command, const char *_Mode);
#if !defined(NO_OLDNAMES) && !defined(popen)
#define popen  _popen
#define pclose _pclose
#endif  /* !defined(NO_OLDNAMES) && !defined(popen) */
#if __MSVCRT_VERSION__ >= 0x1400
  __mingw_ovr
    int printf_s(const char *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfprintf_s(0, stdout, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
#else  /* __MSVCRT_VERSION__ >= 0x1400 */
  /* _CRTIMP */ int    __cdecl  printf_s(const char *_Format, ...);
#endif  /* __MSVCRT_VERSION__ >= 0x1400 */
  /* _CRTIMP */ int    __cdecl  putc(int _Ch, FILE *_File);
  /* _CRTIMP */ int    __cdecl  putchar(int _Ch);
  /* _CRTIMP */ int    __cdecl  puts(const char *_Str);
  _CRTIMP       int    __cdecl _putw(int _Word, FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
  /* _CRTIMP */ int    __cdecl  remove(const char *_Filename);
  /* _CRTIMP */ int    __cdecl  rename(const char *_OldFilename, const char *_NewFilename);
  _CRTIMP       int    __cdecl _unlink(const char *_Filename);
#ifndef NO_OLDNAMES
  /* _CRTIMP */ int    __cdecl  unlink(const char *_Filename) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif  /* !NO_OLDNAMES */
#define _CRT_DIRECTORY_DEFINED
#endif  /* !_CRT_DIRECTORY_DEFINED */
  /* _CRTIMP */ void         __cdecl  rewind(FILE *_File);
  _CRTIMP       int          __cdecl _rmtmp(void);
#if __MSVCRT_VERSION__ >= 0x1400
  __mingw_ovr
    int _scanf_l(const char *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfscanf(0, stdin, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int scanf_s(const char *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfscanf(UCRTBASE_SCANF_SECURECRT, stdin, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _scanf_s_l(const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfscanf(UCRTBASE_SCANF_SECURECRT, stdin, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
#else  /* __MSVCRT_VERSION__ >= 0x1400 */
  _CRTIMP       int          __cdecl _scanf_l(const char *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ int          __cdecl  scanf_s(const char *_Format, ...);
  _CRTIMP       int          __cdecl _scanf_s_l(const char *_Format, _locale_t _Locale, ...);
#endif  /* __MSVCRT_VERSION__ >= 0x1400 */
  /* _CRTIMP */ void         __cdecl  setbuf(FILE * __restrict__ _File, char * __restrict__ _Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       int          __cdecl _setmaxstdio(int _Max);
  _CRTIMP       unsigned int __cdecl _set_output_format(unsigned int _Format);
  _CRTIMP       unsigned int __cdecl _get_output_format(void);
  /* _CRTIMP */ int          __cdecl  setvbuf(FILE * __restrict__ _File, char * __restrict__ _Buf, int _Mode, size_t _Size);
#if __MSVCRT_VERSION__ >= 0x1400
  __mingw_ovr
    int _snprintf_s(char *_DstBuf, size_t _SizeInBytes, size_t _MaxCount, const char *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vsnprintf_s(0, _DstBuf, _SizeInBytes, _MaxCount, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(int, _snprintf_s, _vsnprintf_s, char, _Dest, size_t, _MaxCount, const char *, _Format)
  __mingw_ovr
    int sprintf_s(char *_DstBuf, size_t _SizeInBytes, const char *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vsprintf_s(0, _DstBuf, _SizeInBytes, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(int, sprintf_s, vsprintf_s, char, _Dest, const char *, _Format)
  __mingw_ovr
    int _scprintf(const char * __restrict__ _Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vsprintf(UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _sscanf_l(const char *_Src, const char *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vsscanf(0, _Src, (size_t)-1, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int sscanf_s(const char *_Src, const char *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vsscanf(UCRTBASE_SCANF_SECURECRT, _Src, (size_t)-1, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _sscanf_s_l(const char *_Src, const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vsscanf(UCRTBASE_SCANF_SECURECRT, _Src, (size_t)-1, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _snscanf(const char * __restrict__ _Src, size_t _MaxCount, const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vsscanf(0, _Src, _MaxCount, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _snscanf_l(const char *_Src, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vsscanf(0, _Src, _MaxCount, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _snscanf_s(const char *_Src, size_t _MaxCount, const char *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vsscanf(UCRTBASE_SCANF_SECURECRT, _Src, _MaxCount, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _snscanf_s_l(const char *_Src, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vsscanf(UCRTBASE_SCANF_SECURECRT, _Src, _MaxCount, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
#else  /* __MSVCRT_VERSION__ >= 0x1400 */
  _CRTIMP       int          __cdecl _snprintf_s(char *_DstBuf, size_t _SizeInBytes, size_t _MaxCount, const char *_Format, ...);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(int, _snprintf_s, _vsnprintf_s, char, _Dest, size_t, _MaxCount, const char *, _Format)
  _CRTIMP       int          __cdecl  sprintf_s(char *_DstBuf, size_t _SizeInBytes, const char *_Format, ...);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(int, sprintf_s, vsprintf_s, char, _Dest, const char *, _Format)
  _CRTIMP       int          __cdecl _scprintf(const char * __restrict__ _Format, ...);
  _CRTIMP       int          __cdecl _sscanf_l(const char *_Src, const char *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ int          __cdecl  sscanf_s(const char *_Src, const char *_Format, ...);
  _CRTIMP       int          __cdecl _sscanf_s_l(const char *_Src, const char *_Format, _locale_t _Locale, ...);
  _CRTIMP       int          __cdecl _snscanf(const char * __restrict__ _Src, size_t _MaxCount, const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       int          __cdecl _snscanf_l(const char *_Src, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       int          __cdecl _snscanf_s(const char *_Src, size_t _MaxCount, const char *_Format, ...);
  _CRTIMP       int          __cdecl _snscanf_s_l(const char *_Src, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...);
#endif  /* __MSVCRT_VERSION__ >= 0x1400 */
  /* _CRTIMP */ FILE *       __cdecl  tmpfile(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ errno_t      __cdecl  tmpfile_s(FILE **_File);
  /* _CRTIMP */ errno_t      __cdecl  tmpnam_s(char *_Buf, rsize_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, tmpnam_s, char, _Buf)
  /* _CRTIMP */ char *       __cdecl  tmpnam(char *_Buffer);
  /* _CRTIMP */ int          __cdecl  ungetc(int _Ch, FILE *_File);
#if __MSVCRT_VERSION__ >= 0x1400
  __mingw_ovr
    int vfprintf_s(FILE *_File, const char *_Format, va_list _ArgList) {
      return __stdio_common_vfprintf_s(0, _File, _Format, NULL, _ArgList);
    }
  __mingw_ovr
    int vfscanf_s(FILE *_File, const char *_Format, va_list _ArgList) {
      return __stdio_common_vfscanf(UCRTBASE_SCANF_SECURECRT, _File, _Format, NULL, _ArgList);
    }
  __mingw_ovr
    int vprintf_s(const char *_Format, va_list _ArgList) {
      return __stdio_common_vfprintf_s(0, stdout, _Format, NULL, _ArgList);
    }
  __mingw_ovr
    int vscanf_s(const char *_Format, va_list _ArgList) {
      return __stdio_common_vfscanf(UCRTBASE_SCANF_SECURECRT, stdin, _Format, NULL, _ArgList);
    }
  __mingw_ovr
    int vsnprintf_s(char *_DstBuf, size_t _DstSize, size_t _MaxCount, const char *_Format, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vsnprintf_s(0, _DstBuf, _DstSize, _MaxCount, _Format, NULL, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int, vsnprintf_s, char, _Dest, size_t, _MaxCount, const char *, _Format, va_list, _ArgList)
  __mingw_ovr
    int _vsnprintf_s(char *_DstBuf, size_t _SizeInBytes, size_t _MaxCount, const char *_Format, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vsnprintf_s(0, _DstBuf, _SizeInBytes, _MaxCount, _Format, NULL, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int, _vsnprintf_s, char, _Dest, size_t, _MaxCount, const char *, _Format, va_list, _Args)
  __mingw_ovr __attribute__((__format__(ms_printf, 3, 0))) __MINGW_ATTRIB_NONNULL(3)
    int _vsnprintf(char * __restrict__ _Dest, size_t _Count, const char * __restrict__ _Format, va_list _Args) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      return __stdio_common_vsprintf(UCRTBASE_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Dest, _Count, _Format, NULL, _Args);
    }
  __mingw_ovr __attribute__((__format__(ms_printf, 3, 4))) __MINGW_ATTRIB_NONNULL(3)
    int _snprintf(char * __restrict__ _Dest, size_t _Count, const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = _vsnprintf(_Dest, _Count, _Format, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int vsprintf_s(char *_DstBuf, size_t _SizeInBytes, const char *_Format, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vsprintf_s(0, _DstBuf, _SizeInBytes, _Format, NULL, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vsprintf_s, char, _Dest, const char *, _Format, va_list, _ArgList)
  __mingw_ovr
    int vsscanf_s(const char *_Src, const char *_Format, va_list _ArgList) {
      return __stdio_common_vsscanf(UCRTBASE_SCANF_SECURECRT, _Src, (size_t)-1, _Format, NULL, _ArgList);
    }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vsscanf_s, const char, _Src, const char *, _Format, va_list, _Args)
  __mingw_ovr
    int _vscprintf(const char * __restrict__ _Format, va_list _ArgList) {
      return __stdio_common_vsprintf(UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, NULL, _ArgList);
    }
  __mingw_ovr
    int _snprintf_c(char *_DstBuf, size_t _MaxCount, const char *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vsprintf(0, _DstBuf, _MaxCount, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vsnprintf_c(char *_DstBuf, size_t _MaxCount, const char *_Format, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vsprintf(0, _DstBuf, _MaxCount, _Format, NULL, _ArgList);
      return ret < 0 ? -1 : ret;
    }

  __mingw_ovr
    int _fprintf_p(FILE *_File, const char *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfprintf_p(0, _File, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _printf_p(const char *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vfprintf_p(0, stdout, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _sprintf_p(char *_Dst, size_t _MaxCount, const char *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vsprintf_p(0, _Dst, _MaxCount, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vfprintf_p(FILE *_File, const char *_Format, va_list _ArgList) {
      return __stdio_common_vfprintf_p(0, _File, _Format, NULL, _ArgList)
    }
  __mingw_ovr
    int _vprintf_p(const char *_Format, va_list _ArgList) {
      return __stdio_common_vfprintf_p(0, stdout, _Format, NULL, _ArgList);
    }
  __mingw_ovr
    int _vsprintf_p(char *_Dst, size_t _MaxCount, const char *_Format, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vsprintf_p(0, _Dst, _MaxCount, _Format, NULL, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _scprintf_p(const char *_Format, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Format);
      ret = __stdio_common_vsprintf_p(UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, NULL, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vscprintf_p(const char *_Format, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vsprintf_p(UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, NULL, _ArgList);
      return ret < 0 ? -1 : ret;
    }
#else  /* __MSVCRT_VERSION__ >= 0x1400 */
  /* _CRTIMP */ int          __cdecl  vfprintf_s(FILE *_File, const char *_Format, va_list _ArgList);
#if __MSVCRT_VERSION__ >= 0x1200
  /* _CRTIMP */ int          __cdecl  vfscanf_s(FILE *_File, const char *_Format, va_list _ArgList);
#endif  /* __MSVCRT_VERSION__ >= 0x1200 */
  /* _CRTIMP */ int          __cdecl  vprintf_s(const char *_Format, va_list _ArgList);
#if __MSVCRT_VERSION__ >= 0x1200
  /* _CRTIMP */ int          __cdecl  vscanf_s(const char *_Format, va_list _ArgList);
#endif  /* __MSVCRT_VERSION__ >= 0x1200 */
  /* _CRTIMP */ int          __cdecl  vsnprintf_s(char *_DstBuf, size_t _DstSize, size_t _MaxCount, const char *_Format, va_list _ArgList);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int, vsnprintf_s, char, _Dest, size_t, _MaxCount, const char *, _Format, va_list, _ArgList)
  /* _CRTIMP */ int          __cdecl _vsnprintf_s(char *_DstBuf, size_t _SizeInBytes, size_t _MaxCount, const char *_Format, va_list _ArgList);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int, _vsnprintf_s, char, _Dest, size_t, _MaxCount, const char *, _Format, va_list, _Args)
  __attribute__((__format__(ms_printf, 3, 4))) __MINGW_ATTRIB_NONNULL(3)
  _CRTIMP       int          __cdecl _snprintf(char * __restrict__ _Dest, size_t _Count, const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __attribute__((__format__(ms_printf, 3, 0))) __MINGW_ATTRIB_NONNULL(3)
  _CRTIMP       int          __cdecl _vsnprintf(char * __restrict__ _Dest, size_t _Count, const char * __restrict__ _Format, va_list _Args) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ int          __cdecl  vsprintf_s(char *_DstBuf, size_t _SizeInBytes, const char *_Format, va_list _ArgList);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vsprintf_s, char, _Dest, const char *, _Format, va_list, _ArgList)
#if __MSVCRT_VERSION__ >= 0x1200
  /* _CRTIMP */ int          __cdecl  vsscanf_s(const char *_Src, const char *_Format, va_list _ArgList);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vsscanf_s, const char, _Src, const char *, _Format, va_list, _Args)
#endif  /* __MSVCRT_VERSION__ >= 0x1200 */
  _CRTIMP       int          __cdecl _vscprintf(const char * __restrict__ _Format, va_list _ArgList);
  _CRTIMP       int          __cdecl _snprintf_c(char *_DstBuf, size_t _MaxCount, const char *_Format, ...);
  _CRTIMP       int          __cdecl _vsnprintf_c(char *_DstBuf, size_t _MaxCount, const char *_Format, va_list _ArgList);

  _CRTIMP       int          __cdecl _fprintf_p(FILE *_File, const char *_Format, ...);
  _CRTIMP       int          __cdecl _printf_p(const char *_Format, ...);
  _CRTIMP       int          __cdecl _sprintf_p(char *_Dst, size_t _MaxCount, const char *_Format, ...);
  _CRTIMP       int          __cdecl _vfprintf_p(FILE *_File, const char *_Format, va_list _ArgList);
  _CRTIMP       int          __cdecl _vprintf_p(const char *_Format, va_list _ArgList);
  _CRTIMP       int          __cdecl _vsprintf_p(char *_Dst, size_t _MaxCount, const char *_Format, va_list _ArgList);
  _CRTIMP       int          __cdecl _scprintf_p(const char *_Format, ...);
  _CRTIMP       int          __cdecl _vscprintf_p(const char *_Format, va_list _ArgList);  /* We provide emu. */
#endif  /* __MSVCRT_VERSION__ >= 0x1400 */
  _CRTIMP       int          __cdecl _set_printf_count_output(int _Value);
  _CRTIMP       int          __cdecl _get_printf_count_output(void);

#if __MSVCRT_VERSION__ >= 0x1400
  __mingw_ovr
    int _printf_l(const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfprintf(0, stdout, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _printf_p_l(const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfprintf_p(0, stdout, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _printf_s_l(const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfprintf_s(0, stdout, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _vprintf_l(const char *_Format, _locale_t _Locale, va_list _ArgList) {
      return __stdio_common_vfprintf(0, stdout, _Format, _Locale, _ArgList);
    }
  __mingw_ovr
    int _vprintf_p_l(const char *_Format, _locale_t _Locale, va_list _ArgList) {
      return __stdio_common_vfprintf_p(0, stdout, _Format, _Locale, _ArgList);
    }
  __mingw_ovr
    int _vprintf_s_l(const char *_Format, _locale_t _Locale, va_list _ArgList) {
      return __stdio_common_vfprintf_s(0, stdout, _Format, _Locale, _ArgList);
    }

  __mingw_ovr
    int _fprintf_l(FILE *_File, const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfprintf(0, _File, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _fprintf_p_l(FILE *_File, const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfprintf_p(0, _File, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _fprintf_s_l(FILE *_File, const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vfprintf_s(0, _File, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret;
    }
  __mingw_ovr
    int _vfprintf_l(FILE *_File, const char *_Format, _locale_t _Locale, va_list _ArgList) {
      return __stdio_common_vfprintf(0, _File, _Format, _Locale, _ArgList);
    }
  __mingw_ovr
    int _vfprintf_p_l(FILE *_File, const char *_Format, _locale_t _Locale, va_list _ArgList) {
      return __stdio_common_vfprintf_p(0, _File, _Format, _Locale, _ArgList);
    }
  __mingw_ovr
    int _vfprintf_s_l(FILE *_File, const char *_Format, _locale_t _Locale, va_list _ArgList) {
      return __stdio_common_vfprintf_s(0, _File, _Format, _Locale, _ArgList);
    }

  __mingw_ovr
    int _sprintf_l(char *_DstBuf, const char *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vsprintf(UCRTBASE_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _DstBuf, (size_t)-1, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _sprintf_p_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vsprintf_p(0, _DstBuf, _MaxCount, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _sprintf_s_l(char *_DstBuf, size_t _DstSize, const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vsprintf_s(0, _DstBuf, _DstSize, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vsprintf_l(char *_DstBuf, const char *_Format, _locale_t _Locale, va_list _ArgList) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      ret = __stdio_common_vsprintf(UCRTBASE_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _DstBuf, (size_t)-1, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vsprintf_p_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vsprintf_p(0, _DstBuf, _MaxCount, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vsprintf_s_l(char *_DstBuf, size_t _DstSize, const char *_Format, _locale_t _Locale, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vsprintf_s(0, _DstBuf, _DstSize, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }

  __mingw_ovr
    int _scprintf_l(const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vsprintf(UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _scprintf_p_l(const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vsprintf_p(UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vscprintf_l(const char *_Format, _locale_t _Locale, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vsprintf(UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vscprintf_p_l(const char *_Format, _locale_t _Locale, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vsprintf_p(UCRTBASE_PRINTF_STANDARD_SNPRINTF_BEHAVIOUR, NULL, 0, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }

  __mingw_ovr
    int _snprintf_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vsprintf(UCRTBASE_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _DstBuf, _MaxCount, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _snprintf_c_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vsprintf(0, _DstBuf, _MaxCount, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _snprintf_s_l(char *_DstBuf, size_t _DstSize, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...) {
      int ret;
      __builtin_va_list ap;
      __builtin_va_start(ap, _Locale);
      ret = __stdio_common_vsnprintf_s(0, _DstBuf, _DstSize, _MaxCount, _Format, _Locale, ap);
      __builtin_va_end(ap);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vsnprintf_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList) __MINGW_ATTRIB_DEPRECATED_SEC_WARN {
      int ret;
      ret = __stdio_common_vsprintf(UCRTBASE_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _DstBuf, _MaxCount, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vsnprintf_c_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vsprintf(0, _DstBuf, _MaxCount, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }
  __mingw_ovr
    int _vsnprintf_s_l(char *_DstBuf, size_t _DstSize, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList) {
      int ret;
      ret = __stdio_common_vsnprintf_s(0, _DstBuf, _DstSize, _MaxCount, _Format, _Locale, _ArgList);
      return ret < 0 ? -1 : ret;
    }
#else  /* __MSVCRT_VERSION__ >= 0x1400 */
  _CRTIMP       int          __cdecl _printf_l(const char *_Format, _locale_t _Locale, ...);
  _CRTIMP       int          __cdecl _printf_p_l(const char *_Format, _locale_t _Locale, ...);
  _CRTIMP       int          __cdecl _printf_s_l(const char *_Format, _locale_t _Locale, ...);
  _CRTIMP       int          __cdecl _vprintf_l(const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP       int          __cdecl _vprintf_p_l(const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP       int          __cdecl _vprintf_s_l(const char *_Format, _locale_t _Locale, va_list _ArgList);

  _CRTIMP       int          __cdecl _fprintf_l(FILE *_File, const char *_Format, _locale_t _Locale, ...);
  _CRTIMP       int          __cdecl _fprintf_p_l(FILE *_File, const char *_Format, _locale_t _Locale, ...);
  _CRTIMP       int          __cdecl _fprintf_s_l(FILE *_File, const char *_Format, _locale_t _Locale, ...);
  _CRTIMP       int          __cdecl _vfprintf_l(FILE *_File, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP       int          __cdecl _vfprintf_p_l(FILE *_File, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP       int          __cdecl _vfprintf_s_l(FILE *_File, const char *_Format, _locale_t _Locale, va_list _ArgList);

  _CRTIMP       int          __cdecl _sprintf_l(char *_DstBuf, const char *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       int          __cdecl _sprintf_p_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...);
  _CRTIMP       int          __cdecl _sprintf_s_l(char *_DstBuf, size_t _DstSize, const char *_Format, _locale_t _Locale, ...);
  _CRTIMP       int          __cdecl _vsprintf_l(char *_DstBuf, const char *_Format, _locale_t _Locale, va_list _ArgList) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       int          __cdecl _vsprintf_p_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP       int          __cdecl _vsprintf_s_l(char *_DstBuf, size_t _DstSize, const char *_Format, _locale_t _Locale, va_list _ArgList);

  _CRTIMP       int          __cdecl _scprintf_l(const char *_Format, _locale_t _Locale, ...);
  _CRTIMP       int          __cdecl _scprintf_p_l(const char *_Format, _locale_t _Locale, ...);
  _CRTIMP       int          __cdecl _vscprintf_l(const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP       int          __cdecl _vscprintf_p_l(const char *_Format, _locale_t _Locale, va_list _ArgList);

  _CRTIMP       int          __cdecl _snprintf_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       int          __cdecl _snprintf_c_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...);
  _CRTIMP       int          __cdecl _snprintf_s_l(char *_DstBuf, size_t _DstSize, size_t _MaxCount, const char *_Format, _locale_t _Locale, ...);
  _CRTIMP       int          __cdecl _vsnprintf_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       int          __cdecl _vsnprintf_c_l(char *_DstBuf, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP       int          __cdecl _vsnprintf_s_l(char *_DstBuf, size_t _DstSize, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList);
#endif  /* __MSVCRT_VERSION__ >= 0x1400 */

#ifndef __CRT__NO_INLINE
  __CRT_INLINE int __cdecl _vscprintf_p(const char *_Format, va_list _ArgList) {
    return _vscprintf_p_l(_Format, NULL, _ArgList);
  }
#endif  /* !__CRT__NO_INLINE */

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
  _CRTIMP       int       __cdecl _vscwprintf_p(const wchar_t *_Format, va_list _ArgList);  /* We provide emu. */

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

#ifndef __CRT__NO_INLINE
  __CRT_INLINE int __cdecl _vswprintf_p(wchar_t *_DstBuf, size_t _MaxCount, const wchar_t *_Format, va_list _ArgList) {
    return _vswprintf_p_l(_DstBuf, _MaxCount, _Format, NULL, _ArgList);
  }
  __CRT_INLINE int __cdecl _vscwprintf_p(const wchar_t *_Format, va_list _ArgList) {
    return _vscwprintf_p_l(_Format, NULL, _ArgList);
  }
#endif  /* !__CRT__NO_INLINE */

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

#define _STDIO_DEFINED
#endif  /* !_STDIO_DEFINED */

#define _fgetc_nolock(_stream)     (--(_stream)->_cnt >= 0 ? 0xff & *(_stream)->_ptr++ : _filbuf(_stream))
#define _fputc_nolock(_c, _stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (char)(_c)) : _flsbuf((_c), (_stream)))
#define _getc_nolock(_stream)      _fgetc_nolock(_stream)
#define _putc_nolock(_c, _stream)  _fputc_nolock(_c, _stream)
#define _getchar_nolock()          _getc_nolock(stdin)
#define _putchar_nolock(_c)        _putc_nolock((_c), stdout)
#define _getwchar_nolock()         _getwc_nolock(stdin)
#define _putwchar_nolock(_c)       _putwc_nolock((_c), stdout)

  /* We provide emu. */
  _CRTIMP void   __cdecl _lock_file(FILE *_File);
  _CRTIMP void   __cdecl _unlock_file(FILE *_File);

#if __MSVCRT_VERSION__ > 0x0800
                    _CRTIMP int     __cdecl _fclose_nolock(FILE *_File);
                    _CRTIMP int     __cdecl _fflush_nolock(FILE *_File);
                    _CRTIMP size_t  __cdecl _fread_nolock(void * __restrict__ _DstBuf, size_t _ElementSize, size_t _Count, FILE * __restrict__ _File);
                    _CRTIMP size_t  __cdecl _fread_nolock_s(void *_DstBuf, size_t _DstSize, size_t _ElementSize, size_t _Count, FILE *_File);
                    _CRTIMP int     __cdecl _fseek_nolock(FILE *_File, long _Offset, int _Origin);
                    _CRTIMP long    __cdecl _ftell_nolock(FILE *_File);
  __MINGW_EXTENSION _CRTIMP int     __cdecl _fseeki64_nolock(FILE *_File, __int64 _Offset, int _Origin);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
                    _CRTIMP size_t  __cdecl _fwrite_nolock(const void * __restrict__ _DstBuf, size_t _Size, size_t _Count, FILE * __restrict__ _File);
                    _CRTIMP int     __cdecl _ungetc_nolock(int _Ch, FILE *_File);
#endif  /* __MSVCRT_VERSION__ > 0x0800 */

#if !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  /* _CRTIMP */ char * __cdecl tempnam(const char *_Directory, const char *_FilePrefix) __MINGW_ATTRIB_DEPRECATED_MSVC2005;

  /* _CRTIMP */ int    __cdecl fcloseall(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ FILE * __cdecl fdopen(int _FileHandle, const char *_Format) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl fgetchar(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl fileno(FILE *_File) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl flushall(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl fputchar(int _Ch) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl getw(FILE *_File) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl putw(int _Ch, FILE *_File) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl rmtmp(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;

#endif  /* !defined(NO_OLDNAMES) || !defined(_POSIX) */

#ifndef __MINGW_MBWC_CONVERT_DEFINED
/* Provided in libmingwex. */

/**
 * __mingw_str_wide_utf8
 * Converts a null terminated UCS-2 string to a multibyte (UTF-8) equivalent.
 * Caller is supposed to free allocated buffer with __mingw_str_free().
 * @param[in] wptr Pointer to wide string.
 * @param[out] mbptr Pointer to multibyte string.
 * @param[out] buflen Optional parameter for length of allocated buffer.
 * @return Number of characters converted, 0 for failure.
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
 * @return Number of characters converted, 0 for failure.
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

#ifndef _P_WAIT
#define _P_WAIT          0
#define _P_NOWAIT        1
#define _OLD_P_OVERLAY   2
#define _P_NOWAITO       3
#define _P_DETACH        4

#define _P_OVERLAY       2

#define _WAIT_CHILD      0
#define _WAIT_GRANDCHILD 1
#endif  /* !_P_WAIT */

#ifndef _SPAWNV_DEFINED
  _CRTIMP intptr_t __cdecl _spawnv(int _Mode, const char *_Filename, const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(int _Mode, const char *_Filename, const char *const *_ArgList, const char *const *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(int _Mode, const char *_Filename, const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(int _Mode, const char *_Filename, const char *const *_ArgList, const char *const *_Env);
#define _SPAWNV_DEFINED
#endif  /* !_SPAWNV_DEFINED */

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

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#pragma pack(pop)

#include <_mingw_print_pop.h>

#endif  /* _INC_STDIO */
