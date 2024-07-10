/*-------------------------------------------VARSION2-WORKING!-----------------------------------------------------*/

// #ifndef TREE_GUI_HPP
// #define TREE_GUI_HPP

// #include "tree.hpp"
// #include <SDL2/SDL.h>
// #include <string>

// class TreeGUI {
// public:
//     TreeGUI(const Tree<std::string>& tree);
//     ~TreeGUI();
//     void run();

// private:
//     void renderTree(Node<std::string>* node, int x, int y, int level);
//     void drawNode(const std::string& text, int x, int y);

//     const Tree<std::string>& tree;
//     SDL_Window* window;
//     SDL_Renderer* renderer;
//     int screenWidth;
//     int screenHeight;
//     int nodeWidth;
//     int nodeHeight;
// };

// #endif // TREE_GUI_HPP



/*------------------------------------------------------ALL-TYPE--VERSION-2-WORKING!----------------------------------------*/

#ifndef TREE_GUI_HPP
#define TREE_GUI_HPP

#include "tree.hpp"
#include "complex.hpp"
#include <SDL2/SDL.h>
#include <string>

template <typename T>
class TreeGUI {
public:
    TreeGUI(const Tree<T>& tree);
    ~TreeGUI();
    void run();

private:
    void renderTree(Node<T>* node, int x, int y, int level);
    void drawNode(const std::string& text, int x, int y);
    std::string valueToString(const T& value);

    const Tree<T>& tree;
    SDL_Window* window;
    SDL_Renderer* renderer;
    int screenWidth;
    int screenHeight;
    int nodeWidth;
    int nodeHeight;
};

// Template specializations
template <>
std::string TreeGUI<int>::valueToString(const int& value);

template <>
std::string TreeGUI<double>::valueToString(const double& value);

template <>
std::string TreeGUI<std::string>::valueToString(const std::string& value);

template <>
std::string TreeGUI<Complex>::valueToString(const Complex& value);

#endif // TREE_GUI_HPP


/*------------------------------------------------------ALL-TYPE--VERSION-3----------------------------------------*/
/*------------------------------------in this varsion i`m trying to show node number insaid------------------------*/


// #ifndef TREE_GUI_HPP
// #define TREE_GUI_HPP

// #include "tree.hpp"
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>
// #include "complex.hpp"
// #include <string>
// #include <sstream>

// template<typename T>
// class TreeGUI {
// public:
//     TreeGUI(const Tree<T>& tree);
//     ~TreeGUI();
//     void run();

// private:
//     void renderTree(Node<T>* node, int x, int y, int level);
//     void drawNode(const T& value, int x, int y);
//     std::string valueToString(const T& value);

//     const Tree<T>& tree;
//     SDL_Window* window;
//     SDL_Renderer* renderer;
//     TTF_Font* font;
//     int screenWidth;
//     int screenHeight;
//     int nodeWidth;
//     int nodeHeight;
// };

// #endif // TREE_GUI_HPP

