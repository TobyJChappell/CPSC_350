#include <iostream>
#include "Window.h"

using namespace std;

/**
Default constructor
*/
Window::Window()
{
	idleTime = 0;
}

/**
Empty window constructor takes in clockTick when it became empty (important to know because if the window is empty the entire program than it will have a value of 1 more than it is supposed to have)
@param et Clocktick
*/
Window::Window(int et)
{
	idleTime = 0;
	setEntryTime(et);
}

/**
Filled window constructor takes in a Student as a parameter to know how long that student needs
@param s A student
*/
Window::Window(Student s)
{
	setTimeNeeded(s.getTimeNeeded());
}

/**
Returns how long a window has been idle for
@return idleTime The time it has been idle for
*/
int Window::getIdleTime()
{
	return idleTime;
}

/**
Increments idle time by 1
*/
void Window::incrementIdleTime()
{
	idleTime++;
}

/**
Decrements idle time by 1
*/
void Window::decrementIdleTime()
{
	idleTime--;
}
