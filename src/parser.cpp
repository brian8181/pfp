#include <stack>
#include <regex>
#include "utility.hpp"
#include "parser.hpp"

bool parser::parse(const string& expression)
{
    vector<terminal_node> nodes;
    bool ret = parser::tokenize(expression, nodes);
    parser::parse(nodes);

    vector<token> tokens;
    binary_node n = static_cast<binary_node>(nodes[0]);
    parser::post_fix(n, tokens);
    return true; //parser::post_fix((binary_node)nodes[0], nodes);
}

bool parser::parse(vector<terminal_node>& tokens)
{
    stack<terminal_node> stack;
    int len = tokens.size();
    for (int i = 0; i < len; ++i)
    {
        if (tokens[i].get_token()->get_value() == "(")
        {
            // check for implied mutiplication and create explict
            if (i > 0)
            {
                if (tokens[i - 1].get_token()->get_type() == token_type::Number)
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

bool parser::post_fix(binary_node& node, vector<token>& tokens)
{
    terminal_node* current = &node;
    while (current != 0)
    {
        tokens.push_back(*current->get_token());
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

    std::reverse(tokens.begin(), tokens.end());
    return true;
}

// constexpr vector<token> parser::_post_fix(binary_node& node, vector<token>& tokens)
// {
//     terminal_node* current = &node;
//     vector<token> postfix;
//     while (current != 0)
//     {
//         postfix.push_back(*current->get_token());
//         current = (binary_node*)current;
    
//         while (current != 0)
//         {
//             // current is parents right move to parents Left
//             if ((binary_node*)current->get_parent() != 0 && ((binary_node*)current->get_parent())->get_left() != current)
//             {
//                 current = ((binary_node*)current->get_parent())->get_left();
//                 break;
//             }
//             else // current parents left move to parent.parent
//             {
//                 current = ((binary_node*)current->get_parent());
//             }
//         }
//     }

//     std::reverse(postfix.begin(), postfix.end());
//     return postfix;
// }

const string& parser::post_fix_string(const vector<token>& tokens)                 
{
    string str;
    int len = tokens.size();
    for(int i = 0; i < len; ++i)
    {
        token t = tokens[i];
        str.append(t.get_value() + " ");
    }
    return trim(str);
}

bool parser::tokenize(const string& input, vector<terminal_node>& nodes)
{
    std::regex::flag_type REGX_FLAGS = std::regex::basic;
    std::regex input_epx = std::regex(R"(-?\b((\d+\.\d+)|(\d+))\b)|([\^\(\)\*/\+\-])", REGX_FLAGS);
    
    auto begin = std::sregex_iterator(input.begin(), input.end(), input_epx);
    auto end = std::sregex_iterator(); 
   
    for (std::sregex_iterator iter = begin; iter != end; ++iter)
    {
        std::smatch match = *iter;
        string s = match.str(0);
        token t(s);
        terminal_node n(&t);
        nodes.push_back(n);
    }

    return true;
}

void parser::sub_parse(vector<terminal_node>& nodes, int i, stack<terminal_node>& stack)
{
    // stack
    while (nodes[i].get_token()->get_value() != ")")
    {
        stack.push(nodes[i]);
        ++i;
    }

    // unstack
    terminal_node n = stack.top();
    stack.pop();
    --i;

    vector<terminal_node> tmp_nodes;
    while (n.get_token()->get_value() != "(") 
    {
        tmp_nodes.push_back(n);
        n = stack.top();
        stack.pop();
        --i;
    }

    int len = tmp_nodes.size();
    std::reverse(tmp_nodes.begin(), tmp_nodes.end());
    parse_tokens(tmp_nodes);

    //todo BKP
    // nodes.Insert(i, tmp_nodes[0]);  // put sub list into original
    // nodes.RemoveRange(i + 1, len + 2);

    // continue ...
    if (stack.empty())
    {
        stack.push(tmp_nodes[0]);
        sub_parse(nodes, i + 1, stack);
    }
}

void parser::parse_tokens(vector<terminal_node>& nodes)
{
    int len = plevels.size();
    for(int i = 0; i < len; ++i)
    {
        operator_pass(nodes, plevels[i]);
    }
}

void parser::operator_pass(vector<terminal_node>& nodes, vector<char> level)
{
    int len = nodes.size();;
    for (int i = 0; i < len; ++i)
    {
        int len = 0; // todo
        for (int i = 0; i < len; ++i)
        {
            //if (!(nodes[i] is BinaryNode))
            {
                //if (nodes[i].get_token()->get_type() == c.ToString())
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
