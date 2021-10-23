#include <iostream>
#include <string>
// #include <regex>
// #include <getopt.h>
// #include "main.hpp"
#include "pfp.hpp"

Token::Token(string& value)
{

}

TerminalNode::TerminalNode(Token* token)
{

}


TerminalNode::TerminalNode(string& token)
{
    
}

BinaryNode::BinaryNode(Token* token, TerminalNode* left, TerminalNode* right) : TerminalNode(token)
{

}

