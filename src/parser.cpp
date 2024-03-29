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
// File Name:  parser.cpp
// Build Date: Sun Jul 30 04:02:44 PM CDT 2023
// Version:    0.0.1

#include <iostream>
#include <regex>
#include <string>
#include "utility.hpp"
#include "parser.hpp"

using std::string;
using std::stack;

void parser::parse(const string& expression, /*out*/ vector<token>& tokens)
{
    vector<node*> nodes;
    tokenize(expression, nodes);

    // debugging tokenize!
#ifndef DEBUG
    // print matched tokens
    int len = nodes.size();
    for(int i = 0; i < len; ++i)
    {
        token t = nodes[i]->get_token();
        std::string str_type = (t.get_type() == token_type::Number) ? "Number" : "Operator";
        std::cout << "matched token:" << " type->" << str_type <<  " value->"  << t.get_value() << std::endl;
    }  
 #endif

    vector<vector<node*>> exps;
    objectify(nodes, exps);
    //post_fix((binary_node*)&nodes[0], tokens);
}

void parser::tokenize(const string& input, /*out*/ vector<node*>& nodes)
{
    std::regex::flag_type REGX_FLAGS = std::regex::ECMAScript;
    std::regex input_epx = std::regex("(([0-9]+(\\.[0-9]*)?)|([-+*^/\\(\\)]))", REGX_FLAGS);
        
    auto begin = std::sregex_iterator(input.begin(), input.end(), input_epx);
    auto end = std::sregex_iterator();
  
    for (std::sregex_iterator iter = begin; iter != end; ++iter)
    {
        std::smatch match = *iter;
        string s = match.str(0);
        node* pn = new node(s);
        nodes.push_back(pn);
    }
}

void parser::objectify2(vector<node*>& nodes, /*out*/ vector<vector<node*>>& expressions)
{
    stack<node*> stack;
    int len = nodes.size();

    string lhs, op, rhs;
    for(int i = 0; i < len; ++i)
    {
        if(nodes[i]->get_token().get_value() != ")")
        {
            if(nodes[i]->get_token().get_type() == token_type::Operator)
            {
                binary_node* pn = new binary_node(op, lhs, rhs);
            }
        }
        if(nodes[i]->get_token().get_value() == "(")
        {
            continue;
        }
        if(nodes[i]->get_token().get_value() == ")")
        {
            rhs =  nodes[i]->get_token().get_value();
        }
        lhs = nodes[i]->get_token().get_value();
        // op = nodes[++i]->get_token().get_value();
        // string& rhs = nodes[++i]->get_token().get_value();
        // binary_node* pn = new binary_node(op, lhs, rhs);

    }
}

void parser::objectify(vector<node*>& nodes, /*out*/ vector<vector<node*>>& expressions)
{
    int len = nodes.size();
    for(int i = 0; i < len; ++i)
    {
        token_type tok_t;
        switch(tok_t)
        {
            case token_type::Number:
            {

            }
            break;
            case token_type::Operator:
            {

            }
            break;
        }
        if(nodes[i]->get_token().get_type() == token_type::Operator)
        {
            
        }

        if(nodes[i]->get_token().get_value() == ")")
        {
            int rev_i = i;
            string tval = nodes[--rev_i]->get_token().get_value();
            while(tval != "(")
            {
                tval = nodes[--rev_i]->get_token().get_value();
            }

            // for (int rev_i = 0; rev_i < i; ++rev_i)
            // {
            //     operator_scan(_plevels[rev_i], nodes);
            // }

            // remove nodes & create binary_nodes
            string left = nodes[rev_i+1]->get_token().get_value();
            string right =  nodes[rev_i+3]->get_token().get_value();
            binary_node* pbn = new binary_node(nodes[rev_i+2]->get_token().get_value(), left, right);
            
            // remove terminal nodes & replace with binary node
            vector<node*>::iterator iter = nodes.begin();
            nodes.erase(iter + rev_i, iter + rev_i+5);
            iter = nodes.begin();
            nodes.insert(iter + 3, pbn);

            // vector<node*> sub_exp;
            // sub_exp.push_back(pbn);
            // expressions.push_back(sub_exp);
        }
    }
}  

