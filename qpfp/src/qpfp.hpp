// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.hpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#ifndef _qpfp_HPP
#define _qpfp_HPP

// constants

// Options Flags
unsigned char DEFAULTS = 0;
unsigned char option_flags = 0; 

const string number_ex = "\\d+(\\.\\d*)?";
const string oper_ex = "[-+*^]";
const string opers_ex = "(-)|(+)|(*)|(^)";
const string parens_ex = "(\\))|(\\()";
const string binary_op_ex = number_ex + "\\s+" + "[-+*^]" + "\\s+" + number_ex;
const string exp = "(" + number_ex + ")|(" + oper_ex + ")|(" + "[\\)\\(]" + ")";

#endif

