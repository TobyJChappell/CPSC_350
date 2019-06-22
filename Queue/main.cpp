#include <iostream>
#include "GenQueue.h"

using namespace std;

int main(int argc, char** argv)
{
	GenQueue<int> q(4);
	q.insert(1);
	q.insert(2);
	q.insert(3);
	q.insert(4);
	cout << "Remove head:" << q.remove() << endl;
	q.insert(5);
	cout << "Emptying List:" << endl;
	while(!q.isEmpty())
	{
		cout << q.remove() << endl;
	}
}
