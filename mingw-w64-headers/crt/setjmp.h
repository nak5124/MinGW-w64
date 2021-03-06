/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_SETJMP
#define _INC_SETJMP

#include <crtdefs.h>

#pragma pack(push, _CRT_PACKING)

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

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#if defined(_X86_) && !defined(__x86_64)

#define _JBLEN  16
#define _JBTYPE int

  typedef struct __JUMP_BUFFER {
    unsigned long Ebp;
    unsigned long Ebx;
    unsigned long Edi;
    unsigned long Esi;
    unsigned long Esp;
    unsigned long Eip;
    unsigned long Registration;
    unsigned long TryLevel;
    unsigned long Cookie;
    unsigned long UnwindFunc;
    unsigned long UnwindData[6];
  } _JUMP_BUFFER;

#elif defined(__x86_64)

  typedef _CRT_ALIGN(16) struct _SETJMP_FLOAT128 {
    __MINGW_EXTENSION unsigned __int64 Part[2];
  } SETJMP_FLOAT128;

#define _JBLEN 16
  typedef SETJMP_FLOAT128 _JBTYPE;

  typedef struct _JUMP_BUFFER {
    __MINGW_EXTENSION unsigned __int64 Frame;
    __MINGW_EXTENSION unsigned __int64 Rbx;
    __MINGW_EXTENSION unsigned __int64 Rsp;
    __MINGW_EXTENSION unsigned __int64 Rbp;
    __MINGW_EXTENSION unsigned __int64 Rsi;
    __MINGW_EXTENSION unsigned __int64 Rdi;
    __MINGW_EXTENSION unsigned __int64 R12;
    __MINGW_EXTENSION unsigned __int64 R13;
    __MINGW_EXTENSION unsigned __int64 R14;
    __MINGW_EXTENSION unsigned __int64 R15;
    __MINGW_EXTENSION unsigned __int64 Rip;
    __MINGW_EXTENSION unsigned __int64 Spare;
    SETJMP_FLOAT128                    Xmm6;
    SETJMP_FLOAT128                    Xmm7;
    SETJMP_FLOAT128                    Xmm8;
    SETJMP_FLOAT128                    Xmm9;
    SETJMP_FLOAT128                    Xmm10;
    SETJMP_FLOAT128                    Xmm11;
    SETJMP_FLOAT128                    Xmm12;
    SETJMP_FLOAT128                    Xmm13;
    SETJMP_FLOAT128                    Xmm14;
    SETJMP_FLOAT128                    Xmm15;
  } _JUMP_BUFFER;

#elif defined(_ARM_)

#define _JBLEN  28
#define _JBTYPE int

  typedef struct __JUMP_BUFFER {
    unsigned long      Frame;
    unsigned long      R4;
    unsigned long      R5;
    unsigned long      R6;
    unsigned long      R7;
    unsigned long      R8;
    unsigned long      R9;
    unsigned long      R10;
    unsigned long      R11;
    unsigned long      Sp;
    unsigned long      Pc;
    unsigned long      Fpscr;
    unsigned long long D[8];
  } _JUMP_BUFFER;

#elif defined(_ARM64_)

#define _JBLEN  24
#define _JBTYPE unsigned __int64

  typedef struct __JUMP_BUFFER {
    unsigned __int64 Frame;
    unsigned __int64 Reserved;
    unsigned __int64 X19;
    unsigned __int64 X20;
    unsigned __int64 X21;
    unsigned __int64 X22;
    unsigned __int64 X23;
    unsigned __int64 X24;
    unsigned __int64 X25;
    unsigned __int64 X26;
    unsigned __int64 X27;
    unsigned __int64 X28;
    unsigned __int64 Fp;
    unsigned __int64 Lr;
    unsigned __int64 Sp;
    unsigned long    Fpcr;
    unsigned long    Fpsr;
    double           D[8];
  } _JUMP_BUFFER;

#else

#define _JBLEN  1
#define _JBTYPE int

#endif  /* defined(_X86_) && !defined(__x86_64) */

#ifndef _JMP_BUF_DEFINED
  typedef _JBTYPE jmp_buf[_JBLEN];
#define _JMP_BUF_DEFINED
#endif  /* !_JMP_BUF_DEFINED */

  void * __cdecl mingw_getsp(void) __MINGW_NOTHROW;  /* Provided in libmingwex. */

#if !defined(USE_NO_MINGW_SETJMP_TWO_ARGS) && __MSVCRT_VERSION__ < 0x1400
# ifndef _INC_SETJMPEX
#  if defined(_X86_) || defined(__i386__)
#   define setjmp(BUF) _setjmp3((BUF), NULL)
#  else  /* defined(_X86_) || defined(__i386__) */
#   if (__MINGW_GCC_VERSION < 40702)
#    define setjmp(BUF) _setjmp((BUF), mingw_getsp())
#   else  /* (__MINGW_GCC_VERSION < 40702) */
#    define setjmp(BUF) _setjmp((BUF), __builtin_frame_address(0))
#   endif  /* (__MINGW_GCC_VERSION < 40702) */
  int __cdecl __attribute__((__nothrow__, __returns_twice__)) _setjmp3(jmp_buf _Buf, void *_Ctx);
#  endif  /* defined(_X86_) || defined(__i386__) */
  int __cdecl __attribute__((__nothrow__, __returns_twice__)) _setjmp(jmp_buf _Buf, void *_Ctx);
# else  /* !_INC_SETJMPEX */
#  undef setjmp
#  ifdef _WIN64
#   if (__MINGW_GCC_VERSION < 40702)
#    define setjmp(BUF)   _setjmpex((BUF), mingw_getsp())
#    define setjmpex(BUF) _setjmpex((BUF), mingw_getsp())
#   else  /* (__MINGW_GCC_VERSION < 40702) */
#    define setjmp(BUF)   _setjmpex((BUF), __builtin_frame_address(0))
#    define setjmpex(BUF) _setjmpex((BUF), __builtin_frame_address(0))
#   endif  /* (__MINGW_GCC_VERSION < 40702) */
#  else  /* _WIN64 */
#   define setjmp(BUF)   _setjmpex((BUF), NULL)
#   define setjmpex(BUF) _setjmpex((BUF), NULL)
#  endif  /* _WIN64 */
  int __cdecl __attribute__((__nothrow__, __returns_twice__)) _setjmpex(jmp_buf _Buf, void *_Ctx);
# endif  /* !_INC_SETJMPEX */
#else  /* !defined(USE_NO_MINGW_SETJMP_TWO_ARGS) && __MSVCRT_VERSION__ < 0x1400 */
# if !defined(_INC_SETJMPEX) && __MSVCRT_VERSION__ < 0x1400
#  define setjmp _setjmp
# endif  /* !defined(_INC_SETJMPEX) && __MSVCRT_VERSION__ < 0x1400 */
  int __cdecl __attribute__((__nothrow__, __returns_twice__)) setjmp(jmp_buf _Buf);
#endif  /* !defined(USE_NO_MINGW_SETJMP_TWO_ARGS) && __MSVCRT_VERSION__ < 0x1400 */

  __declspec(noreturn) __attribute__((__nothrow__)) void __cdecl ms_longjmp(jmp_buf _Buf,int _Value)  /* throw(...)*/;
  __declspec(noreturn) __attribute__((__nothrow__)) void __cdecl longjmp(jmp_buf _Buf,int _Value);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#pragma pack(pop)

#endif  /* _INC_SETJMP */
