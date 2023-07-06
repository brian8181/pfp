#ifndef _node_HPP
#define _node_HPP

#include <string>

class node
{
public:

    node(const node& n);
    node(const std::string& name);
    node* get_parent();
    void set_parent(node* parent);

protected:

    std::string _name;
    node* _parent;
};

#endif