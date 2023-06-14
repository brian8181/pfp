#include <iostream>
#include <algorithm>

/*Simple Is-Numeric function in C++*/
bool is_digit(const char value) { return std::isdigit(value); }
bool is_numeric(const std::string& value) { return std::all_of(value.begin(), value.end(), is_digit); }