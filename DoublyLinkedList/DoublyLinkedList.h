#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class DoublyLinkedList
{
private:
	ListNode<T> *front;
	ListNode<T> *back;
	unsigned int size;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	T getFront();
	void insertFront(T data);
	void insertBack(T data);
	T removeFront();
	T removeBack();
	ListNode<T>* remove(T key);
	T deletePos(int pos);
	void printList();
	int find(T val);
	bool isEmpty();
	unsigned int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	size = 0;
	front = NULL;
	back = NULL;
}

//research
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <class T>
T DoublyLinkedList<T>::getFront()
{
	return front->data;
}

template <class T>
void DoublyLinkedList<T>::insertFront(T data)
{
	ListNode<T> *node = new ListNode<T>(data);
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

template <class T>
void DoublyLinkedList<T>::insertBack(T data)
{
	ListNode<T> *node = new ListNode<T>(data);
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

template <class T>
T DoublyLinkedList<T>::removeFront()
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

template <class T>
T DoublyLinkedList<T>::removeBack()
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

template <class T>
ListNode<T>* DoublyLinkedList<T>::remove(T key)
{
	ListNode<T> *current = front;

	while(current->data != key)
	{
		current = current->next;
		if(current == NULL)
		{
			return NULL;
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
	return current;
}

template <class T>
T DoublyLinkedList<T>::deletePos(int pos)
{
	if(pos == 0)
	{
		return removeFront();
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

template <class T>
void DoublyLinkedList<T>::printList()
{
	ListNode<T> *current = front;
	while(current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
}

template <class T>
int DoublyLinkedList<T>::find(T val)
{
	int idx = -1;
	ListNode<T> *current = front;
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

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
	return (size == 0);
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
	return size;
}
