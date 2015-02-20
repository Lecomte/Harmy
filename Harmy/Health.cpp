#include "Health.h"


Health::Health()
{
	this->maxLife = 1 + this->level_get() * 10;
	this->currentLife = this->maxLife;
}

void Health::currentLife_set(float value)
{
	if (this->currentLife + value >= this->maxLife)
		this->currentLife = this->maxLife;
	else if (this->currentLife + value <= 0)
		this->currentLife = 0;
	else
		this->currentLife += value;
}

Health::~Health()
{
}
