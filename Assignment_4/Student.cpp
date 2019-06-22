#include <iostream>
#include "Student.h"

using namespace std;

/**
Default constructor
*/
Student::Student()
{
	entryTime = 0;
	timeNeeded = 0;
	waitTime = 0;
}

/**
Overloaded constructor
@param et Entry time
@param tn Time needed
*/
Student::Student(int et, int tn)
{
	entryTime = et;
	timeNeeded = tn;
	waitTime = 0;
}

/**
Returns the entry time of the student
@return int
*/
int Student::getEntryTime()
{
	return entryTime;
}

/**
Sets the entry time of a student to some value
@param et Entry time
*/
void Student::setEntryTime(int et)
{
	entryTime = et;
}

/**
Returns the time needed for the student
@return int
*/
int Student::getTimeNeeded()
{
	return timeNeeded;
}

/**
Sets the time needed for a student to some value
@param tn Time needed
*/
void Student::setTimeNeeded(int tn)
{
	timeNeeded = tn;
}

/**
Returns the time a student waited for
@return int
*/
int Student::getWaitTime()
{
	return waitTime;
}

/**
Decrements the time needed by 1
*/
void Student::decrementTimeNeeded()
{
	timeNeeded--;
}

/**
Increments the time waited by 1
*/
void Student::incrementWaitTime()
{
	waitTime++;
}

/**
Decrements the time waited by 1
*/
void Student::decrementWaitTime()
{
	waitTime--;
}
