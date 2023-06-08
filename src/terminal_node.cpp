#include "terminal_node.hpp"
#include "token.hpp"

terminal_node::terminal_node()
{

}

terminal_node::terminal_node(token* ptoken) 
{
    _ptoken = ptoken;
}

void terminal_node::set_token(token* ptoken)
{
    _ptoken = ptoken;
}