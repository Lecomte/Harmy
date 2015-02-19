#pragma once
class Firerate
{
public:
	Firerate();
	float value_get() { return (this->currentWaitingTime_); }
	~Firerate();
private:
	float currentWaitingTime_;
	float firerate_;
};

