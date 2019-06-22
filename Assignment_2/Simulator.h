#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include "Board.h"
#include "GameMode.h"
#include "Classic.h"
#include "Doughnut.h"
#include "Mirror.h"
using namespace std;

class Simulator
{
private:
	Board* current;
	Board* next;
	GameMode* mode;
	int gen = 0;
	int out = 0;
	string filename;
public:
	Simulator(int h, int w, double d);
	Simulator(string b);
	~Simulator();
	void chooseMode();
	void chooseOut();
	void run();
	bool isStable();
	void checkNum(int& num);
};

#endif
