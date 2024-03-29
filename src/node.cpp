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
// File Name:  node.cpp
// Build Date: Sun Jul 30 04:02:44 PM CDT 2023
// Version:    0.0.1

#include "node.hpp"
#include "utility.hpp"

int node::_prev_id = 0;

node::node(const string& s) : _token(s)
{
    _type = node_type::terminal;

    if(is_numeric(s))
        _type = node_type::number;
    else
        _type = node_type::binary_operation;

     _id = ++_prev_id;
}

int node::get_id()
{
    return _id;
}

token& node::get_token()
{
    return _token;
}

node_type& node::get_type()
{
    return _type;
}
