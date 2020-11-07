#ifndef SRC_HUMANPLAYER_H_
#define SRC_HUMANPLAYER_H_

#include <ncurses.h>
#include "Player2.h"


class HumanPlayer : public Player2 {

public:
    HumanPlayer(int x, int y);
    int getX();
    int getY();
    int getHeight();
    void setX(int a);
    void setY(int a);
    void drawPlayer(int y, int x);

protected:
    int x, y, height;

};

#endif /* SRC_HUMANPLAYER_H_ */
