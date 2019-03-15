#include "../console.h"
#include "../msgBox.h"

int test() {

    HANDLE curConsole;
    HANDLE newConsole;

    curConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    newConsole = newConsoleBuffer(40,  8, BACKGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_RED | FOREGROUND_INTENSITY);
    activateConsole(newConsole);
    setConsoleWindowSize(newConsole, 40, 7);

    write(TEXT("Line 1\nLine 2\nRené\nSmiley: ☺\n"));

    msgBox(TEXT("Press Enter to continue"));

    write(TEXT("Line 5\nline 6\nline 7\nline 8\nline 9\nline 10\n"));
    msgBox(TEXT("Press Enter to continue"));
    
    activateConsole(curConsole);
    ExitProcess(0);
}
