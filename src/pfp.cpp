#include <iostream>
#include <string>
// #include <regex>
// #include "main.hpp"
#include "pfp.hpp"

Parser::Token::Token(string& value)
{

}

Parser::TerminalNode::TerminalNode(Token* token)
{

}

Parser::TerminalNode::TerminalNode(string& token)
{
    
}

Parser::BinaryNode::BinaryNode(Token* token, TerminalNode* left, TerminalNode* right) : TerminalNode(token)
{

}

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