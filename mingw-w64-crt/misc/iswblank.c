#define _WCTYPE_INLINE_DEFINED
#include <ctype.h>

int __cdecl iswblank (wint_t _C)
{
  return (iswctype(_C, _BLANK) || _C == '\t');
}
