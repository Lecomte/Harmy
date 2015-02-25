#include "AI.h"


AI::AI()
{
}

std::shared_ptr<Action> AI::operator()(Unit& unit, Army& myArmy, Army& otherArmy)
{
	Action* action;
	if (!unit.canShoot())
	{
		std::vector<Point> ennemyPosList = std::vector<Point>();
		for (int i = 0; i < otherArmy.size_get(); i++)
			ennemyPosList.push_back(otherArmy.unitList_getAt(i).position_get());
		Point targetPos = Point().barycentre(ennemyPosList);
		Point moveToPos = getDeplacementForTarget(unit, targetPos);
		action = new MoveAction(unit, -moveToPos, myArmy.armyCode_get());
	}
	else
	{
		unsigned int capId = unit.AICode_get()[1];
		Unit* target=nullptr;
		if (capId != 'D')
		{
			capId -= '0';
			if (unit.AICode_get()[0] == 'H')
				target = &(otherArmy.getHiggestUnit(capId));
			else
				target = &(otherArmy.getLowestUnit(capId));
		}
		else{
			if (unit.AICode_get()[0] == 'L')
				target = &(otherArmy.getNearestUnit(unit.position_get()));
			else
				target = &(otherArmy.getFurtherUnit(unit.position_get()));
		}
		float range = unit.range_get().value_get();
		float distance = unit.position_get().Distance(target->position_get());
		if ( range < distance)
		{
			Point moveToPos = getDeplacementForTarget(unit, target->position_get());
			action = new MoveAction(unit, moveToPos, myArmy.armyCode_get());
		}
		else
		{
			action = new ShootAction(unit, *target, myArmy.armyCode_get(), otherArmy.armyCode_get());
		}
	}
	return std::shared_ptr<Action>(action);
}

Point AI::getDeplacementForTarget(Unit& myUnit, Point targetPos)
{
	Point directionVector = myUnit.position_get() - targetPos;
	Point vector = directionVector.normalize();
	return vector * myUnit.speed_get().value_get();
}

AI::~AI()
{
}
