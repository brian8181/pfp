// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.cpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include <getopt.h>
#include "main.hpp"
#include "bash_color.h"
#include "qpfp.hpp"

using namespace std;

const int NUMBER = 1;
const int MULT_DIV = 0;
const int ADD_SUB = 0;
const int OPERATOR = 3;
const int PAREN = 0;
const int OPEN_PAREN = 5;
const int CLOSE_PAREN = 5;

void parse(string exp);
void tokenize(const string& input, /*out*/ map<int, string>& tokens);
void scan_for_opers(map<int, string>& tokens);

int parse_options(int argc, char* argv[])
{
	string exp = argv[1];
	parse(exp);
	return 0;
}

void parse(string exp)
{
	map<int, string> tokens;
	tokenize(exp, tokens);
}

void tokenize(const string& input, /*out*/ map<int, string>& tokens)
{
	std::regex::flag_type REGX_FLAGS = std::regex::ECMAScript;
	string number_ex = "\\d+(\\.\\d*)?";
	string oper_ex = "[-+*^]";
	string opers_ex = "(-)|(+)|(*)|(^)";
	string binary_op_ex = number_ex + "\\s+" + "[-+*^]" + "\\s+" + number_ex;
	string exp = "(" + number_ex + ")|(" + oper_ex + ")|(" + "[\\)\\(]" + ")";

    std::regex num_regex = std::regex(exp, REGX_FLAGS);
	auto begin = std::sregex_iterator(input.begin(), input.end(), num_regex);
    auto end = std::sregex_iterator();
  
    for(std::sregex_iterator iter = begin; iter != end; ++iter)
    {
        std::smatch match = *iter;
		for(int i = 1; i < 5; ++i)
		{
			if(match[i].matched)
			{
				cout << match[i].str() << endl;
				std::pair<int, string> p(i, match[i].str());
				tokens.insert(p);

			}
		}
    }
}

void scan_for_opers(map<int, string>& tokens)
{
	std::regex::flag_type REGX_FLAGS = std::regex::ECMAScript;
	string number_ex = "\\d+(\\.\\d*)?";
	string oper_ex = "[-+*^]";
	string opers_ex = "(-)|(+)|(*)|(^)";
	string binary_op_ex = number_ex + "\\s+" + "[-+*^]" + "\\s+" + number_ex;
	string exp = "(" + number_ex + ")|(" + oper_ex + ")|(" + "[\\)\\(]" + ")";
}
