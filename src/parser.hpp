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
using std::vector;
using std::list;
using std::stack;

// Options Flags
// unsigned char DEFAULTS = 0;
// unsigned char option_flags = 0; 
//char plevels[1] {'*'};



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

    static list<token> parse(string input);


     /// <summary>
    /// start top level parsing
    /// </summary>
    /// <param name="tokens">the original token list</param>
    /// <returns>a list</returns>
    static list<terminal_node> parse(list<terminal_node> tokens);


    /// <summary>
    /// get postfix 
    /// </summary>
    /// <param name="node">tree to parse</param>
    /// <returns>list of tokens in postfix order</returns>
    static list<token> post_fix(binary_node node);

    /// <summary>
    /// get string representation of postfix
    /// </summary>
    /// <param name="postfix">the list to convert to sting</param>
    /// <param name="s">delimiter</param>
    /// <returns>string of postfix</returns>
    static string post_fix_string(list<token> postfix, char s = ' ');
    
    
    /// <summary>
    /// tokenize - break string into tokens, (eg. numbers and operators)
    /// </summary>
    /// <param name="input">original expression as string</param>
    /// <returns>returns a list of tokens eg. List of TerminalNodes</returns>
    static list<terminal_node> tokenize(string input);

    /// <summary>
        /// handle sub expressions in parens?
    /// </summary>
    /// <param name="nodes"></param>
    /// <param name="i"></param>
    /// <param name="stack"></param>
    static void sub_parse(list<terminal_node> nodes, int i, stack<terminal_node> stack);


    static char** get_operator_precedence();


    /// <summary>
    /// parse once string has been tokenized
    /// </summary>
    /// <param name="nodes"></param>
    static void parse_tokens(list<terminal_node> nodes);

    /// <summary>
    /// makes a left to right pass/scan for operators
    /// </summary>
    /// <param name="nodes">the nodes list</param>
    /// <param name="ops">operators to scan for</param>
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