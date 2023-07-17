// License:    None
// Author:     Brian K Preston
// File Name:  terminal_node.cpp
// Build Date: Sun Jul  9 09:09:59 AM CDT 2023
// Version:    0.0.1

#ifndef _terminal_node_HPP
#define _terminal_node_HPP

#include <string>
#include "node.hpp"
#include "token.hpp"

class terminal_node : public node
{

public:

    terminal_node() {};
    terminal_node(const std::string& s);
    terminal_node(const terminal_node& n);
    ~terminal_node();
    token& get_token();

protected:

    //token* _ptoken;
    token _token;

private:

};

#endif
