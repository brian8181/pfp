#include "node.hpp"

node::node()
{

}

node::~node()
{
    
}

node* node::get_parent()
{
    return _parent;
}

 void node::set_parent(node* parent)
 {
    _parent = parent;
 }
