#ifndef _token_HPP
#define _token_HPP

#include <string>

using std::string;

enum token_type
{
    Number = 0x0,
    Operator = 0x2
};

class token
{

public:

    token(string& value);
    token(const token& tok);
    token_type get_token_type();
    int get_id();
    
public:

    int _id;
    token_type m_type = token_type::Number;
    int prev_id = 0;
    static int last_id;
    string m_value;

};

#endif