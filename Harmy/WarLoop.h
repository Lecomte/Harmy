#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "GameMechanics\GameLoop.h"
#include "WarSlot.h"

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
	std::vector<WarSlot> slotList_;
};

