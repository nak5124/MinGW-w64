/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#include <crtdefs.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef _NLSCMP_DEFINED
#define _NLSCMPERROR 2147483647
#define _NLSCMP_DEFINED
#endif  /* !_NLSCMP_DEFINED */

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

#define _WConst_return _CONST_RETURN

#ifndef RC_INVOKED
#ifndef _CRT_MEMORY_DEFINED
  _CRTIMP                     void *  __cdecl _memccpy(void *_Dst, const void *_Src, int _Val, size_t _MaxCount);
  /* _CRTIMP */ _CONST_RETURN void *  __cdecl  memchr(const void *_Buf, int _Val, size_t _MaxCount);
  _CRTIMP                     int     __cdecl _memicmp(const void *_Buf1, const void *_Buf2, size_t _Size);
  _CRTIMP                     int     __cdecl _memicmp_l(const void *_Buf1, const void *_Buf2, size_t _Size, _locale_t _Locale);
                              int     __cdecl  memcmp(const void *_Buf1, const void *_Buf2, size_t _Size);
                              void *  __cdecl  memcpy(void * __restrict__ _Dst, const void * __restrict__ _Src, size_t _Size) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */               errno_t __cdecl  memcpy_s(void *_Dst, rsize_t _DstSize, const void *_Src, rsize_t _MaxCount);  /* We provide emu. */
                              void *  __cdecl  mempcpy(void *_Dst, const void *_Src, size_t _Size);  /* Provided in libmingwex. */
                              void *  __cdecl  memset(void *_Dst, int _Val, size_t _Size);

#ifndef NO_OLDNAMES
  void * __cdecl memccpy(void *_Dst, const void *_Src, int _Val, size_t _Size) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int    __cdecl memicmp(const void *_Buf1, const void *_Buf2, size_t _Size) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif  /* !NO_OLDNAMES */

#define _CRT_MEMORY_DEFINED
#endif  /* !_CRT_MEMORY_DEFINED */
#endif  /* !RC_INVOKED */

#ifdef _GNU_SOURCE
                void *           memmem(const void *_block, size_t _blen, const void *_pat, size_t _plen);
#endif  /* _GNU_SOURCE */

  _CRTIMP       errno_t __cdecl _strset_s(char *_Dst, size_t _DstSize, int _Value);
                char *  __cdecl _strset(char *_Dest, int _Value) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP       errno_t __cdecl  strcpy_s(char *_Dst, rsize_t _SizeInBytes, const char *_Src);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, strcpy_s, char, _Dest, const char *, _Source)
                char *  __cdecl  strcpy(char * __restrict__ _Dest, const char * __restrict__ _Source);
#if _POSIX_C_SOURCE >= 200809L || _XOPEN_SOURCE >= 700
                char *           stpcpy(char * __restrict__ _Dest, const char * __restrict__ _Source);
                char *           stpncpy(char * __restrict__ _Dest, const char * __restrict__ _Source, size_t n);
#endif  /* _POSIX_C_SOURCE >= 200809L || _XOPEN_SOURCE >= 700 */
  _CRTIMP       errno_t __cdecl  strcat_s(char *_Dst, rsize_t _SizeInBytes, const char *_Src);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, strcat_s, char, _Dest, const char *, _Source)
                char *  __cdecl  strcat(char * __restrict__ _Dest, const char * __restrict__ _Source);
                int     __cdecl  strcmp(const char *_Str1, const char *_Str2);
                size_t  __cdecl  strlen(const char *_Str);
  _CRTIMP       size_t  __cdecl  strnlen(const char *_Str, size_t _MaxCount);
  __forceinline size_t __cdecl strnlen_s(const char *_Str, size_t _MaxCount) {
    return (_Str == 0) ? 0 : strnlen(_Str, _MaxCount);
  }
  /* We provide emu. */
  /* _CRTIMP */ errno_t __cdecl  memmove_s(void *_Dst, rsize_t _DstSize, const void *_Src, rsize_t _MaxCount);

  /* _CRTIMP */ void *  __cdecl  memmove(void *_Dst, const void *_Src, size_t _Size) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  _CRTIMP       char *  __cdecl _strdup(const char *_Src);
