#include <windows.h>
#include <psapi.h>

typedef int (*callBack_enumProc   )(DWORD  procId, HANDLE hProc);
typedef int (*callBack_enumProcMod)(HANDLE hMod);

// HANDLE  openProc(DWORD procId);

void enumProcs   (DWORD desiredAccess, callBack_enumProc);
void enumProcMods(HANDLE hMod, callBack_enumProcMod);

HANDLE procByName(LPCTSTR procName);
