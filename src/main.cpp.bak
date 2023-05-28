#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>
#include <getopt.h>	
#include <unistd.h>
#include <termios.h>
#include "bash_color.h"
#include "main.hpp"

using namespace std;

static struct option long_options[] =
	{
		{"verbose", no_argument, 0, 'v'},
		{"help", no_argument, 0, 'h'},
		{"ignore_case", no_argument, 0, 'i'},
		{"single", no_argument, 0, 's'},
		{"pretty", no_argument, 0, 'P'}, //default
		{"no-pretty", no_argument, 0, 'p'},
		{"version", no_argument, 0, 'r'},
		{"not_extended", no_argument, 0, 'e'}, 
		{"extended", no_argument, 0, 'E'}, //default
		{"options", no_argument, 0, 'o'} //default
	};

void print_version()
{
	cout << VERSION_STRING << endl;
}

void print_help()
{
	cout << "Usage: "  
		 << FMT_BOLD << "pfp" << FMT_RESET << " "
		 << FMT_UNDERLINE << "[OPTION]..." << FMT_RESET << " "
		 << FMT_UNDERLINE << "INPUT..." << FMT_RESET << endl;
}

int main(int argc, char* argv[])
{
	termios t;
	if (tcgetattr(STDIN_FILENO, &t) < 0)
	{
		string buffer;
		cin >> buffer;
		// add piped buffer to end of argv
		char* argvtmp[sizeof(char*) * argc+1];
		memcpy(argvtmp, argv, sizeof(char*) * argc);
		argvtmp[argc] = &buffer[0];
		argv = argvtmp;
		return parse_options(++argc, argv);
	}
	return parse_options(argc, argv);
}

int parse_options(int argc, char* argv[])
{
	int opt = 0;
	int option_index = 0;
	
	optind = 0;
	opt = getopt_long(argc, argv, "hr", long_options, &option_index);
	while (opt != -1)
	{
		switch (opt)
		{
			case 'h':
				print_help();
				return 0;
			case 'r':
				print_version();
				return 0;
			default: // unknown option before args
				cerr << "Unexpected option, -h for help" << endl;
				return -1;
		}
		opt = getopt_long(argc, argv, "hr", long_options, &option_index);
	}

	//DEBUG
	cout << "Welcome to PFP (Post Fix Parser) v 0.1" << endl;

	return 0;
}
