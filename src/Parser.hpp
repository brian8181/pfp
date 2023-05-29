#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <vector>

using std::string;
using std::vector;

// Options Flags
unsigned char DEFAULTS = 0;
unsigned char option_flags = 0; 

class Parser
{

public:

    enum TokenType
    {
        Number,
        Operator
    };

    class Token
    {

    public:

        Token(string& value);

        TokenType& GetTokenType();
        void SetTokenType(TokenType type);
        string GetValue();
        
    private:

        const int id;
        TokenType m_type = TokenType::Number;
        string m_value;

        int prev_id;
        /*static*/ int last_id;
    };