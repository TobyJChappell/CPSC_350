#include <iostream>
#include "BST.h"
using namespace std;

int main(int argc, char** argv)
{
	BST<string> t1;
	t1.insert(5, "on");
	t1.insert(3, "you've");
	t1.insert(7, "mind");
	t1.insert(2, "Ophelia");
	t1.insert(4, "been");
	t1.insert(6, "my");
	t1.insert(8, "girl");
	t1.insert(1, "Oh");
	t1.insert(10, "the");
	t1.insert(9, "since");
	t1.insert(11, "flood");
	cout << "PREORDER: " << endl;
	t1.preOrder(t1.root);
	cout << "INORDER: " << endl;
	t1.inOrder(t1.root);
	cout << "POSTORDER: " << endl;
	t1.postOrder(t1.root);
	cout << "RECPRINT: " << endl;
	t1.printTree();;
	cout << "MIN: " << t1.getMin()->key << ", " << t1.getMin()->value << endl;
	cout << "MAX: " << t1.getMax()->key << ", " << t1.getMax()->value << endl;
	if(t1.contains(5))
	{
		cout << "Tree contains 5" << endl;
	}
	else
	{
		cout << "Tree does not contain 5" << endl;
	}
	t1.deleter(5);
	t1.printTree();
	t1.deleter(3);
	cout << endl;
	t1.printTree();
	t1.deleter(1);
	cout << endl;
	t1.printTree();;
}
