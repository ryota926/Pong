#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(int y, int x)
{
    setX(x);
    setY(y);
}

int HumanPlayer::getX()
{
	return x;
}

int HumanPlayer::getY()
{
	return y;
}

int HumanPlayer::getHeight()
{
	return height;
}
void HumanPlayer::setX(int a)
{
	x = a;
}
void HumanPlayer::setY(int a)
{
	y = a;
}
void HumanPlayer::drawPlayer(int y, int x)
{
	mvaddch(y + 2, x, '|');
	mvaddch(y + 1, x, '|');
	mvaddch(y, x, '|');
	mvaddch(y - 1, x, '|');
	mvaddch(y - 2, x, '|');
}
