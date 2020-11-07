#ifndef PONG_PLAYER_H
#define PONG_PLAYER_H

#include <ncurses.h>


class Player {

public:
    Player(int x, int y);
    int getX();
    int getY();
    int getHeight();
    void setX(int a);
    void setY(int a);
    void drawPlayer(int y, int x);

private:
    int x, y, height;

};


#endif //PONG_PLAYER_H
