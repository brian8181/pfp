#include <iostream>
#include <string>
#include <regex>
#include <getopt.h>
#include "main.hpp"
#include "pfp.hpp"


using namespace std;


enum TokenType
{
	Number,
	Operator
};



class Token
{
	private: 

	static int last_id = 0;
	int id = 0;
	TokenType type = TokenType.Number;
	string value = null;
	
	Token(string value)
	{
		this.value = value;
		id = ++last_id;

		double d;
		bool isnum = double.TryParse(value, out d);
		if (!isnum)
			type = TokenType.Operator;
	}

	TokenType getType()
	{
		return type;
	}

	string Value
	{
		return this.value;
	}
};

int parse_options(int argc, char* argv[])
{
	cout << "Hello Template!" << endl;
	return 0;
}

/// <summary>
    /// a postfix expression parser
    /// </summary>
    class  PostfixParser
    {
        /// <summary>
        /// default operator precedence
        /// </summary>
        
		static char[][] plevels =  
        { 
            new char[1] { '^' }, 
            new char[2] { '*', '/' }, 
            new char[2] { '+', '-' }
        };

        /// <summary>
        /// token type, number or operator
        /// </summary>
        // enum TokenType
        // {
        //     Number,
        //     Operator
        // }

        /// <summary>
        /// reprsents a parser token
        /// </summary>
        

        /// <summary>
        /// represents a parser node
        /// </summary>
        class Node
        {
            Node parent = null;

            Node Parent
            {
                get { return parent; }
                set { parent = value; }
            }
        }
    }

