/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_PROCESS
#define _INC_PROCESS

#include <crtdefs.h>

/* Includes a definition of _pid_t and pid_t */
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

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

  _CRTIMP uintptr_t __cdecl _beginthread(void (__cdecl *_StartAddress) (void *), unsigned _StackSize, void *_ArgList);
  _CRTIMP void      __cdecl _endthread(void) __MINGW_ATTRIB_NORETURN;
  _CRTIMP uintptr_t __cdecl _beginthreadex(void *_Security, unsigned _StackSize, unsigned (__stdcall *_StartAddress) (void *), void *_ArgList, unsigned _InitFlag, unsigned *_ThrdAddr);
  _CRTIMP void      __cdecl _endthreadex(unsigned _Retval) __MINGW_ATTRIB_NORETURN;

#ifndef _CRT_TERMINATE_DEFINED
#pragma push_macro("exit")
#undef exit
  /* _CRTIMP */ void __cdecl exit(int _Code) __MINGW_NOTHROW __MINGW_ATTRIB_NORETURN;
#pragma pop_macro("exit")
  /* _CRTIMP */ void __cdecl _exit(int _Code) __MINGW_NOTHROW __MINGW_ATTRIB_NORETURN;

/* extern stub in static libmingwex.a
 * C99 function name */
  void __cdecl _Exit(int status) __MINGW_ATTRIB_NORETURN;
#ifndef __CRT__NO_INLINE
  __CRT_INLINE void __cdecl __MINGW_ATTRIB_NORETURN _Exit(int status) {
    _exit(status);
  }
#endif  /* !__CRT__NO_INLINE */

#pragma push_macro("abort")
#undef abort
  /* _CRTIMP */ void __cdecl abort(void) __MINGW_ATTRIB_NORETURN;
