#ifndef _binary_node_HPP
#define _binary_node_HPP

#include "terminal_node.hpp"
#include "token.hpp"

class binary_node: public terminal_node
{
public:

    binary_node();
    binary_node(token* t, terminal_node* left, terminal_node* right);
    node* get_left();
    node* get_right();
  
private:

    node* _left;
    node* _right;
};

#endif