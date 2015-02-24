#include <iostream>
#include "GameMechanics\Army.h"
#include "Others\AI.h"

int main(int argc, char **argv)
{
	Army army1 = Army(100, 100);
	Army army2 = Army(100, 100);
	std::cout << "army1 size : " << army1.size_get() << std::endl;
	Unit bouquemissaire = army1.unit_get(0);
	bouquemissaire.print();
	while (bouquemissaire.isAlive())
	{
		bouquemissaire.takeDamage(50);
		bouquemissaire.print();
		AI ai;
		std::shared_ptr<Action> action = ai(bouquemissaire, army1, army2);
		action->execute();
	}
	system("pause");
	return 0;
}