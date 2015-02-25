#pragma once
#include "../GameMechanics/Unit.h"
#include "Action.h"

class ShootAction : public Action
{
public:
	ShootAction(Unit& attacker, Unit& target, std::string attackerArmyCode, std::string targetArmyCode);
	void execute();
	~ShootAction();
private:
	Unit& attacker_;
	Unit& target_;
	std::string attackerArmyCode;
	std::string targetArmyCode;
};

