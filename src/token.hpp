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

    token(string value);
    token(const token& t);
    
    int get_id();
    token_type get_type();
    string get_value();
   
private:

    int _id;
    token_type _type;
    string _value;
    static int _prev_id;
};

#endif