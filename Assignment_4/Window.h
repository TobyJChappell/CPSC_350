#include <iostream>
#include "Student.h"

using namespace std;

class Window: public Student
{
private:
	int idleTime;
public:
	Window();
	Window(int et);
	Window(Student s);
	int getIdleTime();
	void incrementIdleTime();
	void decrementIdleTime();
};
