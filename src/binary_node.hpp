#ifndef _binary_node_HPP
#define _binary_node_HPP

#include "terminal_node.hpp"
#include "token.hpp"

class binary_node: public terminal_node
{
public:

    binary_node();
    binary_node(const binary_node& node);
    binary_node(token* ptoken, terminal_node* pleft, terminal_node* pright);
    ~binary_node();
    terminal_node* get_left();
    void set_left(terminal_node* pnode);
    terminal_node* get_right();
    void set_right(terminal_node* pnode);
  
private:

    terminal_node* p_left;
    terminal_node* p_right;
};

#endif