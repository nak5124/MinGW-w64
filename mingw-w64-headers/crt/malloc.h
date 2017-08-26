/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _MALLOC_H_
#define _MALLOC_H_

#include <crtdefs.h>

#pragma pack(push, _CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifdef _WIN64
#define _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#else  /* _WIN64 */
#define _HEAP_MAXREQ 0xFFFFFFE0
#endif  /* _WIN64 */

#ifndef _STATIC_ASSERT
#ifdef _MSC_VER
#define _STATIC_ASSERT(expr) typedef char __static_assert_t[(expr)]
#else  /* _MSC_VER */
#define _STATIC_ASSERT(expr) extern void __static_assert_t(int [(expr)?1:-1])
#endif  /* _MSC_VER */
#endif  /* !_STATIC_ASSERT */

/* Return codes for _heapwalk()  */
#define _HEAPEMPTY    (-1)
#define _HEAPOK       (-2)
#define _HEAPBADBEGIN (-3)
#define _HEAPBADNODE  (-4)
#define _HEAPEND      (-5)
#define _HEAPBADPTR   (-6)

/* Values for _heapinfo.useflag */
#define _FREEENTRY 0
#define _USEDENTRY 1

#ifndef _HEAPINFO_DEFINED
  /* The structure used to walk through the heap with _heapwalk.  */
  typedef struct _heapinfo {
    int    *_pentry;
    size_t  _size;
    int     _useflag;
  } _HEAPINFO;
#define _HEAPINFO_DEFINED
#endif  /* !_HEAPINFO_DEFINED */

  extern unsigned int _amblksiz;  /* Left for backward compatibility. */

/* Make sure that X86intrin.h doesn't produce here collisions.  */
#if (!defined(_XMMINTRIN_H_INCLUDED) && !defined(_MM_MALLOC_H_INCLUDED)) || defined(_aligned_malloc)
#define __DO_ALIGN_DEFINES
#endif  /* (!defined(_XMMINTRIN_H_INCLUDED) && !defined(_MM_MALLOC_H_INCLUDED)) || defined(_aligned_malloc) */

#ifndef _MM_MALLOC_H_INCLUDED
#define _MM_MALLOC_H_INCLUDED
#endif  /* _MM_MALLOC_H_INCLUDED */

#ifdef __DO_ALIGN_DEFINES
#pragma push_macro("_aligned_free")
#pragma push_macro("_aligned_malloc")
#undef _aligned_free
#undef _aligned_malloc
#endif  /* __DO_ALIGN_DEFINES */

#define _mm_free(a)      _aligned_free(a)
#define _mm_malloc(a, b) _aligned_malloc(a, b)

#ifndef _CRT_ALLOCATION_DEFINED
  /* _CRTIMP */ void * __cdecl calloc(size_t _Count, size_t _Size);
  /* _CRTIMP */ void   __cdecl free(void *_Memory);
  /* _CRTIMP */ void * __cdecl malloc(size_t _Size);
  /* _CRTIMP */ void * __cdecl realloc(void *_Memory, size_t _NewSize);
  _CRTIMP       void * __cdecl _recalloc(void *_Memory, size_t _Count, size_t _Size);  /* We provide emu. */

#ifdef __DO_ALIGN_DEFINES
  _CRTIMP void   __cdecl _aligned_free(void *_Memory);
  _CRTIMP void * __cdecl _aligned_malloc(size_t _Size, size_t _Alignment);
#endif  /* __DO_ALIGN_DEFINES */

  _CRTIMP void * __cdecl _aligned_offset_malloc(size_t _Size, size_t _Alignment, size_t _Offset);
  _CRTIMP void * __cdecl _aligned_realloc(void *_Memory, size_t _NewSize, size_t _Alignment);
  _CRTIMP void * __cdecl _aligned_offset_realloc(void *_Memory, size_t _NewSize, size_t _Alignment, size_t _Offset);
#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP void * __cdecl _aligned_recalloc(void *_Memory, size_t _Count, size_t _Size, size_t _Alignment);
  _CRTIMP void * __cdecl _aligned_offset_recalloc(void *_Memory, size_t _Count, size_t _Size, size_t _Alignment, size_t _Offset);
  _CRTIMP size_t __cdecl _aligned_msize(void * _Memory, size_t _Alignment, size_t _Offset);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */
#define _CRT_ALLOCATION_DEFINED
#endif  /* !_CRT_ALLOCATION_DEFINED */

#ifdef __DO_ALIGN_DEFINES
#undef __DO_ALIGN_DEFINES

#pragma pop_macro("_aligned_malloc")
#pragma pop_macro("_aligned_free")

#endif  /* __DO_ALIGN_DEFINES */

  /* Users should really use MS provided versions
   * Provided in libmingwex. */
  void   __mingw_aligned_free(void *_Memory);
  void * __mingw_aligned_malloc(size_t _Size, size_t _Alignment);
  void * __mingw_aligned_offset_malloc(size_t _Size, size_t _Alignment, size_t _Offset);
  void * __mingw_aligned_realloc(void *_Memory, size_t _Size, size_t _Offset);
  void * __mingw_aligned_offset_realloc(void *_Memory, size_t _Size, size_t _Alignment, size_t _Offset);

  _CRTIMP int __cdecl _resetstkoflw(void);

