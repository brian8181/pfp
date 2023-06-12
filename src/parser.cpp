#include "parser.hpp"
#include <regex>

parser::parser()
{
     plevels.push_back(level1);
     plevels.push_back(level2);
     plevels.push_back(level3);
}

static bool tokenize(const string& input, terminal_node& nodes)
{

    return true;
}

std::vector<terminal_node>* parser::tokenize(string input)
{
    std::regex::flag_type REGX_FLAGS = std::regex::basic;
    std::vector<terminal_node>* nodes =  new std::vector<terminal_node>;
    std::regex input_epx = std::regex(R"(-?\b((\d+\.\d+)|(\d+))\b)|([\^\(\)\*/\+\-])", REGX_FLAGS);
    
    auto begin = std::sregex_iterator(input.begin(), input.end(), input_epx);
    auto end = std::sregex_iterator(); 
    int match_i = 0;
    std::sregex_iterator iter = begin;
    for (; iter != end; ++iter, ++match_i)
    {
        std::smatch match = *iter;
        std::string s = match.str(0);
        token t(s);
        terminal_node n(&t);
        nodes->push_back(n);
    }

    return nodes;

    // C# REFERENCE CODE
    // List<TerminalNode> nodes = new List<TerminalNode>();
    // Regex regx = new Regex(@"(-?\b((\d+\.\d+)|(\d+))\b)|([\^\(\)\*/\+\-])");
    // MatchCollection mc = regx.Matches(input);

    // foreach (Match m in mc)
    // {
    //     TerminalNode n = new TerminalNode(m.Value);
    //     nodes.Add(n);
    // }
    // return nodes;
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


list<terminal_node> parser::parse(list<terminal_node> tokens)
{
    return tokens;
}
