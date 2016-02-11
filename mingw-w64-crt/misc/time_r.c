/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <time.h>

char * __cdecl asctime_r(const struct tm *_Tm, char *_Str)
{
  return asctime_s(_Str, 0x7fffffff, _Tm) ? NULL : _Str;
}

char * __cdecl ctime_r(const time_t *_Time, char *_Str)
{
  return ctime_s(_Str, 0x7fffffff, _Time) ? NULL : _Str;
}

struct tm * __cdecl localtime_r(const time_t *_Time, struct tm *_Tm)
{
  return localtime_s(_Tm, _Time) ? NULL : _Tm;
}

struct tm * __cdecl gmtime_r(const time_t *_Time, struct tm *_Tm)
{
  return gmtime_s(_Tm, _Time) ? NULL : _Tm;
}
