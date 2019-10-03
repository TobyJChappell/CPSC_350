#include <iostream>
using namespace std;

class Vertex
{
public:
	string label;
	boolean wasVisited;
	Vertex(String l);
};

Vertex::Vertex(String l)
{
	label = l;
	wasVisited = false;
}
