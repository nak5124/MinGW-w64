/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_STAT
#define _INC_STAT

#ifndef _WIN32
#error Only Win32 target is supported!
#endif  /* !_WIN32 */

#include <crtdefs.h>
#include <io.h>

#pragma pack(push, _CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif  /* !_CRTIMP */

#include <sys/types.h>

#if defined(_USE_32BIT_TIME_T) && defined(_WIN64)
#undef _USE_32BIT_TIME_T
#endif  /* defined(_USE_32BIT_TIME_T) && defined(_WIN64) */

#ifndef _TIME32_T_DEFINED
  typedef long __time32_t;
#define _TIME32_T_DEFINED
#endif  /* !_TIME32_T_DEFINED */

#ifndef _TIME64_T_DEFINED
  __MINGW_EXTENSION typedef __int64 __time64_t;
#define _TIME64_T_DEFINED
#endif  /* !_TIME64_T_DEFINED */

#ifndef _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  typedef __time32_t time_t;
#else  /* _USE_32BIT_TIME_T */
  typedef __time64_t time_t;
#endif  /* _USE_32BIT_TIME_T */
#define _TIME_T_DEFINED
#endif  /* !_TIME_T_DEFINED */

#ifndef _WCHAR_T_DEFINED
  typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif  /* !_WCHAR_T_DEFINED */

/**
 * Returns _path without trailing slash if any
 *
 * - if _path has no trailing slash, the function returns it
 * - if _path has a trailing slash, but is of the form C:/, then it returns it
 * - otherwise, the function creates a new string, which is a copy of _path
 *   without the trailing slash. It is then the responsibility of the caller
 *   to free it.
 */
  char *    _mingw_no_trailing_slash(const char *_path);
  wchar_t * _w_mingw_no_trailing_slash(const wchar_t *_path);

#ifndef _STAT_DEFINED

  struct _stat32 {
    _dev_t         st_dev;
    _ino_t         st_ino;
    unsigned short st_mode;
    short          st_nlink;
    short          st_uid;
    short          st_gid;
    _dev_t         st_rdev;
    _off_t         st_size;
    __time32_t     st_atime;
    __time32_t     st_mtime;
    __time32_t     st_ctime;
  };

#ifndef NO_OLDNAMES
  struct stat {
    _dev_t         st_dev;
    _ino_t         st_ino;
    unsigned short st_mode;
    short          st_nlink;
    short          st_uid;
    short          st_gid;
    _dev_t         st_rdev;
    _off_t         st_size;
    time_t         st_atime;
    time_t         st_mtime;
    time_t         st_ctime;
  };
#endif  /* !NO_OLDNAMES */

  struct _stat32i64 {
    _dev_t                    st_dev;
    _ino_t                    st_ino;
    unsigned short            st_mode;
    short                     st_nlink;
    short                     st_uid;
    short                     st_gid;
    _dev_t                    st_rdev;
    __MINGW_EXTENSION __int64 st_size;
    __time32_t                st_atime;
    __time32_t                st_mtime;
    __time32_t                st_ctime;
  };

  struct _stat64i32 {
    _dev_t         st_dev;
    _ino_t         st_ino;
    unsigned short st_mode;
    short          st_nlink;
    short          st_uid;
    short          st_gid;
    _dev_t         st_rdev;
    _off_t         st_size;
    __time64_t     st_atime;
    __time64_t     st_mtime;
    __time64_t     st_ctime;
  };

  struct _stat64 {
    _dev_t                    st_dev;
    _ino_t                    st_ino;
    unsigned short            st_mode;
    short                     st_nlink;
    short                     st_uid;
    short                     st_gid;
    _dev_t                    st_rdev;
    __MINGW_EXTENSION __int64 st_size;
    __time64_t                st_atime;
    __time64_t                st_mtime;
    __time64_t                st_ctime;
  };

#define __stat64 _stat64

/* The structure name and function name are the same.*/
#ifdef _USE_32BIT_TIME_T
#define _fstat    _fstat32
#define _fstati64 _fstat32i64
#define _stat     _stat32
#define _stati64  _stat32i64
#define _wstat    _wstat32
#define _wstati64 _wstat32i64
#else  /* _USE_32BIT_TIME_T */
#define _fstat    _fstat64i32
#define _fstati64 _fstat64
#define _stat     _stat64i32
#define _stati64  _stat64
#define _wstat    _wstat64i32
#define _wstati64 _wstat64
#endif  /* _USE_32BIT_TIME_T */

