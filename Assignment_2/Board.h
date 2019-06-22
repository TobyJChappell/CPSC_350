#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>

using namespace std;

class Board
{
private:
	int height = -1;
	int width = -1;
	int density = 0;
	char** board;
public:
	Board(int h, int w);
	Board(int h, int w, double d);
	Board(const Board &b);
	Board(string b);
	~Board();
	int getHeight();
	int getWidth();
	char** getBoard();
	char getElement(int i, int j);
	void setElement(int i, int j, char e);
	void setBoard(Board b);
	void display();
	void outBoard(ofstream& file);
	void fillBlank();
	void fillRandom();
	int checkNum(string s);
};

#endif
