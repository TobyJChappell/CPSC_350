#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student
{
private:
	int entryTime;
	int timeNeeded;
	int waitTime;
public:
	Student();
	Student(int et, int tn);
	int getEntryTime();
	void setEntryTime(int et);
	int getTimeNeeded();
	void setTimeNeeded(int tn);
	int getWaitTime();
	void incrementWaitTime();
	void decrementWaitTime();
	void decrementTimeNeeded();
};

#endif
