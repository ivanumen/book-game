#include "console_editor.h"

#include <windows.h>
#include <conio.h>

int NConsoleEditor::Getch() {
    int key = _getch();
    if (key == 224) {
        key = 1000 + _getch();
    }
    return key;
}


void NConsoleEditor::SetColor(const ConsoleColor textColor, const ConsoleColor backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)((backgroundColor << 4) | textColor));
}

void NConsoleEditor::GoToXY(const int x, const int y) {
    COORD kursor;
    kursor.X = x;
    kursor.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), kursor);
}

void NConsoleEditor::GoToXY(const TPoint& point) {
    COORD kursor;
    kursor.X = point.X;
    kursor.Y = point.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), kursor);
}

void NConsoleEditor::Clear() {
    system("cls");
}

bool NConsoleEditor::IsEnter(const int key) {
    return key == 13;
}

bool NConsoleEditor::IsLeft(const int key) {
    return key == 1075;
}

bool NConsoleEditor::IsRight(const int key) {
    return key == 1077;
}

bool NConsoleEditor::IsUp(const int key) {
    return key == 1072;
}

bool NConsoleEditor::IsDown(const int key) {
    return key == 1080;
}