#include <iostream>
#include <fstream>
#include "TreeNode.h"
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "InputChecker.h"

using namespace std;

class Simulator
{
private:
	BST<Student>* studentTable;
	BST<Faculty>* facultyTable;
	BST<Student>* startingStudentTable;
	BST<Faculty>* startingFacultyTable;
	DLL<BST<Student>*> studentTableList;
	DLL<BST<Faculty>*> facultyTableList;
	InputChecker<int> intChecker;
	InputChecker<double> doubleChecker;
public:
	//Constructor reads from binary file
	Simulator();
	void loadStudentTraversal(ifstream& inf);
	void loadFacultyTraversal(ifstream& inf);
	//Destructor writes to binary file
	~Simulator();
	void saveStudentTraversal(TreeNode<Student>* node, ofstream& of);
	void saveFacultyTraversal(TreeNode<Faculty>* node, ofstream& of);
	//Main method
	void simulate();
	//Selection methods
	void printStudents(TreeNode<Student>* node);
	void printFaculty(TreeNode<Faculty>* node);
	void insertStudent();
	void insertFaculty();
	void editStudent(Student &student);
	void editFaculty(Faculty &faculty);
	void removeAdvisees(TreeNode<Faculty>* node);
	void updateAdvisees(TreeNode<Student>* node);
	//Display methods
	void displayOptions();
	void displayStudentIds(TreeNode<Student>* node);
	void displayFacultyIds(TreeNode<Faculty>* node);
};
