#include <iostream>
#include <fstream>
#include "Simulator.h"
#include "UserInput.h"

using namespace std;

int main(int argc, char** argv)
{
	UserInput u;
	cout << "\nWould you like to provide a map file of the world (f) or would you like a random one (r)?" << endl;
	string s = "";
	cin >> s;
	u.checkInput(s);
	if(s[0] == 'f' || s[0] == 'F')
	{
		cout << "Please input the file path:" << endl;
		string path = "";
		cin >> path;
		u.checkPath(path);
		Simulator s(path);
		s.run();
	}
	else
	{
		cout << "Please enter the height of the board:" << endl;
		int height;
		cin >> height;
		u.checkDimension(height);
		cout << "Please enter the width of the board:" << endl;
		int width;
		cin >> width;
		u.checkDimension(width);
		cout << "Please enter the population density (0-1):" << endl;
		double density;
		cin >> density;
		u.checkDensity(density);
		Simulator s(height, width, density);
		s.run();
	}
	return 0;
}
