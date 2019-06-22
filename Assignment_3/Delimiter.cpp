#include <iostream>
#include <fstream>
#include "Delimiter.h"
#include "GenStack.h"

using namespace std;

/**
Delimiter constructor
@param file Name of a file
*/
Delimiter::Delimiter(string file)
{
	m_file = checkFile(file);
	line = 1;
}

/**
Sets the file to a name and checks to see if it is invalid
@param file A file name
*/
void Delimiter::setFile(string file)
{
	m_file = checkFile(file);
	line = 1;
}

/**
Checks to see if a file is valid and prompts the user to enter a valid file until one is inputted
@param file A file name
@return string A valid file path
*/
string Delimiter::checkFile(string file)
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
Returns the opening bracket of a delimiter
@return char opening delimiter
@param d A closing delimiter
*/
char Delimiter::getOpening(char d)
{
	if(d == '}')
	{
		return '{';
	}
	else if(d == ')')
	{
		return '(';
	}
	else if(d == ']')
	{
		return '[';
	}
	cerr << "ERROR: Only closing delimiters can be used for getOpening()." << endl;
	exit(EXIT_FAILURE);
}

/**
Returns the closing bracket of a delimiter
@return char Closing delimiter
@param d An opening delimiter
*/
char Delimiter::getClosing(char d)
{
	if(d == '{')
	{
		return '}';
	}
	else if(d == '(')
	{
		return ')';
	}
	else if(d == '[')
	{
		return ']';
	}
	cerr << "ERROR: Only opening delimiters can be used for getClosing()." << endl;
	exit(EXIT_FAILURE);
}

/**
Ignores delimiters found in single quotes
@param file Source file
*/
void Delimiter::checkSingleQuotes(ifstream& file)
{
	char character;
	do
	{
		file.get(character);
		if(character == '\\')
		{
			file.get(character);
			file.get(character);
		}
	} while(character != '\'' && !file.eof());
	if(file.eof()){
		cerr << "ERROR: Single quote not closed.\n" << endl;
		exit(0);
	}
}

/**
Ignores delimiters found in double quotes
@param file Source file
*/
void Delimiter::checkDoubleQuotes(ifstream& file)
{
	char character;
	do
	{
		file.get(character);
		if(character == '\\')
		{
			file.get(character);
			file.get(character);
		}
	} while(character != '"' && !file.eof());
	if(file.eof()){
		cerr << "ERROR: Double quote not closed.\n" << endl;
		exit(0);
	}
}

/**
Ignores delimiters found in inline comments
@param file Source file
*/
void Delimiter::checkInlineComments(ifstream& file)
{
	char character;
	do
	{
		file.get(character);
	} while(character != '\n' && !file.eof());
	line++;
}

/**
Ignores delimiters found in block comments
@param file Source file
*/
void Delimiter::checkBlockComments(ifstream& file)
{
	char character;
	do
	{
		file.get(character);
		if(character == '\n')
		{
			line++;
		}
	} while(character != '/' && !file.eof());
	if(file.eof())
	{
		cerr << "ERROR: Block comment not closed.\n" << endl;
		exit(0);
	}
}

/**
Checks if a source file has the correct amount of delimiters. If it does not, the appropriate error message is outputted. If it does, the user is prompted that they have the correct number.
*/
void Delimiter::checkDelimiters()
{
	int max = 0;
	GenStack<char> s1(20);
	ifstream file(m_file);
	char character;
	while(!file.eof()){
		file.get(character);
		if(character == '\n')
		{
			line++;
		}
		else if(character == '\'')
		{
			checkSingleQuotes(file);
		}
		else if(character == '"')
		{
			checkDoubleQuotes(file);
		}
		else if(character == '/')
		{
			file.get(character);
			if(character == '/')
			{
				checkInlineComments(file);
			}
			else
			{
				checkBlockComments(file);
			}
		}
		else if(character == '{' || character == '(' || character == '[')
		{
			s1.push(character);
		}
		else if(character == '}' || character == ')' || character == ']')
		{
			if(s1.isEmpty())
			{
				cerr << "ERROR: Line " << line << ": Expected " << getOpening(character) << "but found " << character << ".\n" << endl;
				exit(0);
			}
			else if(s1.peek() != getOpening(character))
			{
				cerr << "ERROR: Line " << line << ": Expected " << getClosing(s1.peek()) << " but found " << character << ".\n" << endl;
				exit(0);
			}
			s1.pop();
		}
	}
	if(!s1.isEmpty())
	{
		cerr << "ERROR: Reached end of file: missing " << getClosing(s1.peek()) << ".\n"<< endl;
		exit(0);
	}
	cout << "Delimiter syntax is correct." << endl;
}
