#include <iostream>

using namespace std;

template <class T>
class ListNode
{
public:
	ListNode();
	ListNode(int k, T d);
	~ListNode();
	T data;
	int key;
	ListNode *next;
	ListNode *prev;
};

/**
Default constructor
*/
template <class T>
ListNode<T>::ListNode()
{
	key = 0;
	data = NULL;
	next = NULL;
	prev = NULL;
}

/**
Overloaded constructor
@param d Data of node
*/
template <class T>
ListNode<T>::ListNode(int k, T d)
{
	key = k;
	data = d;
	next = NULL;
	prev = NULL;
}

/**
Destructor
*/
template <class T>
ListNode<T>::~ListNode()
{
	delete next;
	delete prev;
}
