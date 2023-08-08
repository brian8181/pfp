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
void scan_for_opers(const string& input, /*out*/ map<int, string>& tokens);

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
	scan_for_opers(exp, tokens);
}

void tokenize(const string& input, /*out*/ map<int, string>& tokens)
{
	const string tokens_sexpress = "(" + number_sexpress + ")|(" + oper_sexpress + ")|(" + "[\\)\\(]" + ")";
	std::regex::flag_type REGX_FLAGS = std::regex::ECMAScript;
	std::regex tokens_express = std::regex(tokens_sexpress, REGX_FLAGS);
	auto begin = std::sregex_iterator(input.begin(), input.end(), tokens_express);
	auto end = std::sregex_iterator();

	for(std::sregex_iterator iter = begin; iter != end; ++iter)
	{
		std::smatch match = *iter;
		cout << match.str() << endl;
		// for(int i = 1; i < 5; ++i)
		// {
		// 	if(match[i].matched)
		// 	{
		// 		cout << match[i].str() << endl;
		// 		std::pair<int, string> p(i, match[i].str());
		// 		tokens.insert(p);
		// 	}
		// }
	}
}

void scan_for_opers(const string& input, /*out*/ map<int, string>& tokens)
{
	std::regex::flag_type REGX_FLAGS = std::regex::ECMAScript;
	std::regex opers_express = std::regex(oper_sexpress, REGX_FLAGS);

	auto begin = std::sregex_iterator(input.begin(), input.end(), opers_express);
	auto end = std::sregex_iterator();

	cout << "operator scan ..." << endl;
	for(std::sregex_iterator iter = begin; iter != end; ++iter)
	{
		std::smatch match = *iter;
		cout << match.str() << endl;
	}
}
