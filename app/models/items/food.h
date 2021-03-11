#pragma once

#include "item.h"

class TFood : public TItem {
private:
	int Amount;
public:
	TFood(const std::string& code, const std::string& name, /*const std::shared_ptr<TPlayer> player*/ const int amount);
	void SetAmount(const int amount);
	int GetAmount() const;
};