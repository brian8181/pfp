// License:    None
// Author:     Brian K Preston
// File Name:  terminal_node.cpp
// Build Date: Fri Jul  7 05:08:36 PM CDT 2023
// Version:    0.0.1

#include "terminal_node.hpp"
#include "token.hpp"

terminal_node::terminal_node(const string& s) : node("node")
{
    _token = new token(s);
}

terminal_node::terminal_node(const terminal_node& n) : node(n)
{
   _token = n._token;
}

terminal_node::~terminal_node()
{
    delete _token;
}

token* terminal_node::get_token()
{
    return _token;
}
