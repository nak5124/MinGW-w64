/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_SEARCH
#define _INC_SEARCH

#include <crtdefs.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef _CRT_ALGO_DEFINED
  _CRTIMP       void * __cdecl bsearch_s(const void *_Key, const void *_Base, rsize_t _NumOfElements, rsize_t _SizeOfElements, int (__cdecl *_PtFuncCompare)(void *, const void *, const void *), void *_Context);
  /* _CRTIMP */ void * __cdecl bsearch(const void *_Key, const void *_Base, size_t _NumOfElements, size_t _SizeOfElements, int (__cdecl *_PtFuncCompare)(const void *, const void *));

  _CRTIMP       void   __cdecl qsort_s(void *_Base, rsize_t _NumOfElements, rsize_t _SizeOfElements, int (__cdecl *_PtFuncCompare)(void *, const void *, const void *), void *_Context);
  /* _CRTIMP */ void   __cdecl qsort(void *_Base, size_t _NumOfElements, size_t _SizeOfElements, int (__cdecl *_PtFuncCompare)(const void *, const void *));
#define _CRT_ALGO_DEFINED
#endif  /* !_CRT_ALGO_DEFINED */

  _CRTIMP void * __cdecl _lfind_s(const void *_Key, const void *_Base, unsigned int *_NumOfElements, size_t _SizeOfElements, int (__cdecl *_PtFuncCompare)(void *, const void *, const void *), void *_Context);
  _CRTIMP void * __cdecl _lfind(const void *_Key, const void *_Base, unsigned int *_NumOfElements, unsigned int _SizeOfElements, int (__cdecl *_PtFuncCompare)(const void *, const void *));

  _CRTIMP void * __cdecl _lsearch_s(const void *_Key, void *_Base, unsigned int *_NumOfElements, size_t _SizeOfElements, int (__cdecl *_PtFuncCompare)(void *, const void *, const void *), void *_Context);
  _CRTIMP void * __cdecl _lsearch(const void *_Key, void *_Base, unsigned int *_NumOfElements, unsigned int _SizeOfElements, int (__cdecl *_PtFuncCompare)(const void *, const void *));

#ifndef NO_OLDNAMES
  /* _CRTIMP */ void * __cdecl lfind(const void *_Key, const void *_Base, unsigned int *_NumOfElements, unsigned int _SizeOfElements, int (__cdecl *_PtFuncCompare)(const void *, const void *)) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ void * __cdecl lsearch(const void *_Key, void *_Base, unsigned int *_NumOfElements, unsigned int _SizeOfElements, int (__cdecl *_PtFuncCompare)(const void *, const void *)) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif  /* !NO_OLDNAMES */

/*
Documentation for these POSIX definitions and prototypes can be found in 
The Open Group Base Specifications Issue 6
IEEE Std 1003.1, 2004 Edition.
eg:  http://www.opengroup.org/onlinepubs/009695399/functions/twalk.html
*/

  typedef struct entry {
    char *key;
    void *data;
  } ENTRY;

  typedef enum {
    FIND,
    ENTER
  } ACTION;

  typedef enum {
    preorder,
    postorder,
    endorder,
    leaf
  } VISIT;

#ifdef _SEARCH_PRIVATE
  typedef struct node {
    char   *key;
    struct  node *llink, *rlink;
  } node_t;
#endif  /* _SEARCH_PRIVATE */
  /* Provided in libmingwex. */
  void * __cdecl tdelete(const void * __restrict__ vkey, void ** __restrict__ vrootp, int (*compare)(const void *, const void *)) __MINGW_ATTRIB_NONNULL(2) __MINGW_ATTRIB_NONNULL(3);
  void * __cdecl tfind(const void *vkey, void * const *vrootp, int (*compare)(const void *, const void *)) __MINGW_ATTRIB_NONNULL(2) __MINGW_ATTRIB_NONNULL(3);
  void * __cdecl tsearch(const void * __restrict__ vkey, void ** __restrict__ vrootp, int (*compare)(const void *, const void *)) __MINGW_ATTRIB_NONNULL(2) __MINGW_ATTRIB_NONNULL(3);
  void   __cdecl twalk(const void *vroot, void (*action)(const void *, VISIT, int));

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* _INC_SEARCH */
