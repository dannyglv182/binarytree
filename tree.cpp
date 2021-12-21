/***********************************
 * Daniel Galvez
 * tree.cpp
 * Binary Tree Project
 **********************************/

#include "tree.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


tree::tree()
{
	root = nullptr;
}


/***********************************
 * destructor
 * input: none
 * Removes every node from the tree
 **********************************/
tree::~tree()
{
	remove_all(this->root);
}


/***********************************
 * insert - public
 * input: int
 * This is a wrapper for the private
 * insert function. a number is
 * passed in here and then passed on
 * to the private version alonw with
 * the tree's root.
 **********************************/
int tree::insert(int num)
{
	return insert(num, this->root);
}


/***********************************
 * insert - private
 * input: int, node*&
 * This function inserts a node into
 * the binary tree. The new node is
 * always a leaf.
 **********************************/
int tree::insert(int num, node*& root)
{
	// Case: Empty Tree
	if (!root)
	{
		root = new node;
		root->set_num(num);
		return 0;
	}

	// num < current invocation of root
	if (num < root->get_num())
	{
		insert(num, root->get_left());
	}

	// num > current invocation of root
	else if (num > root->get_num())
	{
		insert(num, root->get_right());
	}
}


/***********************************
 * display_all - public
 * input: none
 * this function calls the private
 * version and passes in the tree's
 * root.
 **********************************/
int tree::display_all()
{
	return display_all(root);
}


/***********************************
 * display_all - private
 * input: node*
 * This function traverses the
 * binary tree recursively and 
 * displays every number in the tree.
 **********************************/
int tree::display_all(node* root)
{
	int count = 0;
	if (!root)
	{
		return 0;
	}

	count = 1;
	root->print();
	cout << " ";
	count += display_all(root->get_left());
	count += display_all(root->get_right());
	return count;

}


int tree::display_in_order()
{
	if (!root)
	{
		return 0;
	}
	return display_in_order(this->root);
}


int tree::display_in_order(node* root)
{
	if (!root)
	{
		return 0;
	}
	display_in_order(root->get_left());
	root->print();
	cout << " ";
	display_in_order(root->get_right());

}


/*******************************************
 * display_root
 * input: none
 * This function displays the tree's root
 ******************************************/
int tree::get_root_num()
{
	if (!root)
	{
		return 0;
	}
	return root->get_num();
}


/*******************************************
 * get_height - public
 * input: none
 * This function calls the private version
 * to return the tree's height.
 ******************************************/
int tree::get_height()
{
	return get_height(this->root);
}


/*******************************************
 * get_height - private
 * input: node*
 * This function traverses the tree 
 * recursively and returns the height of the
 * tree. Each node returns one for itself 
 * and the count of its longer sub-tree back
 * to the caller.
 ******************************************/
int tree::get_height(node* root)
{
	int lc = 0;
	int rc = 0;
	if (!root)
	{
		return 0;
	}
	lc = get_height(root->get_left());
	rc = get_height(root->get_right());
	if (lc > rc)
	{
		return lc + 1;
	}
	else
	{
		return rc + 1;
	}

}


/*******************************************
 * remove_all - public
 * input: node*
 * This function calls the private version
 * and removes all nodes from the tree.
 ******************************************/
int tree::remove_all()
{
	if (!root)
	{
		return 0;
	}
	return remove_all(this->root);
}


/*******************************************
 * remove_all - private
 * input: node*
 * This function traverses the tree 
 * recursively and deletes all nodes from 
 * the tree. It also returns the number of
 * nodes removed.
 ******************************************/
int tree::remove_all(node*& root)
{
	int count = 0;
	if (!root)
	{
		return 0;
	}
	count += remove_all(root->get_left()) + remove_all(root->get_right()) + 1;
	delete root;
	root = nullptr;
	return count;
}


/*******************************************
 * remove_single - public
 * input: int
 * This wrapper prevents removal from an 
 * empty tree and calls the private
 * recursive version if removal is possible
 ******************************************/
int tree::remove_single(int num)
{
	if (!root)
	{
		return 0;
	}
	remove_single(num, root);
}


/*******************************************
 * remove_single - private
 * input: int, node*&
 * This function removes a single node from
 * the tree. The cases are: deleting a node
 * that has two children, deleting a node
 * that has one child, and deleting a leaf.
 ******************************************/
int tree::remove_single(int num, node*& root)
{
	if (!root)
	{
		return 0;
	}
	if (root->get_num() == num)
	{
		// Case: node has two children
		if (root->get_left() && root->get_right())
		{
			node* ios;
			node* parent;
			parent = root->get_right();
			ios = root->get_right();

			if (!ios->get_left())			// If the right child has no left children it becomes the ios
			{
				cout << "ios is the right child of node being deleted " << endl;
				root->set_num(ios->get_num());
				if (ios->get_right())
				{
					node* ios_child;
					ios_child = ios->get_right();
					root->set_right(ios_child);
					delete ios;
					ios = nullptr;
				}
				else
				{
					cout << "B " << endl;
					delete ios;
					ios = nullptr;
					root->set_right_null();
				}
				
				
			}
			else
			{
				while (ios->get_left())			// Get in-order successor
				{
					parent = ios;
					ios = ios->get_left();
				}

				root->set_num(ios->get_num());		// Copy the ios number into root
				if (ios->get_right())			// Adopt the ios child if it exists
				{
					cout << "Orphan " << endl;
					node* orphan;
					orphan = ios->get_right();
					delete ios;
					parent->set_left(orphan);
				}
				else					// we delete the ios and have no orphans
				{
					cout << "No orphan " << endl;
					delete ios;
					parent->set_left_null();
				}
			}

		}

		// Case: node has one child
		else if (!root->get_left() && root->get_right() || !root->get_right() && root->get_left())
		{
			cout << "ONE CHILD " << endl;
			if (!root->get_left())
			{
				node* temp;
				temp = root;
				root = root->get_right();
				delete temp;
				temp = nullptr;
			}
			else if (!root->get_right())
			{
				node* temp;
				temp = root;
				root = root->get_left();
				delete temp;
				temp = nullptr;
			}
		}

		// Case: node is a leaf
		else if (!root->get_left() && !root->get_right())
		{
			cout << "LEAF " << endl;
			delete root;
			root = nullptr;
			return 0;
		}
	}
	remove_single(num, root->get_left());
	remove_single(num, root->get_right());
}


/*******************************************
 * populate
 * input: none
 * This function generates a random tree 
 * size and fills it with pseudo-random 
 * integers.
 ******************************************/
int tree::populate()
{
	srand (time(0));
	int rand_size = rand() % 100 + 1;	// Random tree size between 1 and 100
	int rand_num = 0;
	for (int i = 0; i < rand_size; ++i)
	{
		rand_num = rand() % 100;	// Random int between 0 and 99
		insert(rand_num, this->root);
	}
	return 0;
}
