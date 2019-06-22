#include <iostream>

template <class T>
class GenStack
{
private:
	int size;
	int top;
	T *myArray;
public:
	GenStack();//constructor
	GenStack(int maxSize);//overloaded constructor
	~GenStack();//destructor

	void push(T d);
	T pop();
	T peek();

	bool isFull();
	bool isEmpty();
};

/**
Default constructor
*/
template <class T>
GenStack<T>::GenStack()
{
	myArray = new T[128];
	size = 128;
	top = -1;
}

/**
Overloaded constructore
@param maxSize Size of the stack
*/
template <class T>
GenStack<T>::GenStack(int maxSize)
{
	myArray = new char[maxSize];
	size = maxSize;
	top = -1;
}

/**
Destructor
*/
template <class T>
GenStack<T>::~GenStack()
{
	delete [] myArray;
}

/**
Inserts an object into the stack
@param d Object being pushed
*/
template <class T>
void GenStack<T>::push(T d)
{
	if(isFull())
	{
		cerr << "ERROR: Stack is full" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		myArray[++top] = d;
	}
}

/**
Returns and removes the top element of the stack
@return T First object of stack
*/
template <class T>
T GenStack<T>::pop()
{
	if(isEmpty())
	{
		cerr << "ERROR: Stack is empty" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		return myArray[top--];
	}
}

/**
Returns the top object of the stack
@return T Top object
*/
template <class T>
T GenStack<T>::peek()
{
	if(isEmpty())
	{
		cerr << "ERROR: Stack is empty" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		return myArray[top];
	}
}

/**
Returns whether or not the stack is full
@return bool True if stack is full
*/
template <class T>
bool GenStack<T>::isFull()
{
	return (top == size - 1);
}

/**
Returns whether or not the stack is empty
@return bool True if stack is empty
*/
template <class T>
bool GenStack<T>::isEmpty()
{
	return (top == -1);
}
