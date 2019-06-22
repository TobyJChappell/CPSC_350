#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <fstream>
#include "DLL.h"
#include "Person.h"
#include "Student.h"
using namespace std;

class Faculty : public Person
{
private:
	string m_department = "";
	DLL<Student>* m_advisees = new DLL<Student>;
public:
	Faculty();
	Faculty(int id, string name, string level, string department);
	string getDepartment();
	void setDepartment(string department);
	Student getAdvisee(int pos);
	void removeFirstAdvisee();
	void removeAdvisee(int studentId);
	void insertAdvisee(int studentId, Student student);
	bool containsAdvisee(int studentId);
	int findAdvisee(int studentId);
	int getNumAdvisees();
	void printInfo();
	void displayAdviseesIds();
	void load(ifstream& inf);
	void save(ofstream& of);
};

#endif
