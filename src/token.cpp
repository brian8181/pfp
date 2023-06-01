#include "token.hpp"

token::token(string& value)
{
    //m_value = value;
    //id = ++last_id;

    //double d;
    //bool isnum = false; // todo
    // if(!isnum)
    //     m_type = token_type::operator;

}

token_type token::get_token_type()
{
    return token_type::Number;
}