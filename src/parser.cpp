// License:    None
// Author:     Brian K Preston
// File Name:  parser.cpp
// Build Date: Fri Jul  7 05:08:36 PM CDT 2023
// Version:    0.0.1

#include <iostream>
#include <regex>
#include <string>
#include "utility.hpp"
#include "parser.hpp"

using std::stack;

void parser::parse(const string& infix, /*out*/ vector<token>& tokens, stack<terminal_node>& nodes_stack)
{
    vector<terminal_node> nodes;
    tokenize(infix, nodes);

    // debugging tokenize!
#if DEBUG

    // print matched tokensgit
    int len = nodes.size();
    for(int i = 0; i < len; ++i)
    {
        token t = nodes[i].get_token();
        std::string str_type = (t.get_type() == token_type::Number) ? "Number" : "Operator";
        std::cout << "matched token:" << " type->" << str_type <<  " value->"  << t.get_value() << std::endl;
    }

#endif
    
    parse_tokens(nodes, nodes_stack);
    // post_fix((binary_node*)&nodes[0], tokens);
}

void parser::parse_tokens(/*out*/ vector<terminal_node>& nodes, stack<terminal_node>& nodes_stack)
{
    //stack<terminal_node> nodes_stack;
    int len = nodes.size();
    for (int i = 0; i < len; ++i)
    {
        if (nodes[i].get_token().get_value() == "(")
        {
            // check for implied mutiplication and create explict
            if (i > 0)
            {
                if (nodes[i - 1].get_token().get_type() == token_type::Number)
                {
                    // add a "*"
                    terminal_node multi_op("*");
                    vector<terminal_node>::iterator iter = nodes.begin();
                    nodes.insert(iter, multi_op);
                    len = nodes.size();
                    ++i;
                }
            }
            sub_parse(nodes, i, nodes_stack);
            len = nodes.size();
        }
    }
    if (nodes.size() > 1)
    {
        operator_scans(nodes);
    }
}

bool parser::post_fix(binary_node* n, /*out*/ vector<token>& tokens)
{
    while (n != 0)
    {
        tokens.push_back(n->get_token());
        while (n != 0)
        {
            if(true)
            {
                
            }
            else
            {
                binary_node *p_parent = (binary_node*)&n->get_parent();
                // current is parents right move to parents Left
                if (p_parent != 0 && p_parent->get_left().get_id() != n->get_id())
                {
                    // warn not used
                    //terminal_node* p_tnode = ((binary_node*)p_node->get_parent())->get_left();
                    break;
                }
                else // current parents left move to parent.parent
                {
                    n = (binary_node*)&n->get_parent();
                }
            }
        }
    } 
    
    std::reverse(tokens.begin(), tokens.end());
    return true;
}

string& parser::post_fix_string(/*out*/ vector<token>& postfix)
{
    string str;
    int len = postfix.size();
    for (int i = 0; i < len; ++i)
    {
        token t = postfix[i];
        str.append(t.get_value() + " ");
    }
    return trim(str);
}

void parser::tokenize(const string& input, /*out*/ vector<terminal_node>& nodes)
{
    std::regex::flag_type REGX_FLAGS = std::regex::ECMAScript;
    std::regex input_epx = std::regex("(([0-9]+(\\.[0-9]*)?)|([-+*^/\\(\\)]))", REGX_FLAGS);
        
    auto begin = std::sregex_iterator(input.begin(), input.end(), input_epx);
    auto end = std::sregex_iterator();
    std::sregex_iterator iter = begin;

    for (std::sregex_iterator iter = begin; iter != end; ++iter)
    {
        std::smatch match = *iter;
        string s = match.str(0);
        terminal_node n(s);
        nodes.push_back(n);
    }
}

void parser::sub_parse(/*out*/ vector<terminal_node>& nodes, int i, /*out*/ stack<terminal_node>& nodes_stack)
{
    // stack
    while (nodes[i].get_token().get_value() != ")")
    {
        nodes_stack.push(nodes[i]);
        ++i;
    }                
    
    // unstack
    terminal_node n = nodes_stack.top();
    nodes_stack.pop();
    --i;
    vector<terminal_node> tmp_nodes;

    while (n.get_token().get_value() != "(")
    {
            tmp_nodes.push_back(n);
            n = nodes_stack.top();
            nodes_stack.pop();
            --i;
    }

    // warn not used
    int len = tmp_nodes.size();
    std::reverse(tmp_nodes.begin(), tmp_nodes.end());
    operator_scans(tmp_nodes);

    vector<terminal_node>::iterator it = nodes.begin();
    nodes.insert(it + i, tmp_nodes[0]);  // put sub list into original
    nodes.erase(it + (i+1), it + (len+2));
    
    if (nodes_stack.empty())
    {
        nodes_stack.push(nodes[0]);
        sub_parse(nodes, i + 1, nodes_stack);
    }
}

void parser::operator_scans(/*out*/ vector<terminal_node>& nodes)
{
    int len = _plevels.size();
    for (int i = 0; i < len; ++i)
    {
        operator_scan(_plevels[i], nodes);
    }
}

void parser::operator_scan(const vector<char> level, /*out*/ vector<terminal_node>& nodes)
{
    int len = nodes.size();
    for (int i = 0; i < len; ++i)
    {
        int len_ops = _plevels.size();
        for(int j = 0; j < len_ops; ++j)
        {
            terminal_node node = nodes[i];
            try
            {
                // binary_node needs to be polymorphic?
                // binary_node& bn = dynamic_cast<binary_node&>(nodes[i]);
                // if (nodes[i].get_token().get_type() == level[j])
                // {
                //     vector<terminal_node>::const_iterator iter = nodes.begin();
                //     nodes.insert(iter - (i - 1), bn);
                //     nodes.erase(iter, iter+2);
                //     len = nodes.size();
                //     --i;
                //     break;
                // }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}
