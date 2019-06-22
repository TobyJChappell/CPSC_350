#include <iostream>

using namespace std;

class Delimiter
{
private:
	string m_file;
	int line;
public:
	Delimiter(string file);
	void setFile(string file);
	string checkFile(string file);
	char getOpening(char d);
	char getClosing(char d);
	void checkSingleQuotes(ifstream& file);
	void checkDoubleQuotes(ifstream& file);
	void checkInlineComments(ifstream& file);
	void checkBlockComments(ifstream& file);
	void checkDelimiters();
};
