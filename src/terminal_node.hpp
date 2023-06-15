#ifndef _terminal_node_HPP
#define _terminal_node_HPP

#include "node.hpp"
#include "token.hpp"

class terminal_node : public node
{
public:

    terminal_node(const string& token);
    terminal_node(token* ptoken);
    void set_token(token* ptoken);
    token* get_token();

private:

    token* _ptoken;
};

#endif