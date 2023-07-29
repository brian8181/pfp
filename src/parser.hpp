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
// Build Date: Fri Jul  7 05:08:36 PM CDT 2023
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
    
    void parse(const string& expression, /*out*/ vector<token>& tokens, /*out*/ stack<terminal_node*>& nodes_stack);
    string& post_fix_string(/*out*/ vector<token>& postfix);
    void post_fix(binary_node* n, /*out*/ vector<token>& tokens);

private:

    void tokenize(const string& input, /*out*/ vector<terminal_node*> nodes);
    void parse_tokens(/*out*/ vector<terminal_node*> nodes, /*out*/ stack<terminal_node*> nodes_stack);
    void sub_parse(/*out*/ vector<terminal_node*> nodes, int i, /*out*/ stack<terminal_node*> nodes_stack);
    void operator_scans(/*out*/ vector<terminal_node*> nodes);
    void operator_scan(const vector<char> level, /*out*/ vector<terminal_node*> nodes);

    vector<vector<char>> _plevels{{ '^' }, { '*', '/' }, { '+', '-' }};
};

#endif
