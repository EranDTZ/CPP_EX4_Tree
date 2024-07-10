CXX = g++
CXXFLAGS = -std=c++11 -Wall -g `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`

all: tree

tree: main.o tree.o node.o iterator.o
	$(CXX) $(CXXFLAGS) -o tree main.o tree.o node.o iterator.o $(LDFLAGS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

tree.o: tree.cpp
	$(CXX) $(CXXFLAGS) -c tree.cpp

iterator.o: iterator.cpp
	$(CXX) $(CXXFLAGS) -c iterator.cpp

clean:
	rm -f *.o tree