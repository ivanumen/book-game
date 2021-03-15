#pragma once

#include "app/util/point/point.h"

namespace NConsoleEditor {
    const int EnterKey = 13;
    const int LeftKey = 1075;
    const int RightKey = 1077;
    const int UpKey = 1072;
    const int DownKey = 1080;
    const int IKey = 105;
    const int OKey = 111;
    const int PKey = 112;
    const int BackspaceKey = 8;

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

    void WaitForBackspace();

    TPoint GetCursorPosition();
};