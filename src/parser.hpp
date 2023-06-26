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
    //parser();
    void parse(const string& expression);
    bool post_fix(binary_node& node);
    string& post_fix_string(const vector<token>& tokens);    
    void tokenize(const string& input);
    static void sub_parse(vector<terminal_node>& nodes, int i, stack<terminal_node>& stack);
    static char** get_operator_precedence();
    static void parse_tokens(vector<terminal_node>& nodes);
    static void operator_pass(vector<terminal_node>& nodes, vector<char> level);

private:

    vector<terminal_node> m_nodes;
    vector<token> m_tokens; 
    vector<vector<char>> plevels{{ '^' }, { '*', '/' }, { '+', '-' }};

};

//const vector<vector<char>> parser::plevels = {{ '^' }, { '*', '/' }, { '+', '-' }};

#endif