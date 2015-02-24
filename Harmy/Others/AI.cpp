#include "AI.h"


AI::AI()
{
}

std::shared_ptr<Action> AI::operator()(Unit unit, Army myArmy, Army otherArmy)
{
	Action* action;
	//if (!unit.canShoot() || true)
	//{
		std::vector<Point> ennemyPosList = std::vector<Point>();
		for (int i = 0; i < otherArmy.size_get(); i++)
			ennemyPosList.push_back(otherArmy.unitList_getAt(i).position_get());
		Point targetPos = Point().barycentre(ennemyPosList);
		int myMovePoint = static_cast<int>(unit.speed_get().value_get());
		Point directionVector = unit.position_get() - targetPos;
		Point moveToPos = directionVector.normalize() * unit.speed_get().value_get();
		action = new MoveAction(unit, moveToPos);
		return std::shared_ptr<Action>(action);
	/*}
	else
	{

	}*/
}

AI::~AI()
{
}
