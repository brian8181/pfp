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
// File Name:  binary_node.hpp
// Build Date: Sun Jul 30 04:02:44 PM CDT 2023
// Version:    0.0.1

#ifndef _binary_node_HPP
#define _binary_node_HPP

#include "terminal_node.hpp"
#include "token.hpp"

class binary_node : public terminal_node
{

public:
    
    //binary_node(const string& token);
    //binary_node(const binary_node* node);
    binary_node(const string& op, terminal_node* left, terminal_node* right);
    virtual ~binary_node();
    terminal_node* get_left();
    terminal_node* get_right();
  
private:

    terminal_node* _op;
    terminal_node* _left;
    terminal_node* _right;
};

#endif