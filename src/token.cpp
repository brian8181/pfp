#include "token.hpp"

token::token(string& value)
{
    _value = value;
    //_id = _prev_id;
    
    //double d;
    //bool isnum = false; // todo
    // if(!isnum)
    //     m_type = token_type::operator;

}

token_type token::get_token_type()
{
    return _type;
}

string token::get_token_value()
{
    return _value;
}