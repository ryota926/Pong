#include <cstdlib>
#include <ctime>
#include "HardComputer.h"

HardComputer::HardComputer(int y, int x)
{
    setX(x);
    setY(y);
}

int HardComputer::getX()
{
	return x;
}

int HardComputer::getY()
{
	return y;
}

int HardComputer::getHeight()
{
	return height;
}

void HardComputer::setX(int a)
{
	x = a;
}

void HardComputer::setY(int a)
{
	y = a;
}

void HardComputer::drawPlayer(int y, int x)
{
	mvaddch(y + 2, x, '|');
	mvaddch(y + 1, x, '|');
	mvaddch(y, x, '|');
	mvaddch(y - 1, x, '|');
	mvaddch(y - 2, x, '|');
}
