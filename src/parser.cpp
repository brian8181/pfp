#include <stack>
#include <regex>
#include "utility.hpp"
#include "parser.hpp"

// parser::parser()
// {
// }

void parser::parse(const string& s)
{
    parser::tokenize(s);
    binary_node node;
    m_pnodes.push_back(&node);
    parser::post_fix(&node);
}

void parser::parse()
{
    stack<terminal_node> stack;
    int len = m_ptokens.size();
    for (int i = 0; i < len; ++i)
    {
        if (m_ptokens[i].get_token()->get_value() == "(")
        {
            // check for implied mutiplication and create explict
            if (i > 0)
            {
                if (m_ptokens[i - 1].get_token()->get_type() == token_type::Number)
                {
                    // add a "*"
                    terminal_node multi_op;
                    vector<terminal_node>::iterator iter = m_ptokens.begin();
                    m_ptokens.insert(iter += i, multi_op);
                    len = m_ptokens.size();
                    ++i;
                }
            }
            sub_parse(m_ptokens, i, stack);
            len = m_ptokens.size();
        }
    }
     if (m_ptokens.size() > 1)
     {
        parse_tokens(m_ptokens);
        //return tokens;
    }
}

bool parser::post_fix(binary_node* p_node)
{
    // terminal_node* current = &node;
    while (p_node != 0)
    {
        m_ptokens.push_back(p_node->get_token());
        // current = (binary_node*)current;

        while (p_node != 0)
        {
            binary_node *p_parent = (binary_node *)p_node->get_parent();
            // current is parents right move to parents Left
            if (p_parent != 0 && p_parent->get_left() != p_node)
            {
                p_node = ((binary_node*)(p_node->get_parent()))->get_left();
                break;
            }
            else // current parents left move to parent.parent
            {
                p_node = (binary_node*)p_node->get_parent();
            }
        }
    }

    std::reverse(m_ptokens.begin(), m_ptokens.end());
    return true;
}

//string &parser::post_fix_string(const vector<token> &tokens)
string &parser::post_fix_string()
{
    string str;
    int len = m_ptokens.size();
    for (int i = 0; i < len; ++i)
    {
        token* t = m_ptokens[i];
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
        token t(s);
        terminal_node n(&t);
        m_pnodes.push_back(&n);
    }
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

    while (n.get_token()->get_value() != "(")
    {
        m_pnodes.push_back(&n);
        n = stack.top();
        stack.pop();
        --i;
    }

    int len = m_pnodes.size();
    std::reverse(m_pnodes.begin(), m_pnodes.end());
    parse_tokens(&m_pnodes);

    // todo BKP
    //  nodes.Insert(i, tmp_nodes[0]);  // put sub list into original
    //  nodes.RemoveRange(i + 1, len + 2);

    if (stack.empty())
    {
        stack.push(&(m_pnodes[0]));
        sub_parse(nodes, i + 1, stack);
    }
}

void parser::parse_tokens(vector<terminal_node>& nodes)
{
    int len = plevels.size();
    for (int i = 0; i < len; ++i)
    {
        operator_pass(nodes, plevels[i]);
    }
}

void parser::operator_pass(vector<terminal_node>& nodes, vector<char> level)
{
    int len = nodes.size();
    for (int i = 0; i < len; ++i)
    {
        int len_ops = plevels.size();
        for(int j = 0; j < len_ops; ++j)
        {
            // if (!(nodes[i] is BinaryNode))
            {
                if (nodes[i].get_token()->get_type() == level[j])
                {
                    binary_node node;
                    // binary_node node = binary_node(nodes[i].get_token(), nodes[i -1], nodes[i + 1]);
                    vector<terminal_node>::const_iterator iter = nodes.begin();
                    nodes.insert(iter - (i - 1), node);
                    nodes.erase(iter);
                    nodes.erase(iter+1);
                    nodes.erase(iter+2);
                    len = nodes.size();
                    --i;
                    break;
                }
            }
        }
    }
}
