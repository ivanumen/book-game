#pragma once

#include "app/models/player/player.h"
#include "app/models/items/item.h"

#include <vector>

namespace NItemView {
	void ShowInventory(TPlayer& player, std::vector<TItem> items);
};
