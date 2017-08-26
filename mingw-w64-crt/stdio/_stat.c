#define __CRT__NO_INLINE
#ifdef _USE_32BIT_TIME_T
#undef _USE_32BIT_TIME_T
#endif  /* _USE_32BIT_TIME_T */
#include <sys/stat.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

char * _mingw_no_trailing_slash(const char *_path);

int __cdecl _stat64(const char *, struct _stat64 *);
static int __cdecl _stub(const char *, struct _stat64 *);

int __cdecl (*__MINGW_IMP_SYMBOL(_stat64))(const char *, struct _stat64 *) = _stub;

static int __cdecl _stub(const char *_Filename, struct _stat64 *_Stat)
{
  int __cdecl (*f)(const char *, struct _stat64 *) = __MINGW_IMP_SYMBOL(_stat64);
  f = (int __cdecl (*)(const char *, struct _stat64 *))GetProcAddress(GetModuleHandleW(L"msvcrt.dll"), "_stat64");
  __MINGW_IMP_SYMBOL(_stat64) = f;
  return (*f)(_Filename, _Stat);
}

int __cdecl _stat64(const char *_Filename, struct _stat64 *_Stat)
{
  char *_path = _mingw_no_trailing_slash(_Filename);

  int ret = _stub(_path, _Stat);

  if (_path != _Filename)
    free(_path);

  return ret;
}

/* FIXME!: We assume that _USE_32BIT_TIME_T is not defined. */
int __cdecl stat(const char *_Filename, struct stat *_Stat)
{
  struct _stat64 st64;
  char *_path = _mingw_no_trailing_slash(_Filename);

  int ret = _stub(_path, &st64);

  if (_path != _Filename)
    free(_path);

  if (ret == -1) {
    memset(_Stat, 0, sizeof(struct stat));
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
  _Stat->st_atime = (time_t)st64.st_atime;
  _Stat->st_mtime = (time_t)st64.st_mtime;
  _Stat->st_ctime = (time_t)st64.st_ctime;
  return ret;
}

/* Add __imp__stat symbol.  */
int (*__MINGW_IMP_SYMBOL(stat))(const char *,struct stat *) = &stat;

int __cdecl _stat32(const char *_Filename, struct _stat32 *_Stat)
{
  struct _stat64 st64;
  char *_path = _mingw_no_trailing_slash(_Filename);

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

int __cdecl _stat32i64(const char *_Filename, struct _stat32i64 *_Stat)
{
  struct _stat64 st64;
  char *_path = _mingw_no_trailing_slash(_Filename);

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

int __cdecl _stat64i32(const char *_Filename, struct _stat64i32 *_Stat)
{
  struct _stat64 st64;
  char *_path = _mingw_no_trailing_slash(_Filename);

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

/**
 * Returns _path without trailing slash if any
 *
 * - if _path has no trailing slash, the function returns it
 * - if _path has a trailing slash, but is of the form C:/, then it returns it
 * - otherwise, the function creates a new string, which is a copy of _path
 *   without the trailing slash. It is then the responsibility of the caller
 *   to free it.
 */
char * _mingw_no_trailing_slash(const char *_path)
{
  int len;
  char *p;

  p = (char*)_path;

  if (_path && *_path) {
    len = strlen(_path);

    /* Ignore X:\ */

    if (len <= 1 || ((len == 2 || len == 3) && _path[1] == ':'))
      return p;

    /* Check UNC \\abc\<name>\ */
    if ((_path[0] == '\\' || _path[0] == '/')
    &&  (_path[1] == '\\' || _path[1] == '/')) {
      const char *r = &_path[2];
      while (*r != 0 && *r != '\\' && *r != '/')
        ++r;
      if (*r != 0)
        ++r;
      if (*r == 0)
        return p;
      while (*r != 0 && *r != '\\' && *r != '/')
        ++r;
      if (*r != 0)
        ++r;
      if (*r == 0)
        return p;
    }

    if (_path[len - 1] == '/' || _path[len - 1] == '\\') {
      p = (char*)malloc(len);
      memcpy(p, _path, len - 1);
      p[len - 1] = '\0';
    }
  }

  return p;
}
