#include "level.h"

TLevel::TLevel(const std::string text, const std::vector<std::pair<int, std::string>> options) : Text(text), Options(options) {}

const std::string& TLevel::GetText() const {
	return Text;
}

const std::vector<std::pair<int, std::string>>& TLevel:: GetOptions() {
	return Options;
}