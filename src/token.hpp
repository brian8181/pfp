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
    int get_id();
    token_type get_token_type();
    string get_token_value();
    static bool is_number(const string& s);
    
private:

    int _id;
    token_type _type;
    string _value;
    static int _prev_id;
};

#endif