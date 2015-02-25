#pragma once
#include "..\GameMechanics\Unit.h"
#include "..\GameMechanics\Army.h"
#include "Action.h"
#include "MoveAction.h"
#include "ShootAction.h"
#include <memory>

class AI
{
public:
	AI();
	std::shared_ptr<Action> operator()(Unit& unit, Army& myArmy, Army& otherArmy);
	~AI();
private:
	Point getDeplacementForTarget(Unit& myUnit, Point targetPos);
};

