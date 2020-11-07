#ifndef SRC_HARDCOMPUTER_H_
#define SRC_HARDCOMPUTER_H_

#include "Player2.h"

class HardComputer : public Player2{
public:
	HardComputer(int x, int y);
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



#endif /* SRC_HARDCOMPUTER_H_ */
