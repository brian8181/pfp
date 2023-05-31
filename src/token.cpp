#include "token.hpp"

token::token(string& value)
{

}

token_type token::get_token_type()
{
    return token_type::Number;
}