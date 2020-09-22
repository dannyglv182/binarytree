/***********************************
 * Daniel Galvez
 * node.h
 * Binary Tree Project
 **********************************/

class node
{
	public:
		node();
		~node();
		int set_num(int num);
		int get_num();
		node*& get_left();
		node*& get_right();
		node*& set_left(node*& a_node);
		node*& set_right(node*& a_node);
		int set_left_null();
		int set_right_null();
		int print();
	private:
		int num;
		node* left;
		node* right;
};
