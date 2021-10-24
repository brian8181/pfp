#include <iostream>
#include <string>
#include "pfp.hpp"

Parser::Token::Token(string& value)
{

}

//** Node **//
Parser::Node* Parser::Node::GetParent()
{
    return 0;
}

void Parser::Node::SetParent(Parser::Node* parent)
{
    this->parent = parent;  
}

//** TerminalNode **//
Parser::TerminalNode::TerminalNode(Token* token)
{

}

Parser::TerminalNode::TerminalNode(string& token)
{
    
}

Parser::Token* Parser::TerminalNode::GetToken()
{
    return 0;
}

void Parser::TerminalNode::SetToken(Token* token)
{
    
}

//** BinaryNode **//
Parser::BinaryNode::BinaryNode(Token* token, TerminalNode* left, TerminalNode* right) : TerminalNode(token)
{
    this->left = left;
    this->right = right;
    this->right->SetParent(this);
    this->left->SetParent(this);
}

Parser::Token* Parser::BinaryNode::GetToken()
{
    return 0;
}

void Parser::BinaryNode::SetToken(Token* node)
{
    
}

Parser::TerminalNode* Parser::BinaryNode::GetRightNode()
{
    return 0;
}

void Parser::BinaryNode::SetRightNode(Parser::TerminalNode* right)
{

}

Parser::TerminalNode* Parser::BinaryNode::GetLeftNode()
{
    return 0;
}

void Parser::BinaryNode::SetLeftNode(Parser::TerminalNode* right)
{

}

//** Parser **//
std::list<Parser::Token>* Parser::Parse(string input)
{
    // std::list<TerminalNode> nodes = Tokenize(input);
    // Parse(nodes);
    // return PostFix((BinaryNode)nodes[0]);
    return 0;
}

std::list<Parser::TerminalNode>* Parse(std::list<Parser::TerminalNode> tokens)
{
    return 0;

}

std::list<Parser::Token>* PostFix(Parser::BinaryNode node)
{
    return 0;
}

// string PostFixString(List<Token> postfix, char s = ' ')
// {

// }

std::list<Parser::TerminalNode>* Tokenize(string input)
{
    return 0;
}

void SubParse(std::list<Parser::TerminalNode> nodes, int i, std::stack<Parser::TerminalNode> stack)
{

}

void ParseTokens(std::list<Parser::TerminalNode> nodes)
{

}

// void OperatorPass(std::list<TerminalNode> nodes, char[] ops)
// {

// }