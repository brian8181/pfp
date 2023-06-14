#include "token.hpp"

int token::_prev_id = 1;

token::token(string value)
{
    _value = value;
    _id = _prev_id++;
    
    //double d;
    //bool isnum = false; // todo
    // if(!isnum)
    //     m_type = token_type::operator;

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