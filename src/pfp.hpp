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

        TokenType& GetTokenType();
        void SetTokenType(TokenType type);

        string GetValue();
        
    private:

        const int id;
        TokenType m_type = TokenType::Number;
        string m_value;

        int prev_id;
        /*static*/ int last_id;
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

        Token* token;
    };


    class BinaryNode : public TerminalNode
    {

    public:

        BinaryNode(Token* token, Parser::TerminalNode* left, TerminalNode* right);

        // Token* GetToken();
        // void SetToken(Token* node);

        Parser::TerminalNode* GetRightNode();
        void SetRightNode(TerminalNode* node);

        Parser::TerminalNode* GetLeftNode();
        void SetLeftNode(TerminalNode* node);

    private:

        TerminalNode* left;
        TerminalNode* right;
    };

    ~Parser();

    static std::list<TerminalNode>* Tokenize(string input);

    static std::list<Token>* Parse(string input);
    
    static std::list<TerminalNode>& Parse(std::list<TerminalNode>& tokens);

    static std::list<Parser::Token>* PostFix(const BinaryNode& node);

    static string PostFixString(std::list<Token>* postfix, char s = ' ');

    static void SubParse(std::list<TerminalNode>* nodes, int i, std::stack<TerminalNode> stack);

    static void ParseTokens(std::list<TerminalNode>* nodes);

    static void OperatorPass(std::list<TerminalNode>* nodes, char* ops);

private:

    const vector<vector<char>> plevels{ {'^'},
                                        {'*', '/'}, 
                                        {'+', '-'} };

    // list<Parser::TerminalNode>* p_nodes;
    // list<Parser::Token>* p_token;
};

#endif
