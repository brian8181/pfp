#ifndef _pfp_HPP
#define _pfp_HPP

#include <iostream>
#include <string>
#include <vector>
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

        TerminalNode();
        TerminalNode(string& token);
        TerminalNode(Token* token);
        void SetToken(Token* token);

    private:

        Token* token;
    };


    class BinaryNode : public TerminalNode
    {

    public:

        BinaryNode(Token* token, Parser::TerminalNode* left, TerminalNode* right);

        Token* GetToken();
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

    static std::vector<TerminalNode>* Tokenize(string input);
    std::vector<Token>* Parse(string input);
    std::vector<TerminalNode>& Parse(std::vector<TerminalNode>& tokens);
    std::vector<Token>* PostFix(const BinaryNode& node);
    void ParseTokens(std::vector<Parser::TerminalNode>* nodes);
    string PostFixString(std::vector<Token>* postfix, char s = ' ');
    void SubParse(std::vector<TerminalNode>& nodes, int i, std::stack<TerminalNode>& stack);
    static void OperatorPass(std::vector<TerminalNode>* nodes, char* ops);

    const vector<vector<char>> plevels{ {'^'},
                                        {'*', '/'}, 
                                        {'+', '-'} };

    std::vector<Parser::TerminalNode>* p_nodes;
    std::vector<Parser::Token>* p_tokens;
};

#endif
