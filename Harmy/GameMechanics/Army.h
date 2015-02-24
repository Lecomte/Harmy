#pragma once
#include "Unit.h"
#include <vector>

class Army
{
public:
	Army();
	Army(int unitCount, int levelPerUnit);
	Army(std::vector<Unit*> unitList);
	Unit& unit_get(int uniqId);
	Unit& unitList_getAt(int index);
	int size_get() { return this->unitList_.size(); }
	Unit& getNearestUnit(Point& pos);
	Unit& getFurtherUnit(Point& pos);
	Unit& getLowestUnit(int capacityId);
	Unit& getHiggestUnit(int capacityId);
	void purge();
	~Army();
private:
	std::vector<Unit*> unitList_;
	int currentID;
};

