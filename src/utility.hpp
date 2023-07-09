// License:    None
// Author:     Brian K Preston
// File Name:  utility.hpp
// Build Date: Fri Jul  7 05:08:36 PM CDT 2023
// Version:    0.0.1

#ifndef _utility_HPP
#define _utility_HPP

#include <iostream>
#include <algorithm>
#include <string>

bool is_integer(const std::string& value);
bool is_digit(const char value);
bool is_numeric(const std::string& value) ;

std::string &ltrim(std::string &s);
std::string &rtrim(std::string &s);
std::string &trim(std::string &s);

#endif
