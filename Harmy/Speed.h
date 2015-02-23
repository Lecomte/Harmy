#pragma once
#include "Capacity.h"

class Speed : public Capacity
{
public:
	Speed();
	float value_get(){ return 1 + this->level_; }
	void level_upgrade() { this->level_++; }
	void level_downgrade() { this->level_--; }
	~Speed();
};

