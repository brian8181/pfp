#include <iostream>
#include <stack>
#include <regex>
#include "utility.hpp"
#include "parser.hpp"

parser::parser()
{
    std::cout << "parser::parser" << std::endl;
}

void parser::parse(const string& s)
{
    parser::tokenize(s);
    binary_node node;
    _nodes.push_back(&node);
    parser::post_fix(&node);
}

void parser::parse()
{
    stack<terminal_node> stack;
    int len = _nodes.size();
    for (int i = 0; i < len; ++i)
    {
        if (_nodes[i]->get_token()->get_value() == "(")
        {
            // check for implied mutiplication and create explict
            if (i > 0)
            {
                if (_nodes[i - 1]->get_token()->get_type() == token_type::Number)
                {
                    // add a "*"
                    terminal_node multi_op;
                    vector<terminal_node*>::iterator iter = _nodes.begin();
                    //m_pnodes.insert((*iter), multi_op);
                    _nodes.insert(iter, &multi_op);
                    len = _nodes.size();
                    ++i;
                }
            }
            sub_parse(i);
            len = _tokens.size();
        }
    }
     if (_tokens.size() > 1)
     {
        parse_tokens();
        //return tokens;
    }
}

bool parser::post_fix(binary_node* n)
{
    while (n != 0)
    {
        _tokens.push_back(n->get_token());
        while (n != 0)
        {
            binary_node *p_parent = (binary_node *)n->get_parent();
            // current is parents right move to parents Left
            if (p_parent != 0 && p_parent->get_left() != n)
            {
                // warn not used
                //terminal_node* p_tnode = ((binary_node*)p_node->get_parent())->get_left();
                break;
            }
            else // current parents left move to parent.parent
            {
                n = (binary_node*)n->get_parent();
            }
        }
    }

    std::reverse(_tokens.begin(), _tokens.end());
    return true;
}

string &parser::post_fix_string()
{
    string str;
    int len = _tokens.size();
    for (int i = 0; i < len; ++i)
    {
        token* t = _tokens[i];
        str.append(t->get_value() + " ");
    }
    return trim(str);
}

void parser::tokenize(const string& input)
{
    std::regex::flag_type REGX_FLAGS = std::regex::basic;
    std::regex input_epx = std::regex(R"(-?\b((\d+\.\d+)|(\d+))\b)|([\^\(\)\*/\+\-])", REGX_FLAGS);

    auto begin = std::sregex_iterator(input.begin(), input.end(), input_epx);
    auto end = std::sregex_iterator();

    for (std::sregex_iterator iter = begin; iter != end; ++iter)
    {
        std::smatch match = *iter;
        string s = match.str(0);
        terminal_node n(s);
        _nodes.push_back(&n);
    }
}

void parser::sub_parse(int i)
{
    vector<terminal_node*> nodes;
    stack<terminal_node*> stack;
    // stack
    while (_nodes[i]->get_token()->get_value() != ")")
    {
        stack.push(nodes[i]);
        ++i;
    }                
    
    // unstack
    terminal_node* n = stack.top();
    stack.pop();
    --i;

    while (n->get_token()->get_value() != "(")
    {
        _nodes.push_back(n);
        n = stack.top();
        stack.pop();
        --i;
    }

    // warn not used
    //int len = m_pnodes.size();
    std::reverse(_nodes.begin(), _nodes.end());
    parse_tokens();

    // todo BKP
    //  nodes.Insert(i, tmp_nodes[0]);  // put sub list into original
    //  nodes.RemoveRange(i + 1, len + 2);

    if (stack.empty())
    {
        stack.push(_nodes[0]);
        sub_parse(i + 1);
    }
}

void parser::parse_tokens()
{
    int len = _plevels.size();
    for (int i = 0; i < len; ++i)
    {
        operator_pass(_plevels[i]);
    }
}

void parser::operator_pass(vector<char> level)
{
    int len = _nodes.size();
    for (int i = 0; i < len; ++i)
    {
        int len_ops = _plevels.size();
        for(int j = 0; j < len_ops; ++j)
        {
            //terminal_node* node = m_pnodes[i];
            // if (!(nodes[i] is BinaryNode))
            {
                if (_nodes[i]->get_token()->get_type() == level[j])
                {
                    binary_node node;
                    // binary_node node = binary_node(nodes[i].get_token(), nodes[i -1], nodes[i + 1]);
                    // vector<terminal_node>::const_iterator iter = m_pnodes.begin();
                    // _nodes.insert(iter - (i - 1), node);
                    // _nodes.erase(iter);
                    // _nodes.erase(iter+1);
                    // _nodes.erase(iter+2);
                    // len = _nodes.size();
                    --i;
                    break;
                }
            }
        }
    }
}
