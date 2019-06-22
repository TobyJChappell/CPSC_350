#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList
{
private:
	Node *front;
	Node *back;
	unsigned int size;
public:
	LinkedList();
	~LinkedList();
	void insertFront(int data);
	int removeFront();
	int deletePos(int pos);
	void printList();
	int find(int val);
	bool isEmpty();
	unsigned int getSize();
};

#endif
