#ifndef _binary_node_HPP
#define _binary_node_HPP

#include "terminal_node.hpp"
#include "token.hpp"

class binary_node: public terminal_node
{

public:

    binary_node();

    terminal_node* get_left();
    terminal_node* get_right();
  
private:

    token* _token;
    terminal_node* left;
    terminal_node* right;
};

#endif