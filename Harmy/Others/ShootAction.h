#pragma once
#include "Action.h"

class ShootAction : public Action
{
public:
	ShootAction();
	void execute();
	~ShootAction();
};

