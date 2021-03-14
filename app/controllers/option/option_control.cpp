#include "option_control.h"

TOption::TOption(const int to, const std::string& text) : To(to), Text(text) {}
TOption::TOption(const int to, const std::string& text, const std::vector<std::pair<std::string, std::string>>& price) : To(to), Text(text), Price(price) {}


bool TOption::CanBeChoosen(const TPlayer& player) const {
	for (const auto& price : Price) {
		if (price.first == "add_spell") {
			return player.HasSpell(price.second);
		}
	}
	return true;
}