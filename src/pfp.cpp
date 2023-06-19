#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <memory>
#include <regex>
#include <cstring>
#include <unistd.h>
#include "pfp.hpp"
#include "token.hpp"
#include "node.hpp"
#include "terminal_node.hpp"
#include "binary_node.hpp"
#include "utility.hpp"
#include "parser.hpp"

using namespace std;

static struct option long_options[] =
{
    {"verbose", no_argument, 0, 'v'},
    {"help", no_argument, 0, 'h'},
    {"file", no_argument, 0, 'f'}
};

void print_help()
{
    cout << "\n"
         << FMT_BOLD << "pfp" << FMT_RESET << " "
         << "[OPTIONS] "
         << FMT_UNDERLINE << "[INPUT ...]" << FMT_RESET << "\n\n";
}

int parse_options(int argc, char* argv[])
{
	int opt = 0;
	int option_index = 0;
	
	optind = 0;
    bool verbose_flag = false;
    
    optind = 0; // is this needed ?????
    while((opt = getopt_long(argc, argv, "hvf", long_options, &option_index)) != -1)
    {
        switch (opt)
        {
        case 'h':
            print_help();
            return 0; 
        case 'v':
            verbose_flag = true;
            break;
        default: // unknown option before args
            fprintf(stderr, "Unexpected option, -h for help\n");
            return EXIT_FAILURE;
        }
    }

    if(verbose_flag)
    {
        print_help();
        return 0;  
    }

	cout << "Welcome to PFP (Post Fix Parser) v 0.1" << endl;
    
    // test token
    // initalize
    // string s = "2";
    token t1("token 1");
    token t2("token 2");
    cout << "Initializing ..." << endl;
    cout << "id = " << t1.get_id() << endl;
    cout << "id = " << t2.get_id() << endl; 

    //test node
    node n1;
    node n2;
    n2.set_parent(&n1);
    node* pn = n2.get_parent();

    terminal_node tn1;
    tn1.name = "tn1";
    terminal_node tn2;
    tn2.name = "tn2";
    tn2.set_parent(&tn1);
    node* ptn = tn1.get_parent();
    cout << tn2.name << " parent -> " << tn2.get_parent()->name << endl;

    //test binary node
    binary_node bn1;
    binary_node bn2;

    // test parser
    parser p;
    // list<token> tokens;
    // bool b = p.post_fix(bn1, tokens);

    test();
    cout << "is_integer(\"2\") = " << is_integer("2") << endl;
    cout << "is_digit(2) = " << is_digit('2') << endl;
    cout << "is_digit(a) = " << is_digit('a') << endl;
    cout << "is_digit(.) = " << is_digit('.') << endl;
    cout << "is_digit(-) = " << is_digit('-') << endl;
    cout << "2 - is_number = " << is_numeric("2") << endl;
    cout << "2.5 - is_number = " << is_numeric("2.5") << endl;
    cout << "a - is_number = " << is_numeric("a") << endl;
    
	return 0;
}