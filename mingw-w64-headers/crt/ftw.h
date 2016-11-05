/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _FTW_HXX
#define _FTW_HXX

#include <sys/types.h>
#include <sys/stat.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

  struct FTW {
    int base;
    int level;
  };

#define FTW_F    0  /* A regular file. */
#define FTW_D    1  /* A directory. */
#define FTW_DNR  2  /* An unreadable directory. */
#define FTW_NS   3  /* An unstatable file. */
#define FTW_SL   4  /* A symbolic link (not supported). */
#define FTW_DP   5  /* A directory (all subdirs are visited). */
#define FTW_SLN  6  /* A symbolic link naming non-existing file (not supported). */

#define FTW_PHYS         1   /* Do a physical walk (ignore symlinks). */
#define FTW_MOUNT        2   /* Do report only files on same device as the argument (partial supported). */
#define FTW_CHDIR        4   /* Change to current directory while processing (unsupported). */
#define FTW_DEPTH        8   /* Do report files in directory before the directory itself. */
#define FTW_ACTIONRETVAL 16  /* Tell callback to return FTW_* values instead of zero to continue and non-zero to terminate. */

#define FTW_CONTINUE      0  /* Continue with next sibling or with the first child-directory. */
#define FTW_STOP          1  /* Return from ftw or nftw with FTW_STOP as return value. */
#define FTW_SKIP_SUBTREE  2  /* Valid only for FTW_D: Don't walk through the subtree. */
#define FTW_SKIP_SIBLINGS 3  /* Continue with FTW_DP callback for current directory (if FTW_DEPTH) and then its siblings. */

  /* Provided in libmingwex. */
  int ftw(const char *path, int (*fcb) (const char *, const struct stat *, int), int descriptors);
  int ftw64(const char *path, int (*fcb) (const char *, const struct stat64 *, int), int descriptors);

  /* Provided in libmingwex. */
  int nftw(const char *path, int (*fcb) (const char *, const struct stat *, int , struct FTW *), int descriptors, int flags);
  int nftw64(const char *path, int (*fcb) (const char *, const struct stat64 *, int , struct FTW *), int descriptors, int flags);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* _FTW_HXX */
