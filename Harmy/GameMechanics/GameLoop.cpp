#include "GameLoop.h"

GameLoop::GameLoop(Army a, Army b)
{
	this->armyA_ = a;
	this->armyB_ = b;
	this->turnNumber_ = 0;
	this->armyA_.baseSpawn_set(Point(0, 0));
	this->armyB_.baseSpawn_set(Point(100, 100));
}

bool GameLoop::runRound()
{
	if (this->armyA_.size_get() < 1 || this->armyB_.size_get() < 1)
	{
		this->endGame();
		return false;
	}

	std::cout << "-------------------- TURN " << this->turnNumber_ << "--------------------" << std::endl;

	/*int totalsize = armyA_.size_get() + armyB_.size_get();

	std::vector<Unit*> usedUnitArmyA;
	std::vector<Unit*> usedUnitArmyB;
	
	if (std::rand() % 2 == 0)
	{
		//armyA
		int currentIndex = std::rand() % armyA_.size_get();
	}
	else{
		//armyB
		int currentIndex = std::rand() % armyB_.size_get();
	}*/

	AI ai;
	//armyA attack
	for (int i = 0; i < armyA_.size_get(); i++)
	{
		Unit* currentUnit = &(armyA_.unitList_getAt(i));
		std::shared_ptr<Action> action = ai(*currentUnit, armyA_, armyB_);
		action->execute();
		armyB_.purge();
		if (armyB_.size_get() < 1)
			return true;
	}

	//armyB attack
	for (int i = 0; i < armyB_.size_get(); i++)
	{
		Unit* currentUnit = &(armyB_.unitList_getAt(i));
		std::shared_ptr<Action> action = ai(*currentUnit, armyB_, armyA_);
		action->execute();
		armyA_.purge();
		if (armyA_.size_get() < 1)
			return true;
	}

	//armyArefresh
	for (int i = 0; i < armyA_.size_get(); i++)
	{
		armyA_.unitList_getAt(i).refresh();
	}

	//armyB refresh
	for (int i = 0; i < armyB_.size_get(); i++)
	{
		armyB_.unitList_getAt(i).refresh();
	}
	this->turnNumber_++;
	return true;
}

void GameLoop::endGame()
{
	if (this->armyA_.size_get() > 0)
	{
		std::cout << "Winner " << armyA_.armyCode_get() << " nombre de points " << armyA_.size_get() << std::endl;
		this->armyA_.save();
	}
	else
	{
		std::cout << "Winner " << armyB_.armyCode_get() << " nombre de points " << armyB_.size_get() << std::endl;
		this->armyB_.save();
	}
}

GameLoop::~GameLoop()
{
}
