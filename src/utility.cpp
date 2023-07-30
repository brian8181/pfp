// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// License:    GPL
// Author:     Brian K Preston
// File Name:  utility.cpp
// Build Date: Sun Jul 30 04:02:44 PM CDT 2023
// Version:    0.0.1

#include "utility.hpp"

bool is_integer(const std::string& value)
{
    int len = value.length();
    for(int i = 0; i < len; ++i)
    {
        if(!std::isdigit(value[i]))
            return false;
        return true;
    }
    return true;
}

bool is_digit(const char value) 
{ 
    return std::isdigit(value); 
}

bool is_numeric(const std::string& s) 
{ 
    std::string::const_iterator end =  s.end();
    for(std::string::const_iterator iter = s.begin(); iter != end; ++iter)
    {
        if(is_digit(*iter) != true)
            return false;
    }
    return true;
}

std::string &ltrim(std::string &s)
{
    auto iter = std::find_if( s.begin(), s.end(), 
        [](char c)
        {
            return !std::isspace<char>(c, std::locale::classic());
        } );
    s.erase(s.begin(), iter);
    return s;
}

std::string &rtrim(std::string &s)
{
    auto iter = std::find_if( s.rbegin(), s.rend(), 
        [](char c)
        {
            return !std::isspace<char>(c, std::locale::classic());
        } );
    s.erase(iter.base(), s.end());
    return s;
}

std::string &trim(std::string &s)
{
    return ltrim(rtrim(s));
}
