#include <iostream>
#include "Person.h"
using namespace std;

/**
Returns the id
@return int Id
*/
int Person::getId()
{
	return m_id;
}

/**
Sets the id to some value
@param id Id
*/
void Person::setId(int id)
{
	m_id = id;
}

/**
Returns the name
@return string Name
*/
string Person::getName()
{
	return m_name;
}

/**
Sets the name to some value
@param name Name
*/
void Person::setName(string name)
{
	m_name = name;
}

/**
Returns the level
@return string Level
*/
string Person::getLevel()
{
	return m_level;
}

/**
Sets the level to some value
@param level Level
*/
void Person::setLevel(string level)
{
	m_level = level;
}
