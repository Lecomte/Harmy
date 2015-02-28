#include "WarLoop.h"


WarLoop::WarLoop()
{

	int i = 1;
	std::cout << "Entrez le nombre de combats : ";
	std::cin >> i;
	int t = 1;
	std::cout << "Score minimum : ";
	std::cin >> t;
	int n = 2;
	std::cout << "Nombre d'armee : ";
	std::cin >> n;
	int x = 2;
	std::cout << "Nombre d'unitee : ";
	std::cin >> x;
	int y = 10;
	std::cout << "Niveau Global : ";
	std::cin >> y;
	for (int j = 0; j < n; j++)
	{
		this->slotList_.push_back(WarSlot(Army(std::string("Army ") + std::to_string(j), x, y)));
	}

	if (t >(n - 1)*x)
	{
		t = (n - 1)*x;
		std::cout << "Redefinition du score minimal a : " << t << std::endl;
	}

	this->battleNumber_ = i;
	this->minimalScore_ = t;
	this->unitNumber_ = x;
	this->levelGlobal_ = y;
}

void WarLoop::clashOfArmy()
{
	for (int i = 0; i < this->battleNumber_; i++)
	{
		for (int j = 0; j < this->slotList_.size(); j++)
		{
			for (int k = j + 1; k < this->slotList_.size(); k++)
			{
				std::cout << "Fight " << this->slotList_[j].army_get().armyCode_get() << " against " << this->slotList_[k].army_get().armyCode_get() << " begin !" << std::endl;
				GameLoop gl = GameLoop(this->slotList_[j].army_get(), this->slotList_[k].army_get());
				bool continu = true;
				while (continu)
				{
					continu = gl.runRound();
				}
				this->slotList_[j].score_increase(gl.getArmyAPoint());
				this->slotList_[k].score_increase(gl.getArmyBPoint());
			}
		}
		std::sort(this->slotList_.begin(), this->slotList_.end());
		if (this->slotList_[0].score_get() > this->minimalScore_)
			break;
	}
	for (int l = 0; l < this->slotList_.size(); l++)
	{
		std::cout << this->slotList_[l].army_get().armyCode_get() << " a " << this->slotList_[l].score_get() << " points." << std::endl;
	}
	this->slotList_[0].army_get().save(this->unitNumber_, this->levelGlobal_);

	//this->slotList_[0].army_get().unitList_getAt(0).mutate();
	//this->slotList_[0].army_get().mutate(); //bug
	//this->slotList_[0].army_get() * this->slotList_[0].army_get();
}

WarLoop::~WarLoop()
{
}
