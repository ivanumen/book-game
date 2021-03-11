#pragma once

//#include "app/models/player/player.h"

#include <string>

class TItem {
private:
	std::string Code, RussianName;
	//TPlayer* Player;
public:
	//TItem();
	TItem(const std::string& code, const std::string& name /*const TPlayer* player*/);
	void SetCode(const std::string& code);
	void SetRussianName(const std::string& name);
	//void SetPlayer(const TPlayer* player);
	const std::string& GetCode() const;
	const std::string& GetRussianName() const;
};
