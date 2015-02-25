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
		this->armyList.push_back(Army(std::string("Army ") + std::to_string(j), x, y));
		this->armyScore.push_back(0);
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
		for (int j = 0; j < this->armyList.size(); j++)
		{
			for (int k = j+1; k < this->armyList.size(); k++)
			{
				std::cout << "Fight " << this->armyList[j].armyCode_get() << " against " << this->armyList[k].armyCode_get() << " begin !" << std::endl;
				GameLoop gl = GameLoop(this->armyList[j], this->armyList[k]);
				bool continu = true;
				while (continu)
				{
					continu = gl.runRound();
				}
				this->armyScore[j] += gl.getArmyAPoint();
				this->armyScore[k] += gl.getArmyBPoint();
			}
		}
	}
	for (int l = 0; l < this->armyList.size(); l++)
	{
		std::cout << this->armyList[l].armyCode_get() << " a " << this->armyScore[l] << " points." << std::endl;
	}
}

WarLoop::~WarLoop()
{
}
