#pragma once
#include "Capacity.h"
class Armor : public Capacity
{
public:
	Armor();
	float value_get() { return this->level_ / 2; }
	void level_upgrade() { this->level_++; }
	void level_downgrade() { this->level_--; }
	~Armor();
};

