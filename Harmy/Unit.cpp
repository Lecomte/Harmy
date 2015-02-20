#include "Unit.h"


Unit::Unit()
{
	this->capacites_.push_back(new Speed());
	this->capacites_.push_back(new Health());
	this->capacites_.push_back(new Armor());
	this->capacites_.push_back(new Regeneration());
	this->capacites_.push_back(new Damage());
	this->capacites_.push_back(new Range());
	this->capacites_.push_back(new AttackSpeed());
}

int Unit::level_get()
{
	int level = 0;
	for (std::vector<Capacity*>::size_type i = 0; i < this->capacites_.size(); i++)
	{
		level += this->capacites_[i]->level_get();
	}
	return level;
}

void Unit::refresh()
{
	this->attackSpeed_get() - 1
}

void Unit::setPosition(int x, int y)
{

}

bool Unit::canShoot()
{

}

void Unit::takeDamage(float value)
{

}

bool Unit::isAlive()
{

}

Unit::~Unit()
{

}