#if _POSIX_C_SOURCE >= 200809L || _XOPEN_SOURCE >= 700
                char *           strndup(const char *_Str, size_t n);
#endif  /* _POSIX_C_SOURCE >= 200809L || _XOPEN_SOURCE >= 700 */

  /* _CRTIMP */ _CONST_RETURN char *  __cdecl  strchr(const char *_Str, int _Val);
  _CRTIMP                     int     __cdecl _stricmp(const char *_Str1, const char *_Str2);
  _CRTIMP                     int     __cdecl _strcmpi(const char *_Str1, const char *_Str2);
  _CRTIMP                     int     __cdecl _stricmp_l(const char *_Str1, const char *_Str2, _locale_t _Locale);
  /* _CRTIMP */               int     __cdecl  strcoll(const char *_Str1, const char *_Str2);
  _CRTIMP                     int     __cdecl _strcoll_l(const char *_Str1, const char *_Str2, _locale_t _Locale);
  _CRTIMP                     int     __cdecl _stricoll(const char *_Str1, const char *_Str2);
  _CRTIMP                     int     __cdecl _stricoll_l(const char *_Str1, const char *_Str2, _locale_t _Locale);
  _CRTIMP                     int     __cdecl _strncoll(const char *_Str1, const char *_Str2, size_t _MaxCount);
  _CRTIMP                     int     __cdecl _strncoll_l(const char *_Str1, const char *_Str2, size_t _MaxCount, _locale_t _Locale);
  _CRTIMP                     int     __cdecl _strnicoll(const char *_Str1, const char *_Str2, size_t _MaxCount);
  _CRTIMP                     int     __cdecl _strnicoll_l(const char *_Str1, const char *_Str2, size_t _MaxCount, _locale_t _Locale);
  /* _CRTIMP */               size_t  __cdecl  strcspn(const char *_Str, const char *_Control);
  _CRTIMP                     char *  __cdecl _strerror(const char *_ErrMsg) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP                     errno_t __cdecl _strerror_s(char *_Buf, size_t _SizeInBytes, const char *_ErrMsg);
  /* _CRTIMP */               char *  __cdecl  strerror(int) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */               errno_t __cdecl  strerror_s(char *_Buf, size_t _SizeInBytes, int _ErrNum);
#if (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) /* && !defined(_GNU_SOURCE) */
                              int              strerror_r(int _ErrNum, char *_Buf, size_t _SizeInBytes);
#ifndef __CRT__NO_INLINE
  __CRT_INLINE int strerror_r(int _ErrNum, char *_Buf, size_t _SizeInBytes) {
    return strerror_s(_Buf, _SizeInBytes, _ErrNum);
  }
