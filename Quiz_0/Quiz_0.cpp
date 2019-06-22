#include <iostream>
#include "Quiz_0.h"

using namespace std;

Quiz_0::Quiz_0()
{
}

Quiz_0::~Quiz_0()
{
	cout << "Object deleted." << endl;
}

int Quiz_0::countVowels(string input)
{
	int count = 0;
	for(int x = 0; x < input.size(); x++)
	{
		char l = tolower(input[x]);
		if(l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')
		{
			count++;
		}
	}
	return count;
}
