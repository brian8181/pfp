#ifndef _node_HPP
#define _node_HPP

#include <string>

class node
{
public:

    node();
    node(const std::string& name);
    node(const node& n);
    node* get_parent();
    void set_parent(node* parent);

private:

    std::string _name;
    node* _parent = 0;
};

#endif