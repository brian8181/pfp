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

token::token(const token& tok)
{
<<<<<<< HEAD
    _value = tok._value;
    _id = tok._id;
=======
    _id = tok._id;
    _value = tok._value;
>>>>>>> debug
    _type = tok._type;
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
