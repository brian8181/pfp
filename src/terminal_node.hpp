#ifndef _terminal_node_HPP
#define _terminal_node_HPP

class TerminalNode : public Node
{

public:

    TerminalNode();
    TerminalNode(string& token);
    TerminalNode(Token* token);
    void SetToken(Token* token);

private:

    Token* token;
};

#endif