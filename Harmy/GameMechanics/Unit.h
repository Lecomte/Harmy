#pragma once
#include "..\Capacities\Capacity.h"
#include "..\Capacities\Armor.h"
#include "..\Capacities\Firerate.h"
#include "..\Capacities\Damage.h"
#include "..\Capacities\Range.h"
#include "..\Capacities\Health.h"
#include "..\Capacities\Regeneration.h"
#include "..\Capacities\Speed.h"
#include "..\Others\Point.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Unit
{
public:
	Unit();
	Unit(int UniqId, int levelCount, Point position);
	Unit(int UniqId, int armorLevel, int firerateLevel, int DamageLevel, int rangeLevel, int healthLevel, int regenerationLevel, int speedLevel, std::string AiCode, Point position);
	Unit(const Unit& unit);
	Unit& operator=(const Unit& unit);
	enum CapacityID : int {SPEED=0,HEALTH,ARMOR,REGENERATION,DAMAGE,RANGE,FIRERATE};
	Capacity* capacity_get(int capacityID) const { return this->capacities_.at(capacityID); }
	void capacity_upgrade(int capacityID) { this->capacities_.at(capacityID)->level_upgrade(); }
	void capacity_downgrade(int capacityID) { this->capacities_.at(capacityID)->level_downgrade(); }
	Armor& armor_get() { return *((Armor*)this->capacities_.at(this->ARMOR)); }
	Firerate& firerate_get() { return *((Firerate*)this->capacities_.at(this->FIRERATE)); }
	const Firerate& firerate_get() const { return *((Firerate*)this->capacities_.at(this->FIRERATE)); }
	Damage& damage_get() { return *((Damage*)this->capacities_.at(this->DAMAGE)); }
	Range& range_get() { return *((Range*)this->capacities_.at(this->RANGE)); }
	Health& health_get() { return *((Health*)this->capacities_.at(this->HEALTH)); }
	const Health& health_get() const { return *((Health*)this->capacities_.at(this->HEALTH)); }
	Regeneration& regeneration_get() { return *((Regeneration*)this->capacities_.at(this->REGENERATION)); }
	Speed& speed_get() { return *((Speed*)this->capacities_.at(this->SPEED)); }
	Point position_get(){ return this->position; }
	std::string AICode_get() const { return this->AICode_; }
	int id_get() { return this->UNIQ_ID; }
	int UNIQ_ID_get();
	int level_get() const;
	void refresh();
	void setPosition(int x, int y);
	bool canShoot();
	void takeDamage(float value);
	bool isAlive();
	Unit mutate() const;
	Unit& operator*(const Unit& unit) const;
	void instanciateCapacities();
	void save(std::ofstream& fichier);
	//Debug
	void print();
	~Unit();
private:
	Point position;
	std::vector<Capacity*> capacities_;
	std::string AICode_;
	int UNIQ_ID;
};

