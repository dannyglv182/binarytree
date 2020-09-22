/***********************************
 * Daniel Galvez
 * tree.h
 * Binary Tree Project
 **********************************/
#include "node.h"

class tree
{
	public:
		tree();
		~tree();
		int insert(int num);			// Public wrapper for insert function
		int display_all();			// Display every number in the tree
		int display_in_order();			// Display the tree in order
		int get_root_num();			// get the tree's root
		int get_height();			// Return the height of the tree
		int remove_all();			// Remove every node in the tree
		int remove_single(int num);		// Remove a single node
		int populate();				// Fill an empty tree
	private:
		int insert(int num, node*& root);	// Private recursive bst insert
		int display_all(node* root);
		int display_in_order(node* root);
		int get_height(node* root);
		int remove_all(node*& root);
		int remove_single(int num, node*& root);
		node* root;
};
