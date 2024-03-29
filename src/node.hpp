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
    number           = 0x8,
    binary_operator  = 0x10,
    urnay_operator   = 0x20,
    open_paren       = 0x40,
    close_paren      = 0x80,
    binary_operation = 0x100,
    unary_operation  = 0x200,
    end              = 0x400,
    variable         = 0x800,
    constant         = 0x1000
};

class node
{

public:

    node(const string& token);
    int get_id();
    token& get_token();
    node_type& get_type();
    node_type _type; //?
  
private:

    int _id;
    static int _prev_id;
    //? node_type _type;
    token _token;
};

#endif
