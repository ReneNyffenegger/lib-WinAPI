#include <shlwapi.h>

#include "proc.h"
#include "msgBox.h"


void enumProcs(DWORD desiredAccess, callBack_enumProc callBack) {
  //
  // EnumProcesses() vs CreateToolhelp32Snapshot()
  //     https://stackoverflow.com/a/4023272/180275
  //

  //
  // Microsoft's documentation on EnumProcesses() 
  //       It is hard to predict how many processes there will be at the time
  //       you call - Therefore we use a (hopefully) large enough
  //       array:
  //
    #ifndef ENUMPROC_ARRAY_SIZE
    #define ENUMPROC_ARRAY_SIZE 1000
    #endif
     DWORD procIds[ENUMPROC_ARRAY_SIZE];

     DWORD cbNeeded;
     DWORD procNo;

     EnumProcesses(procIds, sizeof(procIds), &cbNeeded);

     if (cbNeeded >= ENUMPROC_ARRAY_SIZE) {
         msgBox(TEXT("enumProcs, array size too little"));
         cbNeeded = ENUMPROC_ARRAY_SIZE;
     }

     for (procNo=0; procNo< cbNeeded / sizeof(DWORD); procNo++) {

       HANDLE hProcess = OpenProcess(
           desiredAccess,
           FALSE,
           procIds[procNo]
       );

       if (!hProcess) {
  //     msgBoxLastErr();
         continue;
       }

       if (! callBack(procIds[procNo], hProcess)) {
             CloseHandle(hProcess);
             break;
       }

       CloseHandle(hProcess);
  }
}

void enumProcMods(HANDLE hProc, callBack_enumProcMod callBack) {
     msgBox(TEXT("TODO: implement me"));
}

LPCTSTR procNameToFind    = 0;
HANDLE  procWithNameFound = 0;

int cbEnumProc_findName(DWORD procId, HANDLE hProc) {
//  enumProcMods(hProc, cbEnumMod);

    TCHAR buf[500];
    TCHAR szProcessName[MAX_PATH];
    DWORD lenCopied;

//  GetModuleBaseName(hProc, NULL, szProcessName, sizeof(szProcessName)/sizeof(TCHAR) );
    lenCopied = GetProcessImageFileName  (hProc, szProcessName, sizeof(szProcessName)/sizeof(TCHAR));
    szProcessName[lenCopied] = 0;


//  wsprintf(buf, TEXT("cb find by name - procId: %d, to find: %s - pro: %s\n"), procId, procNameToFind, PathFindFileName(szProcessName));
//  write(buf);
    if (! lstrcmpi(procNameToFind, PathFindFileName(szProcessName))) {
//    write(TEXT("hah!\n"));
      procWithNameFound = hProc;
      return 0;
    }

    return 1;
}


HANDLE procByName(LPCTSTR procName) {
  //
  //   Find a process by its name
  //

       procNameToFind    = procName;
       procWithNameFound = 0;
       enumProcs(PROCESS_QUERY_LIMITED_INFORMATION, cbEnumProc_findName);
       procNameToFind    = NULL;

       return procWithNameFound;

}
