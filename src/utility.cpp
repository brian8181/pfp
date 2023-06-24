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

// const std::string WHITESPACE = " \n\r\t\f\v";
 
// std::string ltrim(const std::string &s)
// {
//     size_t start = s.find_first_not_of(WHITESPACE);
//     return (start == std::string::npos) ? "" : s.substr(start);
// }
 
// std::string rtrim(const std::string &s)
// {
//     size_t end = s.find_last_not_of(WHITESPACE);
//     return (end == std::string::npos) ? "" : s.substr(0, end + 1);
// }
 
// std::string trim(const std::string &s) 
// {
//     return rtrim(ltrim(s));
// }

std::string &_ltrim(std::string &s)
{
    auto it = std::find_if(s.begin(), s.end(),
                           [](char c)
                           {
                               return !std::isspace<char>(c, std::locale::classic());
                           });
    s.erase(s.begin(), it);
    return s;
}

std::string &_rtrim(std::string &s)
{
    auto it = std::find_if(s.rbegin(), s.rend(),
                           [](char c)
                           {
                               return !std::isspace<char>(c, std::locale::classic());
                           });
    s.erase(it.base(), s.end());
    return s;
}

std::string &_trim(std::string &s)
{
    return _ltrim(_rtrim(s));
}

// Print vector.
//std::for_each(nums.rbegin(), nums.rend(), [](const int n) { std::cout << n << ' '; });

// void reverse_vector(vector<T>& v)
// {
//     vector<int>::iter
// })