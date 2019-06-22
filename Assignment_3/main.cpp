#include <iostream>
#include "Delimiter.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << endl;
	string file;
	if(argc > 1)
	{
		file = argv[1];
	}
	else
	{
		cout << "Please input a file:" << endl;
		cin >> file;
	}
	Delimiter d1(file);
	d1.checkDelimiters();
	cout << "\nWould you like to process another file (y/n)?" << endl;
	char ans;
	cin >> ans;
	while(ans == 'y' || ans == 'Y')
	{
		cout << "\nPlease input a file:" << endl;
		cin >> file;
		d1.setFile(file);
		d1.checkDelimiters();
		cout << "\nWould you like to process another file (y/n)?" << endl;
		cin >> ans;
	}
	cout << endl;
	return 0;
}
