#include "node.hpp"

node::node()
{
}

node::node(const node& n)
{
    set_parent(n.p_parent);
}

node* node::get_parent()
{
    return p_parent;
}

 void node::set_parent(node* pparent)
 {
    p_parent = pparent;
 }
