// License:    None
// Author:     Brian K Preston
// File Name:  binary_node.cpp
// Build Date: Sun Jul  9 09:09:59 AM CDT 2023
// Version:    0.0.1

#include "binary_node.hpp"

binary_node::binary_node(const string& token) : terminal_node(token)
{
    
}

binary_node::binary_node(const string& token, terminal_node* left, terminal_node* right) : terminal_node(token)
{
    //todo
    _left = left;
    _right = right;
    left->set_parent(this);
    right->set_parent(this);
}

binary_node::binary_node(const binary_node* node)
{
    _token = node->_token;
    _left = node->_left;
    _right = node->_right;
}

terminal_node* binary_node::get_left()
{
    return _left;
}

void binary_node::set_left(terminal_node* left)
{
    //debug!
    //delete _pleft;
    _left = left;
}

terminal_node* binary_node::get_right()
{
    return _right;
}

void binary_node::set_right(terminal_node* right)
{
    //debug!
    //delete _pright;
    _right = right;
}
