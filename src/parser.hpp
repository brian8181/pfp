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
    void parse(const string& expression);
    bool post_fix(binary_node* p_node);
    string &post_fix_string();
    //void post_fix_string(const vector<token>& tokens, string& s);    
    void tokenize(const string& input);
    void sub_parse(vector<terminal_node>& nodes, int i, stack<terminal_node>& stack);
    void parse_tokens(vector<terminal_node>& nodes);
    void operator_pass(vector<terminal_node>& nodes, vector<char> level);

private:

    vector<terminal_node> m_nodes;
    vector<terminal_node*> m_pnodes;
    vector<token*> m_ptokens; 
    vector<vector<char>> plevels{{ '^' }, { '*', '/' }, { '+', '-' }};

};

//const vector<vector<char>> parser::plevels = {{ '^' }, { '*', '/' }, { '+', '-' }};

#endif