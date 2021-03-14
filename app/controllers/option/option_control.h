#pragma once

#include "app/models/player/player.h"

#include <vector>
#include <string>

struct TOption {
	int To;
	std::string Text;
	std::vector<std::pair<std::string, std::string>> Price;

	TOption() = default;
	TOption(const int to, const std::string& text);
	TOption(const int to, const std::string& text, const std::vector<std::pair<std::string, std::string>>& price);
	bool CanBeChoosen(const TPlayer& player) const;
};
