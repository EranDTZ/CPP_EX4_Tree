CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

all: tree

tree: main.o tree.o node.o iterator.o
    $(CXX) $(CXXFLAGS) -o tree main.o tree.o node.o iterator.o

main.o: main.cpp
    $(CXX) $(CXXFLAGS) -c main.cpp

tree.o: tree.cpp
    $(CXX) $(CXXFLAGS) -c tree.cpp

node.o: node.cpp
    $(CXX) $(CXXFLAGS) -c node.cpp

iterator.o: iterator.cpp
    $(CXX) $(CXXFLAGS) -c iterator.cpp

clean:
    rm -f *.o tree
