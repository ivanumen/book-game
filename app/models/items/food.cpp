#include "food.h"

TFood::TFood(const std::string& code, const std::string& name, /*const TPlayer* player,*/ const int amount) : TItem(code, name /*player*/), Amount(amount) {}

void TFood::SetAmount(const int amount) {
	Amount = amount;
}

int TFood::GetAmount() const {
	return Amount;
}