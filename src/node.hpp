#ifndef _node_HPP
#define _node_HPP

class node
{

public:

    node* get_parent();
    void set_parent(node* parent);

private:

    node* parent = 0;
};

#endif