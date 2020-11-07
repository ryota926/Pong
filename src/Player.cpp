#include "Player.h"

Player::Player(int y, int x)
{
    setX(x);
    setY(y);
}

int Player::getX()
{
	return x;
}

int Player::getY()
{
	return y;
}

int Player::getHeight()
{
	return height;
}

void Player::setX(int a)
{
	x = a;
}

void Player::setY(int a)
{
	y = a;
}

void Player::drawPlayer(int y, int x)
{
	mvaddch(y + 2, x, '|');
	mvaddch(y + 1, x, '|');
	mvaddch(y, x, '|');
	mvaddch(y - 1, x, '|');
	mvaddch(y - 2, x, '|');
}
