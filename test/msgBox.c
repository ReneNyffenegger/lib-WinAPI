#include "../msgBox.h"

int test() {

 //
 // Set (last) error to «Access is denied.»
 //
    SetLastError(5);

 //
 // Show message box with last error message:
 //
    msgBoxLastErr();

 //
 // Show message box with user defined message:
 //
    msgBox(TEXT("Hello, world"));

    ExitProcess(0);
}
