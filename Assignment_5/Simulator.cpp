#include <iostream>
#include <fstream>
#include <limits>
#include "Simulator.h"

using namespace std;

/**
Constructor
*/
Simulator::Simulator()
{
	studentTable = new BST<Student>;
	facultyTable = new BST<Faculty>;
	try
	{
		ifstream facultyFile("facultyTable", ios::binary | ios::in);
		if(facultyFile.is_open())
		{
			loadFacultyTraversal(facultyFile);
			facultyFile.close();
			ifstream studentFile("studentTable", ios::binary | ios::in);
			if(studentFile.is_open())
			{
				loadStudentTraversal(studentFile);
				studentFile.close();
			}
		}
	}
	catch(exception& e)
	{
		studentTable = new BST<Student>;
		facultyTable = new BST<Faculty>;
	}
	startingStudentTable = new BST<Student>(*studentTable);
	startingFacultyTable = new BST<Faculty>(*facultyTable);
}

/**
Retrieves the studentTable from a file
@param node Root of the tree
@param inf File being read from
*/
void Simulator::loadStudentTraversal(ifstream& inf)
{
	int size = 0;
	inf.read((char*) &size, sizeof(size));
	for(int x = 0; x < size; x++)
	{
		Student s1;
		s1.load(inf);
		studentTable->insert(s1.getId(), s1);
	}
}

/**
Retrieves the facultyTable from a file
@param node Root of the tree
@param inf File being read from
*/
void Simulator::loadFacultyTraversal(ifstream& inf)
{
	int size = 0;
	inf.read((char*) &size, sizeof(size));
	for(int x = 0; x < size; x++)
	{
		Faculty f1;
		f1.load(inf);
		facultyTable->insert(f1.getId(), f1);
	}
}

/**
Destructor
*/
Simulator::~Simulator()
{
	ofstream facultyFile("facultyTable", ios::binary | ios::out);
	facultyFile.write((char*) &facultyTable->size, sizeof(facultyTable->size));
	saveFacultyTraversal(facultyTable->root, facultyFile);
	facultyFile.close();
	ofstream studentFile("studentTable", ios::binary | ios::out);
	studentFile.write((char*) &studentTable->size, sizeof(studentTable->size));
	saveStudentTraversal(studentTable->root, studentFile);
	studentFile.close();
	delete studentTable;
}

/**
Uploads the studentTable to a file
@param node Root of the tree
@param of File being uploaded to
*/
void Simulator::saveStudentTraversal(TreeNode<Student>* node, ofstream& of)
{
	if(node == NULL)
	{
		return;
	}
	node->value.save(of);
	saveStudentTraversal(node->left, of);
	saveStudentTraversal(node->right, of);
}

/**
Uploads the facultyTable to a file
@param node Root of the tree
@param of File being uploaded to
*/
void Simulator::saveFacultyTraversal(TreeNode<Faculty>* node, ofstream& of)
{
	if(node == NULL)
	{
		return;
	}
	node->value.save(of);
	saveFacultyTraversal(node->left, of);
	saveFacultyTraversal(node->right, of);
}

