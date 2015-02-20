#include "Health.h"


Health::Health()
{
	this->maxLife = 1 + this->level_get() * 10;
	this->currentLife = this->maxLife;
}


Health::~Health()
{
}
