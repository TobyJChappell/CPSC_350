#include <iostream>
#include "Stack.h"

using namespace std;

int main(int argc, char** argv)
{
	Stack myStack(10);

	myStack.push('T');
	myStack.push('O');
	myStack.push('B');
	myStack.push('Y');

	cout << myStack.peek() << endl;
	while(!myStack.isEmpty())
	{
		cout << myStack.pop();
	}
	cout << endl;
	cout << myStack.pop();
	return 0;
}
