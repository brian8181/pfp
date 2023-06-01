#ifndef _terminal_node_HPP
#define _terminal_node_HPP

#include "node.hpp"
#include "token.hpp"

class terminal_node : public node
{

public:

    // terminal_node();
    terminal_node(string& _token);
    terminal_node(token* _token);
    void set_token(token* _token);

private:

    //token* token;
};

#endif