#include "terminal_node.hpp"
#include "token.hpp"

terminal_node::terminal_node()
{

}

terminal_node::terminal_node(const terminal_node& n)
{
    _token = n._token;
}

terminal_node::terminal_node(const string& s)
{
    _token = new token(s);
}

terminal_node::~terminal_node()
{
    delete _token;
}

token* terminal_node::get_token()
{
    return _token;
}