#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include "Person.h"
using namespace std;

class Student : public Person
{
private:
	string m_major = "";
	double m_gpa = 0.0;
	int m_advisor = 0;
public:
	Student();
	Student(int id, string name, string level, string major, double gpa, int advisor);
	string getMajor();
	void setMajor(string major);
	double getGpa();
	void setGpa(double gpa);
	int getAdvisor();
	void setAdvisor(int advisor);
	void printInfo();
	void load(ifstream& inf);
	void save(ofstream& of);
};

#endif
