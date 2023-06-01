#include "token.hpp"

token::token(string& value) : id(1)
{
    //m_value = value;
    //id = ++last_id;
    //id = 1;

    //double d;
    //bool isnum = false; // todo
    // if(!isnum)
    //     m_type = token_type::operator;

}

token_type token::get_token_type()
{
    return token_type::Number;
}