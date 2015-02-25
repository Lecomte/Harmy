#pragma once
#include "Army.h"
#include "../Others/AI.h"

class GameLoop
{
public:
	GameLoop(Army a, Army b);
	bool runRound();
	int getArmyAPoint() { return this->armyA_.size_get(); }
	int getArmyBPoint() { return this->armyB_.size_get(); }
	void endGame();
	~GameLoop();
private:
	Army armyA_;
	Army armyB_;
	int turnNumber_;
};

