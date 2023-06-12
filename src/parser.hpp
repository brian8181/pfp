#ifndef _parser_HPP
#define _parser_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
//#include "token.hpp"
#include "terminal_node.hpp"
#include "binary_node.hpp"

using std::string;
using std::vector;
using std::list;
using std::stack;

// Options Flags
// unsigned char DEFAULTS = 0;
// unsigned char option_flags = 0; 
//char plevels[1] {'*'};

class token;

class parser
{

public:
    parser();

    // parser()
    // {
    //     plevels.push_back(level1);
    //     plevels.push_back(level2);
    //     plevels.push_back(level3);
    // }

    //// <summary>
    //// default operator precedence
    //// </summary>
    // private static char plevels[][]
    // { 
    //     // char[1] { '^' }, 
    //     // char[2] { '*', '/' }, 
    //     // char[2] { '+', '-' }
    // };

    static bool parse(const string& s, list<token> out_tokens);
    static bool post_fix(const binary_node& node, const list<token>& tokens);
    static string post_fix_string(list<token> postfix, char c);
    static bool tokenize(const string& input, vector<terminal_node>& nodes);
    static void sub_parse(list<terminal_node> nodes, int i, stack<terminal_node> stack);
    static char** get_operator_precedence();
    static void parse_tokens(list<terminal_node> nodes);
    static void operator_pass(list<terminal_node> nodes, char ops[]);
            

private:

    //static char plevels[1][1] { {'^'} };
    vector<char> level1 { '^' };
    vector<char> level2 { '*', '/' };
    vector<char> level3 { '+', '-' };

public:

    vector<vector<char>> plevels;
    //vector<vector<char>> plevels2 { vector<char>() {'a'} };
};

#endif