#include <stdlib.h>
#include <errno.h>
#include <windef.h>

void * __cdecl _recalloc(void *_Memory, size_t _Count, size_t _Size)
{
  size_t old_size;
  void *ret;

  if (!_Memory)
    return calloc(_Count, _Size);

  _Size *= _Count;
  old_size = _msize(_Memory);

  ret = realloc(_Memory, _Size);
  if (!ret) {
    _set_errno(ENOMEM);
    return NULL;
  }

  if (_Size > old_size)
    memset((BYTE*)ret + old_size, 0, _Size - old_size);
  return ret;
}
