#include <windows.h>
#include "console.h"
#include "msgBox.h"
#include "lastErr.h"

HANDLE activeConsole = 0;

HANDLE newConsoleBuffer(SHORT width, SHORT height, WORD color) {

    HANDLE console;
    CONSOLE_SCREEN_BUFFER_INFOEX info;


    console = CreateConsoleScreenBuffer (GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    if (console == INVALID_HANDLE_VALUE) {
        msgBoxLastErr();
        msgBox(TEXT("CreateConsoleScreenBuffer"));
        return 0;
    }

    info.cbSize      = sizeof(info);
    GetConsoleScreenBufferInfoEx(console, &info);


//  wsprintf(buf, "dwSize: %d x %d\nsrWindow = %d,%d %d,%d\nmax: %d x %d\nwAttributes = %d", info.dwSize.X, info.dwSize.Y, 
//      info.srWindow.Left  , info.srWindow.Top,
//      info.srWindow.Right , info.srWindow.Bottom,
//      info.dwMaximumWindowSize.X, info.dwMaximumWindowSize.Y,
//      info.wAttributes);
//  msgBox(buf);

    info.dwSize.X    = width ;
    info.dwSize.Y    = height;

    if (color >= 0) {
      info.wAttributes = color;
    }

    info.srWindow.Left     =      0;
    info.srWindow.Top      =      0;
    info.srWindow.Right    = width ; // TODO: Should or can the new width be
    info.srWindow.Bottom   = height; //       stated here?

    if (! SetConsoleScreenBufferInfoEx(console,   &info)) {
        msgBox(TEXT("SetConsoleScreenBufferInfoEx"));
        msgBoxLastErr();
        return 0;
    }

    return console;
}


int activateConsole(HANDLE console) {

    if (!SetConsoleActiveScreenBuffer(console)) {
        msgBox(TEXT("SetConsoleActiveScreenBuffer"));
        msgBoxLastErr();
        return 0;
    }
    activeConsole = console;
    return 1;
}

int setConsoleWindowPos(HANDLE console, SHORT top, SHORT left, SHORT width, SHORT height) {

    SMALL_RECT rect;

    rect.Left   = left;
    rect.Top    = top;
    rect.Right  = left + width  -1;
    rect.Bottom = top  + height -1;

    if (!SetConsoleWindowInfo(console, TRUE, &rect)) {
        msgBoxLastErr();
        msgBox(TEXT("SetConsoleWindowInfo"));
        return 0;
    }

    return 1;

}

int setConsoleWindowSize(HANDLE console, SHORT width, SHORT height) {
    return setConsoleWindowPos(console, 0, 0, width, height);
}

void write(LPCTSTR text) {

     DWORD nofCharsWritten;

     if (!activeConsole) activeConsole = GetStdHandle(STD_OUTPUT_HANDLE);

     WriteConsole(
         activeConsole,
         text,
         lstrlen(text),
        &nofCharsWritten,
         NULL);

}
