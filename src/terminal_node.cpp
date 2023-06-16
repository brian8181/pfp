#include "terminal_node.hpp"
#include "token.hpp"

terminal_node::terminal_node()
{

}

terminal_node::terminal_node(const string& s)
{
    _ptoken = new token(s);
}

terminal_node::terminal_node(const token& tok)
{
    //_ptoken = &t;
    token t1("t1");
    token* pt = &t1;
}

terminal_node::terminal_node(token* ptok) 
{
    _ptoken = ptok;
}

terminal_node::~terminal_node()
{
}

void terminal_node::set_token(token* ptok)
{
    _ptoken = ptok;
}

token* terminal_node::get_token()
{
    return _ptoken;
}