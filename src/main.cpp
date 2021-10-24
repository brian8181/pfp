#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>
#include <getopt.h>	
#include <unistd.h>
#include <termios.h>
#include "main.hpp"

using std::cin;
using std::string;

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
	opt = getopt_long(argc, argv, "hvispPreEo", long_options, &option_index);
	while (opt != -1)
	{
		switch (opt)
		{
		}
	}

	return 0;
}
