#pragma once
#include "Army.h"

class GameLoop
{
public:
	GameLoop();
	void runRound();
	void endGame();
	~GameLoop();
private:
	Army armyA_;
	Army armyB_;
};

