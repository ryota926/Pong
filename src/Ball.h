#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <ncurses.h>

class Ball {
public:
    Ball(double x, double y, int speed);
    double getX();
    double getY();
    int getSpeed();
    void setX(double a);
    void setY(double a);
    void setSpeed(int a);
    void drawBall(double x, double y);

private:
    double x, y;
    int speed;

};


#endif //PONG_BALL_H
