#pragma once
#include "Capacity.h"

class Speed : public Capacity
{
public:
	Speed();
	float value_get(){ return 1 + this->level_; }
	~Speed();
};

