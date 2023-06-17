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
BUILDDIR = ./build
SRCDIR = ./src
OBJDIR = ./build

# all: pfp

# all: $(APPNAME) test_class.o

# test: $(APPNAME).o main.o
# 	$(CXX) $(CXXFLAGS) $(BUILDDIR)/$(APPNAME).o $(BUILDDIR)/main.o $(BUILDDIR)/token.o -o $(BUILDDIR)/$(APPNAME)
# 	#$(CXX) $(CXXFLAGS) $(BUILDDIR)/test_class.o

#$(APPNAME):

# $(APPNAME): %.o

# %.o: %.cpp
#     $(CXX) -c $(CXXFLAGS) $< -o $@

# link
# $(APPNAME): $(APPNAME).o parser.o node.o token.o terminal_node.o binary_node.o utility.o
# 	$(CXX) $(CXXFLAGS) \
# 		$(BUILDDIR)/$(APPNAME).o $(BUILDDIR)/main.o $(BUILDDIR)/parser.o $(BUILDDIR)/node.o \
# 		$(BUILDDIR)/token.o $(BUILDDIR)/terminal_node.o $(BUILDDIR)/binary_node.o \
# 		-o $(BUILDDIR)/$(APPNAME)

# compile only
# $(APPNAME).o: utility.o
# 	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$(APPNAME).$(EXT) -o $(BUILDDIR)/$(APPNAME).o

pfp: pfp.o main.o
	$(CXX) $(CXXFLAGS) -c $(BUILDDIR)/pfp.o $(BUILDDIR)/main.o -o $(BUILDDIR)/pfp

pfp.o: main.o
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
