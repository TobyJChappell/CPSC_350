#include <iostream>
#include <fstream>
#include "InputHandler.h"

using namespace std;

/**
Default Constructor
@param file Name of a file
*/
InputHandler::InputHandler()
{
	cout << "Please enter a file path" << endl;
	cin >> m_file;
	m_file = checkFile(m_file);
	loadArray();
}

/**
Overloaded Constructor
@param file Name of a file
*/
InputHandler::InputHandler(string file)
{
	m_file = checkFile(file);
	loadArray();
}

/**
Destructor
*/
InputHandler::~InputHandler()
{
	delete array;
}

/**
Checks to see if a file is valid and prompts the user to enter a valid file until one is inputted
@param file A file name
@return string A valid file path
*/
string InputHandler::checkFile(string file)
{
	ifstream test;
	test.open(file);
	while(!test){
		cout << endl;
		cout << "Please enter a valid file path:" << endl;
		cin >> file;
		test.open(file);
	}
	return file;
}

/**
Loads the array from a file
*/
void InputHandler::loadArray()
{
	ifstream file(m_file);
	string line;
	while(getline(file, line) && !checkNum(line))
	{
		getline(file, line);
	}
	if(checkNum(line))
	{
		size = stoi(line);
	}
	else
	{
		cerr << "\nERROR: Size must be a valid input.\n" << endl;
		exit(EXIT_FAILURE);
	}
	if(size < 0)
	{
		cerr << "\nERROR: Size must be greater than 0.\n" << endl;
		exit(EXIT_FAILURE);
	}
	array = new double[size];
	int x = 0;
	while(getline(file, line) && x < size)
	{
		if(checkNum(line))
		{
			array[x] = stod(line);
			x++;
		}
	}
	if(x < size)
	{
		cerr << "\nERROR: Size of " << size << " was specified, but " << x << " numbers were entered.\n" << endl;
		exit(EXIT_FAILURE);
	}
}

/**
Checks a line to determine if it is a number
@param s Line being checked
@return bool True if string is valid
*/
bool InputHandler::checkNum(string s)
{
	if(s.length() == 0)
	{
		return false;
	}
	for(int x = 0; x < s.length(); x++)
	{
		if(!isdigit(s[x]) && s[x] != '.')
		{
			return false;
		}
	}
	return true;
}
