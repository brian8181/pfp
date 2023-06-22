#ifndef _node_HPP
#define _node_HPP

#include <string>

class node
{
public:

    std::string name;
    node* get_parent();
    void set_parent(node* parent);

private:

    node* _parent = 0;
};

#endif