#endif  /* !__CRT__NO_INLINE */
#endif  /* (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) */
  _CRTIMP                     errno_t __cdecl _strlwr_s(char *_Str, size_t _Size);
  _CRTIMP                     char *  __cdecl _strlwr(char *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP                     errno_t __cdecl _strlwr_s_l(char *_Str, size_t _Size, _locale_t _Locale);
  /* _CRTIMP */               char *  __cdecl  strlwr_l(char *_String, _locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */               errno_t __cdecl  strncat_s(char *_Dst, rsize_t _SizeInBytes, const char *_Src, rsize_t _MaxCount);
  /* _CRTIMP */               char *  __cdecl  strncat(char * __restrict__ _Dest, const char * __restrict__ _Source, size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */               int     __cdecl  strncmp(const char *_Str1, const char *_Str2, size_t _MaxCount);
  _CRTIMP                     int     __cdecl _strnicmp(const char *_Str1, const char *_Str2, size_t _MaxCount);
  _CRTIMP                     int     __cdecl _strnicmp_l(const char *_Str1, const char *_Str2, size_t _MaxCount, _locale_t _Locale);
  /* _CRTIMP */               errno_t __cdecl  strncpy_s(char *_Dst, rsize_t _SizeInBytes, const char *_Src, rsize_t _MaxCount);
  /* _CRTIMP */               char *  __cdecl  strncpy(char * __restrict__ _Dest, const char * __restrict__ _Source, size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP                     errno_t __cdecl _strnset_s(char *_Str, size_t _SizeInBytes, int _Val, size_t _MaxCount);
  _CRTIMP                     char *  __cdecl _strnset(char *_Dest, int _Val, size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */ _CONST_RETURN char *  __cdecl  strpbrk(const char *_Str, const char *_Control);
  /* _CRTIMP */ _CONST_RETURN char *  __cdecl  strrchr(const char *_Str, int _Ch);
  _CRTIMP                     char *  __cdecl _strrev(char *_Str);
  /* _CRTIMP */               size_t  __cdecl  strspn(const char *_Str, const char *_Control);
  /* _CRTIMP */ _CONST_RETURN char *  __cdecl  strstr(const char *_Str, const char *_SubStr);
  /* _CRTIMP */               char *  __cdecl  strtok(char * __restrict__ _Str, const char * __restrict__ _Delim) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP                     char *  __cdecl  strtok_s(char *_Str, const char *_Delim, char **_Context);
#pragma push_macro("strtok_r")
#undef strtok_r
/* Provided in libmingwex. */ char *           strtok_r(char * __restrict__ _Str, const char * __restrict__ _Delim, char ** __restrict__ __last);
#pragma pop_macro("strtok_r")
  _CRTIMP                     errno_t __cdecl _strupr_s(char *_Str, size_t _Size);
  _CRTIMP                     char *  __cdecl _strupr(char *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP                     errno_t __cdecl _strupr_s_l(char *_Str, size_t _Size, _locale_t _Locale);
  _CRTIMP                     char *  __cdecl _strupr_l(char *_String, _locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  /* _CRTIMP */               size_t  __cdecl  strxfrm(char * __restrict__ _Dst, const char * __restrict__ _Src, size_t _MaxCount);
  _CRTIMP                     size_t  __cdecl _strxfrm_l(char * __restrict__ _Dst, const char * __restrict__ _Src, size_t _MaxCount, _locale_t _Locale);

#ifndef NO_OLDNAMES
  /* _CRTIMP */ char * __cdecl strdup(const char *_Src) __MINGW_ATTRIB_DEPRECATED_MSVC2005;

  /* _CRTIMP */ int    __cdecl strcmpi(const char *_Str1, const char *_Str2) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl stricmp(const char *_Str1, const char *_Str2) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ char * __cdecl strlwr(char *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ int    __cdecl strnicmp(const char *_Str1, const char *_Str, size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ char * __cdecl strnset(char *_Str, int _Val, size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ char * __cdecl strrev(char *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ char * __cdecl strset(char *_Str, int _Val) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ char * __cdecl strupr(char *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;

  /* _CRTIMP */ int    __cdecl strcasecmp(const char *__sz1, const char *__sz2);                            /* Alias for _stricmp. */
  /* _CRTIMP */ int    __cdecl strncasecmp(const char *__sz1, const char *__sz2, size_t __sizeMaxCompare);  /* Alias for _strnicmp. */
#ifndef __CRT__NO_INLINE
  __CRT_INLINE int __cdecl strcasecmp(const char *__sz1, const char *__sz2) {
    return _stricmp(__sz1, __sz2);
  }
  __CRT_INLINE int __cdecl strncasecmp(const char *__sz1, const char *__sz2, size_t __sizeMaxCompare) {
    return _strnicmp(__sz1, __sz2, __sizeMaxCompare);
  }
#else  /* !__CRT__NO_INLINE */
#define strcasecmp  _stricmp
#define strncasecmp _strnicmp
#endif  /* !__CRT__NO_INLINE */
#endif  /* !NO_OLDNAMES */

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
  _CRTIMP                     size_t    __cdecl   wcsnlen(const wchar_t *_Src, size_t _MaxCount);
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

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* _INC_STRING */
