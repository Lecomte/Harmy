#pragma once
#include "Capacity.h"
class Range : public Capacity
{
public:
	Range();
	float value_get() { return 10 + this->level_ * 2; }
	void level_upgrade() { this->level_++; }
	void level_downgrade() { this->level_--; }
	~Range();
};

