#ifndef _parser_HPP
#define _parser_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include "token.hpp"
#include "terminal_node.hpp"
#include "binary_node.hpp"

using std::string;
using std::list;
using std::stack;
using std::vector;

// Options Flags
// unsigned char DEFAULTS = 0;
// unsigned char option_flags = 0; 
//char plevels[1] {'*'};

class parser
{
public:

    static bool parse(const string& expression);
    static bool parse(vector<terminal_node>& tokens);
    static bool post_fix(binary_node& node, vector<token>& tokens);
    //static constexpr vector<token> post_fix(binary_node& node, vector<token>& tokens);
    static const string& post_fix_string(const vector<token>& tokens);    
    static bool tokenize(const string& input, vector<terminal_node>& nodes);
    static void sub_parse(vector<terminal_node>& nodes, int i, stack<terminal_node>& stack);
    static char** get_operator_precedence();
    static void parse_tokens(vector<terminal_node>& nodes);
    static void operator_pass(vector<terminal_node>& nodes, vector<char> level);

private:

    static const vector<vector<char>> plevels;
};

const vector<vector<char>> parser::plevels = {{ '^' }, { '*', '/' }, { '+', '-' }};

#endif