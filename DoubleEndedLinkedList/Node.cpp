#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{
	//implement
}

Node::Node(int d)
{
	data = d;
	next = NULL;
}

Node::~Node()
{
	delete next;
}
