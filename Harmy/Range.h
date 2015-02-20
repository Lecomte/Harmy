#pragma once
#include "Capacity.h"
class Range : public Capacity
{
public:
	Range();
	float value_get() { return 10 + this->level_ * 2; }
	~Range();
};