void parser::parse_tokens(/*out*/ vector<node*>& nodes, /*out*/ stack<node*>& nodes_stack)
{
    //stack<terminal_node> nodes_stack;
    int len = nodes.size();
    for (int i = 0; i < len; ++i)
    {
        if (nodes[i]->get_token().get_value() == "(")
        {
            // check for implied mutiplication and create explict
            if (i > 0)
            {
                if (nodes[i - 1]->get_token().get_type() == token_type::Operator)
                {
                    // add a "*" in before expression 3(2 + 2) -> 3*(2+2)
                    node multi_op("*");
                    vector<node*>::iterator iter = nodes.begin();
                    nodes.insert(iter, &multi_op);
                    ++i;
                }
            }
            sub_parse(i, nodes, nodes_stack);
        }
    }
    if (nodes.size() > 1)
    {
        operator_scans(nodes);
    }
}

void parser::post_fix(binary_node* n, /*out*/ vector<token>& tokens)
{
    binary_node* ptn = n;
    while (n != 0)
    {
         tokens.push_back(ptn->get_token());
         while (n != 0)
         {
            try
            {
                ptn = dynamic_cast<binary_node*>(n);
            }
            catch(const std::exception& e)
            {
                //ptn = (binary_node*)n->get_parent();
                // current is parents right move to parents Left
                // if (ptn != 0 && dynamic_cast<binary_node*>(ptn)->get_left()->get_id() != n->get_id())
                // {
                //     // warn not used
                //     ptn = (binary_node*)ptn->get_left();
                //     break;
                // }
                // else // current parents left move to parent.parent
                // {
                //     //ptn = (binary_node*)ptn->get_parent();
                // }
            }   
        }
    } 
    std::reverse(tokens.begin(), tokens.end());
}

string& parser::post_fix_string(/*out*/ vector<token>& postfix)
{
    string str;
    int len = postfix.size();
    for (int i = 0; i < len; ++i)
    {
        token t = postfix[i];
        str.append(t.get_value() + " ");
    }
    return trim(str);
}

void parser::sub_parse(const int& beg_i, /*out*/ vector<node*>& nodes, /*out*/ stack<node*>& nodes_stack)
{
    // stack
    int i = beg_i;
    while (nodes[i]->get_token().get_value() != ")")
    {
        nodes_stack.push(nodes[i]);
        ++i;
    }                
    
    // unstack
    node* n = nodes_stack.top();
    nodes_stack.pop();
    --i;
    vector<node*> tmp_nodes;

    while (n->get_token().get_value() != "(")
    {
            tmp_nodes.push_back(n);
            n = nodes_stack.top();
            nodes_stack.pop();
            --i;
    }

    // warn not used
    int len = tmp_nodes.size();
    std::reverse(tmp_nodes.begin(), tmp_nodes.end());
    operator_scans(tmp_nodes);

    vector<node*>::iterator it = nodes.begin();
    nodes.insert(it + i, tmp_nodes[0]);  // put sub list into original
    nodes.erase(it + (i+1), it + (len+2));
    
    if (nodes_stack.empty())
    {
        operator_scan(_plevels[i], nodes);
    }
}

void parser::operator_scans(/*out*/ vector<node*>& nodes)
{
    int len = _plevels.size();
    for (int i = 0; i < len; ++i)
    {
        operator_scan(_plevels[i], nodes);
    }
}

void parser::operator_scan(const vector<char> level, /*out*/ vector<node*>& nodes)
{
    int len = nodes.size();
    for (int i = 0; i < len; ++i)
    {
        int len_ops = _plevels.size();
        for(int j = 0; j < len_ops; ++j)
        {
            // find operators
            //if (nodes[i]->get_token().get_type() == level[j])  
            // if (nodes[i]->get_token().get_type() == token_type::Operator)
            // {
            //     // found operator, now create a binary operation
            //     string token = nodes[i]->get_token().get_value();
            //     binary_node* pbn = new binary_node(token, nodes[i-1], nodes[i+1]);

            //     vector<node*>::const_iterator iter = nodes.begin();
            //     nodes.insert(iter - (i - 1), pbn); // insert new binary_node
            //     nodes.erase(iter, iter+2); // erase terminals
            //     len = nodes.size();
            //     --i;
            //     break;
            // }
        }
    }
}