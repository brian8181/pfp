#ifndef _terminal_node_HPP
#define _terminal_node_HPP

class terminal_node: public Node
{

public:

    terminal_node();
    terminal_node(string& token);
    terminal_node(Token* token);
    void set_token(Token* token);

private:

    token* token;
};

#endif