/**
Lists all 14 options and runs whichever is chosen
*/
void Simulator::simulate()
{
	int choice;
	int studentId;
	int facultyId;
	bool canRollout = false;
	bool first = false;
	bool prev15 = false;
	int count = 0;
	do {
		displayOptions();
		cin >> choice;
		intChecker.checkInput(choice);
		while(((choice == 1 || choice == 3 || choice == 5 || choice == 8 || choice == 9 || choice == 13) && studentTable->isEmpty()) || ((choice == 2 || choice == 4 || choice == 6 || choice == 7 || choice == 11 || choice == 12 || choice == 13 || choice == 14) && facultyTable->isEmpty()) || choice > 16 || choice < 1)
		{
			if(choice > 16 || choice < 1)
			{
				cout << "Please enter a valid choice (1-14):" << endl;
			}
			else
			{
				cout << "Datatable is empty, please input another option" << endl;
			}
			cin >> choice;
			intChecker.checkInput(choice);
		}
		if(choice != 15)
		{
			cout << endl;
		}
		switch (choice) {
			case 1:
				printStudents(studentTable->root);
				//print students
				break;
			case 2:
				printFaculty(facultyTable->root);
				//print faculty
				break;
			case 3:
			{
				cout << "Please enter the student's id:" << endl;
				cin >> studentId;
				intChecker.checkInput(studentId);
				while(!studentTable->contains(studentId))
				{
					cout << "Enter a student id that exists:" << endl;
					cout << "( Existing ids: ";
					displayStudentIds(studentTable->root);
					cout << ")" << endl;
					cin >> studentId;
					intChecker.checkInput(studentId);
				}
				cout << endl;
				studentTable->search(studentId).printInfo();
				//find and print student info
				break;
			}
			case 4:
				cout << "Please enter the faculty member's id:" << endl;
				cin >> facultyId;
				intChecker.checkInput(facultyId);
				while(!facultyTable->contains(facultyId))
				{
					cout << "Enter a faculty id that exists:" << endl;
					cout << "( Existing ids: ";
					displayFacultyIds(facultyTable->root);
					cout << ")" << endl;
					cin >> facultyId;
					intChecker.checkInput(facultyId);
				}
				cout << endl;
				facultyTable->search(facultyId).printInfo();
				//find and print faculty info
				break;
			case 5:
				cout << "Please enter the student's id:" << endl;
				cin >> studentId;
				intChecker.checkInput(studentId);
				while(!studentTable->contains(studentId))
				{
					cout << "Enter a student id that exists:" << endl;
					cout << "( Existing ids: ";
					displayStudentIds(studentTable->root);
					cout << ")" << endl;
					cin >> studentId;
					intChecker.checkInput(studentId);
				}
				cout << endl;
				facultyTable->search(studentTable->search(studentId).getAdvisor()).printInfo();
				//find student and print faculty name and info
				break;
			case 6:
			{
				cout << "Enter the faculty member's id:" << endl;
				cin >> facultyId;
				intChecker.checkInput(facultyId);
				while(!facultyTable->contains(facultyId))
				{
					cout << "Enter a faculty id that exists:" << endl;
					cout << "( Existing ids: ";
					displayFacultyIds(facultyTable->root);
					cout << ")" << endl;
					cin >> facultyId;
					intChecker.checkInput(facultyId);
				}
				int numAdvisees = facultyTable->search(facultyId).getNumAdvisees();
				cout << endl;
				if(numAdvisees != 0)
				{
					for(int x = 0; x < numAdvisees; x++)
					{
						facultyTable->search(facultyId).getAdvisee(x).printInfo();
					}
				}
				else
				{
					cout << "Faculty member does not have any advisees." << endl;
				}
				//find faculty and print all student name and info
				break;
			}
			case 7:
			{
				insertStudent();
				//add student
				break;
			}
			case 8:
				cout << "Enter the student's id:" << endl;
				cin >> studentId;
				intChecker.checkInput(studentId);
				while(!studentTable->contains(studentId))
				{
					cout << "Enter a student id that exists:" << endl;
					cout << "( Existing ids: ";
					displayStudentIds(studentTable->root);
					cout << ")" << endl;
					cin >> studentId;
					intChecker.checkInput(studentId);
				}
				editStudent(studentTable->search(studentId));
				break;
			case 9:
				cout << "Enter the student's id:" << endl;
				cin >> studentId;
				intChecker.checkInput(studentId);
				while(!studentTable->contains(studentId))
				{
					cout << "Enter a student id that exists:" << endl;
					cout << "( Existing ids: ";
					displayStudentIds(studentTable->root);
					cout << ")" << endl;
					cin >> studentId;
					intChecker.checkInput(studentId);
				}
				facultyTable->search(studentTable->search(studentId).getAdvisor()).removeAdvisee(studentId);
				studentTable->deleter(studentId);
				//delete student
				break;
			case 10:
			{
				insertFaculty();
				//add faculty member
				break;
			}
			case 11:
				cout << "Enter the faculty member's id:" << endl;
				cin >> facultyId;
				intChecker.checkInput(facultyId);
				while(!facultyTable->contains(facultyId))
				{
					cout << "Enter a faculty id that exists:" << endl;
					cout << "( Existing ids: ";
					displayFacultyIds(facultyTable->root);
					cout << ")" << endl;
					cin >> facultyId;
					intChecker.checkInput(facultyId);
				}
				editFaculty(facultyTable->search(facultyId));
				break;
			case 12:
				cout << "Enter the faculty member's id:" << endl;
				cin >> facultyId;
				intChecker.checkInput(facultyId);
				while(!facultyTable->contains(facultyId))
				{
					cout << "Enter a faculty id that exists:" << endl;
					cout << "( Existing ids: ";
					displayFacultyIds(facultyTable->root);
					cout << ")" << endl;
					cin >> facultyId;
					intChecker.checkInput(facultyId);
				}
				if(facultyTable->search(facultyId).getNumAdvisees() != 0)
				{
					cout << "Please change/delete the advisee's of this faculty member" << endl;
				}
				else
				{
					facultyTable->deleter(facultyId);
				}
				//delete faculty member
				break;
			case 13:
				cout << "Enter the student's id:" << endl;
				cin >> studentId;
				intChecker.checkInput(studentId);
				while(!studentTable->contains(studentId))
				{
					cout << "Enter a student id that exists:" << endl;
					cout << "( Existing ids: ";
					displayStudentIds(studentTable->root);
					cout << ")" << endl;
					cin >> studentId;
					intChecker.checkInput(studentId);
				}
				cout << "Enter the faculty member's id:" << endl;
				cin >> facultyId;
				intChecker.checkInput(facultyId);
				while(!facultyTable->contains(facultyId))
				{
					cout << "Enter a faculty id that exists:" << endl;
					cout << "( Existing ids: ";
					displayFacultyIds(facultyTable->root);
					cout << ")" << endl;
					cin >> facultyId;
					intChecker.checkInput(facultyId);
				}
				facultyTable->search(studentTable->search(studentId).getAdvisor()).removeAdvisee(studentId);
				studentTable->search(studentId).setAdvisor(facultyId);
				facultyTable->search(facultyId).insertAdvisee(studentId, studentTable->search(studentId));
				//change student's advisor
				break;
			case 14:
				cout << "Enter the faculty member's id:" << endl;
				cin >> facultyId;
				intChecker.checkInput(facultyId);
				while(!facultyTable->contains(facultyId))
				{
					cout << "Enter a faculty id that exists:" << endl;
					cout << "( Existing ids: ";
					displayFacultyIds(facultyTable->root);
					cout << ")" << endl;
					cin >> facultyId;
					intChecker.checkInput(facultyId);
				}
				if(facultyTable->search(facultyId).getNumAdvisees() == 0)
				{
					cout << "Faculty member does not have any advisees."  << endl;
				}
				else
				{
					cout << "Enter the student's id:" << endl;
					cin >> studentId;
					intChecker.checkInput(studentId);
					while(facultyTable->search(facultyId).findAdvisee(studentId) == -1)
					{
						cout << "Enter a student id that is an advisee of the faculty member:" << endl;
						cout << "( Existing ids: ";
						facultyTable->search(facultyId).displayAdviseesIds();
						cout << ")" << endl;
						cin >> studentId;
						intChecker.checkInput(studentId);
					}
					facultyTable->search(facultyId).removeAdvisee(studentId);
					studentTable->deleter(studentId);
				}
				//remove an advisee from a faculty member's id
				break;
				//ERROR with Rollout
			case 15:
				if(!canRollout)
				{
					cout << "\nNo history to rollback" << endl;
				}
				else
				{
					if((first || prev15) && !studentTableList.isEmpty())
					{
						studentTableList.removeFront();
						facultyTableList.removeFront();
						prev15 = false;
					}
					if(!studentTableList.isEmpty())
					{
						studentTable = new BST<Student>(*studentTableList.removeFront());
						facultyTable = new BST<Faculty>(*facultyTableList.removeFront());
					}
					else
					{
						studentTable = new BST<Student>(*startingStudentTable);
						facultyTable = new BST<Faculty>(*startingFacultyTable);
						canRollout = false;
					}
					if(!studentTable->isEmpty())
					{
						removeAdvisees(facultyTable->root);
						updateAdvisees(studentTable->root);
					}
					if(first)
					{
						studentTableList.insertFront(count, new BST<Student>(*studentTable));
						facultyTableList.insertFront(count, new BST<Faculty>(*facultyTable));
						count++;
						first = false;
						prev15 = true;
					}
				}
				//Rollback
				break;
		}
		if(choice >= 7 && choice <= 14)
		{
			studentTableList.insertFront(count, new BST<Student>(*studentTable));
			facultyTableList.insertFront(count, new BST<Faculty>(*facultyTable));
			count++;
			canRollout = true;
			first = true;
			prev15 = false;
		}
	} while(choice != 16);
}

