/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WCTYPE
#define _INC_WCTYPE

#ifndef _WIN32
#error Only Win32 target is supported!
#endif  /* !_WIN32 */

#include <crtdefs.h>

#pragma pack(push, _CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif  /* !_CRTIMP */

#ifndef _WCHAR_T_DEFINED
#ifndef __cplusplus
  typedef unsigned short wchar_t;
#endif  /* !__cplusplus */
#define _WCHAR_T_DEFINED
#endif  /* !_WCHAR_T_DEFINED */

#ifndef _WCTYPE_T_DEFINED
  typedef unsigned short wint_t;
  typedef unsigned short wctype_t;
#define _WCTYPE_T_DEFINED
#endif  /* !_WCTYPE_T_DEFINED */

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif  /* !WEOF */

#ifndef _CRT_CTYPEDATA_DEFINED
#define _CRT_CTYPEDATA_DEFINED
#ifndef _CTYPE_DISABLE_MACROS
#if __MSVCRT_VERSION__ >= 0x0800 || defined(_X86_)
  _CRTIMP const unsigned short ** __cdecl __p__pctype(void);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 || defined(_X86_) */

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
#if __MSVCRT_VERSION__ >= 0x0800 || defined(_X86_)
  _CRTIMP const wctype_t ** __cdecl __p__pwctype(void);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 || defined(_X86_) */

  _CRTIMP        const wctype_t * __cdecl __pwctype_func(void);
  _CRTIMP extern const wctype_t *          _pwctype;
#endif  /* !_CTYPE_DISABLE_MACROS */
#endif  /* !_CRT_WCTYPEDATA_DEFINED */

  extern const unsigned short __newctype[];  /* Internal CRT Global */

#define _UPPER 0x1
#define _LOWER 0x2
#define _DIGIT 0x4
#define _SPACE 0x8

#define _PUNCT 0x10
#define _CONTROL 0x20
#define _BLANK 0x40
#define _HEX 0x80

#define _LEADBYTE 0x8000
#define _ALPHA (0x0100|_UPPER|_LOWER)

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

#ifndef _WCTYPE_DEFINED

  /* _CRTIMP */ int    __cdecl   iswalpha(wint_t _C);
  /* _CRTIMP */ int    __cdecl   iswupper(wint_t _C);
  /* _CRTIMP */ int    __cdecl   iswlower(wint_t _C);
  /* _CRTIMP */ int    __cdecl   iswdigit(wint_t _C);
  /* _CRTIMP */ int    __cdecl   iswxdigit(wint_t _C);
  /* _CRTIMP */ int    __cdecl   iswspace(wint_t _C);
  /* _CRTIMP */ int    __cdecl   iswpunct(wint_t _C);
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || _XOPEN_SOURCE >= 600 || _ISOC99_SOURCE || _POSIX_C_SOURCE >= 200112L || defined(__cplusplus)
#if __MSVCRT_VERSION__ >= 0x1200
  _CRTIMP       int __cdecl  iswblank(wint_t _C);
#else  /* __MSVCRT_VERSION__ >= 0x1200 */
                int __cdecl  iswblank(wint_t _C);  /* Provided in libmingwex. */
#endif  /* __MSVCRT_VERSION__ >= 0x1200 */
#endif  /* (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || ... */
  /* _CRTIMP */ int    __cdecl   iswalnum(wint_t _C);
  /* _CRTIMP */ int    __cdecl   iswprint(wint_t _C);
  /* _CRTIMP */ int    __cdecl   iswgraph(wint_t _C);
  /* _CRTIMP */ int    __cdecl   iswcntrl(wint_t _C);
  /* _CRTIMP */ int    __cdecl   iswascii(wint_t _C);
  /* _CRTIMP */ int    __cdecl   isleadbyte(int _C);

  /* _CRTIMP */ wint_t __cdecl   towupper(wint_t _C);
  /* _CRTIMP */ wint_t __cdecl   towlower(wint_t _C);

  /* _CRTIMP */ int    __cdecl   iswctype(wint_t _C, wctype_t _Type);

  _CRTIMP       int    __cdecl __iswcsymf(wint_t _C);
  _CRTIMP       int    __cdecl __iswcsym(wint_t _C);

  /* _CRTIMP */ int    __cdecl   is_wctype(wint_t _C, wctype_t _Type);

#define _WCTYPE_DEFINED
#endif  /* !_WCTYPE_DEFINED */

