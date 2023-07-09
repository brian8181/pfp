// License:    None
// Author:     Brian K Preston
// File Name:  node.cpp
// Build Date: Fri Jul  7 05:08:36 PM CDT 2023
// Version:    0.0.1

#include "node.hpp"
// #include <stdio.h>
// #include <stdlib.h>

int node::_prev_id = 0;

node::node(const std::string& name)
{
    // _id = ++_prev_id;
    // char buffer[33];
    // itoa(_id, buffer, 10);
    //_name = name + _id;
    _name = name;
    //_name.append(itoa(_id));
}

node::node(const node& n)
{
    _id = ++_prev_id;
    _name = n._name;
    _parent = n._parent;
}

int node::get_id()
{
    return _id;
}

node* node::get_parent()
{
    return _parent;
}

void node::set_parent(node* parent)
{
    _parent = parent;
}
