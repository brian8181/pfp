// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.hpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#include <iostream>
#include <regex>
#include "utility.hpp"

string tokenize(const string& sexpress, const string& input)
{
    std::regex::flag_type REGX_FLAGS = std::regex::ECMAScript;
    std::regex opers_express = std::regex(sexpress, REGX_FLAGS);

    auto begin = std::sregex_iterator(input.begin(), input.end(), opers_express);
    auto end = std::sregex_iterator();

    std::cout << "operator scan ..." << std::endl;
    for(std::sregex_iterator iter = begin; iter != end; ++iter)
    {
        std::smatch match = *iter;
        std::cout << match.str() << std::endl;
    }

    return "";
}


