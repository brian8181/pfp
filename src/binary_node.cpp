#include "binary_node.hpp"

binary_node::binary_node()
{

}

binary_node::binary_node(const string& tok, terminal_node* left, terminal_node* right) : terminal_node(tok)
{
    _left = left;
    _right = right;
    left->set_parent(this);
    right->set_parent(this);
}

terminal_node* binary_node::get_left()
{
    return _left;
}

void binary_node::set_left(terminal_node* left)
{
    _left = left;
}

terminal_node* binary_node::get_right()
{
    return _right;
}

void binary_node::set_right(terminal_node* right)
{
    _right = right;
}
