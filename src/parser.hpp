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

class parser
{
public:
    
    parser();
    void parse();
    void parse(const string& expression);
    bool post_fix(binary_node* n);
    string& post_fix_string();
    void tokenize(const string& input);
    void sub_parse(int i);
    void parse_tokens();
    void operator_pass(vector<char> level);

private:

    vector<terminal_node*> _nodes;
    vector<token*> _tokens; 
    vector<vector<char>> _plevels{{ '^' }, { '*', '/' }, { '+', '-' }};

};

//const vector<vector<char>> parser::plevels = {{ '^' }, { '*', '/' }, { '+', '-' }};

#endif