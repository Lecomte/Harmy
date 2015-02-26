#pragma once
#include "Unit.h"
#include <vector>

class Army
{
public:
	Army();
	Army(std::string armyCode,int unitCount, int levelPerUnit);
	Army(std::string armyCode,std::vector<Unit*> unitList);
	Army(Army& army);
	Army& operator=(const Army& army);
	Unit& unit_get(int uniqId);
	Unit& unitList_getAt(int index);
	int size_get() { return this->unitList_.size(); }
	void baseSpawn_set(Point value);
	std::string armyCode_get() { return this->armyCode_; }
	Unit& getNearestUnit(Point& pos);
	Unit& getFurtherUnit(Point& pos);
	Unit& getLowestUnit(int capacityId);
	Unit& getHiggestUnit(int capacityId);
	void purge();
	Army mutate();
	Army& operator*(const Army& army);
	~Army();
private:
	std::vector<Unit*> unitList_;
	int currentID;
	std::string armyCode_;
	int rangeSpwan = 20;
};

