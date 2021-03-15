#pragma once

#include <app/models/items/item.h>

#include <iostream>
#include <tuple>
#include <string>
#include <vector>


class TPlayer
{
private:
	std::string Name;
	int Strength, Agility, Charisma;
	int MaxStrength, MaxAgility;
	int Gold;
	int Flask;
	std::vector<bool> Luck;
	std::vector<std::pair<std::string, int>> Spells;
	std::vector<TItem*> Items;
public:
	TPlayer();
	void SetName(const std::string& name);
	void SetStrength(const int strength);
	void SetAgility(const int agility);
	void SetMaxStrength(const int maxStrength);
	void SetMaxAgility(const int maxAgility);
	void SetCharisma(const int charisma);
	void SetGold(const int gold);
	void SetFlask(const int flask);
	void SetSpells(std::vector<std::pair<std::string, int>>);
	const std::string& GetName() const;
	int GetStrength() const;
	int GetAgility() const;
	int GetMaxStrength() const;
	int GetMaxAgility() const;
	int GetCharisma() const;
	int GetGold() const;
	int GetFlask() const;
	const std::vector<std::pair<std::string, int>>& GetSpells() const;
	void IncreaseStrength(const int strength);
	bool CheckLuck(const int index) const;
	void WriteLuck() const;
	void UnLockLuck(const int index);
	void LockLuck(const int index);
	std::tuple<int, int, int> GetRandomCharacteristics();
	void GainGold(const int gold);
	void SpendGold(const int gold);
	bool HasEnoughGold(const int gold) const;
	void GainFlask(const int flask);
	void SpendFlask(const int flask);
	bool HasEnoughFlask(const int flask) const;
	void DrinkFromFlask();
	void AddItem(const int index, TItem* item);
	void ResizeItems(const int size);
	void DropItem(const int index);
	bool HasSpell(const std::string& spell) const;
	void CastSpell(const std::string& spell);
	void AddSpell(const std::string& spell);
};
