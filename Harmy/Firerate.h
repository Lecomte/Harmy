#pragma once
#include "Capacity.h"
class Firerate : public Capacity
{
public:
	Firerate();
	float value_get() { return (this->currentWaitingTime_); }
	void reset_value() { this->currentWaitingTime_ = this->firerate_; }
	void level_upgrade() { this->level_++; this->firerate_ = 1000 / (this->level_get() + 1); this->currentWaitingTime_ = this->firerate_; }
	void level_downgrade() { this->level_--; this->firerate_ = 1000 / (this->level_get() + 1); this->currentWaitingTime_ = this->firerate_; }
	void decrease_value();
	~Firerate();
private:
	float currentWaitingTime_;
	float firerate_;
};

