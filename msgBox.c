#include <windows.h>
#include "msgBox.h"
#include "lastErr.h"

void msgBox(LPCTSTR txt) {
  MessageBox(NULL, txt, TEXT(""), MB_OK);
}

void msgBoxLastErr() {
  MessageBox(NULL, lastErr(), TEXT("Last Windows Error"), 0);
}
