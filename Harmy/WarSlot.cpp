#include "WarSlot.h"


WarSlot::WarSlot(Army& myArmy)
{
	this->army_ = myArmy;
	this->score_ = 0;
}

Army WarSlot::army_get()
{
	return this->army_;
}

int WarSlot::score_get() const
{
	return this->score_;
}

WarSlot::~WarSlot()
{
}
