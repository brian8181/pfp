// License:    None
// Author:     Brian K Preston
// File Name:  parser.hpp
// Build Date: Fri Jul  7 05:08:36 PM CDT 2023
// Version:    0.0.1

#ifndef _parser_HPP
#define _parser_HPP

#include <string>
#include <vector>
#include "token.hpp"
#include "terminal_node.hpp"
#include "binary_node.hpp"

using std::string;
using std::vector;

class parser
{
public:
    
    void parse(const string& expression, /*out*/ vector<token>& tokens);
    void parse(/*out*/ vector<terminal_node>& nodes);
    string& post_fix_string(/*out*/ vector<token>& postfix);
    bool post_fix(binary_node* n, /*out*/ vector<token>& tokens);
    void tokenize(const string& input, /*out*/ vector<terminal_node>& nodes);
    void sub_parse(int i, /*out*/ vector<terminal_node>& nodes);
    void parse_tokens(/*out*/ vector<terminal_node>& nodes);
    void operator_pass(const vector<char> level, /*out*/ vector<terminal_node>& nodes);
   
private:

    vector<vector<char>> _plevels{{ '^' }, { '*', '/' }, { '+', '-' }};
};

#endif
