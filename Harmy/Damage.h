#pragma once
#include "Capacity.h"
class Damage : public Capacity
{
public:
	Damage();
	float value_get() { return (1 + this->level_get()) *1.5; }
	~Damage();
};