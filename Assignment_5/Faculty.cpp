#include <iostream>
#include <cstring>
#include <fstream>
#include "Faculty.h"
using namespace std;

/**
Constructor
*/
Faculty::Faculty()
{
	m_id = 0;
	m_name = "";
	m_level = "";
	m_department = "";
}

/**
Overloaded Constructor
*/
Faculty::Faculty(int id, string name, string level, string department)
{
	m_id = id;
	m_name = name;
	m_level = level;
	m_department = department;
}

/**
Returns the department
@return string Department
*/
string Faculty::getDepartment()
{
	return m_department;
}

/**
Sets the department to a string
@param department A department
*/
void Faculty::setDepartment(string department)
{
	m_department = department;
}

/**
Returns an advisee given a position
@param pos Position of the advisee
@return Student Advisee at the position
*/
Student Faculty::getAdvisee(int pos)
{
	return m_advisees->get(pos);
}

/**
Removes an advisee from the faculty member
@param studentId The student's id being removed
*/
void Faculty::removeFirstAdvisee()
{
	m_advisees->removeFront();
}

/**
Removes an advisee from the faculty member
@param studentId The student's id being removed
*/
void Faculty::removeAdvisee(int studentId)
{
	m_advisees->remove(studentId);
}

/**
Inserts an advisee to the faculty member
@param studentId The student's id number
@param student Student being inserted
*/
void Faculty::insertAdvisee(int studentId, Student student)
{
	m_advisees->insert(studentId, student);
}

/**
Determines if a faculty member contains a advisee
@param studentId The student's id number
@param student Student being checked
*/
bool Faculty::containsAdvisee(int studentId)
{
	return m_advisees->contains(studentId);
}

/**
Finds a student in the list
@param studentId Student's id being searched for
@return int Position of student
*/
int Faculty::findAdvisee(int studentId)
{
	return m_advisees->find(studentId);
}

/**
Returns the number of advisees
@return int Number of advisees
*/
int Faculty::getNumAdvisees()
{
	return m_advisees->getSize();
}

/**
Prints the faculty info
*/
void Faculty::printInfo()
{
	cout << "ID: " << m_id << endl;
	cout << "NAME: " << m_name << endl;
	cout << "LEVEL: " << m_level << endl;
	cout << "DEPARTMENT: " << m_department << endl;
	cout << endl;
}

/**
Prints the ids of a faculty's advisees
@param faculty A faculty member
*/
void Faculty::displayAdviseesIds()
{
	for(int x = 0; x < m_advisees->getSize() - 1; x++)
	{
		cout << m_advisees->get(x).getId() << " ";
	}
	cout << m_advisees->get(m_advisees->getSize() - 1).getId();
}

/**
Loads faculty member from facultyTable
@param inf File being read
*/
void Faculty::load(ifstream& inf)
{
	int size = 0;
  inf.read((char *)&m_id, sizeof(m_id));
	getline(inf, m_name,'\0');
	getline(inf, m_level,'\0');
	getline(inf, m_department,'\0');
	inf.read((char *)&size, sizeof(size));
	for(int x = 0; x < size; x++)
	{
		Student s1;
		s1.load(inf);
		m_advisees->insert(s1.getId(), s1);
	}
}

/**
Saves faculty member to facultyTable
@param of File being outputted to
*/
void Faculty::save(ofstream& of)
{
	int size = m_advisees->getSize();
	of.write((char *)&m_id, sizeof(m_id));
	of.write(m_name.c_str(), m_name.size());
	of.write("\0", sizeof(char));
	of.write(m_level.c_str(), m_level.size());
	of.write("\0", sizeof(char));
	of.write(m_department.c_str(), m_department.size());
	of.write("\0", sizeof(char));
	of.write((char *)&size, sizeof(size));
	while(!m_advisees->isEmpty())
	{
		m_advisees->removeFront().save(of);
	}
}
