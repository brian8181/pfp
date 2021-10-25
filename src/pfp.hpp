#ifndef _pfp_HPP
#define _pfp_HPP

#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <vector>

using std::string;
using std::vector;

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
        void SetParent(Node* parent);

    private:

        Node* parent = 0;
    };

    class TerminalNode : public Node
    {

    public:

        //TerminalNode();
        TerminalNode(string& token);
        TerminalNode(Token* token);

        Token* GetToken();
        void SetToken(Token* token);

    private:

        Token* token = 0;
    };


    class BinaryNode : public TerminalNode
    {

    public:

        BinaryNode(Token* token, TerminalNode* left, TerminalNode* right);
        //BinaryNode( const TerminalNode& node );

        Token* GetToken();
        void SetToken(Token* node);

        TerminalNode* GetRightNode();
        void SetRightNode(TerminalNode* node);

        TerminalNode* GetLeftNode();
        void SetLeftNode(TerminalNode* node);

    private:

        Token* token;
        TerminalNode* left;
        TerminalNode* right;
    };

    static void foo();
    static std::list<TerminalNode>* Tokenize(string input);

    static std::list<Token>* Parse(string input);
    
    static std::list<TerminalNode>* Parse(std::list<TerminalNode>& tokens);

    static std::list<Token>* PostFix(const BinaryNode& node);

    static string PostFixString(std::list<Token>* postfix, char s = ' ');

    static void SubParse(std::list<TerminalNode>* nodes, int i, std::stack<TerminalNode> stack);

    static void ParseTokens(std::list<TerminalNode>* nodes);

    static void OperatorPass(std::list<TerminalNode>* nodes, char* ops);

private:

    const vector<vector<char>> plevels{ {'^'},
                                        {'*', '/'}, 
                                        {'+', '-'} };

};

#endif
