#ifndef _terminal_node_HPP
#define _terminal_node_HPP

#include "node.hpp"
#include "token.hpp"

class terminal_node : public node
{

public:

    terminal_node();

    // terminal_node(string& name);
    terminal_node(token val);
    void set_token(token* val);

private:

    token* _token;
};

#endif