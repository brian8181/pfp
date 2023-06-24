#include "node.hpp"

node::node()
{
    name = "unnamed";
}

node::node(node* pparent)
{
    name = "unnamed";
    set_parent(pparent);
}

node* node::get_parent()
{
    return p_parent;
}

 void node::set_parent(node* pparent)
 {
    p_parent = pparent;
 }
