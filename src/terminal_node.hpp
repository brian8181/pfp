#ifndef _terminal_node_HPP
#define _terminal_node_HPP

#include "node.hpp"
#include "token.hpp"

class terminal_node : public node
{
public:

    terminal_node();
    terminal_node(const terminal_node& n);
    terminal_node(const string& s);
    ~terminal_node();
   
    token* get_token();

private:

    token* _token;
};

#endif