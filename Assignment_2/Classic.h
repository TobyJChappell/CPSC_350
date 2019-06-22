#ifndef CLASSIC_H
#define CLASSIC_H

#include <iostream>
#include "Board.h"
#include "GameMode.h"

using namespace std;

class Classic: public GameMode
{
public:
	int numNeighbors(Board b, int i, int j);
};

#endif
