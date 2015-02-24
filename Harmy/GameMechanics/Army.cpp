#include "Army.h"

Army::Army()
{
	currentID = 0;
	this->unitList_ = std::vector<Unit*>();
	for (int i = 0; i < 10; i++)
	{
		this->unitList_.push_back(new Unit(currentID, 10));
		currentID++;
	}
}

Army::Army(int unitCount, int levelPerUnit)
{
	currentID = 0;
	this->unitList_ = std::vector<Unit*>();
	for (int i = 0; i < unitCount; i++)
	{
		this->unitList_.push_back(new Unit(currentID, levelPerUnit));
		currentID++;
	}
}

Army::Army(std::vector<Unit*> unitList)
{
	this->unitList_ = std::vector<Unit*>();
	for (int i = 0; i < unitList.size(); i++)
	{
		this->unitList_.push_back(new Unit(((Unit&)unitList[i])));
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
	Unit& nearestUnit = ((Unit&)this->unitList_[0]);
	int currentDist = pos.Distance(nearestUnit.position_get());
	for (int i = 1; i < this->size_get(); i++)
	{
		int dist = pos.Distance(this->unitList_[i]->position_get());
		if (dist < currentDist)
		{
			nearestUnit = ((Unit&)this->unitList_[i]);
			currentDist = dist;
		}
	}
	return nearestUnit;
}

Unit& Army::getFurtherUnit(Point& pos)
{
	Unit& furtherUnit = ((Unit&)this->unitList_[0]);
	int currentDist = pos.Distance(furtherUnit.position_get());
	for (int i = 1; i < this->size_get(); i++)
	{
		int dist = pos.Distance(this->unitList_[i]->position_get());
		if (dist > currentDist)
		{
			furtherUnit = ((Unit&)this->unitList_[i]);
			currentDist = dist;
		}
	}
	return furtherUnit;
}

Unit& Army::getLowestUnit(int capacityId)
{
	Unit& lowestUnit = ((Unit&)this->unitList_[0]);
	float currentValue = lowestUnit.capacity_get(capacityId)->value_get();
	for (int i = 1; i < this->size_get(); i++)
	{
		float value = this->unitList_[i]->capacity_get(capacityId)->value_get();
		if (value < currentValue)
		{
			lowestUnit = ((Unit&)this->unitList_[i]);
			currentValue = value;
		}
	}
	return lowestUnit;
}

Unit& Army::getHiggestUnit(int capacityId)
{
	Unit& higgestUnit = ((Unit&)this->unitList_[0]);
	float currentValue = higgestUnit.capacity_get(capacityId)->value_get();
	for (int i = 1; i < this->size_get(); i++)
	{
		float value = this->unitList_[i]->capacity_get(capacityId)->value_get();
		if (value > currentValue)
		{
			higgestUnit = ((Unit&)this->unitList_[i]);
			currentValue = value;
		}
	}
	return higgestUnit;
}

void Army::purge()
{
	int number = 0;
	std::vector<int> removedList = std::vector<int>();
	for (int i = 0; i < this->size_get(); i++)
	{
		Unit* currentUnit = this->unitList_[i];
		if (!currentUnit->isAlive())
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
}
