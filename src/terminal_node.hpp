#ifndef _terminal_node_HPP
#define _terminal_node_HPP

#include "node.hpp"
#include "token.hpp"

class terminal_node : public node
{
public:

    terminal_node(const string& tok);
    terminal_node(const token& tok);
    terminal_node(token* ptok);
    void set_token(token* ptok);
    token* get_token();

private:

    token* _ptoken;
};

#endif