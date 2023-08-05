// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
// License:    GPL
// Author:     Brian K Preston
// File Name:  main.cpp
// Build Date: Sun Jul 30 04:02:44 PM CDT 2023
// Version:    0.0.1

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include "token.hpp"
#include "terminal_node.hpp"
#include "binary_node.hpp"
#include "parser.hpp"

// #define TOKEN
#if defined TOKEN
// #include <string>
// using std::string;

// enum token_type
// {￼
// public:

//     token() {};
//     token(string value);
//     token(const token& t);
    
//     int get_id();
//     token_type get_type();
//     string get_value();
   
// private:

//     int _id;
//     token_type _type;
//     string _value;
//     static int _prev_id;
// };
#endif

using namespace std;

void test_1()
{
    cout << "create toekn ..." << endl;
    token t1("test");
    string s = "+";
    token t2(s);

    cout << "create terminal_node..." << endl;
    terminal_node tn1("2");
    terminal_node tn2("+");
    terminal_node tn3("3");

    // cout << "create binary_node..." << endl;
    // binary_node bn("+", &tn1, &tn3);

    cout << "create vector<terminal_node>..." << endl;
    std::vector<terminal_node> nodes;
    nodes.push_back(tn1);
    nodes.push_back(tn3);
    nodes.push_back(tn2);


    string s2 = "2+3";
    vector<token> tokens;
    parser p;
    p.parse(s2, tokens);

    // int len = nodes.size();
    // for(int i = 0; i < len; ++i)
    // {
    //     string s = nodes[i].get_token().get_value();
    //     cout << s << endl;
    // }
}

int main(int argc, char* argv[])
{
	//
    token t("test");
    //node n;

    std::string s = "test";

    test_1();
    
    return 0;
}
