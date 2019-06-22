#include <iostream>
#include "Quiz_0.h"

using namespace std;

int main(int argc, char** argv)
{
	string in;
	//if(argc > 1)
	//{
		//in = argv[1];
		cout << "Please enter a string:" << endl;
		cin >> in;

		Quiz_0 q0; //stored on the stack

		cout << "The number of vowels in \"" << in << "\" is: " << q0.countVowels(in) << endl;

		/**
	}
	else
	{
		cout << "Please input a string!" << endl;
		cout << "USAGE: ./quiz0 [input_string]" << endl;
	}
	*/
	cout << "Program exited successfully." << endl;
	return 0;
}
