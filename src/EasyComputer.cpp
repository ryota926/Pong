#include <cstdlib>
#include <ctime>
#include "EasyComputer.h"

EasyComputer::EasyComputer(int y, int x)
{
    setX(x);
    setY(y);
}

int EasyComputer::getX()
{
	return x;
}

int EasyComputer::getY()
{
	return y;
}

int EasyComputer::getHeight()
{
	return height;
}

void EasyComputer::setX(int a)
{
	x = a;
}

void EasyComputer::setY(int a)
{
	if(delay_count == 5) {
		delay_count = 0;
		y = a;
	}
	else
		delay_count++;
}

void EasyComputer::drawPlayer(int y, int x)
{
	mvaddch(y + 1, x, '|');
	mvaddch(y, x, '|');
	mvaddch(y - 1, x, '|');
}
