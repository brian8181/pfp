# Mon Jul 10 11:09:17 AM CDT 2023
MAKE_TEMPLATE = 1.5;SRCOBJ
BUILD_VERSION = 0.2.1
# make variables
SHELL = /bin/bash
CXX = g++
CXXFLAGS = -Wall -std=c++11 -DDEBUG -g
# app variables
APPNAME = pfp
EXT = cpp
ROOT = ..
BUILD = build
SRC = src
OBJ = build

all: $(APPNAME) main_test

$(APPNAME): $(APPNAME).o parser.o token.o node.o terminal_node.o binary_node.o main.o utility.o
	$(CXX) $(CXXFLAGS) $(BUILD)/$(APPNAME).o $(BUILD)/parser.o $(BUILD)/main.o $(BUILD)/utility.o \
	$(BUILD)/terminal_node.o $(BUILD)/binary_node.o \
	$(BUILD)/token.o $(BUILD)/node.o \
	-o $(BUILD)/$(APPNAME)

$(APPNAME).o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/$(APPNAME).cpp -o $(BUILD)/$(APPNAME).o

main.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.cpp -o $(BUILD)/main.o

parser.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/parser.cpp -o $(BUILD)/parser.o

node.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/node.cpp -o $(BUILD)/node.o

token.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/token.cpp -o $(BUILD)/token.o

terminal_node.o: node.o token.o
	$(CXX) $(CXXFLAGS) -c $(SRC)/terminal_node.cpp -o $(BUILD)/terminal_node.o

binary_node.o: node.o token.o
	$(CXX) $(CXXFLAGS) -c $(SRC)/binary_node.cpp -o $(BUILD)/binary_node.o

utility.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/utility.cpp -o $(BUILD)/utility.o

main_test: utility.o token.o node.o terminal_node.o binary_node.o parser.o main_test.o
	$(CXX) $(CXXFLAGS) $(BUILD)/main_test.o \
	$(BUILD)/parser.o $(BUILD)/utility.o $(BUILD)/token.o \
	$(BUILD)/node.o $(BUILD)/terminal_node.o $(BUILD)/binary_node.o \
	-o $(BUILD)/main_test

main_test.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)/main_test.cpp -o $(BUILD)/main_test.o

000-CatchMain.o: 
# $(CXX) $(CXXFLAGS) -Icatch.hpp -c $(SRC)/000-CatchMain.cpp -o $(BUILD)/000-CatchMain.o
	$(CXX) $(CXXFLAGS) -c $(SRC)/000-CatchMain.cpp -o $(BUILD)/000-CatchMain.o

uTest1:
	$(CXX) $(CXXFLAGS) -I "/home/brian/src/Catch2-3.4.0/src/" -c $(SRC)/uTest1.cpp -o $(BUILD)/uTest1

# delete object files & app executable
.PHONY: clean
clean:
	-rm -f $(BUILD)/$(APPNAME) $(BUILD)/*.o