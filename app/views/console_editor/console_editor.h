#pragma once

#include "app/util/point/point.h"

const int Enter = 13;
const int Left = 1075;
const int Right = 1077;
const int Up = 1072;
const int Down = 1080;
const int I = 105;
const int O = 111;
const int P = 112;
const int Backspace = 8;

namespace NConsoleEditor {
    enum ConsoleColor {
        Black = 0,
        Blue = 1,
        Green = 2,
        Cyan = 3,
        Red = 4,
        Magenta = 5,
        Brown = 6,
        LightGray = 7,
        DarkGray = 8,
        LightBlue = 9,
        LightGreen = 10,
        LightCyan = 11,
        LightRed = 12,
        LightMagenta = 13,
        Yellow = 14,
        White = 15
    };

    int Getch();

    void SetColor(const ConsoleColor textColor, const ConsoleColor backgroundColor = Black);

    void GoToXY(const int x, const int y);

    void GoToXY(const TPoint& point);

    void Clear();

    void Clear(const TPoint& pointLeft, const TPoint& pointRight);

    bool IsEnter(const int key);

    bool IsLeft(const int key);

    bool IsRight(const int key);

    bool IsUp(const int key);

    bool IsDown(const int key);

    bool IsI(const int key);

    bool IsO(const int key);

    bool IsP(const int key);

    bool IsBackspace(const int key);

<<<<<<< HEAD
    void WaitForBackspace();

=======
>>>>>>> master
    TPoint GetCursorPosition();
};