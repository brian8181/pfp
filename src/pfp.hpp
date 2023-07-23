// License:    None
// Author:     Brian K Preston
// File Name:  node.hpp
// Build Date: Sun Jul  9 09:09:59 AM CDT 2023
// Version:    0.0.1

#ifndef _pfp_HPP
#define _pfp_HPP

#include <string>

using std::string;

// Options Flags
// unsigned char DEFAULTS = 0;
// unsigned char option_flags = 0;

void test_a();
void print_help();
int parse_options(int argc, char* argv[]);

#endif
