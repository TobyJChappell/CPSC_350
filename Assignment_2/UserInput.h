#ifndef USERINPUT_H
#define USERINPUT_H

#include <iostream>

using namespace std;

class UserInput
{
public:
	void checkInput(string& s);
	void checkPath(string& path);
	void checkDimension(int& d);
	void checkDensity(double& d);
};

#endif
