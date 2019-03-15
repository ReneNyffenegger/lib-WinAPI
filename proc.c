#include "proc.h"
#include "msgBox.h"

void enumProcs(DWORD desiredAccess, callBack_enumProc callBack) {

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
