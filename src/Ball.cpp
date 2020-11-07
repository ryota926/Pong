#include "Ball.h"

Ball::Ball(double y, double x, int speed)
{
    setY(y);
    setX(x);
    setSpeed(speed);
}

double Ball::getX()
{
	return x;
}

double Ball::getY()
{
	return y;
}

int Ball::getSpeed()
{
	return speed;
}

void Ball::setX(double a)
{
	x = a;
}

void Ball::setY(double a)
{
	y = a;
}

void Ball::setSpeed(int a)
{
	speed = a;
}

void Ball::drawBall(double x, double y)
{
	mvaddch(x, y, 'o');
}
