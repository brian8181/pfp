# Mon Jul 10 11:09:17 AM CDT 2023
MAKE_TEMPLATE = 1.5;
BUILD_VERSION = 0.2.1
# make variables
SHELL = /bin/bash
CXX = g++
CXXFLAGS = -Wall -std=c++11 -DDEBUG -g
# app variables
APPNAME = pfp
EXT = cpp
ROOTDIR = ..
BUILDDIR = build
SRCDIR = src
OBJDIR = build

all: $(APPNAME) main_test

$(APPNAME): $(APPNAME).o parser.o token.o node.o terminal_node.o binary_node.o main.o utility.o
	$(CXX) $(CXXFLAGS) $(BUILDDIR)/$(APPNAME).o $(BUILDDIR)/parser.o $(BUILDDIR)/main.o $(BUILDDIR)/utility.o \
	$(BUILDDIR)/terminal_node.o $(BUILDDIR)/binary_node.o \
	$(BUILDDIR)/token.o $(BUILDDIR)/node.o \
	-o $(BUILDDIR)/$(APPNAME)

$(APPNAME).o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$(APPNAME).$(EXT) -o $(BUILDDIR)/$(APPNAME).o

main.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.$(EXT) -o $(BUILDDIR)/main.o

parser.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/parser.$(EXT) -o $(BUILDDIR)/parser.o

node.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/node.$(EXT) -o $(BUILDDIR)/node.o

token.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/token.$(EXT) -o $(BUILDDIR)/token.o

terminal_node.o: node.o token.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/terminal_node.$(EXT) -o $(BUILDDIR)/terminal_node.o

binary_node.o: node.o token.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/binary_node.$(EXT) -o $(BUILDDIR)/binary_node.o

utility.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/utility.$(EXT) -o $(BUILDDIR)/utility.o

main_test: utility.o token.o main_test.o
	$(CXX) $(CXXFLAGS) $(BUILDDIR)/main_test.o $(BUILDDIR)/utility.o $(BUILDDIR)/token.o -o $(BUILDDIR)/main_test

main_test.o: utility.o token.o node.o terminal_node.o binary_node.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main_test.$(EXT) -o $(BUILDDIR)/main_test.o

000-CatchMain.o: 
	$(CXX) $(CXXFLAGS) -Icatch.hpp -c $(SRCDIR)/000-CatchMain.cpp -o $(BUILDDIR)/000-CatchMain.o

# delete object files & app executable
.PHONY: clean
clean:
	-rm -f $(BUILDDIR)/$(APPNAME) $(BUILDDIR)/*.o