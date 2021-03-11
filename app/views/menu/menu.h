#pragma once

#include <iostream>
#include <vector>

#include "app/util/point/point.h"


class TMenu {
private:
    std::vector<std::string> Options;
    TPoint PointLeft, PointRight;
    std::vector<int> Buttons;
public:
    TMenu();
    TMenu(const std::vector<std::string>& options);
    TMenu(const std::vector<std::string>& options, const TPoint& pointLeft, const TPoint& pointRight, const std::vector<int> buttons);
    int Show(int& pressedKey);
    int Show();
};

