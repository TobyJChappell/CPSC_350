#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

template <class T>
class GenQueue
{
private:
	DoublyLinkedList<T> myGenQueue;
public:
	void insert(T d);
	T remove();
	T front();
	bool isEmpty();
	int getSize();
};

/**
Inserts an element to the back of the GenQueue
@param d The element being inserted
*/
template <class T>
void GenQueue<T>::insert(T d)
{
	myGenQueue.insertBack(d);
}

/**
Removes the front element of the GenQueue
@return T The front element
*/
template <class T>
T GenQueue<T>::remove()
{
	return myGenQueue.removeFront();
}

/**
Returns the element at the front of the GenQueue
@return T The element at the front
*/
template <class T>
T GenQueue<T>::front()
{
	return myGenQueue.getFront();
}

/**
Returns whether the GenQueue is empty
@return bool True if it is empty
*/
template <class T>
bool GenQueue<T>::isEmpty()
{
	return myGenQueue.isEmpty();
}

/**
Returns the size the number of elements in the GenQueue
*/
template <class T>
int GenQueue<T>::getSize()
{
	return myGenQueue.getSize();
}
