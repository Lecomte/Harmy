#pragma once
#include "Capacity.h"
class Firerate : public Capacity
{
public:
	Firerate();
	float value_get() { return (this->currentWaitingTime_); }
	void decrease_value();
	~Firerate();
private:
	float currentWaitingTime_;
	float firerate_;
};

