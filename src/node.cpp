#include "node.hpp"

node::node()
{
    _name = "node";
}

node::node(const std::string& name)
{
    _name = name;
}

node::node(const node& n)
{
    _name = n._name;
    _parent = n._parent;
}

node* node::get_parent()
{
    return _parent;
}

void node::set_parent(node* parent)
{
    _parent = parent;
}
