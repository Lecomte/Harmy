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

Unit::~Unit()
{

}
