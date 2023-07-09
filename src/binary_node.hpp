// License:    None
// Author:     Brian K Preston
// File Name:  binary_node.hpp
// Build Date: Fri Jul  7 05:08:36 PM CDT 2023
// Version:    0.0.1

#ifndef _binary_node_HPP
#define _binary_node_HPP

#include "terminal_node.hpp"
#include "token.hpp"

class binary_node : public terminal_node
{

public:
    
    binary_node(const string& t, terminal_node* pleft, terminal_node* pright);
    terminal_node* get_left();
    void set_left(terminal_node* pleft);
    terminal_node* get_right();
    void set_right(terminal_node* pright);
  
private:

    terminal_node* _pleft;
    terminal_node* _pright;
};

#endif
