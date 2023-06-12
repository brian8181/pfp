#ifndef _terminal_node_HPP
#define _terminal_node_HPP

#include "node.hpp"
#include "token.hpp"

class terminal_node : public node
{

public:

    terminal_node();
    terminal_node(string token);
    terminal_node(token* ptoken);
    void set_token(token* ptoken);

private:

    token* _ptoken;
};

#endif