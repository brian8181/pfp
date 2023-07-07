#ifndef _node_HPP
#define _node_HPP

#include <string>

class node
{
public:

    node(const node& n);
    node(const std::string& name);
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