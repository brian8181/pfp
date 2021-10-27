#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <memory>
#include "pfp.hpp"


//** Token **//
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

//** Node **//
Parser::Node* Parser::Node::GetParent()
{
    return parent;
}

void Parser::Node::SetParent(Parser::Node* parent)
{
    this->parent = parent;  
}

//** TerminalNode **//
// Parser::TerminalNode::TerminalNode()
// {

// }

Parser::TerminalNode::TerminalNode(Token* token)
{
    SetToken(token);
}

Parser::TerminalNode::TerminalNode(string& token)
{
    this->token = new Token(token);
}

Parser::Token* Parser::TerminalNode::GetToken()
{
    return token;
}

void Parser::TerminalNode::SetToken(Token* token)
{
    this->token = token;
}

//** BinaryNode **//
// Parser::BinaryNode::BinaryNode( const TerminalNode& node );
// {

// }

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

//** Parser **//
Parser::~Parser()
{

}

std::list<Parser::TerminalNode>* Parser::Tokenize(string input)
{
    return 0;
}

std::list<Parser::Token>* Parser::Parse(string input)
{
    std::list<Parser::TerminalNode>* nodes = Parser::Tokenize(input);
    Parse(*nodes);
    Parser::TerminalNode node = nodes->front();
    return PostFix((BinaryNode&)node);
}

std::list<Parser::TerminalNode>& Parser::Parse(std::list<Parser::TerminalNode>& tokens)
{
    std::stack<TerminalNode> stack;

    std::list<Parser::TerminalNode>::iterator begin = tokens.begin();
    std::list<Parser::TerminalNode>::iterator end = tokens.end();
    for (std::list<Parser::TerminalNode>::iterator iter=begin; iter != end; ++iter)
    {
        if(/* iter->token->GetValue() == "("*/0)
        {
            // check for implied mutiplication and create explict
    //       if (i > 0)
    //         {
    //             if (tokens[i - 1].Token.Type == TokenType.Number)
    //             {
    //                 // add a "*"
    //                 TerminalNode multi_op = new TerminalNode("*");
    //                 tokens.Insert(i, multi_op);
    //                 len = tokens.Count;
    //                 ++i;
    //             }
    //         }
    //         SubParse(tokens, i, stack);
    //         len = tokens.Count;
        }
    }

    // if (tokens.Count > 1)
    //     ParseTokens(tokens);
    return tokens;
}

std::list<Parser::Token>* Parser::PostFix(const Parser::BinaryNode& node)
{
    const TerminalNode* current = &node;
    std::unique_ptr<std::list<Token>> postfix(new std::list<Token>);

    string s = "+"; // debug
    Parser::Token t = Parser::Token(s); //debug

    while (current != 0)
    {
            postfix->push_back(t); // debug
            //postfix_->push_back(current->token);
    //     if (current is BinaryNode)
    //     {
    //         current = ((BinaryNode)current).Right;
    //     }
    //     else 
    //     {
    //         while (current != null)
    //         {
    //             // current is parents right move to parents Left
    //             if (((BinaryNode)current.Parent) != null && ((BinaryNode)current.Parent).Left != current)
    //             {
    //                 current = ((BinaryNode)current.Parent).Left;
    //                 break;
    //             }
    //             // current parents left move to parent.parent
    //             else 
    //             {
    //                 current = ((BinaryNode)current.Parent);
    //             }
    //         }
    //     }
    }
    // postfix.Reverse();
    return postfix.get();
}

string Parser::PostFixString(std::list<Token>* postfix, char s)
{
    // StringBuilder str = new StringBuilder();
    // foreach (Token t in postfix)
    // {
    //     str.Append(t.Value + s);
    // }
    // return str.ToString().TrimEnd();
    return "";
}

void Parser::SubParse(std::list<Parser::TerminalNode>* nodes, int i, std::stack<Parser::TerminalNode> stack)
{
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

    // // continue ...
    // if (stack.Count != 0)
    // {
    //     stack.Push(tmp_nodes[0]);
    //     SubParse(nodes, i + 1, stack);
    // }
}

void Parser::ParseTokens(std::list<Parser::TerminalNode>* nodes)
{
    //for (char[] ops in plevels)
    //int len = Parser::plevels.size(); // debug
    int len = 0; // debug'
    for(int i = 0; i < len; ++i)
    {
    //     OperatorPass(nodes, ops);
    }
}

void Parser::OperatorPass(std::list<Parser::TerminalNode>* nodes, char* ops)
{
    int len = nodes->size();
    for (int i = 0; i < len; ++i)
    {
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
