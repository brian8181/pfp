#include "node.hpp"

node::node()
{
    _name = "node";
}

node::node(const std::string& name)
{
    _name = name;
}

node::node(const std::string& name, const node& n)
{
    
}

node* node::get_parent()
{
    return _parent;
}

void node::set_parent(node* parent)
{
    _parent = parent;
}
