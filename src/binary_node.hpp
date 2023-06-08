#ifndef _binary_node_HPP
#define _binary_node_HPP

#include "node.hpp"
#include "terminal_node.hpp"
#include "token.hpp"

class binary_node: public node
{

public:

    binary_node();
    node* get_left();
    node* get_right();
  
private:

    token* _token;
    node* _left;
    node* _right;
};

#endif