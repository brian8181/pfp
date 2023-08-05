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
// File Name:  binary_node.cpp
// Build Date: Sun Jul 30 04:02:44 PM CDT 2023
// Version:    0.0.1

#include "binary_node.hpp"
#include "token.hpp"

binary_node:: binary_node(const string& s, const string& left, const string& right) : node(s)
{
    _type = node_type::binary_operation;
    _left = new node(left);
    _right = new node(right);
}

// binary_node::binary_node(const binary_node& n) : node(n)
// {
//     _type = node_type::binary_operation;


//     _left = n._left;
//     _right = n._right;

//     delete n.left;
//     delete n._right;
// }

binary_node::~binary_node()
{
    delete _left;
    delete _right;
}

