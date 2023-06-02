#include "binary_node.hpp"

binary_node::binary_node()
{

}


terminal_node* binary_node::get_left()
{
    return left;
}

terminal_node* binary_node::get_right()
{
    return right;
}