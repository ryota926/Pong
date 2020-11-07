#ifndef PONG_PLAYER2_H
#define PONG_PLAYER2_H

#include <ncurses.h>

class Player2 {

public:
	Player2();
    Player2(int x, int y);
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual int getHeight() = 0;
    virtual void setX(int a) = 0;
    virtual void setY(int a) = 0;
    virtual void drawPlayer(int y, int x) = 0;

protected:
    int x, y, height;

};

#endif //PONG_PLAYER2_H
