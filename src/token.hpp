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
// File Name:  token.hpp
// Build Date: Sun Jul 30 04:02:44 PM CDT 2023
// Version:    0.0.1

#ifndef _token_HPP
#define _token_HPP

#include <string>
using std::string;

enum token_type
{
    Number = 0x1,
    Operator = 0x2
};

class token
{
public:

    token(const string& value);
    token(const token& t);
    
    int get_id();
    token_type get_type();
    string& get_value();
   
private:

    int _id;
    token_type _type;
    string _value;
    static int _prev_id;
};

#endif
