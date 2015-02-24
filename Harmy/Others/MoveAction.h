#pragma once
#include "Action.h"
#include "Point.h"
#include "..\GameMechanics\Unit.h"

class MoveAction : public Action
{
public:
	MoveAction(Unit unit, Point target);
	void execute();
	~MoveAction();
private:
	Unit unit_;
	Point positionTarget_;
};