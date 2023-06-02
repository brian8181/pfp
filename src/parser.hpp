#ifndef _parser_HPP
#define _parser_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include "token.hpp"
#include "terminal_node.hpp"

using std::string;
using std::vector;
using std::list;

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

    list<token> parse(string input);


     /// <summary>
    /// start top level parsing
    /// </summary>
    /// <param name="tokens">the original token list</param>
    /// <returns>a list</returns>
    //static list<terminal_node> parse(List<terminal_node> tokens);


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