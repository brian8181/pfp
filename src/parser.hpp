#ifndef _parser_HPP
#define _parser_HPP

#include <iostream>
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
    
    parser();
    void parse(const string& expression, vector<token>& tokens);
    void parse(vector<terminal_node>& nodes);
    bool post_fix(binary_node* n, vector<token>& tokens);
    string& post_fix_string(vector<token>& postfix);
    void tokenize(const string& input, vector<terminal_node>& nodes);
    void sub_parse(int i, vector<terminal_node>& nodes);
    void parse_tokens(vector<terminal_node>& nodes);
    void operator_pass(vector<char> level, vector<terminal_node>& nodes);

private:

    vector<vector<char>> _plevels{{ '^' }, { '*', '/' }, { '+', '-' }};
};

//const vector<vector<char>> parser::plevels = {{ '^' }, { '*', '/' }, { '+', '-' }};

#endif