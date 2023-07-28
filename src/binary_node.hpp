// License:    None
// Author:     Brian K Preston
// File Name:  binary_node.hpp
// Build Date: Sun Jul  9 09:09:59 AM CDT 2023
// Version:    0.0.1

#ifndef _binary_node_HPP
#define _binary_node_HPP

#include "terminal_node.hpp"
#include "token.hpp"

class binary_node : public terminal_node
{

public:
    
    binary_node(const string& token);
    binary_node(const binary_node* node);
    binary_node(const string& token, terminal_node* left, terminal_node* right);
    terminal_node* get_left();
    void set_left(terminal_node* left);
    terminal_node* get_right();
    void set_right(terminal_node* right);
  
private:

    terminal_node* _left;
    terminal_node* _right;
};

#endif
