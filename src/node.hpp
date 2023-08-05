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
// File Name:  node.hpp
// Build Date: Sun Jul 30 04:02:44 PM CDT 2023
// Version:    0.0.1

#ifndef _node_HPP
#define _node_HPP

#include <string>
#include "token.hpp"

enum node_type
{
    unknown          = 0x1,
    literal          = 0x2,
    terminal         = 0x4,
    operation        = 0x8,
    binary_operation = 0x10,
};

class node
{
public:

    node(const string& token);
    int get_id();
    token& get_token();
    string& get_value();
    node_type _type;
    string _value;
  
private:


    int _id;
    static int _prev_id;
    token _token;
};

#endif
