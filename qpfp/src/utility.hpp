// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.hpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#ifndef _utility_HPP
#define _utility_HPP

#include <string>
#include <map>

using std::string;
using std::map;

void tokenize(const string& input, /*out*/ map<int, string>& tokens);

#endif

