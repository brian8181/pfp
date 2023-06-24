#ifndef _terminal_node_HPP
#define _terminal_node_HPP

#include "node.hpp"
#include "token.hpp"

class terminal_node : public node
{
public:

    terminal_node();
    terminal_node(const string& token);
    terminal_node(const token& token);
    terminal_node(token* ptoken);
    ~terminal_node();
   
    token* get_token();
    void set_token(token* ptoken);

private:

    token* p_token;
};

#endif