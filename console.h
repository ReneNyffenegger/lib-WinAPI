#include <windows.h>

HANDLE newConsoleBuffer(SHORT width, SHORT height, WORD color);
int    activateConsole (HANDLE console);
int    setConsoleWindowPos (HANDLE console, SHORT top, SHORT left, SHORT width, SHORT height);
int    setConsoleWindowSize(HANDLE console, SHORT width, SHORT height);
