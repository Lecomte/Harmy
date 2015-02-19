#pragma once
#include "Capacity.h"
class Firerate : public Capacity
{
public:
	Firerate();
	float value_get() { return (this->currentWaitingTime_); }
	~Firerate();
private:
	float currentWaitingTime_;
	float firerate_;
};

