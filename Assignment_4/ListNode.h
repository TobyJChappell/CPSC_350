#include <iostream>

using namespace std;

template <class T>
class ListNode
{
public:
	ListNode();
	ListNode(T d);
	~ListNode();
	T data;
	ListNode *next;
	ListNode *prev;
};

/**
Default constructor
*/
template <class T>
ListNode<T>::ListNode()
{
	data = NULL;
	next = NULL;
	prev = NULL;
}

/**
Overloaded constructor
@param d Data of node
*/
template <class T>
ListNode<T>::ListNode(T d)
{
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
