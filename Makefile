# Thu Jun 15 03:57:16 PM CDT 2023
MAKE_TEMPLATE = 1.3;
BUILD_VERSION = 0.1.0
# make variables
SHELL = /bin/bash
CXX = g++
CXXFLAGS = -std=c++11 -DDEBUG -g
# app variables
APPNAME = pfp
EXT = cpp
ROOTDIR = ..
BUILDDIR = build
SRCDIR = src
OBJDIR = build

all: pfp

# all: $(APPNAME) test_class.o

pfp: pfp.o token.o node.o terminal_node.o binary_node.o main.o utility.o
	$(CXX) $(CXXFLAGS) $(BUILDDIR)/pfp.o $(BUILDDIR)/main.o $(BUILDDIR)/utility.o $(BUILDDIR)/terminal_node.o $(BUILDDIR)/binary_node.o \
	$(BUILDDIR)/token.o $(BUILDDIR)/node.o \
	-o $(BUILDDIR)/pfp

# compile only
# $(APPNAME).o: utility.o
# 	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$(APPNAME).$(EXT) -o $(BUILDDIR)/$(APPNAME).o

pfp.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/pfp.$(EXT) -o $(BUILDDIR)/pfp.o

main.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.$(EXT) -o $(BUILDDIR)/main.o

parser.o: node.o token.o terminal_node.o binary_node.o utility.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/parser.$(EXT) -o $(BUILDDIR)/parser.o

node.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/node.$(EXT) -o $(BUILDDIR)/node.o

token.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/token.$(EXT) -o $(BUILDDIR)/token.o

terminal_node.o: node.o token.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/terminal_node.$(EXT) -o $(BUILDDIR)/terminal_node.o

binary_node.o: node.o token.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/binary_node.$(EXT) -o $(BUILDDIR)/binary_node.o

test_class.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/test_class.$(EXT) -o $(BUILDDIR)/test_class.o

utility.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/utility.$(EXT) -o $(BUILDDIR)/utility.o

# delete object files & app executable
.PHONY: clean
clean:
	-rm -f $(BUILDDIR)/$(APPNAME) $(BUILDDIR)/*.o