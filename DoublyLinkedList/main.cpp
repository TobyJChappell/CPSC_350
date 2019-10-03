#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main(int argc, char** argv)
{
	DoublyLinkedList<int> ll;
	ll.insertFront(1);
	ll.insertFront(2);
	ll.insertFront(3);
	ll.insertFront(4);
	cout << "List:" << endl;
	ll.printList();
	cout << "Insert 5 (front):" << endl;
	ll.insertFront(5);
	ll.printList();
	cout << "Insert 0 (back):" << endl;
	ll.insertBack(0);
	ll.printList();
	cout << "Delete 3:" << endl;
	int pos = ll.find(3);
	cout << pos << endl;
	ll.deletePos(pos);
	ll.printList();
	cout << "Empty list elements from back:" << endl;
	while(!ll.isEmpty())
	{
		cout << ll.removeBack() << endl;
	}
}
