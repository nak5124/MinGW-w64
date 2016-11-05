/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _LIBGEN_H_
#define _LIBGEN_H_

#include <crtdefs.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

  /* Provided in libmingwex. */
  char * __cdecl basename(char *) __MINGW_NOTHROW;
  char * __cdecl dirname(char *) __MINGW_NOTHROW;

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* _LIBGEN_H_ */
