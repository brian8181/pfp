#ifndef _node_HPP
#define _node_HPP

#include <string>

class node
{
public:

    std::string name;
    
    node();
    node(node* pparent);
    node* get_parent();
    void set_parent(node* pparent);

private:

    node* p_parent = 0;
};

#endif