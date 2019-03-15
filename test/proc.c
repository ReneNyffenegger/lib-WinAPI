#include "shlwapi.h"

#include "../proc.h"
#include "../console.h"  

int cbEnumProc(DWORD procId, HANDLE hProc) {

    TCHAR buf[500];
    TCHAR szProcessName[MAX_PATH];
    DWORD lenCopied;

//  lenCopied = GetModuleBaseName  (hProc, NULL, szProcessName, sizeof(szProcessName)/sizeof(TCHAR));
//  lenCopied = GetModuleFileNameEx(hProc, NULL, szProcessName, sizeof(szProcessName)/sizeof(TCHAR));
    lenCopied = GetProcessImageFileName  (hProc, szProcessName, sizeof(szProcessName)/sizeof(TCHAR));

    szProcessName[lenCopied] = 0;

    wsprintf(buf, TEXT("procId: %6d, hProc: %4d, pro: %s\n"), procId, hProc, PathFindFileName(szProcessName));
    write(buf);

    return 1;
}


int test() {
    enumProcs(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, cbEnumProc);
}
