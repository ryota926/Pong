#ifndef SRC_PLAYER2FACTORY_H_
#define SRC_PLAYER2FACTORY_H_

#include "Player2.h"
#include "Player2Factory.h"

#include "EasyComputer.h"
#include "HardComputer.h"
#include "Player.h"
#include "Player2.h"
#include "HumanPlayer.h"

class Player2Factory:public Player2 {
public:
	static Player2 *choice(int choice);
};

#endif /* SRC_PLAYER2FACTORY_H_ */
