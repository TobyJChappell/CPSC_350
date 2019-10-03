#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char** argv)
{
	LinkedList ll;
	ll.insertFront(1);
	ll.insertFront(2);
	ll.insertFront(3);
	ll.insertFront(4);
	cout << "List: ";
	ll.printList();
	cout << "Insert 5: ";
	ll.insertFront(5);
	ll.printList();
	cout << "Delete 3: ";
	ll.deletePos(ll.find(3));
	ll.printList();
	cout << "Empty list elements from front:" << endl;
	while(!ll.isEmpty())
	{
		cout << ll.removeFront() << endl;
	}
}
