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
    
    void parse(const string& expression, vector<token>& tokens);
    void parse(vector<terminal_node>& nodes);
    string& post_fix_string(vector<token>& postfix);
    bool post_fix(binary_node* n, vector<token>& tokens);
    void tokenize(const string& input, vector<terminal_node>& nodes);
    void sub_parse(int i, vector<terminal_node>& nodes);
    void parse_tokens(vector<terminal_node>& nodes);
    void operator_pass(vector<char> level, vector<terminal_node>& nodes);
   
private:

    vector<vector<char>> _plevels{{ '^' }, { '*', '/' }, { '+', '-' }};
};

#endif