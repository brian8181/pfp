#ifndef _pfp_HPP
#define _pfp_HPP

#include <iostream>
#include <string>

using std::string;

// constants

// Options Flags
unsigned char DEFAULTS = 0;
unsigned char option_flags = 0; 

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

class PostfixParser
{

public:

private:

};

#endif
