#pragma once
#include "Capacity.h"
class Health : public Capacity
{
public:
	Health();
	float value_get() { return this->currentLife; }
	~Health();
private:
	float maxLife;
	float currentLife;
};