#pragma pop_macro("abort")
#define _CRT_TERMINATE_DEFINED
#endif  /* !_CRT_TERMINATE_DEFINED */

  /* _CRTIMP */ void __cdecl _cexit(void) __MINGW_NOTHROW;
  /* _CRTIMP */ void __cdecl _c_exit(void) __MINGW_NOTHROW;

  _CRTIMP int      __cdecl _getpid(void);
  _CRTIMP intptr_t __cdecl _cwait(int *_TermStat, intptr_t _ProcHandle, int _Action);
  _CRTIMP intptr_t __cdecl _execl(const char *_Filename, const char *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _execle(const char *_Filename, const char *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _execlp(const char *_Filename, const char *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _execlpe(const char *_Filename, const char *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _execv(const char *_Filename, const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(const char *_Filename, const char *const *_ArgList, const char *const *_Env);
  _CRTIMP intptr_t __cdecl _execvp(const char *_Filename, const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(const char *_Filename, const char *const *_ArgList, const char *const *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(int _Mode, const char *_Filename, const char *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _spawnle(int _Mode, const char *_Filename, const char *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _spawnlp(int _Mode, const char *_Filename, const char *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _spawnlpe(int _Mode, const char *_Filename, const char *_ArgList, ...);

#ifndef _SPAWNV_DEFINED
  _CRTIMP intptr_t __cdecl _spawnv(int _Mode, const char *_Filename, const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(int _Mode, const char *_Filename, const char *const *_ArgList, const char *const *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(int _Mode, const char *_Filename, const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(int _Mode, const char *_Filename, const char *const *_ArgList, const char *const *_Env);
#define _SPAWNV_DEFINED
#endif  /* !_SPAWNV_DEFINED */

#ifndef _CRT_SYSTEM_DEFINED
  /* _CRTIMP */ int __cdecl system(const char *_Command);
#define _CRT_SYSTEM_DEFINED
#endif  /* !_CRT_SYSTEM_DEFINED */

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

  /* Provided in libmingw32. */
  void __cdecl __security_init_cookie(void);
#if defined(_X86_) && !defined(__x86_64)
  void __fastcall __security_check_cookie(uintptr_t _StackCookie);
  void __cdecl    __report_gsfailure(void) __MINGW_ATTRIB_NORETURN;
#else  /* defined(_X86_) && !defined(__x86_64) */
  void __cdecl    __security_check_cookie(uintptr_t _StackCookie);
  void __cdecl    __report_gsfailure(uintptr_t _StackCookie) __MINGW_ATTRIB_NORETURN;
#endif  /* defined(_X86_) && !defined(__x86_64) */
  extern uintptr_t __security_cookie;

#if (defined(_X86_) && !defined(__x86_64)) || __MSVCRT_VERSION__ >= 0x0800
  intptr_t __cdecl _loaddll(char *_Filename);
  int      __cdecl _unloaddll(intptr_t _Handle);
  int (__cdecl * __cdecl _getdllprocaddr(intptr_t _Handle, char *_ProcedureName, intptr_t _Ordinal))(void);
#endif  /* (defined(_X86_) && !defined(__x86_64)) || __MSVCRT_VERSION__ >= 0x0800 */

#ifdef _DECL_DLLMAIN
#ifdef _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle, DWORD _Reason, LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle, DWORD _Reason, LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle, DWORD _Reason, LPVOID _Reserved);
  extern WINBOOL (WINAPI * const _pRawDllMain)(HANDLE, DWORD, LPVOID);
#else  /* _WINDOWS_ */
  int __stdcall DllMain(void *_HDllHandle, unsigned _Reason, void *_Reserved);
  int __stdcall _CRT_INIT(void *_HDllHandle, unsigned _Reason, void *_Reserved);
  int __stdcall _wCRT_INIT(void *_HDllHandle, unsigned _Reason, void *_Reserved);
  extern int (__stdcall * const _pRawDllMain)(void *, unsigned, void *);
#endif  /* _WINDOWS_ */
#endif  /* _DECL_DLLMAIN */

#ifndef NO_OLDNAMES

#define P_WAIT          _P_WAIT
#define P_NOWAIT        _P_NOWAIT
#define P_OVERLAY       _P_OVERLAY
#define OLD_P_OVERLAY   _OLD_P_OVERLAY
#define P_NOWAITO       _P_NOWAITO
#define P_DETACH        _P_DETACH
#define WAIT_CHILD      _WAIT_CHILD
#define WAIT_GRANDCHILD _WAIT_GRANDCHILD

  /* _CRTIMP */ intptr_t __cdecl cwait(int *_TermStat, intptr_t _ProcHandle, int _Action) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#ifdef __GNUC__
                int      __cdecl execl(const char *_Filename, const char *_ArgList, ...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
                int      __cdecl execle(const char *_Filename, const char *_ArgList, ...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
                int      __cdecl execlp(const char *_Filename, const char *_ArgList, ...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
                int      __cdecl execlpe(const char *_Filename, const char *_ArgList, ...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#else  /* __GNUC__ */
  /* _CRTIMP */ intptr_t __cdecl execl(const char *_Filename, const char *_ArgList, ...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ intptr_t __cdecl execle(const char *_Filename, const char *_ArgList, ...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ intptr_t __cdecl execlp(const char *_Filename, const char *_ArgList, ...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ intptr_t __cdecl execlpe(const char *_Filename, const char *_ArgList, ...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif  /* __GNUC__ */
  /* _CRTIMP */ intptr_t __cdecl spawnl(int _Mode, const char *_Filename, const char *_ArgList, ...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ intptr_t __cdecl spawnle(int _Mode, const char *_Filename, const char *_ArgList, ...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ intptr_t __cdecl spawnlp(int _Mode, const char *_Filename, const char *_ArgList, ...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  /* _CRTIMP */ intptr_t __cdecl spawnlpe(int _Mode, const char *_Filename, const char *_ArgList, ...) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#ifndef _CRT_GETPID_DEFINED
  /* _CRTIMP */ int      __cdecl getpid(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#define _CRT_GETPID_DEFINED  /* Also in unistd.h */
#endif  /* !_CRT_GETPID_DEFINED */
#ifdef __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width. */
  /* Provided in libmingwex. */
  int __cdecl execv(const char *_Filename, char *const _ArgList[]) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl execve(const char *_Filename, char *const _ArgList[], char *const _Env[]) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl execvp(const char *_Filename, char *const _ArgList[]) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  int __cdecl execvpe(const char *_Filename, char *const _ArgList[], char *const _Env[]) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#else  /* __GNUC__ */
  intptr_t __cdecl execv(const char *_Filename, const char *_ArgList) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  intptr_t __cdecl execve(const char *_Filename, const char *const *_ArgList, const char *const *_Env) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  intptr_t __cdecl execvp(const char *_Filename, const char *_ArgList) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  intptr_t __cdecl execvpe(const char *_Filename, const char *const *_ArgList, const char *const *_Env) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif  /* __GNUC__ */
  /* Provided in libmingwex. */
  intptr_t __cdecl spawnv(int _Mode, const char *_Filename, char *const _ArgList[]) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  intptr_t __cdecl spawnve(int _Mode, const char *_Filename, char *const _ArgList[], char *const _Env[]) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  intptr_t __cdecl spawnvp(int _Mode, const char *_Filename, char *const _ArgList[]) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  intptr_t __cdecl spawnvpe(int _Mode, const char *_Filename, char *const _ArgList[], char *const _Env[]) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif  /* !NO_OLDNAMES */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* _INC_PROCESS */
