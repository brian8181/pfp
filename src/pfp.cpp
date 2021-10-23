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

// static std::list<Token>& Parser::Parse(string input);
// {
//     // std::list<TerminalNode> nodes = Tokenize(input);
//     // Parse(nodes);
//     // return PostFix((BinaryNode)nodes[0]);
//     return std::list<Token>();
// }


