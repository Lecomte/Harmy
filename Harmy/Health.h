#pragma once
#include "Capacity.h"
class Health : public Capacity
{
public:
	Health();
	float value_get() { return this->currentLife; }
	void currentLife_set(float value);
	~Health();
private:
	float maxLife;
	float currentLife;
};

