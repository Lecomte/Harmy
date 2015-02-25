#include <iostream>
#include <time.h>
#include "WarLoop.h"

int main(int argc, char **argv)
{
	srand(time(nullptr));
	WarLoop war = WarLoop();
	war.clashOfArmy();
	system("pause");
	return 0;
}