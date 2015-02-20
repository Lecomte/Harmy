#pragma once
#include "Capacity.h"

class AttackSpeed : public Capacity
{
public:
	AttackSpeed();
	float value_get() { return 1000 / (this->level_get() + 1); }
	~AttackSpeed();
};

