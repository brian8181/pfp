// License:    None
// Author:     Brian K Preston
// File Name:  node.hpp
// Build Date: Fri Jul  7 05:08:36 PM CDT 2023
// Version:    0.0.1

#ifndef _node_HPP
#define _node_HPP

#include <string>

class node
{
public:

    node(const std::string& name);
    node(const node& n);
    int get_id();
    node* get_parent();
    void set_parent(node* parent);
    
protected:

    std::string _name;
    node* _parent;

private:

    int _id;
    static int _prev_id;
};

#endif