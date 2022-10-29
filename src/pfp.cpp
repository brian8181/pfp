#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <memory>
#include <regex>
#include <cstring>
#include "pfp.hpp"

///////////////
//** Token **//
//////////////
Parser::Token::Token(string& value) : id(0)
{
    Parser::Token::prev_id = 0;
    //Parser::Token::last_id = 0;

}

Parser::TokenType& Parser::Token::GetTokenType()
{
    return m_type;
}

void Parser::Token::SetTokenType(TokenType type)
{
    m_type = type; 
}

string Parser::Token::GetValue()
{
    return m_value;
}

///////////////
//** Node **//
/////////////
Parser::Node* Parser::Node::GetParent()
{
    return parent;
}

void Parser::Node::SetParent(Parser::Node* parent)
{
    this->parent = parent;  
}

///////////////////////
//** TerminalNode **//
/////////////////////
Parser::TerminalNode::TerminalNode(string& token)
{
    this->token = new Token(token);
}


Parser::TerminalNode::TerminalNode(Token* token)
{
    SetToken(token);
}

Parser::Token* Parser::TerminalNode::GetToken()
{
    return token;
}

void Parser::TerminalNode::SetToken(Token* token)
{
    this->token = token;
}

/////////////////////
//** BinaryNode **//
///////////////////
Parser::BinaryNode::BinaryNode(Token* token, TerminalNode* left, TerminalNode* right) : TerminalNode(token)
{
    this->left = left;
    this->right = right;
    this->right->SetParent(this);
    this->left->SetParent(this);
}

Parser::TerminalNode* Parser::BinaryNode::GetRightNode()
{
    return right;
}

void Parser::BinaryNode::SetRightNode(Parser::TerminalNode* right)
{

}

Parser::TerminalNode* Parser::BinaryNode::GetLeftNode()
{
    return left;
}

void Parser::BinaryNode::SetLeftNode(Parser::TerminalNode* right)
{

}

/////////////////
//** Parser **//
///////////////
Parser::~Parser()
{
    // 1234567890
    // 0987654321
    // abcdefghij
    // ABCDEFGHIJ
    // LIHGFEDCBA 000
    //            111
    //            222
    //            888
}

std::vector<Parser::TerminalNode>* Parser::Tokenize(string input)
{
    std::regex::flag_type REGX_FLAGS = std::regex::basic;
    std::vector<Parser::TerminalNode>* nodes =  new std::vector<Parser::TerminalNode>;
    std::regex input_epx = std::regex(R"(-?\b((\d+\.\d+)|(\d+))\b)|([\^\(\)\*/\+\-])", REGX_FLAGS);
    
    auto begin = std::sregex_iterator(input.begin(), input.end(), input_epx);
    auto end = std::sregex_iterator(); 
    int match_i = 0;
    std::sregex_iterator iter = begin;
    for (; iter != end; ++iter, ++match_i)
    {
        std::smatch match = *iter;
        std::string s = match.str(0);
        Parser::TerminalNode n(s);
        nodes->push_back(n);
    }

    return nodes;

    // C# REFERENCE CODE
    // List<TerminalNode> nodes = new List<TerminalNode>();
    // Regex regx = new Regex(@"(-?\b((\d+\.\d+)|(\d+))\b)|([\^\(\)\*/\+\-])");
    // MatchCollection mc = regx.Matches(input);

    // foreach (Match m in mc)
    // {
    //     TerminalNode n = new TerminalNode(m.Value);
    //     nodes.Add(n);
    // }
    // return nodes;
}

std::vector<Parser::Token>* Parser::Parse(string input)
{
    std::vector<Parser::TerminalNode>* nodes = Parser::Tokenize(input);
    Parse(*nodes);
    Parser::TerminalNode node = nodes->front();
    return PostFix((BinaryNode&)node);
}

std::vector<Parser::TerminalNode>& Parser::Parse(std::vector<Parser::TerminalNode>& tokens)
{
    std::stack<TerminalNode> stack;
    
    int i = 0;
    int len = tokens.size();
    std::vector<Parser::TerminalNode>::iterator begin = tokens.begin();
    std::vector<Parser::TerminalNode>::iterator end = tokens.end();
    for (std::vector<Parser::TerminalNode>::iterator iter=begin; iter != end; ++iter)
    {
        Parser::Token token = *iter->GetToken();
        if(token.GetValue() == "(")
        {
            // check for implied mutiplication and create explict
            if (i > 0)
            {
                    if (tokens[i - 1].GetToken()->GetTokenType() == Number)
                    //if (tokens.insert(i-1).Token.Type == TokenType.Number)
                    {
                        // add a "*"
                        string op("*");
                        TerminalNode multi_op(op);
                        //tokens.insert(iter, multi_op);
                        tokens.push_back(multi_op);
                        len = tokens.size();
                        ++i;
                    }
            }
            SubParse(tokens, i, stack);
            //len = tokens.Count;
        }
    }

    if (tokens.size() > 1)
    {
         //ParseTokens(tokens);
    }
    return tokens;
}

