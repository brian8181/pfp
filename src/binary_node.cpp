// License:    None
// Author:     Brian K Preston
// File Name:  binary_node.cpp
// Build Date: Fri Jul  7 05:08:36 PM CDT 2023
// Version:    0.0.1

#include "binary_node.hpp"

binary_node::binary_node(const string& t, terminal_node* left, terminal_node* right) : terminal_node(t)
{
    _left = left;
    _right = right;
    left->set_parent(this);
    right->set_parent(this);
}

terminal_node* binary_node::get_left()
{
    return _left;
}

void binary_node::set_left(terminal_node* left)
{
    delete _left;
    _left = new terminal_node(*left);
}

terminal_node* binary_node::get_right()
{
    return _right;
}

void binary_node::set_right(terminal_node* right)
{
    delete _right;
    _right = new terminal_node(*right);
}
