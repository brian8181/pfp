#ifndef _terminal_node_HPP
#define _terminal_node_HPP

#include <string>
#include "node.hpp"
#include "token.hpp"

class terminal_node : public node
{
public:

    terminal_node();
    terminal_node(const terminal_node& n);
    terminal_node(const std::string& s);
    terminal_node(const std::string& name, const node& n);
    ~terminal_node();
   
    token* get_token();

protected:

    token* _token;
};

#endif