/* for POSIX */
#define fstat64 _fstat64
#define stat64  _stat64
#define wstat64 _wstat64  /* not POSIX, but we define this. */

#define _STAT_DEFINED
#endif  /* !_STAT_DEFINED */

#define _S_IFMT   0xF000
#define _S_IFDIR  0x4000
#define _S_IFCHR  0x2000
#define _S_IFIFO  0x1000
#define _S_IFREG  0x8000
#define _S_IREAD  0x0100
#define _S_IWRITE 0x0080
#define _S_IEXEC  0x0040

#if __MSVCRT_VERSION__ >= 0x0800
  _CRTIMP int __cdecl _fstat32(int _FileDes, struct _stat32 *_Stat);
  _CRTIMP int __cdecl _fstat32i64(int _FileDes, struct _stat32i64 *_Stat);
  _CRTIMP int __cdecl _fstat64i32(int _FileDes, struct _stat64i32 *_Stat);
#else  /* __MSVCRT_VERSION__ >= 0x0800 */
#ifdef _WIN64
          int __cdecl _fstat32(int _FileDes, struct _stat32 *_Stat);        /* On WIN64, we porvide emu. */
          int __cdecl _fstat32i64(int _FileDes, struct _stat32i64 *_Stat);  /* On WIN64, we porvide emu. */
  _CRTIMP int __cdecl _fstat64i32(int _FileDes, struct _stat64i32 *_Stat);  /* On WIN64, we provide alias for _fstat. */
#else  /* _WIN64 */
  _CRTIMP int __cdecl _fstat32(int _FileDes, struct _stat32 *_Stat);        /* On WIN32, we provide alias for _fstat. */
  _CRTIMP int __cdecl _fstat32i64(int _FileDes, struct _stat32i64 *_Stat);  /* On WIN32, we provide alias for _fstati64. */
          int __cdecl _fstat64i32(int _FileDes, struct _stat64i32 *_Stat);  /* On WIN32, we provide emu. */
#endif  /* _WIN64 */
#endif  /* __MSVCRT_VERSION__ >= 0x0800 */
  _CRTIMP int __cdecl _fstat64(int _FileDes, struct _stat64 *_Stat);
          /* We provide emu in libmingwex for trailing slash bug of MSVCR*.DLL _stat*. */
          int __cdecl _stat32(const char *_Filename, struct _stat32 *_Stat);
          int __cdecl _stat64(const char *_Filename, struct _stat64 *_Stat);
          int __cdecl _stat32i64(const char *_Filename, struct _stat32i64 *_Stat);
          int __cdecl _stat64i32(const char *_Filename, struct _stat64i32 *_Stat);

#ifndef _WSTAT_DEFINED

          /* We provide emu in libmingwex for trailing slash bug of MSVCR*.DLL _stat*. */
          int __cdecl _wstat32(const wchar_t *_Filename, struct _stat32 *_Stat);
          int __cdecl _wstat64(const wchar_t *_Filename, struct _stat64 *_Stat);
          int __cdecl _wstat32i64(const wchar_t *_Filename, struct _stat32i64 *_Stat);
          int __cdecl _wstat64i32(const wchar_t *_Filename, struct _stat64i32 *_Stat);

#define _WSTAT_DEFINED
#endif  /* !_WSTAT_DEFINED */

#ifndef NO_OLDNAMES
#define _S_IFBLK    0x3000  /* Block: Is this ever set under w32? */

#define S_IFMT      _S_IFMT
#define S_IFDIR     _S_IFDIR
#define S_IFCHR     _S_IFCHR
#define S_IFREG     _S_IFREG
#define S_IREAD     _S_IREAD
#define S_IWRITE    _S_IWRITE
#define S_IEXEC     _S_IEXEC

#define S_IFIFO     _S_IFIFO
#define S_IFBLK     _S_IFBLK

#define _S_IRWXU    (_S_IREAD | _S_IWRITE | _S_IEXEC)
#define _S_IXUSR    _S_IEXEC
#define _S_IWUSR    _S_IWRITE

#define S_IRWXU     _S_IRWXU
#define S_IXUSR     _S_IXUSR
#define S_IWUSR     _S_IWUSR
#define S_IRUSR     _S_IRUSR
#define _S_IRUSR    _S_IREAD

