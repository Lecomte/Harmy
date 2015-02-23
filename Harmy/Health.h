#pragma once
#include "Capacity.h"
class Health : public Capacity
{
public:
	Health();
	float value_get() { return this->currentLife; }
	void currentLife_set(float value);
	void level_upgrade() { this->level_++; this->maxLife = 1 + this->level_get() * 10; this->currentLife = this->maxLife; }
	void level_downgrade() { this->level_--; this->maxLife = 1 + this->level_get() * 10; this->currentLife = this->maxLife; }
	~Health();
private:
	float maxLife;
	float currentLife;
};

