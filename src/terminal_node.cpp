#include "terminal_node.hpp"
#include "token.hpp"

terminal_node::terminal_node()
{

}

// terminal_node::terminal_node(string& name)
// {
//     //m_token = token(name);
// }

// terminal_node::terminal_node(token val)
// {
//     //_token = val;
// }

void terminal_node::set_token(token* val)
{
    _token = val;
}