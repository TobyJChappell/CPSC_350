#ifndef INPUTCHECKER_H
#define INPUTCHECKER_H

#include <iostream>
#include <limits>

using namespace std;

template <class T>
class InputChecker
{
public:
	void checkInput(T& input);
};

/**
Determines if parameter is valid. If not, asks user for a number until one is inputted.
@param int& num Variable being checked
*/
template <class T>
void InputChecker<T>::checkInput(T& input)
{
	while(!cin)
	{
		cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Please enter a valid input:" << endl;
		cin >> input;
	}
}

#endif
