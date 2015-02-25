#include "Unit.h"

Unit::Unit()
{

}

Unit::Unit(int UniqId, int levelCount, Point position)
{
	instanciateCapacities();
	this->UNIQ_ID = UniqId;
	for (int i = 0; i < levelCount; i++)
	{
		int capacityId = std::rand() % 7;
		this->capacity_get(capacityId)->level_upgrade();
		this->position = position;
	}
	std::string AICode = "";
	if (std::rand() % 2 == 0)
		AICode += "H";
	else
		AICode += "L";
	int capacitiesID = std::rand() % this->capacities_.size() + 1;
	if (capacitiesID == this->capacities_.size())
		AICode += "D";
	else
		AICode += std::to_string(capacitiesID);
	this->AICode_ = AICode;
	//IA aléatoire
}

Unit::Unit(Unit& unit)
{
	instanciateCapacities();
	this->UNIQ_ID = unit.UNIQ_ID;
	for (int i = 0; i < unit.capacities_.size(); i++)
	{
		if (i == HEALTH)
			this->health_get() = unit.health_get();
		else if (i == FIRERATE)
			this->firerate_get() = unit.firerate_get();
		else
			*(this->capacities_[i]) = *(unit.capacities_[i]);
	}
	this->position = unit.position;
	this->AICode_ = unit.AICode_get();
}

Unit& Unit::operator=(const Unit& unit)
{
	if (this != &unit)
	{
		this->AICode_ = unit.AICode_;
		for (int i = 0; i < this->capacities_.size(); i++)
		{
			if (i == HEALTH)
				this->health_get() = unit.health_get();
			else if (i == FIRERATE)
				this->firerate_get() = unit.firerate_get();
			else
				*(this->capacities_[i]) = *(unit.capacities_[i]);
		}
		this->position = unit.position;
	}
	return *this;
}

Unit::Unit(int uniqId, int armorLevel, int firerateLevel, int damageLevel, int rangeLevel, int healthLevel, int regenerationLevel, int speedLevel, std::string AiCode, Point position)
{
	instanciateCapacities();
	this->UNIQ_ID = uniqId;
	this->capacities_[SPEED]->level_set(speedLevel);
	this->capacities_[HEALTH]->level_set(healthLevel);
	this->capacities_[ARMOR]->level_set(armorLevel);
	this->capacities_[REGENERATION]->level_set(regenerationLevel);
	this->capacities_[DAMAGE]->level_set(damageLevel);
	this->capacities_[RANGE]->level_set(rangeLevel);
	this->capacities_[FIRERATE]->level_set(firerateLevel);
	this->position = position;
	this->AICode_ = AiCode;
	//Ajouter l'IA
}

void Unit::instanciateCapacities()
{
	this->capacities_.push_back(new Speed());
	this->capacities_.push_back(new Health());
	this->capacities_.push_back(new Armor());
	this->capacities_.push_back(new Regeneration());
	this->capacities_.push_back(new Damage());
	this->capacities_.push_back(new Range());
	this->capacities_.push_back(new Firerate());
}

int Unit::UNIQ_ID_get()
{
	return this->UNIQ_ID;
}

int Unit::level_get()
{
	int level = 0;
	for (std::vector<Capacity*>::size_type i = 0; i < this->capacities_.size(); i++)
	{
		level += this->capacities_[i]->level_get();
	}
	return level;
}

void Unit::refresh()
{
	//this->health_get().currentLife_set(this->regeneration_get().value_get());
	this->firerate_get().decrease_value();
}

void Unit::setPosition(int x, int y)
{
	this->position.x_set(x);
	this->position.y_set(y);
}

bool Unit::canShoot()
{
	if (this->firerate_get().value_get() == 0 )
	{
		//this->firerate_get().reset_value();
		return true;
	}
	return false;
}

void Unit::takeDamage(float value)
{
	float damage = -(value - this->armor_get().value_get());
	if (damage > 0)
		damage = -1;
	this->health_get().currentLife_set(damage);
}

bool Unit::isAlive()
{
	if (this->health_get().value_get() > 0)
		return true;
	return false;
}

//debug
void Unit::print()
{
	std::cout << "Uniq Id : " << this->UNIQ_ID << std::endl;
	//std::cout << "armor : " << this->armor_get().value_get() << std::endl;
	//std::cout << "health : " << this->health_get().value_get() << std::endl;
	//std::cout << "health level : " << this->health_get().level_get() << std::endl;
	//std::cout << "speed : " << this->speed_get().value_get() << std::endl;
	//std::cout << "regeneration : " << this->regeneration_get().value_get() << std::endl;
	//std::cout << "damage : " << this->damage_get().value_get() << std::endl;
	std::cout << "range : " << this->range_get().value_get() << std::endl;
	std::cout << "firerate : " << this->firerate_get().value_get() << std::endl;
	//std::cout << "firerate level : " << this->firerate_get().level_get() << std::endl;
	std::cout << "Position : " << this->position_get().x_get() << " : " << this->position_get().y_get() << std::endl;
	std::cout << "IACode : " << this->AICode_ << std::endl;
	std::cout << std::endl;
}

Unit::~Unit()
{
	for (int i = 0; i < this->capacities_.size(); i++)
	{
		delete this->capacities_[i];
	}
	this->capacities_.clear();
}
