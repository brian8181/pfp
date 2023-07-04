#include "terminal_node.hpp"
#include "token.hpp"

terminal_node::terminal_node()
{

}

terminal_node::terminal_node(const terminal_node& n)
{
    ptoken = n.ptoken;
}

terminal_node::terminal_node(const string& s)
{
    ptoken = new token(s);
}

terminal_node::~terminal_node()
{
    delete ptoken;
}

token* terminal_node::get_token()
{
    return ptoken;
}