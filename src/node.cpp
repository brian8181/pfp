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
// Build Date: Fri Jul  7 05:08:36 PM CDT 2023
// Version:    0.0.1

#include "node.hpp"

int node::_prev_id = 0;

node::node() : _pparent(0)
{
}

node::node(const node& n)
{
    _id = ++_prev_id;
    _pparent = n._pparent;
}

int node::get_id()
{
    return _id;
}

node* node::get_parent()
{
    return _pparent;
}

void node::set_parent(node* pparent)
{
    _pparent = pparent;
}
