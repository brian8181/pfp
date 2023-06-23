#include "parser.hpp"
#include <stack>
#include <regex>

parser::parser()
{

}

bool parser::parse(vector<terminal_node>& tokens)
{
    stack<terminal_node> stack;
    int len = tokens.size();
    for (int i = 0; i < len; ++i)
    {
        if (tokens[i].get_token()->get_token_value() == "(")
        {
            // check for implied mutiplication and create explict
            if (i > 0)
            {
                if (tokens[i - 1].get_token()->get_token_type() == token_type::Number)
                {
                    // add a "*"
                    terminal_node multi_op;
                    vector<terminal_node>::iterator iter = tokens.begin();
                    tokens.insert(iter += i, multi_op);
                    len = tokens.size();
                    ++i;
                }
            }
            sub_parse(tokens, i, stack);
            len = tokens.size();
        }
    }

    if (tokens.size() > 1)
    {
        parse_tokens(tokens);
        //return tokens;
    }
    string input = "TEST";
    parser::tokenize(input, tokens);
    return true;
}

bool parser::post_fix(const binary_node& node, const list<token>& tokens)
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

    return true;
}

string parser::post_fix_string(const list<token>& postfix, char c)                    //tokens.Insert(i, multi_op);
{
    // StringBuilder str = new StringBuilder();
    // foreach (Token t in postfix)
    // {
    //     str.Append(t.Value + s);
    // }
    // return str.ToString().TrimEnd();
    
    string s = "test";
    return s;
}

bool parser::tokenize(const string& input, vector<terminal_node>& nodes)
{
    std::regex::flag_type REGX_FLAGS = std::regex::basic;
    std::regex input_epx = std::regex(R"(-?\b((\d+\.\d+)|(\d+))\b)|([\^\(\)\*/\+\-])", REGX_FLAGS);
    
    auto begin = std::sregex_iterator(input.begin(), input.end(), input_epx);
    auto end = std::sregex_iterator(); 
    int match_i = 0;
    std::sregex_iterator iter = begin;
    for (; iter != end; ++iter, ++match_i)
    {
        std::smatch match = *iter;
        std::string s = match.str(0);
        token t(s);
        terminal_node n(&t);
        nodes.push_back(n);
    }

    return true;
}

void parser::sub_parse(const vector<terminal_node>& nodes, int i, stack<terminal_node>& stack)
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

void parser::parse_tokens(const vector<terminal_node>& nodes)
{
    // foreach (char[] ops in plevels)
    // {
    //     OperatorPass(nodes, ops);
    // }
}

void parser::operator_pass(const list<terminal_node>& nodes, char ops[])
{
    // int len = nodes.Count;
    // for (int i = 0; i < len; ++i)
    // {
    //     foreach (char c in ops)
    //     {
    //         if (!(nodes[i] is BinaryNode))
    //         {
    //             if (nodes[i].Token.Value == c.ToString())
    //             {
    //                 BinaryNode node = 
    //                     new BinaryNode(nodes[i].Token, nodes[i - 1], nodes[i + 1]);
    //                 nodes.Insert(i - 1, node);
    //                 nodes.RemoveRange(i, 3);
    //                 len = nodes.Count;
    //                 --i;
    //                 break;
    //             }
    //         }
    //     }
    // }
}
