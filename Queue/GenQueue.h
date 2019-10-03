#include <iostream>

using namespace std;

template <class T>
class GenQueue
{
private:
	int mSize;
	int head;
	int tail;
	int numElements;
	T *myGenQueue;
public:
	GenQueue();
	GenQueue(int maxsize);
	~GenQueue();

	void insert(T d);//enGenQueue
	T remove();//deGenQueue
	T front();

	bool isFull();
	bool isEmpty();
	int getSize();
};

/**
Default constructor
*/
template <class T>
GenQueue<T>::GenQueue()
{
	myGenQueue = new T[128];
	mSize = 128;
	numElements = 0;
	head = 0;
	tail = -1;
}

/**
Overloaded constructor
@param maxSize Size of the GenQueue
*/
template <class T>
GenQueue<T>::GenQueue(int maxSize)
{
	myGenQueue = new T[maxSize];
	mSize = maxSize;
	numElements = 0;
	head = 0;
	tail = -1;
}

/**
Destructor
*/
template <class T>
GenQueue<T>::~GenQueue()
{
	delete [] myGenQueue;
}

/**
Inserts an element to the back of the GenQueue
@param d The element being inserted
*/
template <class T>
void GenQueue<T>::insert(T d)
{
	if(!isFull())
	{
		if(tail == mSize - 1)
		{
			tail = -1;
		}
		myGenQueue[++tail] = d;
		++numElements;
	}
	else
	{
		cerr << "ERROR: GenQueue is full" << endl;
		exit(EXIT_FAILURE);
	}
}

/**
Removes the front element of the GenQueue
@return T The front element
*/
template <class T>
T GenQueue<T>::remove()
{
	T c = '\0';
	if(!isEmpty())
	{
		c = myGenQueue[head];
		++head;
		if(head == mSize)
		{
			head = 0;
		}
		numElements--;
	}
	return c;
}

/**
Returns the element at the front of the GenQueue
@return T The element at the front
*/
template <class T>
T GenQueue<T>::front()
{
	return myGenQueue[head];
}

/**
Returns whether a GenQueue is full
@return bool True if the GenQueue is full
*/
template <class T>
bool GenQueue<T>::isFull()
{
	return (numElements == mSize);
}

/**
Returns whether the GenQueue is empty
@return bool True if it is empty
*/
template <class T>
bool GenQueue<T>::isEmpty()
{
	return (numElements == 0);
}

/**
Returns the size the number of elements in the GenQueue
*/
template <class T>
int GenQueue<T>::getSize()
{
	return numElements;
}
