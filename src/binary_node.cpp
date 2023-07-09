// License:    None
// Author:     Brian K Preston
// File Name:  binary_node.cpp
// Build Date: Sun Jul  9 09:09:59 AM CDT 2023
// Version:    0.0.1

#include "binary_node.hpp"

binary_node::binary_node(const string& t, terminal_node* pleft, terminal_node* pright) : terminal_node(t)
{
    _pleft = pleft;
    _pright = pright;
    pleft->set_parent(this);
    pright->set_parent(this);
}

terminal_node* binary_node::get_left()
{
    return _pleft;
}

void binary_node::set_left(terminal_node* pleft)
{
    delete _pleft;
    _pleft = new terminal_node(*pleft);
}

terminal_node* binary_node::get_right()
{
    return _pright;
}

void binary_node::set_right(terminal_node* pright)
{
    delete _pright;
    _pright = new terminal_node(*pright);
}