/**
Recursively prints the a subtree of some node in order
@param node Node to print on
*/
void Simulator::printStudents(TreeNode<Student>* node)
{
	if(node == NULL)
	{
		return;
	}
	printStudents(node->left);
	node->value.printInfo();
	printStudents(node->right);
}

/**
Recursively prints the a subtree of some node in order
@param node Node to print on
*/
void Simulator::printFaculty(TreeNode<Faculty>* node)
{
	if(node == NULL)
	{
		return;
	}
	printFaculty(node->left);
	node->value.printInfo();
	printFaculty(node->right);
}

/**
Inserts a student into the studentTable
*/
void Simulator::insertStudent()
{
	Student student;
	cout << "Enter the student's id:" << endl;
	int id;
	cin >> id;
	intChecker.checkInput(id);
	while(studentTable->contains(id))
	{
		cout << "Enter an id that does not currently exist:" << endl;
		cout << "( Existing ids: ";
		displayStudentIds(studentTable->root);
		cout << ")" << endl;
		cin >> id;
		intChecker.checkInput(id);
	}
	cin.ignore();
	student.setId(id);
	cout << "Enter the student's name:" << endl;
	string name;
	getline(cin, name);
	student.setName(name);
	cout << "Enter the student's level:" << endl;
	string level;
	getline(cin, level);
	student.setLevel(level);
	cout << "Enter the student's major:" << endl;
	string major;
	getline(cin, major);
	student.setMajor(major);
	cout << "Enter the student's gpa:" << endl;
	double gpa;
	cin >> gpa;
	doubleChecker.checkInput(gpa);
	student.setGpa(gpa);
	cout << "Enter the student's advisor id:" << endl;
	int advisor;
	cin >> advisor;
	intChecker.checkInput(advisor);
	while(!facultyTable->contains(advisor))
	{
		cout << "Enter a faculty id that exists:" << endl;
		cout << "( Existing ids: ";
		displayFacultyIds(facultyTable->root);
		cout << ")" << endl;
		cin >> advisor;
		intChecker.checkInput(advisor);
	}
	student.setAdvisor(advisor);
	studentTable->insert(id, student);
	facultyTable->search(advisor).insertAdvisee(id, student);
}

