#include <iostream>
#include "Unit.h"

int main(int argc, char **argv)
{
	Unit* u = new Unit();
	std::cout << u->capacity_value_get(u->ARMOR) << std::endl;
	for (int i = 0; i < 10; i++)
		u->capacity_upgrade(u->ARMOR);
	std::cout << u->capacity_value_get(u->ARMOR) << std::endl;
	system("pause");
	return 0;
}