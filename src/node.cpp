// License:    None
// Author:     Brian K Preston
// File Name:  node.cpp
// Build Date: Fri Jul  7 05:08:36 PM CDT 2023
// Version:    0.0.1

#include "node.hpp"

int node::_prev_id = 0;

node::node() : _pparent(0)
{
}

node::node(const node& n)
{
    _id = ++_prev_id;
    _pparent = n._pparent;
}

int node::get_id()
{
    return _id;
}

node* node::get_parent()
{
    return _pparent;
}

void node::set_parent(node* pparent)
{
    _pparent = pparent;
}
