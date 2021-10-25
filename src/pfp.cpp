#include <iostream>
#include <string>
#include <stack>
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
// Parser::TerminalNode::TerminalNode()
// {

// }

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

std::list<Parser::TerminalNode>* Parser::Parse(std::list<Parser::TerminalNode>& tokens)
{
    std::stack<TerminalNode> stack;

    int len = tokens.size();
    for (int i = 0; i < len; ++i)
    {
    //     if (tokens[i].Token.Value == "(")
    //     {
    //         // check for implied mutiplication and create explict
    //         if (i > 0)
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
    //     }
    }

    // if (tokens.Count > 1)
    //     ParseTokens(tokens);
    // return tokens;
    return 0;

}

std::list<Parser::Token>* Parser::PostFix(const Parser::BinaryNode& node)
{
    // TerminalNode current = node;
    // List<Token> postfix = new List<Token>();
    // while (current != null)
    // {
    //     postfix.Add(current.Token);
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
    // }
    // postfix.Reverse();
    // return postfix;
    return 0;
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
    // foreach (char[] ops in plevels)
    // {
    //     OperatorPass(nodes, ops);
    // }
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
