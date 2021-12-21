/***********************************
 * Daniel Galvez
 * node.cpp
 * Binary Tree Project
 **********************************/

#include "node.h"
#include <iostream>
using namespace std;


node::node()
{
	left = nullptr;
	right = nullptr;
}


node::~node()
{

}


int node::set_num(int num)
{
	this->num = num;
}


int node::get_num()
{
	return this->num;
}


node*& node::get_left()
{
	return this->left;
}


node*& node::get_right()
{
	return this->right;
}


node*& node::set_left(node*& a_node)
{
	this->left = a_node;
}


node*& node::set_right(node*& a_node)
{
	this->right = a_node;
}


int node::set_left_null()
{
	this->left = nullptr;
}


int node::set_right_null()
{
	this->right = nullptr;
}


int node::print()
{
	cout << this->num;
}
