#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <iostream>
#include <limits>
#include "Board.h"

using namespace std;

/**
GameMode is an astract class so that when once a mode is chosen by the user, Simulator then assigns that mode to this class. Thus, the behavior of Simulator remains unaltered no matter what mode the user selects.
*/
class GameMode
{
public:
	virtual int numNeighbors(Board b, int i, int j) {return 0;}
};

#endif
