#include "../lastErr.h"

int test() {

 //
 // Set last error message to «Access is denied.»
 //
    SetLastError(5);

 //
 // Get last error
 //
    LPCTSTR err = lastErr();

 //
 // Compare text of last error message.
 //
    if (lstrcmp(err, TEXT("Access is denied."))) {
        MessageBox(NULL, err, TEXT("Test failed"), 0);
        ExitProcess(1);
    }

    ExitProcess(0);
}
