#include "parser.hpp"
#include <stack>
#include <regex>

bool parser::parse(const string& infix_expression)
{
    vector<terminal_node> nodes;// = parser::tokenize(infix_expression);
    parser::parse(nodes);
    return true; //parser::post_fix((binary_node)nodes[0], nodes);
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

bool parser::_post_fix(binary_node& node, const vector<token>& tokens)
{
    terminal_node* current = &node;
    vector<token> postfix;
    while (current != 0)
    {
        postfix.push_back(*current->get_token());
        current = (binary_node*)current;
    
        while (current != 0)
        {
            // current is parents right move to parents Left
            if ((binary_node*)current->get_parent() != 0 && ((binary_node*)current->get_parent())->get_left() != current)
            {
                current = ((binary_node*)current->get_parent())->get_left();
                break;
            }
            else // current parents left move to parent.parent
            {
                current = ((binary_node*)current->get_parent());
            }
        }
    }

    std::reverse(postfix.begin(), postfix.end());
    //return postfix;
    return true;
}

constexpr vector<token> parser::post_fix(binary_node& node, vector<token>& tokens)
{
    terminal_node* current = &node;
    vector<token> postfix;
    while (current != 0)
    {
        postfix.push_back(*current->get_token());
        current = (binary_node*)current;
    
        while (current != 0)
        {
            // current is parents right move to parents Left
            if ((binary_node*)current->get_parent() != 0 && ((binary_node*)current->get_parent())->get_left() != current)
            {
                current = ((binary_node*)current->get_parent())->get_left();
                break;
            }
            else // current parents left move to parent.parent
            {
                current = ((binary_node*)current->get_parent());
            }
        }
    }

    std::reverse(postfix.begin(), postfix.end());
    return postfix;
}

string parser::post_fix_string(const vector<token>& postfix, char c)                    //tokens.Insert(i, multi_op);
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

void parser::operator_pass(vector<terminal_node>& nodes, char ops[])
{
    int len = nodes.size();;
    for (int i = 0; i < len; ++i)
    {
        int len = 0; // todo
        for (int i = 0; i < len; ++i)
        {
            //if (!(nodes[i] is BinaryNode))
            {
                //if (nodes[i].get_token()->get_token_type() == c.ToString())
                {
                    binary_node node;
                    //binary_node node = binary_node(nodes[i].get_token(), nodes[i -1], nodes[i + 1]); 
                    vector<terminal_node>::const_iterator iter = nodes.begin();
                    nodes.insert(iter -= (i-1), node);
                    //nodes.Insert(i - 1, node);
                    //nodes.RemoveRange(i, 3);
                    //nodes.erase()
                    len = nodes.size();
                    --i;
                    break;
                }
            }
        }
    }
}
