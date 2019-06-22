#include <iostream>

using namespace std;

class InputHandler
{
private:
	void loadArray();
	bool checkNum(string s);
	string checkFile(string file);
	string m_file;
public:
	double* array;
	int size;
	InputHandler();
	InputHandler(string file);
	~InputHandler();
};
