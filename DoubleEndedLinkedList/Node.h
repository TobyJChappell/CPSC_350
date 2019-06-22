#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;
//organize files
class Node
{
public:
	Node();
	Node(int d);
	~Node();
	int data;
	Node *next;
};

#endif
