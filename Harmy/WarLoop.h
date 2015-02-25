#pragma once
#include <vector>
#include <iostream>
#include "GameMechanics\GameLoop.h"
class WarLoop
{
public:
	WarLoop();
	void clashOfArmy();
	~WarLoop();
private:
	int battleNumber_;
	int minimalScore_;
	int unitNumber_;
	int levelGlobal_;
	std::vector<Army> armyList;
	std::vector<int> armyScore;
};