#define S_IRGRP     (S_IRUSR >> 3)
#define S_IWGRP     (S_IWUSR >> 3)
#define S_IXGRP     (S_IXUSR >> 3)
#define S_IRWXG     (S_IRWXU >> 3)

#define S_IROTH     (S_IRGRP >> 3)
#define S_IWOTH     (S_IWGRP >> 3)
#define S_IXOTH     (S_IXGRP >> 3)
#define S_IRWXO     (S_IRWXG >> 3)

#define S_ISDIR(m)  (((m) & S_IFMT) == S_IFDIR)
#define S_ISFIFO(m) (((m) & S_IFMT) == S_IFIFO)
#define S_ISCHR(m)  (((m) & S_IFMT) == S_IFCHR)
#define S_ISBLK(m)  (((m) & S_IFMT) == S_IFBLK)
#define S_ISREG(m)  (((m) & S_IFMT) == S_IFREG)

#endif  /* !NO_OLDNAMES */

#if !defined(RC_INVOKED) && !defined(NO_OLDNAMES)
  /* Provided in libmingwex.
   * FIXME!: We assume that _USE_32BIT_TIME_T is not defined. */
  int __cdecl fstat(int _FileDes, struct stat *_Stat);
  int __cdecl stat(const char *_Filename, struct stat *_Stat);
  int __cdecl wstat(const wchar_t *_Filename, struct stat *_Stat);

#ifndef __CRT__NO_INLINE

#ifndef _STATIC_ASSERT
#ifdef _MSC_VER
#define _STATIC_ASSERT(expr) typedef char __static_assert_t[(expr)]
#else  /* _MSC_VER */
#define _STATIC_ASSERT(expr) extern void __static_assert_t(int [(expr)?1:-1])
#endif  /* _MSC_VER */
#endif  /* !_STATIC_ASSERT */

#ifdef _USE_32BIT_TIME_T
  __CRT_INLINE int __cdecl fstat(int _FileDes, struct stat *_Stat) {
    _STATIC_ASSERT( sizeof(struct stat) == sizeof(struct _stat32) );
    return _fstat32(_FileDes, (struct _stat32 *)_Stat);
  }
  __CRT_INLINE int __cdecl stat(const char *_Filename, struct stat *_Stat) {
    _STATIC_ASSERT( sizeof(struct stat) == sizeof(struct _stat32) );
    return _stat32(_Filename, (struct _stat32 *)_Stat);
  }
  __CRT_INLINE int __cdecl wstat(const wchar_t *_Filename, struct stat *_Stat) {
    _STATIC_ASSERT( sizeof(struct stat) == sizeof(struct _stat32) );
    return _wstat32(_Filename, (struct _stat32 *)_Stat);
  }
#else  /* _USE_32BIT_TIME_T */
  __CRT_INLINE int __cdecl fstat(int _FileDes, struct stat *_Stat) {
    _STATIC_ASSERT( sizeof(struct stat) == sizeof(struct _stat64i32) );
    return _fstat64i32(_FileDes, (struct _stat64i32 *)_Stat);
  }
  __CRT_INLINE int __cdecl stat(const char *_Filename, struct stat *_Stat) {
    _STATIC_ASSERT( sizeof(struct stat) == sizeof(struct _stat64i32) );
    return _stat64i32(_Filename, (struct _stat64i32 *)_Stat);
  }
  __CRT_INLINE int __cdecl wstat(const wchar_t *_Filename, struct stat *_Stat) {
    _STATIC_ASSERT( sizeof(struct stat) == sizeof(struct _stat64i32) );
    return _wstat64i32(_Filename, (struct _stat64i32 *)_Stat);
  }
#endif  /* _USE_32BIT_TIME_T */

#endif  /* !__CRT__NO_INLINE */
#endif  /* !defined(RC_INVOKED) && !defined(NO_OLDNAMES) */

#if defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64)
#ifdef _USE_32BIT_TIME_T
#define fstat _fstat32i64
#define stat  _stat32i64
#define wstat _wstat32i64
#else  /* _USE_32BIT_TIME_T */
#define fstat _fstat64
#define stat  _stat64
#define wstat _wstat64
#endif  /* _USE_32BIT_TIME_T */
#endif  /* defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64) */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#pragma pack(pop)

#endif  /* _INC_STAT */
