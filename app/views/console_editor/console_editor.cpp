#include "console_editor.h"

#include <iostream>
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

void NConsoleEditor::Clear(const TPoint& pointLeft, const TPoint& pointRight) {
    for (int i = pointLeft.Y; i <= pointRight.Y; i++) {
        for (int j = pointLeft.X; j <= pointRight.X; j++) {
            GoToXY({ j, i });
            std::cout << " ";
        }
    }
}

void NConsoleEditor::Clear() {
    system("cls");
}

bool NConsoleEditor::IsEnter(const int key) {
    return key == Enter;
}

bool NConsoleEditor::IsLeft(const int key) {
    return key == Left;
}

bool NConsoleEditor::IsRight(const int key) {
    return key == Right;
}

bool NConsoleEditor::IsUp(const int key) {
    return key == Up;
}

bool NConsoleEditor::IsDown(const int key) {
    return key == Down;
}

bool NConsoleEditor::IsI(const int key) {
    return key == I;
}

bool NConsoleEditor::IsO(const int key) {
    return key == O;
}

bool NConsoleEditor::IsP(const int key) {
    return key == P;
}

bool NConsoleEditor::IsBackspace(const int key) {
    return key == Backspace;
}

TPoint NConsoleEditor::GetCursorPosition() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (!GetConsoleScreenBufferInfo(hConsole, &cbsi)) {
        throw "Error with cursor";
    }

    return TPoint(cbsi.dwCursorPosition.X, cbsi.dwCursorPosition.Y);
}

void NConsoleEditor::WaitForBackspace() {
    while (!IsBackspace(Getch()));
}