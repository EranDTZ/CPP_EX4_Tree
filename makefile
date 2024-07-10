#-------------------------------------------VARSION2-WORKING!-----------------------------------------------------#
# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -g `sdl2-config --cflags`

# all: tree

# tree: main.o tree.o node.o iterator.o tree_gui.o
# 	$(CXX) $(CXXFLAGS) -o tree main.o tree.o node.o iterator.o tree_gui.o `sdl2-config --libs`

# main.o: main.cpp
# 	$(CXX) $(CXXFLAGS) -c main.cpp

# tree.o: tree.cpp
# 	$(CXX) $(CXXFLAGS) -c tree.cpp

# node.o: node.cpp
# 	$(CXX) $(CXXFLAGS) -c node.cpp

# iterator.o: iterator.cpp
# 	$(CXX) $(CXXFLAGS) -c iterator.cpp

# tree_gui.o: tree_gui.cpp
# 	$(CXX) $(CXXFLAGS) -c tree_gui.cpp

# clean:
# 	rm -f *.o tree

#------------------------------------------------------ALL-TYPE--VERSION2-WORKING!-----------------------------------------#

# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -g `sdl2-config --cflags`

# all: tree

# tree: main.o tree.o node.o iterator.o tree_gui.o
# 	$(CXX) $(CXXFLAGS) -o tree main.o tree.o node.o iterator.o tree_gui.o `sdl2-config --libs`

# main.o: main.cpp
# 	$(CXX) $(CXXFLAGS) -c main.cpp

# tree.o: tree.cpp
# 	$(CXX) $(CXXFLAGS) -c tree.cpp

# node.o: node.cpp
# 	$(CXX) $(CXXFLAGS) -c node.cpp

# iterator.o: iterator.cpp
# 	$(CXX) $(CXXFLAGS) -c iterator.cpp

# tree_gui.o: tree_gui.cpp
# 	$(CXX) $(CXXFLAGS) -c tree_gui.cpp

# clean:
# 	rm -f *.o tree


#------------------------------------------------------ALL-TYPE--VERSION-3----------------------------------------#
#------------------------------------in this varsion i`m trying to show node number insaid------------------------#

# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -g `sdl2-config --cflags` -lSDL2_ttf

# all: tree

# tree: main.o tree.o node.o iterator.o tree_gui.o
# 	$(CXX) $(CXXFLAGS) -o tree main.o tree.o node.o iterator.o tree_gui.o `sdl2-config --libs` -lSDL2_ttf

# main.o: main.cpp
# 	$(CXX) $(CXXFLAGS) -c main.cpp

# tree.o: tree.cpp
# 	$(CXX) $(CXXFLAGS) -c tree.cpp

# node.o: node.cpp
# 	$(CXX) $(CXXFLAGS) -c node.cpp

# iterator.o: iterator.cpp
# 	$(CXX) $(CXXFLAGS) -c iterator.cpp

# tree_gui.o: tree_gui.cpp
# 	$(CXX) $(CXXFLAGS) -c tree_gui.cpp

# clean:
# 	rm -f *.o tree

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g `sdl2-config --cflags` -lSDL2_ttf

all: tree test

tree: main.o tree.o node.o iterator.o tree_gui.o
	$(CXX) $(CXXFLAGS) -o tree main.o tree.o node.o iterator.o tree_gui.o `sdl2-config --libs` -lSDL2_ttf

test: test.o tree.o node.o iterator.o
	$(CXX) $(CXXFLAGS) -o test test.o tree.o node.o iterator.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

tree.o: tree.cpp
	$(CXX) $(CXXFLAGS) -c tree.cpp

node.o: node.cpp
	$(CXX) $(CXXFLAGS) -c node.cpp

iterator.o: iterator.cpp
	$(CXX) $(CXXFLAGS) -c iterator.cpp

tree_gui.o: tree_gui.cpp
	$(CXX) $(CXXFLAGS) -c tree_gui.cpp

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp

clean:
	rm -f *.o tree test

