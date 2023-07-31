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
// File Name:  terminal_node.cpp
// Build Date: Sun Jul 30 04:02:44 PM CDT 2023
// Version:    0.0.1

#ifndef _terminal_node_HPP
#define _terminal_node_HPP

#include <string>
#include "node.hpp"
#include "token.hpp"

class terminal_node : public node
{

public:

    terminal_node(const std::string& s);
    terminal_node(const terminal_node& n);
    token& get_token();
    
protected:

    token _token;
    // needs to be polymorphic
    virtual void foo();
};

#endif
