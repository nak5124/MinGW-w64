#define _POSIX_C_SOURCE 200809L
#include <string.h>

char * stpcpy(char * __restrict__ _Dest, const char * __restrict__ _Source)
{
  for (; (*_Dest = *_Source); ++_Source, ++_Dest);
  return _Dest;
}

char * stpncpy(char * __restrict__ _Dest, const char * __restrict__ _Source, size_t n)
{
  for (; n--; _Dest++, _Source++) {
    if (!(*_Dest = *_Source)) {
      char *ret = _Dest;
      while (n--)
        *++_Dest = '\0';
      return ret;
    }
  }
  return _Dest;
}