/**
Inserts a faculty member into the facultyTable
*/
void Simulator::insertFaculty()
{
	Faculty faculty;
	cout << "Enter the faculty member's id:" << endl;
	int id;
	cin >> id;
	intChecker.checkInput(id);
	while(facultyTable->contains(id))
	{
		cout << "Enter an id that does not currently exist:" << endl;
		cout << "( Existing ids: ";
		displayFacultyIds(facultyTable->root);
		cout << ")" << endl;
		cin >> id;
		intChecker.checkInput(id);
	}
	cin.ignore();
	faculty.setId(id);
	cout << "Enter the faculty member's name:" << endl;
	string name;
	getline(cin, name);
	faculty.setName(name);
	cout << "Enter the faculty member's level:" << endl;
	string level;
	getline(cin, level);
	faculty.setLevel(level);
	cout << "Enter the faculty member's department:" << endl;
	string department;
	getline(cin, department);
	faculty.setDepartment(department);
	facultyTable->insert(id, faculty);
}

/**
Allows the user to edit information about a student
@param student Student being edited
*/
void Simulator::editStudent(Student &student)
{
	cout << "\nSelect an option:" << endl;
	cout << "1. Name" << endl;
	cout << "2. Level" << endl;
	cout << "3. Major" << endl;
	cout << "4. Gpa" << endl;
	int choice;
	cin >> choice;
	intChecker.checkInput(choice);
	cout << endl;
	while(choice < 1 || choice > 4)
	{
		cout << "Please enter a valid choice (1-4):" << endl;
		cin >> choice;
		intChecker.checkInput(choice);
	}
	cin.ignore();
	switch(choice)
	{
		case 1:
		{
			cout << "Enter what you would like to set the student's name to:" << endl;
			string name;
			getline(cin, name);
			student.setName(name);
			break;
		}
		case 2:
		{
			cout << "Enter what you would like to set the student's level to:" << endl;
			string level;
			getline(cin, level);
			student.setLevel(level);
			break;
		}
		case 3:
		{
			cout << "Enter what you would like to set the student's major to:" << endl;
			string major;
			getline(cin, major);
			student.setMajor(major);
			break;
		}
		case 4:
		{
			cout << "Enter what you would like to set the student's gpa to:" << endl;
			double gpa;
			cin >> gpa;
			doubleChecker.checkInput(gpa);
			student.setGpa(gpa);
			break;
		}
	}
	facultyTable->search(student.getAdvisor()).removeAdvisee(student.getId());
	facultyTable->search(student.getAdvisor()).insertAdvisee(student.getId(), student);
}

