#pragma once
#include "Capacity.h"
class Regeneration : public Capacity
{
public:
	Regeneration();
	float value_get() { return this->level_ * 3; }
	~Regeneration();
};

