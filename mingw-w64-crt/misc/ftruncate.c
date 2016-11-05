#include <io.h>

int _chsize(int _FileHandle, long _Size);
int ftruncate(int __fd, _off_t __length);

int ftruncate(int __fd, _off_t __length)
{
  return _chsize(__fd, (_off_t)__length);
}
