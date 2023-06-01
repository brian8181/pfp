#ifndef _token_HPP
#define _token_HPP

#include "parser.hpp"
#include "node.hpp"

enum token_type
{
    Number = 0x0,
    Operator = 0x2
};

class token //: public node
{

public:

    token(string& value);
    token_type get_token_type();
    
private:

    const int _id = 0;
    token_type m_type = token_type::Number;
    int prev_id = 0;
    static int last_id;
    string m_value;

};

#endif