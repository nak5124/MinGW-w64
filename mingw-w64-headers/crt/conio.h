/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CONIO
#define _INC_CONIO

#include <crtdefs.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

  _CRTIMP char *  __cdecl _cgets(char *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _cgets_s(char *_Buffer, size_t _Size, size_t *_SizeRead);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _cgets_s, char, _Buffer, size_t *, _SizeRead)
  _CRTIMP int     __cdecl _cprintf(const char * __restrict__ _Format, ...);
  _CRTIMP int     __cdecl _cprintf_s(const char * _Format, ...);
  _CRTIMP int     __cdecl _cputs(const char *_Str);
  _CRTIMP int     __cdecl _cscanf(const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int     __cdecl _cscanf_l(const char * __restrict__ _Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int     __cdecl _cscanf_s(const char *_Format, ...);
  _CRTIMP int     __cdecl _cscanf_s_l(const char *_Format, _locale_t _Locale, ...);
  _CRTIMP int     __cdecl _getch(void);
  _CRTIMP int     __cdecl _getche(void);
  _CRTIMP int     __cdecl _vcprintf(const char * __restrict__ _Format, va_list _ArgList);
  _CRTIMP int     __cdecl _vcprintf_s(const char *_Format, va_list _ArgList);

  _CRTIMP int     __cdecl _cprintf_p(const char * __restrict__ _Format, ...);
  _CRTIMP int     __cdecl _vcprintf_p(const char * __restrict__ _Format, va_list _ArgList);

  _CRTIMP int     __cdecl _cprintf_l(const char * __restrict__ _Format, _locale_t _Locale, ...);
  _CRTIMP int     __cdecl _cprintf_s_l(const char *_Format, _locale_t _Locale, ...);
  _CRTIMP int     __cdecl _vcprintf_l(const char * __restrict__ _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int     __cdecl _vcprintf_s_l(const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int     __cdecl _cprintf_p_l(const char * __restrict__ _Format, _locale_t _Locale, ...);
  _CRTIMP int     __cdecl _vcprintf_p_l(const char * __restrict__ _Format, _locale_t _Locale, va_list _ArgList);

#if defined(_X86_) && !defined(__x86_64)
  int            __cdecl _inp(unsigned short);
  unsigned short __cdecl _inpw(unsigned short);
  unsigned long  __cdecl _inpd(unsigned short);
  int            __cdecl _outp(unsigned short, int);
  unsigned short __cdecl _outpw(unsigned short, unsigned short);
  unsigned long  __cdecl _outpd(unsigned short, unsigned long);
#endif  /* defined(_X86_) && !defined(__x86_64) */
  _CRTIMP int __cdecl _kbhit(void);
  _CRTIMP int __cdecl _putch(int _Ch);
  _CRTIMP int __cdecl _ungetch(int _Ch);

#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP int __cdecl _getch_nolock(void);
  _CRTIMP int __cdecl _getche_nolock(void);
  _CRTIMP int __cdecl _putch_nolock(int _Ch);
  _CRTIMP int __cdecl _ungetch_nolock(int _Ch);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */

#ifndef _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif  /* !WEOF */

  _CRTIMP wchar_t * __cdecl _cgetws(wchar_t *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t   __cdecl _cgetws_s(wchar_t *_Buffer, size_t _SizeInWords, size_t *_SizeRead);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _cgetws_s, wchar_t, _Buffer, size_t *, _SizeRead)
  _CRTIMP wint_t    __cdecl _getwch(void);
  _CRTIMP wint_t    __cdecl _getwche(void);
  _CRTIMP wint_t    __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t    __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP int       __cdecl _cputws(const wchar_t *_String);
  _CRTIMP int       __cdecl _cwprintf(const wchar_t * __restrict__ _Format, ...);
  _CRTIMP int       __cdecl _cwprintf_s(const wchar_t *_Format, ...);
  _CRTIMP int       __cdecl _cwscanf(const wchar_t * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int       __cdecl _cwscanf_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int       __cdecl _cwscanf_s(const wchar_t *_Format, ...);
  _CRTIMP int       __cdecl _cwscanf_s_l(const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP int       __cdecl _vcwprintf(const wchar_t * __restrict__ _Format, va_list _ArgList);
  _CRTIMP int       __cdecl _vcwprintf_s(const wchar_t *_Format, va_list _ArgList);

  _CRTIMP int       __cdecl _cwprintf_p(const wchar_t * __restrict__ _Format, ...);
  _CRTIMP int       __cdecl _vcwprintf_p(const wchar_t * __restrict__ _Format, va_list _ArgList);

  _CRTIMP int       __cdecl _cwprintf_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, ...);
  _CRTIMP int       __cdecl _cwprintf_s_l(const wchar_t *_Format, _locale_t _Locale, ...);
  _CRTIMP int       __cdecl _vcwprintf_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int       __cdecl _vcwprintf_s_l(const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int       __cdecl _cwprintf_p_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, ...);
  _CRTIMP int       __cdecl _vcwprintf_p_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList);

#ifdef __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(void);
  _CRTIMP wint_t __cdecl _getwche_nolock(void);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */

#define _WCONIO_DEFINED
#endif  /* !_WCONIO_DEFINED */

#ifndef NO_OLDNAMES
  /* _CRTIMP */ char * __cdecl cgets(char *_Buffer) __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ int    __cdecl cprintf(const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl cputs(const char *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl cscanf(const char * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl getch(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl getche(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl kbhit(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl putch(int _Ch) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl ungetch(int _Ch) __MINGW_ATTRIB_DEPRECATED_MSVC2005;

#if defined(_X86_) && !defined(__x86_64)
  int            __cdecl inp(unsigned short) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  unsigned long  __cdecl inpd(unsigned short) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  unsigned short __cdecl inpw(unsigned short) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int            __cdecl outp(unsigned short, int) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  unsigned long  __cdecl outpd(unsigned short, unsigned long) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  unsigned short __cdecl outpw(unsigned short, unsigned short) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif  /* defined(_X86_) && !defined(__x86_64) */

#endif  /* !NO_OLDNAMES */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* _INC_CONIO */
