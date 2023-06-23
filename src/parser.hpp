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

    parser();
    static bool parse(vector<terminal_node>& tokens);
    static bool post_fix(const binary_node& node, const vector<token>& tokens);
    static string post_fix_string(const vector<token>& postfix, char c);
    static bool tokenize(const string& input, vector<terminal_node>& nodes);
    static void sub_parse(const vector<terminal_node>& nodes, int i, stack<terminal_node>& stack);
    static char** get_operator_precedence();
    static void parse_tokens(const vector<terminal_node>& nodes);
    static void operator_pass(const vector<terminal_node>& nodes, char ops[]);

private:

    static vector<vector<char>> plevels{{ '^' }, { '*', '/' }, { '+', '-' }};
};

#endif