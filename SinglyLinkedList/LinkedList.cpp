#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
	size = 0;
	front = NULL;
	back = NULL;
}

LinkedList::~LinkedList()
{
	Node *current = front;
	while(current != NULL)
	{
		Node *next = current->next;
		delete current;
		current = next;
	}
	front = NULL;
	delete front;
}

void LinkedList::insertFront(int data)
{
	++size;
	Node *node = new Node(data);
	node->next = front;
	front = node;
}

int LinkedList::removeFront()
{
	--size;
	int temp = front->data;
	Node *ft = front;
	front = front->next;
	ft->next = NULL;
	delete ft;
	return temp;
}

int LinkedList::deletePos(int pos)
{
	if(pos == 0)
	{
		return removeFront();
	}
	int idx = 0;
	Node *current = front;
	Node *previous = front;
	while(idx != pos)
	{
		previous = current;
		current = current->next;
		++idx;
	}
	--size;
	int temp = current->data;
	previous->next = current->next;
	current->next = NULL;
	delete current;
	return temp;
}

void LinkedList::printList()
{
	Node *current = front;
	while(current)
	{
		cout << current->data << " ";//endl
		current = current->next;
	}
	cout << endl;//remove
}

int LinkedList::find(int val)
{
	int idx = -1;
	Node *current = front;
	while(current != NULL)
	{
		++idx;
		if(current->data == val)
		{
			break;
		}
		current = current->next;
	}
	if(current == NULL)
	{
		return -1;
	}
	return idx;
}

bool LinkedList::isEmpty()
{
	return (size == 0);
}

unsigned int LinkedList::getSize()
{
	return size;
}
