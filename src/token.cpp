#include "token.hpp"
#include "utility.hpp"

int token::_prev_id = 1;

token::token(string value) : _type(token_type::Operator)
{
    _value = value;
    _id = _prev_id++;
    
    if(is_numeric(value))
        _type = token_type::Number;
    else
        _type = token_type::Operator;
}

token::token(const token& t)
{
    _value = t._value;
    _id = t._id;
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
