#include "player.h"
#include <algorithm>
#include "app/util/dice/dice.h"

TPlayer::TPlayer() : Luck(std::vector<bool>(6, true)) {}

void TPlayer::SetName(const std::string& name) {
	Name = name;
}

void TPlayer::SetStrength(const int strength) {
	Strength = strength;
}

void TPlayer::SetAgility(const int agility) {
	Agility = agility;
}

void TPlayer::SetMaxStrength(const int maxStrength) {
	MaxStrength = maxStrength;
}

void TPlayer::SetMaxAgility(const int maxAgility) {
	MaxAgility = maxAgility;
}

void TPlayer::SetCharisma(const int charisma) {
	Charisma = charisma;
}

void TPlayer::SetGold(const int gold) {
	Gold = gold;
}

void TPlayer::SetFlask(const int flask) {
	Flask = flask;
}

void TPlayer::SetSpells(std::vector<std::pair<std::string, int>> spells) {
	Spells = spells;
}

const std::string& TPlayer::GetName() const {
	return Name;
}

int TPlayer::GetStrength() const {
	return Strength;
}

int TPlayer::GetAgility() const {
	return Agility;
}

int TPlayer::GetMaxStrength() const {
	return MaxStrength;
}

int TPlayer::GetMaxAgility() const {
	return MaxAgility;
}

int TPlayer::GetCharisma() const {
	return Charisma;
}

int TPlayer::GetGold() const {
	return Gold;
}

int TPlayer::GetFlask() const {
	return Flask;
}

const std::vector<std::pair<std::string, int>>& TPlayer::GetSpells() const {
	return Spells;
}

void TPlayer::IncreaseStrength(const int strength) {
	Strength = std::min(MaxStrength, Strength + strength);
}

void TPlayer::UnLockLuck(const int dice) {
	Luck[dice - 1] = true;
}

void TPlayer::LockLuck(const int dice) {
	Luck[dice - 1] = false;
}

void TPlayer::WriteLuck() const {
	std::cout << std::endl;
	for (const auto elem : Luck) {
		if (elem) {
			std::cout << "<*>" << " ";
		}
		else {
			std::cout << "<!>" << " ";
		}
	}
	std::cout << std::endl;
}

bool TPlayer::CheckLuck(const int dice) const {
	return Luck[dice - 1];
}

std::tuple<int, int, int> TPlayer::GetRandomCharacteristics() {
	const std::vector<std::tuple<int, int, int>> arrayCharacteristics = {
		{8, 22, 8},
		{10, 20, 6},
		{12, 16, 5},
		{9, 18, 8},
		{11, 20, 6},
		{9, 20, 7},
		{10, 16, 7},
		{8, 24, 7},
		{9, 22, 6},
		{10, 18, 7},
		{11, 20, 5}
	};
	const int sumTwoDices = NDice::usingD6() + NDice::usingD6() - 2;
	return arrayCharacteristics[sumTwoDices];
}

void TPlayer::GainGold(const int gold) {
	Gold += gold;
}

void TPlayer::SpendGold(const int gold) {
	if (Gold < gold) {
		throw "Not enough money";
	}
	Gold -= gold;
}

bool TPlayer::HasEnoughGold(const int gold) const {
	return Gold >= gold;
}

void TPlayer::GainFlask(const int flask) {
	Flask += flask;
}

void TPlayer::SpendFlask(const int flask) {
	if (Flask < flask) {
		throw "Not enough water";
	}
	Flask -= flask;
}

bool TPlayer::HasEnoughFlask(const int flask) const {
	return Flask >= flask;
}

void TPlayer::DrinkFromFlask() {
	SpendFlask(1);
	IncreaseStrength(2);
}

void TPlayer::AddItem(const int index, TItem* item) {
	if (index >= Items.size()) {
		throw "Array index out of bounds";
	}
	Items[index] = item;
}

void TPlayer::ResizeItems(const int size) {
	Items.resize(size);
}

void TPlayer::DropItem(const int index) {
	if (index >= Items.size()) {
		throw "Array index out of bounds";
	}
	Items[index] = nullptr;
}

<<<<<<< HEAD
bool TPlayer::HasSpell(const std::string& spell) const {
	for (const auto& elem : Spells) {
		if (elem.first == spell) {
			return elem.second > 0;
		}
	}
	throw "Not this spell";
}

void TPlayer::CastSpell(const std::string& spell) {
	for (auto& elem : Spells) {
		if (elem.first == spell) {
			elem.second--;
			if (elem.second == -1) {
				break;
			}
			return;
		}
	}
	throw "Not this spell";
}

void TPlayer::AddSpell(const std::string& spell) {
	for (auto& elem : Spells) {
		if (elem.first == spell) {
			elem.second++;
			return;
		}
	}
	throw "Not this spell";
}
=======
void TPlayer::Inventory() const {
	for (const auto& item : Items) {

	}
}

>>>>>>> master