#ifndef _WCTYPE_INLINE_DEFINED
#ifndef __cplusplus
#define iswalpha(_c)  (iswctype(_c, _ALPHA))
#define iswupper(_c)  (iswctype(_c, _UPPER))
#define iswlower(_c)  (iswctype(_c, _LOWER))
#define iswdigit(_c)  (iswctype(_c, _DIGIT))
#define iswxdigit(_c) (iswctype(_c, _HEX))
#define iswspace(_c)  (iswctype(_c,_SPACE))
#define iswpunct(_c)  (iswctype(_c,_PUNCT))
#define iswblank(_c)  (((_c) == '\t') ? _BLANK : iswctype(_c, _BLANK))
#define iswalnum(_c)  (iswctype(_c, _ALPHA|_DIGIT))
#define iswprint(_c)  (iswctype(_c, _BLANK|_PUNCT|_ALPHA|_DIGIT))
#define iswgraph(_c)  (iswctype(_c, _PUNCT|_ALPHA|_DIGIT))
#define iswcntrl(_c)  (iswctype(_c, _CONTROL))
#define iswascii(_c)  ((unsigned)(_c) < 0x80)

#define isleadbyte(c) (__pctype_func()[(unsigned char)(c)] & _LEADBYTE)
#else  /* !__cplusplus */
#ifndef __CRT__NO_INLINE
  __CRT_INLINE int __cdecl iswalpha(wint_t _C) {
    return iswctype(_C, _ALPHA);
  }
  __CRT_INLINE int __cdecl iswupper(wint_t _C) {
    return iswctype(_C, _UPPER);
  }
  __CRT_INLINE int __cdecl iswlower(wint_t _C) {
    return iswctype(_C, _LOWER);
  }
  __CRT_INLINE int __cdecl iswdigit(wint_t _C) {
    return iswctype(_C, _DIGIT);
  }
  __CRT_INLINE int __cdecl iswxdigit(wint_t _C) {
    return iswctype(_C, _HEX);
  }
  __CRT_INLINE int __cdecl iswspace(wint_t _C) {
    return iswctype(_C, _SPACE);
  }
  __CRT_INLINE int __cdecl iswpunct(wint_t _C) {
    return iswctype(_C, _PUNCT);
  }
  __CRT_INLINE int __cdecl iswblank(wint_t _C) {
    return (((_C) == '\t') ? _BLANK : iswctype(_C,_BLANK));
  }
  __CRT_INLINE int __cdecl iswalnum(wint_t _C) {
    return iswctype(_C, _ALPHA|_DIGIT);
  }
  __CRT_INLINE int __cdecl iswprint(wint_t _C) {
    return iswctype(_C, _BLANK|_PUNCT|_ALPHA|_DIGIT);
  }
  __CRT_INLINE int __cdecl iswgraph(wint_t _C) {
    return iswctype(_C, _PUNCT|_ALPHA|_DIGIT);
  }
  __CRT_INLINE int __cdecl iswcntrl(wint_t _C) {
    return iswctype(_C, _CONTROL);
  }
  __CRT_INLINE int __cdecl iswascii(wint_t _C) {
    return ((unsigned)(_C) < 0x80);
  }

  __CRT_INLINE int __cdecl isleadbyte(int _C) {
    return (__pctype_func()[(unsigned char)(_C)] & _LEADBYTE);
  }
#endif  /* !__CRT__NO_INLINE */
#endif  /* !__cplusplus */
#define _WCTYPE_INLINE_DEFINED
#endif  /* ! _WCTYPE_INLINE_DEFINED */

  typedef wchar_t wctrans_t;
#if __MSVCRT_VERSION__ >= 0x1200
  _CRTIMP       wint_t    __cdecl towctrans(wint_t wc, wctrans_t desc);
  _CRTIMP       wctrans_t __cdecl wctrans(const char *property);
  _CRTIMP       wctype_t  __cdecl wctype(const char *property);
#else  /* __MSVCRT_VERSION__ >= 0x1200 */
  /* Provided in libmingwex. */
  /* _CRTIMP */ wint_t    __cdecl towctrans(wint_t wc, wctrans_t desc);
  /* _CRTIMP */ wctrans_t __cdecl wctrans(const char *property);
  /* _CRTIMP */ wctype_t  __cdecl wctype(const char *property);
#endif  /* __MSVCRT_VERSION__ >= 0x1200 */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#pragma pack(pop)

#endif  /* _INC_WCTYPE */
