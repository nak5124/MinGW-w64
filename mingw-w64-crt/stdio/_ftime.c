#define __CRT__NO_INLINE
#ifdef _USE_32BIT_TIME_T
#undef _USE_32BIT_TIME_T
#endif
#include <sys/timeb.h>

/* FIXME!: We assume that _USE_32BIT_TIME_T is not defined. */
void __cdecl ftime(struct timeb *b)
{
  _ftime64((struct __timeb64 *)b);
}
