#include <iostream>
#include <fstream>
#include <limits>
#include "UserInput.h"

/**
Checks to see if the user inputs one of the two correct input (random or file)
@param s Input being checked
*/
void UserInput::checkInput(string& s)
{
	while(!(s[0] == 'f' || s[0] == 'F' || s[0] == 'r' || s[0] == 'R'))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Please enter a valid option (f or r):" << endl;
		cin >> s;
	}
}

/**
Checks to see if the user inputs a valid path
@param path Filename being checked
*/
void UserInput::checkPath(string& path)
{
	ifstream test;
	test.open(path);
	while(!test)
	{
		cout << endl;
		cout << "Please enter a valid file path:" << endl;
		cin >> path;
		test.open(path);
	}
}

/**
Checks to see if the user inputs valid dimensions
@param d Dimension being checked
*/
void UserInput::checkDimension(int& d)
{
	while(!cin || d < 1)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Please enter a valid number:" << endl;
		cin >> d;
	}
}

/**
Checks to see if the user inputs a valid density
@param d Density being checked
*/
void UserInput::checkDensity(double& d)
{
	while(!cin || d > 1 || d <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Please enter a valid number:" << endl;
		cin >> d;
	}
}
