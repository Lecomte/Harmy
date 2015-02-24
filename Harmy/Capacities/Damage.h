#pragma once
#include "Capacity.h"
class Damage : public Capacity
{
public:
	Damage();
	float value_get() { return (1 + this->level_get()) *1.5; }
	void level_upgrade() {this->level_++;}
	void level_downgrade() { this->level_--; }
	~Damage();
};