#define _MAX_WAIT_MALLOC_CRT 60000

#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP unsigned long __cdecl _set_malloc_crt_max_wait(unsigned long _NewValue);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */


  _CRTIMP void * __cdecl _expand(void *_Memory, size_t _NewSize);
  _CRTIMP size_t __cdecl _msize(void *_Memory);

#ifdef __GNUC__
#undef _alloca
#define _alloca(x) __builtin_alloca((x))  /* GCC builtin */
#else  /* __GNUC__ */
  void * __cdecl _alloca(size_t _Size) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;  /* This function is not exported. */
#endif  /* __GNUC__ */
  /* MSVCRT.DLL && MSVCR(=<90).DLL export these functions. */
  _CRTIMP size_t __cdecl _get_sbh_threshold(void);
  _CRTIMP int    __cdecl _set_sbh_threshold(size_t _NewValue);
#if __MSVCRT_VERSION__ == 0x0900
  _CRTIMP errno_t __cdecl _set_amblksiz(size_t _Value);
  _CRTIMP errno_t __cdecl _get_amblksiz(size_t *_Value);
#endif  /* __MSVCRT_VERSION__ == 0x0900 */
  _CRTIMP int      __cdecl _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP int      __cdecl _heapadd(void *_Memory, size_t _Size);
  _CRTIMP int      __cdecl _heapchk(void);
  _CRTIMP int      __cdecl _heapmin(void);
  _CRTIMP int      __cdecl _heapset(unsigned int _Fill);
#if __MSVCRT_VERSION__ >= 0x0800 || (defined(_X86_) && !defined(__x86_64))
  /* 64bit MSVCRT.DLL does not export these functions. */
  _CRTIMP intptr_t __cdecl _get_heap_handle(void);
  _CRTIMP size_t   __cdecl _heapused(size_t *_Used, size_t *_Commit);
#endif  /* __MSVCRT_VERSION__ >= 0x0800 || (defined(_X86_) && !defined(__x86_64)) */

#define _ALLOCA_S_THRESHOLD    1024
#define _ALLOCA_S_STACK_MARKER 0xCCCC
#define _ALLOCA_S_HEAP_MARKER  0xDDDD

#if defined(_ARM_) || (defined(_X86_) && !defined(__x86_64))
#define _ALLOCA_S_MARKER_SIZE 8
#elif defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#define _ALLOCA_S_MARKER_SIZE 16
#endif  /* defined(_ARM_) || (defined(_X86_) && !defined(__x86_64)) */

_STATIC_ASSERT(sizeof(unsigned int) <= _ALLOCA_S_MARKER_SIZE);

#ifndef RC_INVOKED
  static __inline void *_MarkAllocaS(void *_Ptr, unsigned int _Marker) {
    if (_Ptr) {
      *((unsigned int*)_Ptr) = _Marker;
      _Ptr = (char*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    return _Ptr;
  }
  static __inline int _MallocaIsSizeInRange(size_t size) {
    return size + _ALLOCA_S_MARKER_SIZE > size;
  }
#endif  /* !RC_INVOKED */

#undef _malloca
#define _malloca(size) \
  (_MallocaIsSizeInRange(size) ? \
    (((((size_t)(size) + _ALLOCA_S_MARKER_SIZE) <= _ALLOCA_S_THRESHOLD) ? \
      _MarkAllocaS(_alloca((size_t)(size) + _ALLOCA_S_MARKER_SIZE), _ALLOCA_S_STACK_MARKER) : \
      _MarkAllocaS(malloc((size_t)(size) + _ALLOCA_S_MARKER_SIZE), _ALLOCA_S_HEAP_MARKER))) : NULL)
#undef _FREEA_INLINE
#define _FREEA_INLINE

#ifndef RC_INVOKED
#undef _freea
  static __inline void __cdecl _freea(void *_Memory) {
    unsigned int _Marker;
    if (_Memory) {
      _Memory = (char*)_Memory - _ALLOCA_S_MARKER_SIZE;
      _Marker = *(unsigned int *)_Memory;
      if (_Marker == _ALLOCA_S_HEAP_MARKER)
        free(_Memory);
#ifdef _ASSERTE
      else if (_Marker != _ALLOCA_S_STACK_MARKER)
        _ASSERTE(("Corrupted pointer passed to _freea", 0));
#endif  /* _ASSERTE */
    }
  }
#endif /* !RC_INVOKED */

#ifndef NO_OLDNAMES
#undef alloca
#define alloca _alloca
#endif  /* !NO_OLDNAMES */

#ifdef HEAPHOOK
#ifndef _HEAPHOOK_DEFINED
  typedef int (__cdecl *_HEAPHOOK)(int, size_t, void *, void **);
#define _HEAPHOOK_DEFINED
#endif  /* !_HEAPHOOK_DEFINED */

  _CRTIMP _HEAPHOOK __cdecl _setheaphook(_HEAPHOOK _NewHook);  /* Left for backward compatibility. */

#define _HEAP_MALLOC  1
#define _HEAP_CALLOC  2
#define _HEAP_FREE    3
#define _HEAP_REALLOC 4
#define _HEAP_MSIZE   5
#define _HEAP_EXPAND  6
#endif  /* HEAPHOOK */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#pragma pack(pop)

#endif  /* _MALLOC_H_ */
