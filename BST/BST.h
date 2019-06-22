#ifndef BST_H
#define BST_H

#include <iostream>
#include "TreeNode.h"
using namespace std;

template<class T>
class BST
{
public:
	TreeNode<T> *root;
	BST();
	virtual ~BST();
	void insert(int key, T value);
	T& search(int key);
	bool contains(int key);
	//bool deleteNode(int value);
	TreeNode<T>* getSuccessor(TreeNode<T>* d);
	bool deleter(int k);

	TreeNode<T>* getMin();
	TreeNode<T>* getMax();
	bool isEmpty();
	void printTree();
	void recPrint(TreeNode<T>* node);

	void preOrder(TreeNode<T> *n);
	void inOrder(TreeNode<T> *n);
	void postOrder(TreeNode<T> *n);
};

/**
Constructor
*/
template<class T>
BST<T>::BST()
{
	root = NULL;
}

/**
Destructor
*/
template<class T>
BST<T>::~BST()
{
	delete root;
}

/**
Prints the entire tree to the screen
*/
template<class T>
void BST<T>::printTree()
{
	recPrint(root);
}

/**
Recursively prints the a subtree of some node in order
@param node Node to print on
*/
template<class T>
void BST<T>::recPrint(TreeNode<T>* node)
{
	if(node == NULL)
	{
		return;
	}
	recPrint(node->left);
	cout << "KEY: " << node->key << " VALUE: " << node->value << endl;
	recPrint(node->right);
}

/**
Returns whether the tree is empty
@bool True if tree is empty
*/
template<class T>
bool BST<T>::isEmpty()
{
	return (root == NULL);
}

/**
Inserts an element and key into the tree
@param key The key of the element being inserted
@param value The value of the element being inserted
*/
template<class T>
void BST<T>::insert(int key, T value)
{
	//check if value exists, if not continue
	TreeNode<T> *node = new TreeNode<T>(key, value);
	if(isEmpty())
	{
		root = node;
	}
	else if(!contains(key))
	{
		TreeNode<T> *current = root;
		TreeNode<T> *parent;
		while(true)
		{
			parent = current;
			if(key < current->key)
			{
				current = current->left;
				if(current == NULL)
				{
					parent->left = node;
					break;
				}
			}
			else if(key > current->key)
			{
				current = current->right;
				if(current == NULL)
				{
					parent->right = node;
					break;
				}
			}
		}
	}
}

/**
Checks whether the tree contains a particular key
@param key The key being checked
*/
template <class T>
bool BST<T>::contains(int key)
{
	if(isEmpty())
	{
		return false;
	}
	TreeNode<T> *current = root;
	while(current != NULL)
	{
		if(current->key == key)
		{
			return true;
		}
		else if(key < current->key)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	return false;
}

/**
Returns the node of a tree given a key
@param key The key being searched for
*/
template <class T>
T& BST<T>::search(int key)
{
	TreeNode<T> *current = root;
	if(isEmpty() || !contains(key))
	{
		return current->value;
	}
	while(current != NULL)
	{
		if(current->key == key)
		{
			return current->value;
		}
		else if(key < current->key)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	return current->value;
}

/**
Deletes an element based on its key from the tree
@param key Key being deleted
@return bool True if key was deleted
*/
template<class T>
bool BST<T>::deleter(int key)
{
	if(isEmpty() || !contains(key))
	{
		return false;
	}

	TreeNode<T> *current = root;
	TreeNode<T> *parent = root;
	bool isLeft = true;

	while(current->key != key)
	{
		parent = current;

		if(key < current->key)
		{
			isLeft = true;
			current = current->left;
		}
		else
		{
			isLeft = false;
			current = current->right;
		}
	}

	if(current->left == NULL && current->right == NULL)
	{
		if(current == root)
		{
			root = NULL;
		}
		else if(isLeft)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
	}
	else if(current->right == NULL)
	{
		if(current == root)
		{
			root = current->left;
		}
		else if(isLeft)
		{
			parent->left = current->left;
		}
		else
		{
			parent->right = current->left;
		}
	}
	else if(current->left == NULL)
	{
		if(current == root)
		{
			root = current->right;
		}
		else if(isLeft)
		{
			parent->left = current->right;
		}
		else
		{
			parent->right = current->right;
		}
	}
	else
	{
		TreeNode<T> *successor = getSuccessor(current);
		if(current == root)
		{
			root = successor;
		}
		else if(isLeft)
		{
			parent->left = successor;
		}
		else
		{
			parent->right = successor;
		}
		successor->left = current->left;
	}
	current->left = NULL;
	current->right = NULL;
	delete current;
	return true;
}

/**
Returns the successor of a node (Used in delete if a node has two children) and updates the appropriate pointers
@param d Node being checked if there is a successor
@return TreeNode<T>* The successor node
*/
template<class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d)
{
	TreeNode<T> *sp = d;
	TreeNode<T> *successor = d;
	TreeNode<T> *current = d->right;
	while(current != NULL)
	{
		sp = successor;
		successor = current;
		current = current->left;
	}

	if(successor != d->right)
	{
		sp->left = successor->right;
		successor->right = d->right;
	}
	return successor;
}

/**
Return the minimum node of the tree (based on key value)
@return TreeNode<T>* The minimum node
*/
template <class T>
TreeNode<T>* BST<T>::getMin()
{
	TreeNode<T>* current = root;
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

/**
Return the maximum node of the tree (based on key value)
@return TreeNode<T>* The maximum node
*/
template<class T>
TreeNode<T>* BST<T>::getMax()
{
	TreeNode<T>* current = root;
	while(current->right != NULL)
	{
		current = current->right;
	}
	return current;
}

/**
Prints the preorder traversal of the tree
@param TreeNode<T>* Node to print on
*/
template<class T>
void BST<T>::preOrder(TreeNode<T> *n)
{
	if(n != NULL)
	{
		cout << "KEY: " << n->key << " VALUE: " << n->value << endl;
		preOrder(n->left);
		preOrder(n->right);
	}
}

/**
Prints the inorder traversal of the tree
@param TreeNode<T>* Node to print on
*/
template<class T>
void BST<T>::inOrder(TreeNode<T> *n)
{
	if(n != NULL)
	{
		inOrder(n->left);
		cout << "KEY: " << n->key << " VALUE: " << n->value << endl;
		inOrder(n->right);
	}
}

/**
Prints the postorder traversal of the tree
@param TreeNode<T>* Node to print on
*/
template<class T>
void BST<T>::postOrder(TreeNode<T> *n)
{
	if(n != NULL)
	{
		postOrder(n->left);
		postOrder(n->right);
		cout << "KEY: " << n->key << " VALUE: " << n->value << endl;
	}
}

#endif
