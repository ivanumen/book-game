#pragma once

#include <iostream>
#include <vector>

#include "app/util/point/point.h"


class TMenu {
private:
    std::vector<std::string> Options;
    TPoint PointLeft, PointRight;

public:
    TMenu() = default;
    TMenu(const std::vector<std::string>& options);
    TMenu(const std::vector<std::string>& options, const TPoint& pointLeft, const TPoint& pointRight);
    int Show();
};

