// License:    None
// Author:     Brian K Preston
// File Name:  terminal_node.cpp
// Build Date: Sun Jul  9 09:09:59 AM CDT 2023
// Version:    0.0.1

#include "terminal_node.hpp"
#include "token.hpp"

// terminal_node::terminal_node() 
// {

// }

terminal_node::terminal_node(const string& s) : _token(s)
{
    //_ptoken = new token(s);
}

terminal_node::terminal_node(const terminal_node& n) : node(n), _token("")
{
   //_ptoken = n._ptoken;
}

terminal_node::~terminal_node()
{
    //debug!
    //delete _ptoken;
}

token& terminal_node::get_token()
{
    return _token;
}
