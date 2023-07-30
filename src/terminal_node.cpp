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

#include "terminal_node.hpp"
#include "token.hpp"


terminal_node::terminal_node() : _token("NO_TOKEN")
{

}

terminal_node::terminal_node(const string& s) : _token(s)
{

}

terminal_node::terminal_node(const terminal_node& n) : node(n), _token(n._token)
{

}

// const token& terminal_node::get_token() const
// {
//     return _token;
// }

token& terminal_node::get_token()
{
    return _token;
}

// only to make dynamic cast work!
void terminal_node::foo()
{
    
}
