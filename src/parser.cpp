#include "parser.hpp"

parser::parser()
{
     plevels.push_back(level1);
     plevels.push_back(level2);
     plevels.push_back(level3);
}

/// <summary>
/// parse an input string
/// </summary>
/// <param name="input">the input as a string</param>
/// <returns>list of token in postfix order</returns>
list<token> parser::parse(string input)
{
    // List<TerminalNode> nodes = Tokenize(input);
    // Parse(nodes);
    // return PostFix((BinaryNode)nodes[0]);
    list<token>* ret = new list<token>();
    return *ret;
}


// list<terminal_node> parser::parse(list<terminal_node> tokens)
// {
//     return list<terminal_node>();
// }
