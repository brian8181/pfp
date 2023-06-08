#include "token.hpp"

token::token(string& _value)
{
    //m_value = value;
    //id = ++last_id;
    //id = 1;

    //double d;
    //bool isnum = false; // todo
    // if(!isnum)
    //     m_type = token_type::operator;

}

int token::get_id()
{
    return _id;
}

token::token(const token& tok)
{

    _id = tok._id;
}

token_type token::get_token_type()
{
    return token_type::Number;
}