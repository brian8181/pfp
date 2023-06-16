#include "binary_node.hpp"

binary_node::binary_node()
{

}

binary_node::~binary_node()
{

}

binary_node::binary_node(token* t, terminal_node* left, terminal_node* right)
{
    _left = left;
    _right = right;
    (*left).get_parent();
    (*right).get_parent();
}

node* binary_node::get_left()
{
    return _left;
}

node* binary_node::get_right()
{
    return _right;
}