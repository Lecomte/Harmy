#include "GameLoop.h"

GameLoop::GameLoop()
{
	this->armyA_ = Army(100, 100);
	this->armyB_ = Army(100, 100);
}

void GameLoop::runRound()
{
	if (this->armyA_.size_get() < 1 || this->armyB_.size_get() < 1)
	{
		this->endGame();
		return;
	}

}

void GameLoop::endGame()
{
	std::cout << "Winner mais il faudrait m'implementer" << std::endl;
}

GameLoop::~GameLoop()
{
}
