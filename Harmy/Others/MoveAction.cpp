#include "MoveAction.h"


MoveAction::MoveAction(Unit unit, Point target)
{
	this->unit_ = unit;
	this->positionTarget_ = target;
}

void MoveAction::execute()
{
	this->unit_.setPosition(positionTarget_.x_get(), positionTarget_.y_get());
	std::cout << "L'unite : " << this->unit_.UNIQ_ID_get() << " se deplace a la position : " << positionTarget_.x_get() << " " << positionTarget_.y_get() << std::endl;
}

MoveAction::~MoveAction()
{
}
