// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.hpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include "utility.hpp"

void tokenize(const string& sexpress, const string& input, /* out */ vector<string>& tokens)
{
    std::regex::flag_type REGX_FLAGS = std::regex::ECMAScript;
    std::regex opers_express = std::regex(sexpress, REGX_FLAGS);

    auto begin = std::sregex_iterator(input.begin(), input.end(), opers_express);
    auto end = std::sregex_iterator();

    for(std::sregex_iterator iter = begin; iter != end; ++iter)
    {
        std::smatch match = *iter;
        tokens.push_back(match.str());
    }
}


