#ifndef _token_HPP
#define _token_HPP

#include "parser.hpp"

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

};

#endif