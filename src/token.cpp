#include <iostream>
#include "token.hpp"

int token::_prev_id = 1;

token::token(string value)
{
    _value = value;
    _id = _prev_id++;
    
    double d;
    bool isnum = is_number(value);
    if(!isnum)
        _type = token_type::Operator;
}

int token::get_id()
{
    return _id;
}

token_type token::get_token_type()
{
    return _type;
}

string token::get_token_value()
{
    return _value;
}

bool token::is_number(const string& s)
{
    size_t len = s.length();
    for(int i = 0; i < len; ++i)
    {
        if( !(isdigit(s[i]) || s[i] == '.') )
            return false;
    }
    return true;
}