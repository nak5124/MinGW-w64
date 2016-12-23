#include <wchar.h>
#include <errno.h>
#include <io.h>
#include <winternl.h>
#include <windows.h>

int __cdecl (* const __MINGW_IMP_SYMBOL(isatty))(int) = isatty;

/* MSYS2-compatible isatty.
 *
 * MSYS2 pty is a specially-named named pipe.
 * Fetch [absolute] fd's NT object path (if any),
 * and check it for the following pattern:
 *
 *   \Device\NamedPipe\msys-[a-fA-F0-9]{16}-pty[0-9]{1,4}-(from-master|to-master|to-master-cyg)
 *
 * [a-fA-F0-9] is the msys2 installation key, 16 characters long.
 * pty[0-9] is the pty name. Its index is of type int, but is safe to be limited to 4 characters.
 *
 * */

int __cdecl isatty(int fd) {
  wchar_t const expect_dev[] = L"\\Device\\NamedPipe\\msys-";
  wchar_t const expect_pty[] = L"-pty";

  typedef NTSTATUS (NTAPI proc_NtQueryObject) (HANDLE, OBJECT_INFORMATION_CLASS, PVOID, ULONG, PULONG);
  proc_NtQueryObject *pNtQueryObject;

  HANDLE h_fd, h_ntdll;

  /* NtQueryObject needs space for OBJECT_NAME_INFORMATION.Name->Buffer also. */
  char ntfn_bytes[sizeof(OBJECT_NAME_INFORMATION) + MAX_PATH * sizeof(WCHAR)];

  OBJECT_NAME_INFORMATION *ntfn = (OBJECT_NAME_INFORMATION*) ntfn_bytes;
  NTSTATUS status;
  ULONG ntfn_size = sizeof(ntfn_bytes);

  wchar_t *s;
  int l;

  h_fd = (HANDLE) _get_osfhandle(fd);
  if (!h_fd || h_fd == INVALID_HANDLE_VALUE)
    goto bad_fp;

  h_ntdll = GetModuleHandleW(L"ntdll.dll");
  if (!h_ntdll || h_ntdll == INVALID_HANDLE_VALUE)
    goto bad_fp;

  pNtQueryObject = (proc_NtQueryObject*) GetProcAddress(h_ntdll, "NtQueryObject");
  if (!pNtQueryObject)
    goto no_tty;

  memset(ntfn, 0, ntfn_size);
  status = pNtQueryObject((HANDLE)h_fd, ObjectNameInformation, ntfn, ntfn_size, &ntfn_size);

  if (!NT_SUCCESS(status)) {
    /* If it is not NUL (i.e. \Device\Null, which would succeed),
     * then normal isatty() could be consulted.
     * */
    if (_isatty(fd))
      return 1;
    goto no_tty;
  }

  s = ntfn->Name.Buffer;
  s[ntfn->Name.Length / sizeof(WCHAR)] = 0;

  l = wcslen(expect_dev);
  if (wcsncmp(s, expect_dev, l) != 0)
    goto no_tty;
  s += l;

  l = wcsspn(s, L"0123456789abcdefABCDEF");
  if (l != 16)
    goto no_tty;
  s += l;

  l = wcslen(expect_pty);
  if (wcsncmp(s, expect_pty, l) != 0)
    goto no_tty;
  s += l;

  l = wcsspn(s, L"0123456789");
  if (l < 1 || l > 4)
    goto no_tty;
  s += l;

  if (wcscmp(s, L"-from-master") != 0 &&
        wcscmp(s, L"-to-master") != 0 &&
        wcscmp(s, L"-to-master-cyg") != 0)
    goto no_tty;

  return 1;

bad_fp:
  errno = EBADF;
  return 0;

no_tty:
  errno = EINVAL;
  return 0;
}
