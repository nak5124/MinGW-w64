#define __CRT__NO_INLINE
#include <io.h>
#include <string.h>

#ifdef _WIN64

int __cdecl _findnext32(intptr_t _FindHandle, struct _finddata32_t *_FindData)
{
  struct __finddata64_t fd64;
  int ret = _findnext64(_FindHandle, &fd64);
  if (ret == -1) {
    memset(_FindData, 0, sizeof(struct _finddata32_t));
    return -1;
  }
  _FindData->attrib      = fd64.attrib;
  _FindData->time_create = (__time32_t)fd64.time_create;  /* 32bit time */
  _FindData->time_access = (__time32_t)fd64.time_access;  /* 32bit time */
  _FindData->time_write  = (__time32_t)fd64.time_write;   /* 32bit time */
  _FindData->size        = (_fsize_t)fd64.size;           /* 32bit size */
  strncpy(_FindData->name, fd64.name, 260);
  return ret;
}

int __cdecl _findnext32i64(intptr_t _FindHandle, struct _finddata32i64_t *_FindData)
{
  struct __finddata64_t fd64;
  int ret = _findnext64(_FindHandle, &fd64);
  if (ret == -1) {
    memset(_FindData, 0, sizeof(struct _finddata32i64_t));
    return -1;
  }
  _FindData->attrib      = fd64.attrib;
  _FindData->time_create = (__time32_t)fd64.time_create;  /* 32bit time */
  _FindData->time_access = (__time32_t)fd64.time_access;  /* 32bit time */
  _FindData->time_write  = (__time32_t)fd64.time_write;   /* 32bit time */
  _FindData->size        = fd64.size;
  strncpy(_FindData->name, fd64.name, 260);
  return ret;
}

#else  /* _WIN64 */

int __cdecl _findnext64i32(intptr_t _FindHandle, struct _finddata64i32_t *_FindData)
{
  struct __finddata64_t fd64;
  int ret = _findnext64(_FindHandle, &fd64);
  if (ret == -1) {
    memset(_FindData, 0, sizeof(struct _finddata64i32_t));
    return -1;
  }
  _FindData->attrib      = fd64.attrib;
  _FindData->time_create = fd64.time_create;
  _FindData->time_access = fd64.time_access;
  _FindData->time_write  = fd64.time_write;
  _FindData->size        = (_fsize_t)fd64.size;  /* 32bit size */
  strncpy(_FindData->name, fd64.name, 260);
  return ret;
}

#endif  /* _WIN64 */
