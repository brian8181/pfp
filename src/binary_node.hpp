#ifndef _binary_node_HPP
#define _binary_node_HPP

#include "terminal_node.hpp"
#include "token.hpp"

class binary_node: public terminal_node
{
public:

    binary_node(token* t, terminal_node* left, terminal_node* right);
    ~binary_node();
    terminal_node* get_left();
    void set_left(terminal_node* node);
    terminal_node* get_right();
    void set_right(terminal_node* node);
  
private:

    terminal_node* _left;
    terminal_node* _right;
};

#endif