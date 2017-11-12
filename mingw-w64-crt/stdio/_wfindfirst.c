#define __CRT__NO_INLINE
#include <io.h>
#include <string.h>

#ifdef _WIN64

intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename, struct _wfinddata32_t *_FindData)
{
  struct _wfinddata64_t fd64;
  intptr_t ret = _wfindfirst64(_Filename, &fd64);
  if (ret == -1) {
    memset(_FindData, 0, sizeof(struct _wfinddata32_t));
    return -1;
  }
  _FindData->attrib      = fd64.attrib;
  _FindData->time_create = (__time32_t)fd64.time_create;  /* 32bit time */
  _FindData->time_access = (__time32_t)fd64.time_access;  /* 32bit time */
  _FindData->time_write  = (__time32_t)fd64.time_write;   /* 32bit time */
  _FindData->size        = (_fsize_t)fd64.size;           /* 32bit size */
  memcpy(_FindData->name, fd64.name, 260 * sizeof(wchar_t));
  return ret;
}

intptr_t __cdecl (*__MINGW_IMP_SYMBOL(_wfindfirst32))(const wchar_t *, struct _wfinddata32_t *) = _wfindfirst32;

intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename, struct _wfinddata32i64_t *_FindData)
{
  struct _wfinddata64_t fd64;
  intptr_t ret = _wfindfirst64(_Filename, &fd64);
  if (ret == -1) {
    memset(_FindData, 0, sizeof(struct _wfinddata32i64_t));
    return -1;
  }
  _FindData->attrib      = fd64.attrib;
  _FindData->time_create = (__time32_t)fd64.time_create;  /* 32bit time */
  _FindData->time_access = (__time32_t)fd64.time_access;  /* 32bit time */
  _FindData->time_write  = (__time32_t)fd64.time_write;   /* 32bit time */
  _FindData->size        = fd64.size;
  memcpy(_FindData->name, fd64.name, 260 * sizeof(wchar_t));
  return ret;
}

intptr_t __cdecl (*__MINGW_IMP_SYMBOL(_wfindfirst32i64))(const wchar_t *, struct _wfinddata32i64_t *) = _wfindfirst32i64;

#else  /* _WIN64 */

intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename, struct _wfinddata64i32_t *_FindData)
{
  struct _wfinddata64_t fd64;
  intptr_t ret = _wfindfirst64(_Filename, &fd64);
  if (ret == -1) {
    memset(_FindData, 0, sizeof(struct _wfinddata64i32_t));
    return -1;
  }
  _FindData->attrib      = fd64.attrib;
  _FindData->time_create = fd64.time_create;
  _FindData->time_access = fd64.time_access;
  _FindData->time_write  = fd64.time_write;
  _FindData->size        = (_fsize_t)fd64.size;  /* 32bit size */
  memcpy(_FindData->name, fd64.name, 260 * sizeof(wchar_t));
  return ret;
}

intptr_t __cdecl (*__MINGW_IMP_SYMBOL(_wfindfirst64i32))(const wchar_t *, struct _wfinddata64i32_t *) = _wfindfirst64i32;

#endif  /* _WIN64 */
