#include <winbase.h>

#ifndef __LIBMSVCRT__
#error "This file should only be used in libmsvcrt.a"
#endif

#if __MSVCRT_VERSION__ >= 0x1400
#define MSVCRTDLL_NAME L"ucrtbase.dll"
#elif __MSVCRT_VERSION__ == 0x1200
#define MSVCRTDLL_NAME L"msvcr120.dll"
#elif __MSVCRT_VERSION__ == 0x1100
#define MSVCRTDLL_NAME L"msvcr110.dll"
#elif __MSVCRT_VERSION__ == 0x1000
#define MSVCRTDLL_NAME L"msvcr100.dll"
#elif __MSVCRT_VERSION__ == 0x0900
#define MSVCRTDLL_NAME L"msvcr90.dll"
#elif __MSVCRT_VERSION__ == 0x0800
#define MSVCRTDLL_NAME L"msvcr80.dll"
#else
#define MSVCRTDLL_NAME L"msvcrt.dll"
#endif

static inline HANDLE __mingw_get_msvcrt_handle(void)
{
    return GetModuleHandleW(MSVCRTDLL_NAME);
}
