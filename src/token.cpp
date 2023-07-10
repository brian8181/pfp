// License:    None
// Author:     Brian K Preston
// File Name:  token.cpp
// Build Date: Sun Jul  9 09:09:59 AM CDT 2023
// Version:    0.0.1

#include "token.hpp"
#include "utility.hpp"

int token::_prev_id = 0;

token::token(string value) : _type(token_type::Operator)
{
    _id = ++_prev_id;
    _value = value;
        
    if(is_numeric(value))
        _type = token_type::Number;
    else
        _type = token_type::Operator;
}

token::token(const token& t)
{
    _id = t._id;
    _value = t._value;
    _type = t._type;
}

int token::get_id()
{
    return _id;
}

token_type token::get_type()
{
    return _type;
}

string token::get_value()
{
    return _value;
}
