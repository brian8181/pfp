#include "parser.hpp"
#include <regex>

parser::parser()
{
     plevels.push_back(level1);
     plevels.push_back(level2);
     plevels.push_back(level3);
}

void foo()
{

}

void test2()
{

}

bool parse(const string& input, list<terminal_node>& nodes)
{
    parser::tokenize(input, nodes);
    return true;
}

bool post_fix(const binary_node& node, list<token>& tokens)
{
    return true;
}

string parser::post_fix_string(const list<token>& postfix, char c)
{
    string s = "test";
    return s;
}

bool parser::tokenize(const string& input, list<terminal_node>& nodes)
{
    std::regex::flag_type REGX_FLAGS = std::regex::basic;
    //std::vector<terminal_node>* nodes =  new std::vector<terminal_node>;
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

void parser::sub_parse(const list<terminal_node>& nodes, int i, stack<terminal_node>& stack)
{

}

void parser::parse_tokens(const list<terminal_node>& nodes)
{

}

void parser::operator_pass(const list<terminal_node>& nodes, char ops[])
{

}
