#include "binary_node.hpp"

binary_node::binary_node(token* t, terminal_node* left, terminal_node* right)
{
    _left = left;
    _right = right;
    (*left).set_parent(this);
    (*right).set_parent(this);
}

binary_node::~binary_node()
{

}

terminal_node* binary_node::get_left()
{
    return _left;
}

void binary_node::set_left(terminal_node* node)
{
    _left = node;
}

terminal_node* binary_node::get_right()
{
    return _right;
}

void binary_node::set_right(terminal_node* node)
{
    _right = node;
}
