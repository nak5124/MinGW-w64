#define __CRT__NO_INLINE
#include <sys/stat.h>
#undef _wstat
#undef _wstati64
#include <windows.h>
#include <msvcrt.h>
#include <stdlib.h>
#include <string.h>

wchar_t * _w_mingw_no_trailing_slash(const wchar_t *_path);
int __cdecl _wstat64(const wchar_t *, struct _stat64 *);

int __cdecl (*__MINGW_IMP_SYMBOL(_wstat64))(const wchar_t *, struct _stat64 *) = _wstat64;

static int __cdecl _stub(const wchar_t *_Filename, struct _stat64 *_Stat)
{
  int __cdecl (*f)(const wchar_t *, struct _stat64 *) = __MINGW_IMP_SYMBOL(_wstat64);
  f = (int __cdecl (*)(const wchar_t *, struct _stat64 *))GetProcAddress(__mingw_get_msvcrt_handle(), "_wstat64");
  __MINGW_IMP_SYMBOL(_wstat64) = f;
  return (*f)(_Filename, _Stat);
}

int __cdecl _wstat64(const wchar_t *_Filename, struct _stat64 *_Stat)
{
  wchar_t *_path = _w_mingw_no_trailing_slash(_Filename);

  int ret = _stub(_path, _Stat);

  if (_path != _Filename)
    free(_path);

  return ret;
}

int __cdecl _wstat32(const wchar_t *_Filename, struct _stat32 *_Stat)
{
  struct _stat64 st64;
  wchar_t *_path = _w_mingw_no_trailing_slash(_Filename);

  int ret = _stub(_path, &st64);

  if (_path != _Filename)
    free(_path);

  if (ret == -1) {
    memset(_Stat, 0, sizeof(struct _stat32));
    return -1;
  }
  _Stat->st_dev   = st64.st_dev;
  _Stat->st_ino   = st64.st_ino;
  _Stat->st_mode  = st64.st_mode;
  _Stat->st_nlink = st64.st_nlink;
  _Stat->st_uid   = st64.st_uid;
  _Stat->st_gid   = st64.st_gid;
  _Stat->st_rdev  = st64.st_rdev;
  _Stat->st_size  = (_off_t)st64.st_size;       /* 32bit size */
  _Stat->st_atime = (__time32_t)st64.st_atime;  /* 32bit time */
  _Stat->st_mtime = (__time32_t)st64.st_mtime;  /* 32bit time */
  _Stat->st_ctime = (__time32_t)st64.st_ctime;  /* 32bit time */
  return ret;
}

int __cdecl (*__MINGW_IMP_SYMBOL(_wstat32))(const wchar_t *, struct _stat32 *) = _wstat32;

int __cdecl _wstat32i64(const wchar_t *_Filename, struct _stat32i64 *_Stat)
{
  struct _stat64 st64;
  wchar_t *_path = _w_mingw_no_trailing_slash(_Filename);

  int ret = _stub(_path, &st64);

  if (_path != _Filename)
    free(_path);

  if (ret == -1) {
    memset(_Stat, 0, sizeof(struct _stat32i64));
    return -1;
  }
  _Stat->st_dev   = st64.st_dev;
  _Stat->st_ino   = st64.st_ino;
  _Stat->st_mode  = st64.st_mode;
  _Stat->st_nlink = st64.st_nlink;
  _Stat->st_uid   = st64.st_uid;
  _Stat->st_gid   = st64.st_gid;
  _Stat->st_rdev  = st64.st_rdev;
  _Stat->st_size  = st64.st_size;
  _Stat->st_atime = (__time32_t)st64.st_atime;  /* 32bit time */
  _Stat->st_mtime = (__time32_t)st64.st_mtime;  /* 32bit time */
  _Stat->st_ctime = (__time32_t)st64.st_ctime;  /* 32bit time */
  return ret;
}

int __cdecl (*__MINGW_IMP_SYMBOL(_wstat32i64))(const wchar_t *, struct _stat32i64 *) = _wstat32i64;

int __cdecl _wstat64i32(const wchar_t *_Filename, struct _stat64i32 *_Stat)
{
  struct _stat64 st64;
  wchar_t *_path = _w_mingw_no_trailing_slash(_Filename);

  int ret = _stub(_path, &st64);

  if (_path != _Filename)
    free(_path);

  if (ret == -1) {
    memset(_Stat, 0, sizeof(struct _stat64i32));
    return -1;
  }
  _Stat->st_dev   = st64.st_dev;
  _Stat->st_ino   = st64.st_ino;
  _Stat->st_mode  = st64.st_mode;
  _Stat->st_nlink = st64.st_nlink;
  _Stat->st_uid   = st64.st_uid;
  _Stat->st_gid   = st64.st_gid;
  _Stat->st_rdev  = st64.st_rdev;
  _Stat->st_size  = (_off_t)st64.st_size;  /* 32bit size */
  _Stat->st_atime = st64.st_atime;
  _Stat->st_mtime = st64.st_mtime;
  _Stat->st_ctime = st64.st_ctime;
  return ret;
}

int __cdecl (*__MINGW_IMP_SYMBOL(_wstat64i32))(const wchar_t *, struct _stat64i32 *) = _wstat64i32;

#ifdef _WIN64
int __cdecl (*__MINGW_IMP_SYMBOL(_wstat))(const wchar_t *, struct _stat64i32 *) = _wstat64i32;
int __cdecl _wstat(const wchar_t *_Filename, struct _stat64i32 *_Stat) __attribute__((alias("_wstat64i32")));
int __cdecl (*__MINGW_IMP_SYMBOL(_wstati64))(const wchar_t *, struct _stat64 *) = _wstat64;
int __cdecl _wstati64(const wchar_t *_Filename, struct _stat64 *_Stat) __attribute__((alias("_wstat64")));
#else  /* _WIN64 */
int __cdecl (*__MINGW_IMP_SYMBOL(_wstat))(const wchar_t *, struct _stat32 *) = _wstat32;
int __cdecl _wstat(const wchar_t *_Filename, struct _stat32 *_Stat) __attribute__((alias("_wstat32")));
int __cdecl (*__MINGW_IMP_SYMBOL(_wstati64))(const wchar_t *, struct _stat32i64 *) = _wstat32i64;
int __cdecl _wstati64(const wchar_t *_Filename, struct _stat32i64 *_Stat) __attribute__((alias("_wstat32i64")));
#endif  /* _WIN64 */
