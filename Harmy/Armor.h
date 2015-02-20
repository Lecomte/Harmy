#pragma once
#include "Capacity.h"
class Armor : public Capacity
{
public:
	Armor();
	float value_get() { return this->level_ * 2; }
	~Armor();
};

