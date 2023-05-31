#ifndef _parser_HPP
#define _parser_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <vector>

using std::string;
using std::vector;

// Options Flags
// unsigned char DEFAULTS = 0;
// unsigned char option_flags = 0; 
//char plevels[1] {'*'};



class parser
{

public:

    //// <summary>
    //// default operator precedence
    //// </summary>
    // private static char plevels[][]
    // { 
    //     // char[1] { '^' }, 
    //     // char[2] { '*', '/' }, 
    //     // char[2] { '+', '-' }
    // };

private:

    //static char plevels[1][1] { {'^'} };
    vector<char> level1 { '^' };
    vector<char> level2 { '*', '/' };
    vector<char> level3 { '+', '-' };
  
};

#endif