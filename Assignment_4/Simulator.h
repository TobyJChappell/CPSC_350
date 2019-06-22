#include <iostream>
#include <fstream>
#include "GenQueue.h"
#include "DoublyLinkedList.h"
#include "Student.h"
#include "Window.h"

using namespace std;

class Simulator
{
private:
	string filename; //name of the input file
	int numWindows = 0;
	double meanWait = 0;
	double medianWait = 0;
	int longestWait = 0;
	int waitTen = 0;
	double meanIdle = 0;
	int longestIdle = 0;
	int idleFive = 0;
	GenQueue<Student> studentQueue; //Queue of all students in the simulation
	DoublyLinkedList<Student> waitQueue; //Students enter this list during the appropriate clockTick
	DoublyLinkedList<Window> filledWindows; //Windows that are currently occupied by a student
	DoublyLinkedList<Window> emptyWindows; //Windows that are currently idle
	GenQueue<int> waitTimes; //List of how long each student waited for
	GenQueue<int> idleTimes; //List of how long each window was idle for
public:
	Simulator(string file);
	string checkFile(string file);
	void readFile();
	int getNum(ifstream& file);
	void simulate();
	void calcStats();
	void outStats();
};
