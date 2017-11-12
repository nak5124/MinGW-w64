/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_LOCALE
#define _INC_LOCALE

#include <crtdefs.h>

#ifdef __cplusplus
#include <stdio.h>
#endif  /* __cplusplus */

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

#define LC_ALL      0
#define LC_COLLATE  1
#define LC_CTYPE    2
#define LC_MONETARY 3
#define LC_NUMERIC  4
#define LC_TIME     5

#define LC_MIN      LC_ALL
#define LC_MAX      LC_TIME

#ifndef _LCONV_DEFINED
  struct lconv {
    char *decimal_point;
    char *thousands_sep;
    char *grouping;
    char *int_curr_symbol;
    char *currency_symbol;
    char *mon_decimal_point;
    char *mon_thousands_sep;
    char *mon_grouping;
    char *positive_sign;
    char *negative_sign;
    char  int_frac_digits;
    char  frac_digits;
    char  p_cs_precedes;
    char  p_sep_by_space;
    char  n_cs_precedes;
    char  n_sep_by_space;
    char  p_sign_posn;
    char  n_sign_posn;
  };
#define _LCONV_DEFINED
#endif  /* _LCONV_DEFINED */

#ifndef _CONFIG_LOCALE_SWT
#define _ENABLE_PER_THREAD_LOCALE         0x1
#define _DISABLE_PER_THREAD_LOCALE        0x2
#define _ENABLE_PER_THREAD_LOCALE_GLOBAL  0x10
#define _DISABLE_PER_THREAD_LOCALE_GLOBAL 0x20
#define _ENABLE_PER_THREAD_LOCALE_NEW     0x100
#define _DISABLE_PER_THREAD_LOCALE_NEW    0x200
#define _CONFIG_LOCALE_SWT
#endif  /* !_CONFIG_LOCALE_SWT */

  _CRTIMP       int            __cdecl _configthreadlocale(int _Flag);
  /* _CRTIMP */ char *         __cdecl setlocale(int _Category, const char *_Locale);
  _CRTIMP       struct lconv * __cdecl localeconv(void);
  _CRTIMP       _locale_t      __cdecl _get_current_locale(void);
  _CRTIMP       _locale_t      __cdecl _create_locale(int _Category, const char *_Locale);
  _CRTIMP       void           __cdecl _free_locale(_locale_t _Locale);
#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP _locale_t            __cdecl __get_current_locale(void);
  _CRTIMP _locale_t            __cdecl __create_locale(int _Category, const char *_Locale);
  _CRTIMP void                 __cdecl __free_locale(_locale_t _Locale);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */

#ifndef _WLOCALE_DEFINED
  _CRTIMP wchar_t * __cdecl _wsetlocale(int _Category, const wchar_t *_Locale);
#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP _locale_t __cdecl _wcreate_locale(int _Category, const wchar_t *_Locale);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */
#define _WLOCALE_DEFINED
#endif  /* _WLOCALE_DEFINED */

#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP wchar_t **   __cdecl ___lc_locale_name_func(void);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */
  _CRTIMP unsigned int __cdecl ___lc_codepage_func(void);
  _CRTIMP unsigned int __cdecl ___lc_collate_cp_func(void);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#pragma pack(pop)

#endif  /* _INC_LOCALE */
