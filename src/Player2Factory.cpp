#include "Player2Factory.h"

Player2 *Player2Factory::choice(int choice)
{
	if(choice == 2)
		return new HumanPlayer(24 / 2, 80 - 3);
	else if (choice == 1)
		return new EasyComputer(24 / 2, 80 - 3);
	else if (choice == 3)
		return new HardComputer(24 / 2, 80 - 3);
	else
		return NULL;
}
