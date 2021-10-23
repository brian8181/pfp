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

