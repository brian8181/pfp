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

int parse_options(int argc, char* argv[])
{
	string input = argv[1];
	parse(input);
	return 0;
}

void parse(string input)
{
	const string tokens_sexpress = "(" + number_sexpress + ")|(" + oper_sexpress + ")|(" + "[\\)\\(]" + ")";

	cout << "tokens ..." << endl;
	vector<string> tokens;
	qmatch(tokens_sexpress, input, tokens);
	int len = tokens.size();
	for(int i = 0; i < len; ++i)
	{
		cout << tokens[i] << endl;
	}

	cout << "opers ..." << endl;
	vector<string> opers;
	qmatch(oper_sexpress, input, opers);
	len = opers.size();
	for(int i = 0; i < len; ++i)
	{
		cout << opers[i] << endl;
	}

	cout << "numbers ..." << endl;
	vector<string> numbers;
	qmatch(number_sexpress, input, numbers);
	len = numbers.size();
	for(int i = 0; i < len; ++i)
	{
		cout << numbers[i] << endl;
	}

	cout << "opers_alt ..." << endl;
	vector<string> opers_alt;
	qmatch(opers_sexpress, input, opers_alt);
	len = opers_alt.size();
	for(int i = 0; i < len; ++i)
	{
		cout << opers_alt[i] << endl;
	}

	cout << "opers ..." << endl;
	vector<smatch> opers_sm;
	qmatch(oper_sexpress, input, opers_sm);
	len = opers_sm.size();
	for(int i = 0; i < len; ++i)
	{
		cout << opers_sm[i].str() << endl;
	}
}