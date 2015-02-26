#pragma once
#include "GameMechanics\Army.h"


class WarSlot
{
public:
	WarSlot(Army& myArmy);
	int score_get() const;
	void score_increase(int value) { this->score_ += value; }
	Army army_get();
	bool operator<(const WarSlot& armyB) const { return this->score_get() > armyB.score_get(); }
	~WarSlot();
private:
	Army army_;
	int score_;
};

