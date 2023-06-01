#include "terminal_node.hpp"
//#include "token.hpp"

terminal_node::terminal_node(string& name)
{
    //m_token = token(name);
}

terminal_node::terminal_node(token* _token)
{
    m_token = _token;
}

void terminal_node::set_token(token* _token)
{
    m_token = _token;
}