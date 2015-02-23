#pragma once
#include "Capacity.h"
class Regeneration : public Capacity
{
public:
	Regeneration();
	float value_get() { return this->level_ * 3; }
	void level_upgrade() { this->level_++; }
	void level_downgrade() { this->level_--; }
	~Regeneration();
};

