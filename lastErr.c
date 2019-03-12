#include <windows.h>

#define BUFSIZE 500

TCHAR lastErrBuf[BUFSIZE] = {0};

LPCTSTR lastErr() {

  if (!FormatMessage( 

//    FORMAT_MESSAGE_ALLOCATE_BUFFER | 
      FORMAT_MESSAGE_FROM_SYSTEM     | 
      FORMAT_MESSAGE_IGNORE_INSERTS,
      NULL,
      GetLastError(),
      0, // MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
      lastErrBuf,
      BUFSIZE,
      0 )) {
         return TEXT("lastErr failed!!");
      }

 //
 // Remove trailing new line (2 characters: 0x0d 0x0a)
 //
    lastErrBuf[lstrlen(lastErrBuf) - 2] = 0;


    return lastErrBuf;
}
