#include "Firerate.h"


Firerate::Firerate()
{
	//1000/(niveau+1)
	this->firerate_ = 1000 / (this->level_get() + 1);
	this->currentWaitingTime_ = this->firerate_;
}

void Firerate::decrease_value()
{
	if (currentWaitingTime_ > 0)
		this->currentWaitingTime_--;
}

Firerate::~Firerate()
{
}
