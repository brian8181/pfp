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
#include "utility.hpp"

using namespace std;

const int NUMBER = 1;
const int MULT_DIV = 0;
const int ADD_SUB = 0;
const int OPERATOR = 3;
const int PAREN = 0;
const int OPEN_PAREN = 5;
const int CLOSE_PAREN = 5;

void parse(string exp);
void scan_for_opers(const string& input, /*out*/ map<int, string>& tokens);
void scan_for_numbers(const string& input, /*out*/ map<int, string>& tokens);

int parse_options(int argc, char* argv[])
{
	string input = argv[1];
	parse(input);
	return 0;
}

void parse(string input)
{
	const string tokens_sexpress = "(" + number_sexpress + ")|(" + oper_sexpress + ")|(" + "[\\)\\(]" + ")";
	vector<string> tokens;
	tokenize(tokens_sexpress, input, tokens);
	int len = tokens.size();
	for(int i = 0; i < len; ++i)
	{
		cout << tokens[i] << endl;
	}

	// scan_for_opers(exp, tokens);
	// scan_for_numbers(exp, tokens);
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

void scan_for_numbers(const string& input, /*out*/ map<int, string>& tokens)
{
	std::regex::flag_type REGX_FLAGS = std::regex::ECMAScript;
	std::regex number_express = std::regex(number_sexpress, REGX_FLAGS);

	auto begin = std::sregex_iterator(input.begin(), input.end(), number_express);
	auto end = std::sregex_iterator();

	cout << "operator scan ..." << endl;
	for(std::sregex_iterator iter = begin; iter != end; ++iter)
	{
		std::smatch match = *iter;
		cout << match.str() << endl;
	}
}
