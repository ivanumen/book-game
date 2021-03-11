#include "item.h"

//TItem::TItem() : Player(nullptr) {}

TItem::TItem(const std::string& code, const std::string& name /*const TPlayer* player*/) : RussianName(name), Code(code) /*Player(player)*/ {}

void TItem::SetRussianName(const std::string& name) {
	RussianName = name;
}

void TItem::SetCode(const std::string& code) {
	Code = code;
}

//void TItem::SetPlayer(const TPlayer* player) {
	//Player = player;
//}

const std::string& TItem::GetRussianName() const {
	return RussianName;
}

const std::string& TItem::GetCode() const {
	return Code;
}