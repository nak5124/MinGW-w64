/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _POSIX_C_SOURCE 200112L
#define __CRT__NO_INLINE
#include <string.h>

/* XSI-compliant strerror_r */
int strerror_r(int _ErrNum, char *_Buf, size_t _SizeInBytes) {
  return strerror_s(_Buf, _SizeInBytes, _ErrNum);
}
