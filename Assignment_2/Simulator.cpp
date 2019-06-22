#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Simulator.h"
using namespace std;

/**
Creates a random board and prompts the user to choose a boundary mode and output
@param h Height of board
@param w Width of board
@param d Density of population
*/
Simulator::Simulator(int h, int w, double d)
{
	current = new Board(h, w, d);
	next = new Board(h, w);
	chooseMode();
	chooseOut();
}

/**
Creates a board from an input file and prompts the user to choose a boundary mode and output
@param b The name of a valid input file
*/
Simulator::Simulator(string b)
{
	current = new Board(b);
	next = new Board(current->getHeight(), current->getWidth());
	chooseMode();
	chooseOut();
}

/**
Destructor
*/
Simulator::~Simulator()
{
	delete current;
	delete next;
	delete mode;
}

/**
Prompts the user to choose a boundary mode and assigns it to mode
*/
void Simulator::chooseMode()
{
	cout << "Please select which mode you would like to play (1-3):" << endl;
	cout << "1. Classic" << endl;
	cout << "2. Doughnut" << endl;
	cout << "3. Mirror" << endl;
	int choice;
	cin >> choice;
	checkNum(choice);
	switch(choice)
	{
		case 1:
			mode = new Classic();
			break;
		case 2:
			mode = new Doughnut();
			break;
		case 3:
			mode = new Mirror();
			break;
		default:
			cerr << "ERROR: Choice must be valid (1-3)" << endl;
			exit(EXIT_FAILURE);
	}
}

/**
Prompts the user to choose an output and assigns out to a numeric value (1-3)
*/
void Simulator::chooseOut()
{
	cout << "Please select which output you would like to use (1-3):" << endl;
	cout << "1. A brief pause between generations" << endl;
	cout << "2. Press \"enter\" to display the next generation" << endl;
	cout << "3. Output to a text file" << endl;
	cin >> out;
	checkNum(out);
	if(out == 3)
	{
		cout << "Please enter what you would like to name the output file" << endl;
		cin >> filename;
		ofstream file(filename);
	}
	else
	{
		cout << endl;
	}
}

/**
Simulates Game of Life until it has stabilized or surpasses 1000 generations
*/
void Simulator::run()
{
	int neighbors;
	do
	{
		switch(out)
		{
			case 1:
				cout << gen << endl;
				current->display();
				usleep(100000);
				break;
			case 2:
				cin.ignore();
				cout << gen << endl;
				current->display();
				break;
			case 3:
				ofstream file(filename, ios_base::app);
				file << gen << endl;
				current->outBoard(file);
				file.close();
				break;
		}
		for(int x = 0; x < current->getHeight(); x++)
		{
			for(int y = 0; y < current->getWidth(); y++)
			{
				Board temp(*current);
				neighbors = mode->numNeighbors(temp, x, y);
				switch(neighbors)
				{
					case(2):
						next->setElement(x, y, current->getElement(x, y));
						break;
					case(3):
						next->setElement(x, y, 'X');
						break;
					default:
						next->setElement(x, y, '-');
				}
			}
		}
		gen++;
	} while(!isStable() && gen < 1000);
	cout << "\nSimulation stabilized, press the \"enter\" key to exit." << endl;
	if(out != 2)
	{
		cin.ignore();
	}
	cin.ignore();
}

/**
Determines whether or not the program is stable
@return bool True if current generation = next generation
*/
bool Simulator::isStable()
{
	for(int x = 0; x < current->getHeight(); x++)
	{
		for(int y = 0; y < current->getWidth(); y++)
		{
			if(current->getElement(x, y) != next->getElement(x, y))
			{
				Board temp(*next);
				current->setBoard(temp);
				next->fillBlank();
				return false;
			}
		}
	}
	return true;
}

/**
Determines if parameter is a number as well as in the range specified. If not, asks user for a number until one is inputted.
@param num Variable being checked
*/
void Simulator::checkNum(int& num)
{
	while(!cin || num < 1 || num > 3)
	{
		cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Please enter a valid number:" << endl;
		cin >> num;
	}
}
