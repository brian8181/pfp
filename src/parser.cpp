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
    return true;
}

string parser::post_fix_string(const list<token>& postfix, char c)                    //tokens.Insert(i, multi_op);
{
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

}

void parser::parse_tokens(const vector<terminal_node>& nodes)
{

}

void parser::operator_pass(const list<terminal_node>& nodes, char ops[])
{

}
