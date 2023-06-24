#ifndef _utility_HPP
#define _utility_HPP

#include <iostream>
#include <algorithm>
#include <string>

bool is_integer(const std::string& value);
bool is_digit(const char value);
bool is_numeric(const std::string& value) ;

// std::string ltrim(const std::string &s);
// std::string rtrim(const std::string &s);
// std::string trim(const std::string &s);


std::string &ltrim(std::string &s);
std::string &rtrim(std::string &s);
std::string &trim(std::string &s);

#endif