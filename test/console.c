#include "../console.h"
#include "../msgBox.h"

int test() {

    HANDLE curConsole;
    HANDLE newConsole;

    curConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    newConsole = newConsoleBuffer(198, 67, BACKGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    activateConsole(newConsole);
    setConsoleWindowSize(newConsole, 198, 67);

    msgBox(TEXT("Press Enter to continue"));
    
    activateConsole(curConsole);
    ExitProcess(0);
}
