#include "node.hpp"

int node::_prev_id = 0;

node::node(const std::string& name)
{
    _id = ++_prev_id;
    _name = name;
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
