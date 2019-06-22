#ifndef DOUGHNUT_H
#define DOUGHNUT_H

#include <iostream>
#include "Board.h"
#include "GameMode.h"

using namespace std;

class Doughnut: public GameMode
{
public:
	int numNeighbors(Board b, int i, int j);
};

#endif
