#define __CRT__NO_INLINE
#ifdef _USE_32BIT_TIME_T
#undef _USE_32BIT_TIME_T
#endif  /* _USE_32BIT_TIME_T */
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

wchar_t * _w_mingw_no_trailing_slash(const wchar_t *_path);

int __cdecl _wstat64(const wchar_t *, struct _stat64 *);

/* FIXME!: We assume that _USE_32BIT_TIME_T is not defined. */
int __cdecl wstat(const wchar_t *_Filename, struct stat *_Stat)
{
  struct _stat64 st64;
  wchar_t *_path = _w_mingw_no_trailing_slash(_Filename);

  int ret = _wstat64(_path, &st64);

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

/**
 * Returns _path without trailing slash if any
 *
 * - if _path has no trailing slash, the function returns it
 * - if _path has a trailing slash, but is of the form C:/, then it returns it
 * - otherwise, the function creates a new string, which is a copy of _path
 *   without the trailing slash. It is then the responsibility of the caller
 *   to free it.
 */
wchar_t * _w_mingw_no_trailing_slash(const wchar_t *_path)
{
  int len;
  wchar_t *p;

  p = (wchar_t*)_path;

  if (_path && *_path) {
    len = wcslen(_path);

    /* Ignore X:\ */

    if (len <= 1 || ((len == 2 || len == 3) && _path[1] == L':'))
      return p;

    /* Check UNC \\abc\<name>\ */
    if ((_path[0] == L'\\' || _path[0] == L'/')
    &&  (_path[1] == L'\\' || _path[1] == L'/')) {
      const wchar_t *r = &_path[2];
      while (*r != 0 && *r != L'\\' && *r != L'/')
        ++r;
      if (*r != 0)
        ++r;
      if (*r == 0)
        return p;
      while (*r != 0 && *r != L'\\' && *r != L'/')
        ++r;
      if (*r != 0)
        ++r;
      if (*r == 0)
        return p;
    }

    if (_path[len - 1] == L'/' || _path[len - 1] == L'\\') {
      p = (wchar_t*)malloc(len * sizeof(wchar_t));
      memcpy(p, _path, (len - 1) * sizeof(wchar_t));
      p[len - 1] = L'\0';
    }
  }

  return p;
}
