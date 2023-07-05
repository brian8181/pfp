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
    _name = "node";
    set_parent(n._p_parent);
}

node* node::get_parent()
{
    return _p_parent;
}

 void node::set_parent(node* pparent)
 {
    _p_parent = pparent;
 }
