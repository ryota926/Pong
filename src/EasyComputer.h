#ifndef SRC_EASYCOMPUTER_H_
#define SRC_EASYCOMPUTER_H_

#include <ncurses.h>
#include "Player2.h"

class EasyComputer : public Player2{
public:
	EasyComputer(int x, int y);
    int getX();
    int getY();
    int getHeight();
    void setX(int a);
    void setY(int a);
    void drawPlayer(int y, int x);

private:
    int x, y, height;
    int delay_count = 0;
};

#endif /* SRC_EASYCOMPUTER_H_ */
