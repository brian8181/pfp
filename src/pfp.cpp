// License:    None
// Author:     Brian K Preston
// File Name:  pfp.cpp
// Build Date: Fri Jul  7 05:08:36 PM CDT 2023
// Version:    0.0.1

#include <iostream>
#include <string>
#include <vector>
#include <getopt.h> 
#include "bash_color.h"
#include "pfp.hpp"
#include "token.hpp"
#include "node.hpp"
#include "terminal_node.hpp"
#include "binary_node.hpp"
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

	cout << "Welcome to PFP (Post Fix Parser) v 0.1" << endl << endl;
    print_help();

    if(argc < 2)
    {
        cout << "Error: no input" << endl;
        return -1;
    }

    string input( argv[1] );
    cout << "Input string is " << "\"" << input << "\"" << endl;
    cout << "Initializing ..." << endl;

    parser p;
    vector<token> tokens;
    p.parse(input, tokens);
    string s = p.post_fix_string(tokens);
    
    return 0;
}
