#ifndef _token_HPP
#define _token_HPP

#include "parser.hpp"
#include "node.hpp"

enum token_type
{
    Number,
    Operator
};

class token //: public node
{

public:

    token(string& value);
    token_type get_token_type();
    
private:

    const int id = 0;
    token_type m_type = token_type::Number;
    string m_value;
    int prev_id;
    static int last_id;

};

#endif