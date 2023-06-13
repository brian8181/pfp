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

    static bool _initialized; 
    static int _prev_id;

    static void init();
    token(string& value);
    token_type get_token_type();
    string get_token_value();
    
private:
     
    int _id;
    token_type _type;
    string _value;
};

#endif