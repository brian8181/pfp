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

// binary_node::binary_node(const string& token) : terminal_node(token)
// {
    
// }

binary_node::binary_node(string& token) : terminal_node(token)
{
    
}

binary_node::binary_node(const string& token, terminal_node* left, terminal_node* right) : terminal_node(token)
{
    _left = left;
    _right = right;
    left->set_parent(this);
    right->set_parent(this);
}

// binary_node::binary_node(const binary_node* node) : terminal_node(node->get_token().get_value())
// {
//     _token = node->_token;
//     _left = node->_left;
//     _right = node->_right;
//     _left->set_parent(this);
//     _right->set_parent(this);
// }

binary_node::binary_node(binary_node* node) : terminal_node(node->get_token().get_value())
{
    _token = node->_token;
    _left = node->_left;
    _right = node->_right;
    _left->set_parent(this);
    _right->set_parent(this);
}

binary_node::~binary_node()
{
    // ?
}

terminal_node* binary_node::get_left()
{
    return _left;
}

void binary_node::set_left(terminal_node* left)
{
    _left = left;
}

terminal_node* binary_node::get_right()
{
    return _right;
}

void binary_node::set_right(terminal_node* right)
{
   _right = right;
}