/**
Allows the user to edit information about a faculty member
@param faculty Faculty member veing edited
*/
void Simulator::editFaculty(Faculty &faculty)
{
	cout << "\nSelect an option:" << endl;
	cout << "1. Name" << endl;
	cout << "2. Level" << endl;
	cout << "3. Department" << endl;
	int choice;
	cin >> choice;
	intChecker.checkInput(choice);
	cout << endl;
	while(choice < 1 || choice > 3)
	{
		cout << "Please enter a valid choice (1-3):" << endl;
		cin >> choice;
		intChecker.checkInput(choice);
	}
	cin.ignore();
	switch(choice)
	{
		case 1:
		{
			cout << "Enter what you would like to set the faculty member's name to:" << endl;
			string name;
			getline(cin, name);
			faculty.setName(name);
			break;
		}
		case 2:
		{
			cout << "Enter what you would like to set the faculty member's level to:" << endl;
			string level;
			getline(cin, level);
			faculty.setLevel(level);
			break;
		}
		case 3:
		{
			cout << "Enter what you would like to set the faculty member's department to:" << endl;
			string department;
			getline(cin, department);
			faculty.setDepartment(department);
			break;
		}
	}
}

void Simulator::removeAdvisees(TreeNode<Faculty>* node)
{
	if(node == NULL)
	{
		return;
	}
	removeAdvisees(node->left);
	while(node->value.getNumAdvisees() != 0)
	{
		node->value.removeFirstAdvisee();
	}
	removeAdvisees(node->right);
}

/**
Updates the faculty advisee lists when rollback is called
@param node Student being checked
*/
void Simulator::updateAdvisees(TreeNode<Student>* node)
{
	if(node == NULL)
	{
		return;
	}
	updateAdvisees(node->left);
	facultyTable->search(node->value.getAdvisor()).insertAdvisee(node->key, node->value);
	updateAdvisees(node->right);
}

/**
Prints all 16 options to the screen
*/
void Simulator::displayOptions()
{
	cout << "\n1. Print all students and their information (sorted by ascending id #)" << endl;
	cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
	cout << "3. Find and display student information given the students id" << endl;
	cout << "4. Find and display faculty information given the faculty id" << endl;
	cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
	cout << "6. Given a faculty id, print ALL the names and info of his/her advisees" << endl;
	cout << "7. Add a new student" << endl;
	cout << "8. Edit a student given the id" << endl;
	cout << "9. Delete a student given the id" << endl;
	cout << "10. Add a new faculty member" << endl;
	cout << "11. Edit a faculty member given the id" << endl;
	cout << "12. Delete a faculty member given the id" << endl;
	cout << "13. Change a student’s advisor given the student id and the new faculty id" << endl;
	cout << "14. Remove an advisee from a faculty member given the ids" << endl;
	cout << "15. Rollback" << endl;
	cout << "16. Exit" << endl;
}

/**
Displays the student ids in student table
@param node Root node of studentTable
*/
void Simulator::displayStudentIds(TreeNode<Student>* node)
{
	if(node == NULL)
	{
		return;
	}
	displayStudentIds(node->left);
	cout << node->value.getId() << " ";
	displayStudentIds(node->right);
}

/**
Displays the faculty ids in faculty table
@param node Root node of facultyTable
*/
void Simulator::displayFacultyIds(TreeNode<Faculty>* node)
{
	if(node == NULL)
	{
		return;
	}
	displayFacultyIds(node->left);
	cout << node->value.getId() << " ";
	displayFacultyIds(node->right);
}
