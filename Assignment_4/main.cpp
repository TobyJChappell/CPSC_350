#include <iostream>
#include "Simulator.h"

using namespace std;

int main(int argc, char** argv)
{
	string file;
	if(argc > 1)
	{
		file = argv[1];
	}
	else
	{
		cout << "\nPlease input a file:" << endl;
		cin >> file;
	}
	Simulator s1(file);
	cout << endl;
	s1.simulate();
	return 0;
}
