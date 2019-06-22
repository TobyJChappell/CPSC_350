#include <iostream>

using namespace std;

template<class T>
class TreeNode
{
public:
	TreeNode *left;
	TreeNode *right;
	int key;
	T value;
	TreeNode();
	TreeNode(int k, T v);
	virtual ~TreeNode();
};

template<class T>
TreeNode<T>::TreeNode()
{
	left = NULL;
	right = NULL;
}

template<class T>
TreeNode<T>::TreeNode(int k, T v)
{
	left = NULL;
	right = NULL;
	key = k;
	value = v;
}

template<class T>
TreeNode<T>::~TreeNode()
{
	delete left;
	delete right;
}
