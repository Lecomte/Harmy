#pragma once
#include "Capacity.h"
#include "Armor.h"
#include "AttackSpeed.h"
#include "Damage.h"
#include "Range.h"
#include "Health.h"
#include "Regeneration.h"
#include "Speed.h"
#include "Point.h"
#include <vector>

class Unit
{
public:
	Unit();
	enum CapacityID : int {SPEED=0,HEALTH,ARMOR,REGENERATION,DAMAGE,RANGE,FIRERATE};
	float capacity_value_get(int capacityID) { return this->capacites_.at(capacityID)->value_get(); }
	void capacity_upgrade(int capacityID) { this->capacites_.at(capacityID)->level_updgrade(); }
	void capacity_downgrade(int capacityID) { this->capacites_.at(capacityID)->level_downgrade(); }
	float armor_get() { return this->capacites_.at(this->ARMOR)->value_get(); }
	AttackSpeed& attackSpeed_get() { return ((AttackSpeed&)this->capacites_.at(this->FIRERATE)); }
	float damage_get() { return this->capacites_.at(this->DAMAGE)->value_get(); }
	float range_get() { return this->capacites_.at(this->RANGE)->value_get(); }
	float health_get() { return this->capacites_.at(this->HEALTH)->value_get(); }
	float regeneration_get() { return this->capacites_.at(this->REGENERATION)->value_get(); }
	float speed_get() { return this->capacites_.at(this->SPEED)->value_get(); }
	int id_get() { return this->UNIQ_ID; }
	int level_get();
	~Unit();
private:
	std::vector<Capacity*> capacites_;
	int UNIQ_ID;
};

