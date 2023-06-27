#include "terminal_node.hpp"
#include "token.hpp"

terminal_node::terminal_node()
{

}

terminal_node::terminal_node(const string& s)
{
    p_token = new token(s);
}

terminal_node::terminal_node(const token& rtokrn)
{
    token t1("t1");
    token* pt = &t1;
}

terminal_node::terminal_node(token* ptoken) 
{
    p_token = ptoken;
}

terminal_node::~terminal_node()
{
    delete p_token;
}

void terminal_node::set_token(token* ptoken)
{
    p_token = ptoken;
}

token* terminal_node::get_token()
{
    return p_token;
}