std::vector<Parser::Token>* Parser::PostFix(const Parser::BinaryNode& node)
{
    const TerminalNode* current = &node;
    std::vector<Token>* postfix(new std::vector<Token>);

    string s = "+"; // debug
    Parser::Token t = Parser::Token(s); //debug

    while (current != 0)
    {
            postfix->push_back(t); // debug
            // postfix->push_back(t);
            if (typeid(current) == typeid(BinaryNode))
            {
        

            }
            //    current = ((BinaryNode)current).Right;
            //}
            //else 
            // {
            //     while (current != 0)
            //     {
            //         // current is parents right move to parents Left
            //         // if (((BinaryNode)current.Parent) != null && ((BinaryNode)current.Parent).Left != current)
            //         // {
            //         //     current = ((BinaryNode)current.Parent).Left;
            //         //     break;
            //         // }
            //         // // current parents left move to parent.parent
            //         // else 
            //         // {
            //         //     current = ((BinaryNode)current.Parent);
            //         // }
            //     }
            //}
    }
    // postfix.Reverse();
    return postfix;
    }

string Parser::PostFixString(std::vector<Token>* postfix, char s)
{
    // StringBuilder str = new StringBuilder();
    // foreach (Token t in postfix)
    // {
    //     str.Append(t.Value + s);
    // }
    // return str.ToString().TrimEnd();
    return "";
}

void Parser::SubParse(std::vector<Parser::TerminalNode>& nodes, int i, std::stack<Parser::TerminalNode>& stack)
{
    //C++ 
    // stack
    //while (nodes[i].Token.Value != ")")
    {
        //stack.push(nodes[i]);
         ++i;
    }

    // // unstack
    TerminalNode& n = stack.top();
    stack.pop();
    --i;
    std::list<TerminalNode> tmp_nodes;
    // while (n.Token.Value != "(") 
    {
        tmp_nodes.push_back(n);
    //     n = stack.Pop();
        --i;
    }

    // int len = tmp_nodes.Count;
    // tmp_nodes.Reverse();
    // ParseTokens(tmp_nodes);         // parse sub list
    // nodes.Insert(i, tmp_nodes[0]);  // put sub list into original
    // nodes.RemoveRange(i + 1, len + 2);

    // // continue ...
    // if (stack.Count != 0)
    {
    //     stack.Push(tmp_nodes[0]);
    //     SubParse(nodes, i + 1, stack);
    }

   //C# ref code
    // stack
    // while (nodes[i].Token.Value != ")")
    // {
    //     stack.Push(nodes[i]);
    //     ++i;
    // }

    // // unstack
    // TerminalNode n = stack.Pop();
    // --i;
    // List<TerminalNode> tmp_nodes = new List<TerminalNode>();
    // while (n.Token.Value != "(") 
    // {
    //     tmp_nodes.Add(n);
    //     n = stack.Pop();
    //     --i;
    // }

    // int len = tmp_nodes.Count;
    // tmp_nodes.Reverse();
    // ParseTokens(tmp_nodes);         // parse sub list
    // nodes.Insert(i, tmp_nodes[0]);  // put sub list into original
    // nodes.RemoveRange(i + 1, len + 2);

    // // continue ...`
    // if (stack.Count != 0)
    // {
    //     stack.Push(tmp_nodes[0]);
    //     SubParse(nodes, i + 1, stack);
    // }
}

void Parser::ParseTokens(std::vector<Parser::TerminalNode>* nodes)
{
    //for (char[] ops in plevels)
    //int len = Parser::plevels.size(); // debug
    int len = 0; // debug'
    for(int i = 0; i < len; ++i)
    {
        // OperatorPass(nodes, ops);
    }
}

void Parser::OperatorPass(std::vector<Parser::TerminalNode>* nodes, char* ops)
{
    int len = nodes->size();
    for (int i = 0; i < len; ++i)
    {
        // NEW C++ CODE
        int len = strlen(ops);
        for(int i = 0; i < len; ++i)
        {
            //if(nodes->begin() != BinaryNode)
            {
                //if()
                {
                    //BinaryNode node();
                    //nodes->insert(i -1, node);
                    //nodes->remove();
                    len = nodes->size();
                    ++i;
                    break;
                }
            }
        }

        //C# code
        // foreach (char c in ops)
        // {
        //     if (!(nodes[i] is BinaryNode))
        //     {
        //         if (nodes[i].Token.Value == c.ToString())
        //         {
        //             BinaryNode node = 
        //                 new BinaryNode(nodes[i].Token, nodes[i - 1], nodes[i + 1]);
        //             nodes.Insert(i - 1, node);
        //             nodes.RemoveRange(i, 3);
        //             len = nodes.Count;
        //             --i;
        //             break;
        //         }
        //     }
        // }
    }
}
