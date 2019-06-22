#include <iostream>
#include <fstream>
#include "Board.h"

using namespace std;

/**
Creates a blank board
@param h Height of the board
@param w Width of the board
*/
Board::Board(int h, int w)
{
	height = h;
	width = w;
	board = new char* [h];
	for(int x = 0; x < h; x++)
	{
		board[x] = new char[w];
	}
	fillBlank();
}

/**
Creates a random board
@param h Height of the board
@param w Width of the board
@param d Density of the population
*/
Board::Board(int h, int w, double d)
{
	height = h;
	width = w;
	density = d * h * w;
	board = new char* [h];
	for(int x = 0; x < h; x++)
	{
		board[x] = new char[w];
	}
	fillBlank();
	fillRandom();
}

/**
Copy constructor
@param b A board being copied
*/
Board::Board(const Board &b)
{
	height = b.height;
	width = b.width;
	board = new char* [height];
	for(int x = 0; x < height; x++)
	{
		board[x] = new char[width];
	}
	for(int x = 0; x < height; x++)
	{
		for(int y = 0; y < width; y++)
		{
			board[x][y] = b.board[x][y];
		}
	}
}

/**
Creates a board provided a valid filename
@param b The filename (consists of a 2 numbers and a board)
*/
Board::Board(string b)
{
	ifstream file(b);
	char character;
	string line;
	int count = 0;
	int i = 0;
	int j = 0;
	if(getline(file, line))
	{
		height = checkNum(line);
	}
	if(getline(file, line))
	{
		width = checkNum(line);
	}
	board = new char* [height];
	for(int x = 0; x < height; x++)
	{
		board[x] = new char[width];
	}
	while(!file.eof())
	{
		file.get(character);
		if(character == '\n')
		{
			i++;
			j = 0;
		}
		else if(i >= height || j >= width)
		{
			cerr << "ERROR: Incorrect file dimensions" << endl;
			exit(EXIT_FAILURE);
		}
		else if(character == 'X' || character == '-')
		{
			board[i][j] = character;
			j++;
		}
		else
		{
			cerr << "ERROR: Input file has invalid character on board" << endl;
			exit(EXIT_FAILURE);
		}
	}
	if(board[height - 1][width - 1] != 'X' && board[height - 1][width - 1] != '-')
	{
		cerr << "ERROR: Incorrect file dimensions" << endl;
		exit(EXIT_FAILURE);
	}
	file.close();
}


/**
Removes the board[][] from the heap
*/
Board::~Board()
{
	for(int x = 0; x < height; x++)
	{
		delete[] board[x];
	}
	delete[] board;
}

/**
Returns the height of the Board
*/
int Board::getHeight()
{
	return height;
}

/**
Returns the width of the Board
*/
int Board::getWidth()
{
	return width;
}

/**
Returns the element of a board at a particular index
@param i Row
@param j Column
*/
char Board::getElement(int i, int j)
{
	return board[i][j];
}

/**
Sets the value of a particular index to a char
@param i Row
@param j Column
@param e An 'X' or a '-'
*/
void Board::setElement(int i, int j, char e)
{
	board[i][j] = e;
}

/**
Sets the board to another board
@param b A board
*/
void Board::setBoard(Board b)
{
	for(int x = 0; x < height; x++)
	{
		for(int y = 0; y < width; y++)
		{
			board[x][y] = b.getElement(x, y);
		}
	}
}

/**
Displays the board to the console
*/
void Board::display()
{
	for(int x = 0; x < height; x++)
	{
		for(int y = 0; y < width; y++)
		{
			cout << board[x][y];
		}
		cout << endl;
	}
}

/**
Appends the board to a file
@param filename The name of a file
*/
void Board::outBoard(ofstream& file)
{
	for(int x = 0; x < height; x++)
	{
		for(int y = 0; y < width; y++)
		{
			file << board[x][y];
		}
		file << endl;
	}
}

/**
Fills the board with '-'
*/
void Board::fillBlank()
{
	for(int x = 0; x < height; x++)
	{
		for(int y = 0; y < width; y++)
		{
			board[x][y] = '-';
		}
	}
}

/**
Fills the board with some number of 'X' based on some density
*/
void Board::fillRandom()
{
	int count = 0;
	int x;
	int y;
	while(count < density)
	{
		x = rand()%height;
		y = rand()%width;
		if(board[x][y] == '-')
		{
			board[x][y] = 'X';
			count++;
		}
	}
}

/**
Checks a line to determine if it is a number
@param s The first two lines of the input file (the height and width)
@return int The conversion of s into a number
*/
int Board::checkNum(string s)
{
	for(int x = 0; x < s.length(); x++)
	{
		if(!isdigit(s[x]))
		{
			cerr << "ERROR: Dimensions must be numbers at the top of the file" << endl;
			exit(EXIT_FAILURE);
		}
	}
	int num = stoi(s);
	if(num < 1)
	{
		cerr << "ERROR: Dimensions must be greater than 1" << endl;
		exit(EXIT_FAILURE);
	}
	return num;
}
