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
// File Name:  parser.hpp
// Build Date: Sun Jul 30 04:02:44 PM CDT 2023
// Version:    0.0.1

#ifndef _parser_HPP
#define _parser_HPP

#include <string>
#include <vector>
#include <stack>
#include "token.hpp"
#include "terminal_node.hpp"
#include "binary_node.hpp"

using std::string;
using std::vector;
using std::stack;

class parser
{
    
public:
    
    void parse(const string& expression, /*out*/ vector<token>& tokens);
    string& post_fix_string(/*out*/ vector<token>& postfix);

private:

    void objectify2(vector<node*>& nodes, /*out*/ vector<vector<node*>>& expressions);
    void objectify(vector<node*>& tokens, /*out*/ vector<vector<node*>>& expressions);
    void tokenize(const string& input, /*out*/ vector<node*>& nodes);
    
    void post_fix(binary_node* n, /*out*/ vector<token>& tokens);
    void parse_tokens(/*out*/ vector<node*>& nodes, /*out*/ stack<node*>& nodes_stack);
    void sub_parse(const int& beg_i, /*out*/ vector<node*>& nodes, /*out*/ stack<node*>& nodes_stack);
    void operator_scans(/*out*/ vector<node*>& nodes);
    void operator_scan(const vector<char> level, /*out*/ vector<node*>& nodes);

    //vector<vector<char>> _plevels{{')'}, { '^' }, { '*', '/' }, { '+', '-' }};
    vector<vector<char>> _plevels{{ '^' }, { '*', '/' }, { '+', '-' }};
};

#endif