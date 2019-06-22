#include <iostream>
#include <fstream>
#include <algorithm>
#include "Simulator.h"

using namespace std;

/**
Simulator constructor takes in a filename as an argument, checks if the file is valid, and then reads the file.
@param file A filename
*/
Simulator::Simulator(string file)
{
	filename = checkFile(file);
	readFile();
}

/**
Checks if a file is valid, if not, the user is prompted to enter a valid file
@param file A filename
@return string A valid filename
*/
string Simulator::checkFile(string file)
{
	ifstream test;
	test.open(file);
	while(!test){
		cout << endl;
		cout << "Please enter a valid file path:" << endl;
		cin >> file;
		test.open(file);
	}
	return file;
}

/**
Reads a valid file and inputs it correctly into the studentQueue
*/
void Simulator::readFile()
{
	ifstream file(filename);
	int clockTick = 0;
	int numStudents = 0;
	string line;
	if(file.is_open())
  {
		numWindows = getNum(file);
		if(numWindows == 0)
		{
			cerr << "\nERROR: Number of windows must be greater than 0.\n" << endl;
			exit(EXIT_FAILURE);
		}
    while(getline(file, line))
    {
			while(line.length() == 0)
			{
				getline(file, line);
			}
			try
			{
				clockTick = stoi(line);
			}
			catch(exception& err)
			{
				cerr << "\nERROR: All inputs must be numbers.\n" << endl;
				exit(EXIT_FAILURE);
			}
			numStudents = getNum(file);
			for(int x = 0; x < numStudents; x++)
			{
				studentQueue.insert(Student(clockTick, getNum(file)));
			}
    }
		file.close();
	}
}

/**
Returns a number from the file if it is valid
@param file The file being read
@return int A valid number
*/
int Simulator::getNum(ifstream& file)
{
	string line;
	if(file.is_open())
	{
		if(getline(file, line))
		{
			while(line.length() == 0)
			{
				getline(file, line);
			}
			try
			{
				return stoi(line);
			}
			catch(exception& err)
			{
				cerr << "\nERROR: All inputs must be numbers.\n" << endl;
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			cerr << "\nERROR: Invalid input file.\n" << endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << "\nERROR: File is not open.\n" << endl;
		exit(EXIT_FAILURE);
	}
}

/**
Simulates the program
*/
void Simulator::simulate()
{
	int windowsFilled = 0;
	int clockTick = 0;
	for(int x = 0; x < numWindows; x++)
	{
		emptyWindows.insertBack(Window(clockTick));
	}
	while(!(studentQueue.isEmpty() && waitQueue.isEmpty() && filledWindows.isEmpty()))
	{
		while(!studentQueue.isEmpty() && studentQueue.front().getEntryTime() == clockTick)
		{
			waitQueue.insertBack(studentQueue.remove());
		}
		while(!waitQueue.isEmpty() && windowsFilled < numWindows)
		{
			waitTimes.insert(waitQueue.getFront().getWaitTime());
			filledWindows.insertBack(Window(waitQueue.removeFront()));
			idleTimes.insert(emptyWindows.removeFront().getIdleTime());
			windowsFilled++;
		}
		for(int x = 0; x < filledWindows.getSize(); x++)
		{
			filledWindows.get(x).decrementTimeNeeded();
			if(filledWindows.get(x).getTimeNeeded() <= 0)
			{
				filledWindows.deletePos(x);
				windowsFilled--;
				emptyWindows.insertBack(Window(clockTick));
				emptyWindows.getBack().decrementIdleTime();
				x--;
			}
		}
		for(int x = 0; x < waitQueue.getSize(); x++)
		{
			waitQueue.get(x).incrementWaitTime();
		}
		for(int x = 0; x < emptyWindows.getSize(); x++)
		{
			emptyWindows.get(x).incrementIdleTime();
		}
		clockTick++;
	}
	while(!emptyWindows.isEmpty())
	{
		if(emptyWindows.getFront().getEntryTime() != 0)
		{
			idleTimes.insert(emptyWindows.removeFront().getIdleTime());
		}
		else
		{
			idleTimes.insert(emptyWindows.removeFront().getIdleTime() - 1);
		}
	}
	calcStats();
	outStats();
}

/**
Calculates the statistics based on waitTimes and idleTimes. If a wait or idle is equal to 0, it is ignored since the student didn't actually wait/the window wasn't actually idle.
*/
void Simulator::calcStats()
{
	int wait;
	double sum = 0;
	int size = waitTimes.getSize();
	GenQueue<int> temp;
	while(!waitTimes.isEmpty())
	{
		wait = waitTimes.front();
		cout << "WAIT: " << wait << endl;
		if(wait > 0)
		{
			if(wait > longestWait)
			{
				longestWait = wait;
			}
			if(wait >= 10)
			{
				waitTen++;
			}
			temp.insert(waitTimes.front());
		}
		else
		{
			size--;
		}
		sum += waitTimes.remove();
	}
	if(size > 0)
	{
		double waits[size];
		for(int x = 0; x < size; x++)
		{
			waits[x] = temp.remove();
		}
		meanWait = sum/size;
		sort(waits, waits+size);
		if(size % 2 == 0)
		{
			medianWait = (waits[size/2] + waits[size/2 - 1])/2;
		}
		else
		{
			medianWait = waits[size/2];
		}
	}
	int idle;
	sum = 0;
	size = idleTimes.getSize();
	while(!idleTimes.isEmpty())
	{
		idle = idleTimes.front();
		cout << "IDLE: " << idle << endl;
		if(idle > 0)
		{
			if(idle > longestIdle)
			{
				longestIdle = idle;
			}
			if(idle >= 5)
			{
				idleFive++;
			}
		}
		else
		{
			size--;
		}
		sum += idleTimes.remove();
	}
	if(size != 0)
	{
		meanIdle = sum/size;
	}
}

/**
Outputs the statistics calculated
*/
void Simulator::outStats()
{
	cout << "1. The mean student wait time: " << meanWait << " min" << endl;
	cout << "2. The median student wait time: " << medianWait << " min" << endl;
	cout << "3. The longest student wait time: " << longestWait << " min" << endl;
	cout << "4. The number of students waiting over 10 minutes: " << waitTen << " students" << endl;
	cout << "5. The mean window idle time: " << meanIdle << " min" << endl;
	cout << "6. The longest window idle time: " << longestIdle << " min" << endl;
	cout << "7. Number of windows idle for over 5 minutes: " << idleFive << " windows\n" << endl;
}
