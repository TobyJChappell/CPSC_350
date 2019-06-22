#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person
{
protected:
	int m_id = 0;
	string m_name = "";
	string m_level = "";
public:
	int getId();
	void setId(int id);
	string getName();
	void setName(string name);
	string getLevel();
	void setLevel(string level);
};

#endif
