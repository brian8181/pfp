// License:    None
// Author:     Brian K Preston
// File Name:  node.hpp
// Build Date: Fri Jul  7 05:08:36 PM CDT 2023
// Version:    0.0.1

#ifndef _pfp_HPP
#define _pfp_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <getopt.h>
#include "bash_color.h"

using std::string;
using std::vector;

// Options Flags
// unsigned char DEFAULTS = 0;
// unsigned char option_flags = 0;

void print_help();
void print_match_header(const string& pattern, const string& src, const bool single_flag, const bool pretty_flag);
int parse_options(int argc, char* argv[]);

// Pass by reference
constexpr float exp2(const float& x, const int& n);


#endif