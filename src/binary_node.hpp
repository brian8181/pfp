#ifndef _binary_node_HPP
#define _binary_node_HPP

#include "node.hpp"
#include "token.hpp"

class binary_node: public node
{

public:

    // binary_node();
  
private:

    token* _token;
};

#endif