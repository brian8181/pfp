#include "node.hpp"

node* node::get_parent()
{
    return p_parent;
}

 void node::set_parent(node* pparent)
 {
    p_parent = pparent;
 }
