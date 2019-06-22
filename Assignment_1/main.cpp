#include <iostream>
#include <fstream>
#include "DNA.h"
using namespace std;

int main(int argc, char** argv)
{
	char ans = ' ';
	bool cont;
	string filename;
	do
	{
		if(argc > 1 && !cont)
		{
			filename = argv[1];
		}
		else
		{
			cout << endl;
			cout << "Please enter a file path:" << endl;
			cin >> filename;
		}
		ifstream test;
		test.open(filename);
		while(!test)
		{
			cout << endl;
			cout << "Please enter a valid file path:" << endl;
			cin >> filename;
			test.open(filename);
		}
		DNA dna(filename, !cont);
		dna.computeStats();
		dna.outFile();
		cout << "Would you like to process another list (y/n)?" << endl;
		cin >> ans;
		cont = false;
		if(ans == 'y' || ans == 'Y')
		{
			cont = true;
		}
	} while(cont);
	cout << endl;
	return 0;
}
