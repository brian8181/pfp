#ifndef _pfp_HPP
#define _pfp_HPP

#include <iostream>
#include <string>
#include <list>
#include <stack>

using std::string;

// Options Flags
unsigned char DEFAULTS = 0;
unsigned char option_flags = 0; 

class Parser
{

public:

    enum TokenType
    {
        Number,
        Operator
    };

    class Token
    {

    public:

        Token(string& value);

    private:

        const static int last_id = 0;
        int id;
        TokenType type = TokenType::Number;
        string value;
    };

    class Node
    {

    public:

        Node* GetParent();
        void SetParent(Node& parent);

    private:

        Node* parent = 0;
    };

    class TerminalNode
    {

    public:

        TerminalNode(string& token);
        TerminalNode(Token* token);

        Token* GetToken();
        void SetToken(Token& token);

    private:

        Token* token = 0;
    };


    class BinaryNode : public TerminalNode
    {

    public:

        BinaryNode(Token* token, TerminalNode* left, TerminalNode* right);

    private:

        TerminalNode* left;
        TerminalNode* right;
    };

    static std::list<Token>& Parse(string input);

    static std::list<TerminalNode>& Parse(std::list<TerminalNode> tokens);

    static std::list<Token> PostFix(BinaryNode node);

    //static string PostFixString(List<Token> postfix, char s = ' ')

    static std::list<TerminalNode> Tokenize(string input);

    static void SubParse(std::list<TerminalNode> nodes, int i, std::stack<TerminalNode> stack);

    static void ParseTokens(std::list<TerminalNode> nodes);

    //static void OperatorPass(std::list<TerminalNode> nodes, char[] ops);

private:

    // static char plevels[][] = new char[3][] 
    // { 
    //     new char[1] { '^' }, 
    //     new char[2] { '*', '/' }, 
    //     new char[2] { '+', '-' }
    // };
};

#endif
