/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_MEMORY
#define _INC_MEMORY

#include <crtdefs.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef _CONST_RETURN
#ifdef __cplusplus
#define _CONST_RETURN const
#define _CRT_CONST_CORRECT_OVERLOADS
#else  /* __cplusplus */
#define _CONST_RETURN
#endif  /* __cplusplus */
#endif  /* !_CONST_RETURN */

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
  _CRTIMP                     void *  __cdecl _memccpy(void *_Dst, const void *_Src, int _Val, size_t _MaxCount);
  /* _CRTIMP */ _CONST_RETURN void *  __cdecl  memchr(const void *_Buf, int _Val, size_t _MaxCount);
  _CRTIMP                     int     __cdecl _memicmp(const void *_Buf1, const void *_Buf2, size_t _Size);
  _CRTIMP                     int     __cdecl _memicmp_l(const void *_Buf1, const void *_Buf2, size_t _Size, _locale_t _Locale);
  /* _CRTIMP */               int     __cdecl  memcmp(const void *_Buf1, const void *_Buf2, size_t _Size);
  /* _CRTIMP */               void *  __cdecl  memcpy(void * __restrict__ _Dst, const void * __restrict__ _Src, size_t _Size) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP                     errno_t __cdecl  memcpy_s(void *_Dst, rsize_t _DstSize, const void *_Src, rsize_t _MaxCount);  /* We provide emu. */
                              void *  __cdecl  mempcpy(void *_Dst, const void *_Src, size_t _Size);                          /* Provided in libmingwex. */
  /* _CRTIMP */               void *  __cdecl  memset(void *_Dst, int _Val, size_t _Size);

#ifndef NO_OLDNAMES
  /* _CRTIMP */               void *  __cdecl  memccpy(void *_Dst, const void *_Src, int _Val, size_t _Size) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */               int     __cdecl  memicmp(const void *_Buf1, const void *_Buf2, size_t _Size) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif  /* !NO_OLDNAMES */
#define _CRT_MEMORY_DEFINED
#endif  /* !_CRT_MEMORY_DEFINED */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* _INC_MEMORY */
