#include "binary_node.hpp"

binary_node::binary_node()
{

}

binary_node::binary_node(const binary_node& node)
{
    
}

binary_node::binary_node(token* ptoken, terminal_node* pleft, terminal_node* pright)
{
    p_left = pleft;
    p_right = pright;
    pleft->set_parent(this);
    pright->set_parent(this);
}

binary_node::~binary_node()
{

}

terminal_node* binary_node::get_left()
{
    return p_left;
}

void binary_node::set_left(terminal_node* pnode)
{
    p_left = pnode;
}

terminal_node* binary_node::get_right()
{
    return p_right;
}

void binary_node::set_right(terminal_node* pnode)
{
    p_right = pnode;
}
