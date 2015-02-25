#include "MoveAction.h"


MoveAction::MoveAction(Unit& unit, Point target, std::string armyCode) :unit_(unit), positionTarget_(target), armyCode_(armyCode)
{
}

void MoveAction::execute()
{
	Point newPos = Point(unit_.position_get().x_get() + positionTarget_.x_get(), unit_.position_get().y_get() + positionTarget_.y_get());
	this->unit_.setPosition(newPos.x_get(), newPos.y_get() );
	std::cout << "L'unite : " << this->unit_.UNIQ_ID_get() << " de l'armee (" << this->armyCode_ <<") se deplace a la position : " << this->unit_.position_get().x_get() << " " << this->unit_.position_get().y_get() << std::endl;
}

MoveAction::~MoveAction()
{
}
