#include "Army.h"

Army::Army()
{
	//currentID = 0;
	//this->unitList_ = std::vector<Unit*>();
	/*for (int i = 0; i < 10; i++)
	{
		this->unitList_.push_back(new Unit(currentID, 10,Point(0,0)));
		currentID++;
	}*/
}

Army::Army(std::string armyCode,int unitCount, int levelPerUnit)
{
	currentID = 0;
	this->armyCode_ = armyCode;
	Point currentSpawn;
	this->unitList_ = std::vector<Unit*>();
	for (int i = 0; i < unitCount; i++)
	{
		currentSpawn = Point(0,0);
		currentSpawn.x_set(currentSpawn.x_get() + (((std::rand() % 2) + 1) * std::rand() % this->rangeSpwan));
		currentSpawn.y_set(currentSpawn.y_get() + (((std::rand() % 2) + 1) * std::rand() % this->rangeSpwan));
		this->unitList_.push_back(new Unit(currentID, levelPerUnit,currentSpawn));
		currentID++;
	}
}

Army::Army(std::string armyCode, std::vector<Unit*> unitList)
{
	this->armyCode_ = armyCode;
	this->unitList_ = std::vector<Unit*>();
	for (int i = 0; i < unitList.size(); i++)
	{
		this->unitList_.push_back(new Unit((*unitList[i])));
	}
}

Army::Army(Army& army)
{
	this->armyCode_ = army.armyCode_;
	for (int i = 0; i < army.unitList_.size(); i++)
	{
		this->unitList_.push_back(new Unit(*army.unitList_[i]));
	}
	this->currentID = army.currentID;
}

Army& Army::operator=(const Army& army)
{
	if (this != &army)
	{
		this->armyCode_ = army.armyCode_;
		for (int i = 0; i < this->unitList_.size(); i++)
		{
			delete this->unitList_[i];
		}
		this->unitList_.clear();
		for (int i = 0; i < army.unitList_.size(); i++)
		{
			this->unitList_.push_back(new Unit(*army.unitList_[i]));
		}
		this->currentID = army.currentID;
	}
	return *this;
}

void Army::baseSpawn_set(Point value)
{
	for (int i = 0; i < this->unitList_.size(); i++)
	{
		Point currentSpawn = value;
		currentSpawn.x_set(currentSpawn.x_get() + (((std::rand() % 2) + 1) * std::rand() % this->rangeSpwan));
		currentSpawn.y_set(currentSpawn.y_get() + (((std::rand() % 2) + 1) * std::rand() % this->rangeSpwan));
		this->unitList_[i]->setPosition(currentSpawn.x_get(), currentSpawn.y_get());
	}
}

Unit& Army::unit_get(int uniqId)
{
	Unit* u = nullptr;
	for (int i = 0; i < this->unitList_.size(); i++)
	{
		if (this->unitList_[i]->UNIQ_ID_get() == uniqId)
			u = this->unitList_[i];
	}
	return *u;
}

Unit& Army::unitList_getAt(int index)
{
	//if (uniqId < this->size_get())
	return *(this->unitList_[index]);
	//return nullptr;
}

Unit& Army::getNearestUnit(Point& pos)
{
	Unit* nearestUnit = &(unitList_getAt(0));
	int currentDist = pos.Distance(nearestUnit->position_get());
	for (int i = 1; i < this->size_get(); i++)
	{
		int dist = pos.Distance(unitList_getAt(i).position_get());
		if (dist < currentDist)
		{
			nearestUnit = &(unitList_getAt(i));
			currentDist = dist;
		}
	}
	return *nearestUnit;
}

Unit& Army::getFurtherUnit(Point& pos)
{
	Unit* furtherUnit = &(unitList_getAt(0));
	int currentDist = pos.Distance(furtherUnit->position_get());
	for (int i = 1; i < this->size_get(); i++)
	{
		int dist = pos.Distance(unitList_getAt(i).position_get());
		if (dist > currentDist)
		{
			furtherUnit = &(unitList_getAt(i));
			currentDist = dist;
		}
	}
	return *furtherUnit;
}

Unit& Army::getLowestUnit(int capacityId)
{
	Unit* lowestUnit = &(unitList_getAt(0));
	float currentValue = lowestUnit->capacity_get(capacityId)->value_get();
	for (int i = 1; i < this->size_get(); i++)
	{
		float value = unitList_getAt(i).capacity_get(capacityId)->value_get();
		if (value < currentValue)
		{
			lowestUnit = &(unitList_getAt(i));
			currentValue = value;
		}
	}
	return *lowestUnit;
}

Unit& Army::getHiggestUnit(int capacityId)
{
	Unit* higgestUnit = &(unitList_getAt(0));
	float currentValue = higgestUnit->capacity_get(capacityId)->value_get();
	for (int i = 1; i < this->size_get(); i++)
	{
		float value = unitList_getAt(i).capacity_get(capacityId)->value_get();
		if (value > currentValue)
		{
			higgestUnit = &(unitList_getAt(i));
			currentValue = value;
		}
	}
	return *higgestUnit;
}

void Army::purge()
{
	int number = 0;
	std::vector<int> removedList = std::vector<int>();
	for (int i = 0; i < this->size_get(); i++)
	{
		Unit& currentUnit = this->unitList_getAt(i);
		if (!currentUnit.isAlive())
			removedList.push_back(number);
		else
			number++;
	}
	for (int i = 0; i < removedList.size(); i++)
	{
		this->unitList_.erase(this->unitList_.begin() + removedList[i]);
	}
}

Army::~Army()
{
	for (int i = 0; i < this->unitList_.size(); i++)
	{
		delete this->unitList_[i];
	}
	this->unitList_.clear();
}
