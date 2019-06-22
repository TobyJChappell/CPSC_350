#include <iostream>
#include <cstring>
#include <fstream>
#include "Student.h"
using namespace std;

/**
Constructor
*/
Student::Student()
{
	m_id = 0;
	m_name = "";
	m_level = "";
	m_major = "";
	m_gpa = 0.0;
	m_advisor = 0;
}

/**
Overloaded Constructor
*/
Student::Student(int id, string name, string level, string major, double gpa, int advisor)
{
	m_id = id;
	m_name = name;
	m_level = level;
	m_major = major;
	m_gpa = gpa;
	m_advisor = advisor;
}

/**
Returns the major
@return string Major
*/
string Student::getMajor()
{
	return m_major;
}

/**
Sets the major to some value
@param major Major
*/
void Student::setMajor(string major)
{
	m_major = major;
}

/**
Returns the gpa
@return double Gpa
*/
double Student::getGpa()
{
	return m_gpa;
}

/**
Sets the gpa to some value
@param gpa Gpa
*/
void Student::setGpa(double gpa)
{
	m_gpa = gpa;
}

/**
Returns the advisor
@return int Advisor
*/
int Student::getAdvisor()
{
	return m_advisor;
}

/**
Sets the advisor to some value
@param advisor Advisor
*/
void Student::setAdvisor(int advisor)
{
	m_advisor = advisor;
}

/**
Prints the info of a student
*/
void Student::printInfo()
{
	cout << "ID: " << m_id << endl;
	cout << "NAME: " << m_name << endl;
	cout << "LEVEL: " << m_level << endl;
	cout << "MAJOR: " << m_major << endl;
	cout << "GPA: " << m_gpa << endl;
	cout << "ADVISOR ID: " << m_advisor << endl;
	cout << endl;
}

/**
Loads student from studentTable
@param inf File being read
*/
void Student::load(ifstream& inf)
{
  inf.read((char *)&m_id, sizeof(m_id));
	getline(inf, m_name,'\0');
	getline(inf, m_level,'\0');
	getline(inf, m_major,'\0');
	inf.read((char *)&m_gpa, sizeof(m_gpa));
	inf.read((char *)&m_advisor, sizeof(m_advisor));
}

/**
Saves student to studentTable
@param of File being outputted to
*/
void Student::save(ofstream& of)
{
	of.write((char *)&m_id, sizeof(m_id));
	of.write(m_name.c_str(), m_name.size());
	of.write("\0", sizeof(char));
	of.write(m_level.c_str(), m_level.size());
	of.write("\0", sizeof(char));
	of.write(m_major.c_str(), m_major.size());
	of.write("\0", sizeof(char));
	of.write((char *)&m_gpa, sizeof(m_gpa));
	of.write((char *)&m_advisor, sizeof(m_advisor));
}
