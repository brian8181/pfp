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

bool is_numeric(const std::string& value) 
{ 
    return std::all_of(value.begin(), value.end(), is_digit); 
}