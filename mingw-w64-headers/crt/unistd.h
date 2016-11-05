/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _UNISTD_H
#define _UNISTD_H
#define __UNISTD_H_SOURCED__ 1

#include <io.h>
#include <process.h>
#include <getopt.h>

/* These are also defined in stdio.h. */
#ifndef SEEK_SET
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#endif  /* !SEEK_SET */

/* These are also defined in stdio.h. */
#ifndef STDIN_FILENO
#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#endif  /* !STDIN_FILENO */

/* Used by shutdown(2). */
#ifdef _POSIX_SOURCE

/* MySql connector already defined SHUT_RDWR. */
#ifndef SHUT_RDWR
#define SHUT_RD   0x00
#define SHUT_WR   0x01
#define SHUT_RDWR 0x02
#endif  /* !SHUT_RDWR */

#endif  /* _POSIX_SOURCE */

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#pragma push_macro("sleep")
#undef sleep
  /* Provided in libmingwex. */
  unsigned int __cdecl sleep(unsigned int seconds);
#pragma pop_macro("sleep")

#include <sys/types.h>  /* For useconds_t. */

  /* Provided in libmingwex. */
  int __cdecl __MINGW_NOTHROW usleep(useconds_t us);

#ifndef TRUNCATE_DEFINED
/* This is defined as a real library function to allow autoconf
   to verify its existence. */
#if defined(_BSD_SOURCE) || (_XOPEN_SOURCE >= 500) || (defined(_XOPEN_SOURCE) && defined(_XOPEN_SOURCE_EXTENDED)) || _POSIX_C_SOURCE >= 200809L
  int truncate(const char *path, off_t length);
  int truncate64(const char *path, off64_t length);
#endif  /* defined(_BSD_SOURCE) || ... */
#if defined(_BSD_SOURCE) || (_XOPEN_SOURCE >= 500) || (defined(_XOPEN_SOURCE) && defined(_XOPEN_SOURCE_EXTENDED)) || _POSIX_C_SOURCE >= 200112L
  int ftruncate(int fd, off_t length);
  int ftruncate64(int fd, off64_t length);
#ifndef __CRT__NO_INLINE
  __CRT_INLINE int ftruncate(int __fd, off_t __length) {
    return _chsize(__fd, (off_t)__length);
  }
#endif  /* !__CRT__NO_INLINE */
#endif  /* defined(_BSD_SOURCE) || ... */
#define TRUNCATE_DEFINED
#endif  /* !TRUNCATE_DEFINED */

#ifndef _FILE_OFFSET_BITS_SET_TRUNCATE
#if defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64)
#define truncate  truncate64
#define ftruncate ftruncate64
#endif  /* defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64) */
#define _FILE_OFFSET_BITS_SET_TRUNCATE
#endif  /* !_FILE_OFFSET_BITS_SET_TRUNCATE */

#ifndef _CRT_SWAB_DEFINED
  /* _CRTIMP */ void __cdecl swab(char *_Buf1, char *_Buf2, int _SizeInBytes) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#define _CRT_SWAB_DEFINED  /* Also in stdlib.h */
#endif  /* !_CRT_SWAB_DEFINED */

#ifndef _CRT_GETPID_DEFINED
  /* _CRTIMP */ int  __cdecl getpid(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#define _CRT_GETPID_DEFINED  /* Also in process.h */
#endif  /* !_CRT_GETPID_DEFINED */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#include <pthread_unistd.h>

#undef __UNISTD_H_SOURCED__

#endif /* _UNISTD_H */
