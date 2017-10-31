/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdio.h>

__int64 __cdecl _ftelli64(FILE *stream)
{
    fpos_t pos;
    /* fgetpos is thread-safe, so no need to lock stream.
       fgetpos sets errno. */
    if(fgetpos(stream, &pos))
        return -1i64;
    else
        return ((__int64)pos);
}
