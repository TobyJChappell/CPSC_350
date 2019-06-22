#ifndef DLL_H
#define DLL_H

#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class DLL
{
private:
	ListNode<T> *front;
	ListNode<T> *back;
	unsigned int size;
public:
	DLL();
	~DLL();
	T& getFront();
	T& getBack();
	T& get(int pos);
	bool contains(int key);
	void insertFront(int key, T data);
	void insert(int key, T data);
	void insertBack(int key, T data);
	T removeFront();
	T removeBack();
	T remove(int key);
	T deletePos(int pos);
	void printList();
	int find(int key);
	bool isEmpty();
	unsigned int getSize();
};

/**
Default constructor
*/
template <class T>
DLL<T>::DLL()
{
	size = 0;
	front = NULL;
	back = NULL;
}

/**
Destructor
*/
template <class T>
DLL<T>::~DLL()
{
	while(!isEmpty())
	{
		removeFront();
	}
	delete front;
	delete back;
}

/**
Returns the first node
@return T& The data of the first node
*/
template <class T>
T& DLL<T>::getFront()
{
	return front->data;
}

/**
Returns the last node
@return T& The data of the last node
*/
template <class T>
T& DLL<T>::getBack()
{
	return back->data;
}

/**
Returns the node at some postition
@param pos Position being searched for
@return T& The data of the node
*/
template <class T>
T& DLL<T>::get(int pos)
{
	if(pos == 0)
	{
		return getFront();
	}
	else if(pos == size - 1)
	{
		return getBack();
	}
	if(pos >= size || pos < 0)
	{
		cerr << "ERROR: Invalid position entered." << endl;
		exit(EXIT_FAILURE);
	}
	int idx = 0;
	ListNode<T> *current = front;
	ListNode<T> *previous = front;
	while(idx != pos)
	{
		previous = current;
		current = current->next;
		++idx;
	}
	return current->data;
}

/**
Determines if a doublylinked list contains a key
@param key Key being searched for
@return bool True if key is found
*/
template <class T>
bool DLL<T>::contains(int key)
{
	ListNode<T> *current = front;
	while(current != NULL)
	{
		if(current->key == key)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}

/**
Inserts a node to the front of the list
@param data Value being inserted
*/
template <class T>
void DLL<T>::insertFront(int key, T data)
{
	ListNode<T> *node = new ListNode<T>(key, data);
	if(size == 0)
	{
		back = node;
	}
	else
	{
		node->next = front;
		front->prev = node;
	}
	front = node;
	size++;
}

/**
Inserts a node to the list based on its key
@param data Value being inserted
*/
template <class T>
void DLL<T>::insert(int key, T data)
{
	if(size == 0)
	{
		insertFront(key, data);
		return;
	}
	ListNode<T> *current = front;

	while(current->key < key)
	{
		current = current->next;
		if(current == NULL)
		{
			insertBack(key, data);
			return;
		}
	}
	if(current == front)
	{
		insertFront(key, data);
		return;
	}
	ListNode<T> *node = new ListNode<T>(key, data);
	node->next = current;
	node->prev = current->prev;
	current->prev = node;
	current->prev->prev->next = node;

	size++;
}

/**
Inserts a node into the back of the list
@param data Value being inserted
*/
template <class T>
void DLL<T>::insertBack(int key, T data)
{
	ListNode<T> *node = new ListNode<T>(key, data);
	if(size == 0)
	{
		front = node;
	}
	else
	{
		back->next = node;
		node->prev = back;
	}
	back = node;
	size++;
}

/**
Removes the front node from the list
@return T value of the node
*/
template <class T>
T DLL<T>::removeFront()
{
	if(size == 0)
	{
		cerr << "ERROR: Doubly Linked List is empty." << endl;
		exit(EXIT_FAILURE);
	}
	ListNode<T> *node = front;
	if(front->next == NULL)
	{
		back = NULL;
	}
	else
	{
		front->next->prev = NULL;
	}
	front = front->next;
	T temp = node->data;
	node->next = NULL;

	delete node;
	size--;

	return temp;
}

/**
Removes the last node from the list
@return T Value of the node
*/
template <class T>
T DLL<T>::removeBack()
{
	if(size == 0)
	{
		cerr << "ERROR: Doubly Linked List is empty." << endl;
		exit(EXIT_FAILURE);
	}
	ListNode<T> *node = back;
	if(back->prev == NULL)
	{
		front = NULL;
	}
	else
	{
		back->prev->next = NULL;
	}
	back = back->prev;
	T temp = node->data;
	node->prev = NULL;

	delete node;
	size--;

	return temp;
}

/**
Removes the first element with some value
@param key Value being deleted
@return ListNode<T>* Node that was deleted
*/
template <class T>
T DLL<T>::remove(int key)
{
	ListNode<T> *current = front;

	while(current->key != key)
	{
		current = current->next;
		if(current == NULL)
		{
			T obj;
			return obj;
		}
	}
	if(current == front)
	{
		front = current->next;
	}
	else
	{
		current->prev->next = current->next;
	}

	if(current == back)
	{
		back = current->prev;
	}
	else
	{
		current->next->prev = current->prev;
	}
	current->next = NULL;
	current->prev = NULL;

	size--;
	return current->data;
}

/**
Removes a node as some position
@param pos Index of node
@return T Value of deleted node
*/
template <class T>
T DLL<T>::deletePos(int pos)
{
	if(pos == 0)
	{
		return removeFront();
	}
	else if(pos == size - 1)
	{
		return removeBack();
	}
	int idx = 0;
	ListNode<T> *current = front;
	ListNode<T> *previous = front;
	while(idx != pos)
	{
		previous = current;
		current = current->next;
		++idx;
	}
	--size;
	T temp = current->data;
	previous->next = current->next;
	current->next->prev = previous;
	current->next = NULL;
	current->prev = NULL;
	delete current;
	return temp;
}

/**
Prints the values of the list
*/
template <class T>
void DLL<T>::printList()
{
	ListNode<T> *current = front;
	while(current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
}

/**
Returns the index of a node with some value
@param T Value of the node
@return int Index of node
*/
template <class T>
int DLL<T>::find(int key)
{
	int idx = -1;
	ListNode<T> *current = front;
	while(current != NULL)
	{
		++idx;
		if(current->key == key)
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

/**
Returns whether the list is empty
@return bool True if list is empty
*/
template <class T>
bool DLL<T>::isEmpty()
{
	return (size == 0);
}

/**
Returns the size of the list
*/
template <class T>
unsigned int DLL<T>::getSize()
{
	return size;
}

#endif
