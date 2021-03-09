#pragma once

#include <iostream>
#include <unordered_map>

#include "app/models/player/player.h"
#include "app/models/level/level.h"


class TGame
{
private:
	TPlayer Player;
	int CurrentLevel;
	std::unordered_map<int, TLevel> Levels;
public:
	TGame() = default;
	void Start();
	void New();
	void ReadConfig();
	void Run();
	int InitSpells();
	void InitPlayer();
	void WritePlayer() const;
};

