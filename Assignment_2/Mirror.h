#ifndef MIRROR_H
#define MIRROR_H


#include <iostream>
#include "Board.h"
#include "GameMode.h"

using namespace std;

class Mirror: public GameMode
{
public:
	int numNeighbors(Board b, int i, int j);
};

#endif
