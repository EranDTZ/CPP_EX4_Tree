/*------------------------------------------------------ALL-TYPE--VERSION-2-WORKING!----------------------------------------*/

#include "tree_gui.hpp"
#include <iostream>
#include <sstream>

// Template specializations for valueToString must come before the template instantiation

template <>
std::string TreeGUI<int>::valueToString(const int& value) {
    return std::to_string(value);
}

template <>
std::string TreeGUI<double>::valueToString(const double& value) {
    return std::to_string(value);
}

template <>
std::string TreeGUI<std::string>::valueToString(const std::string& value) {
    return value;
}

template <>
std::string TreeGUI<Complex>::valueToString(const Complex& value) {
    return value.toString();
}

// Constructor and Destructor
template <typename T>
TreeGUI<T>::TreeGUI(const Tree<T>& tree)
    : tree(tree), window(nullptr), renderer(nullptr),
      screenWidth(800), screenHeight(600),
      nodeWidth(100), nodeHeight(50) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    window = SDL_CreateWindow("Tree Visualization", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }
}

template <typename T>
TreeGUI<T>::~TreeGUI() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// Run method
template <typename T>
void TreeGUI<T>::run() {
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        renderTree(tree.getRoot(), screenWidth / 2, 50, 0);

        SDL_RenderPresent(renderer);
    }
}

// Render tree method
template <typename T>
void TreeGUI<T>::renderTree(Node<T>* node, int x, int y, int level) {
    if (node == nullptr) return;

    drawNode(valueToString(node->value), x, y);

    int childX = x - (node->children.size() * nodeWidth / 2);
    int childY = y + nodeHeight + 50;

    for (auto* child : node->children) {
        SDL_RenderDrawLine(renderer, x + nodeWidth / 2, y + nodeHeight, childX + nodeWidth / 2, childY);
        renderTree(child, childX, childY, level + 1);
        childX += nodeWidth;
    }
}

// Draw node method
template <typename T>
void TreeGUI<T>::drawNode(const std::string& text, int x, int y) {
    SDL_Rect rect = { x, y, nodeWidth, nodeHeight };
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);
    // Here you can add code to render the text inside the node
}

// Include the explicit template instantiation at the end of the file
template class TreeGUI<int>;
template class TreeGUI<double>;
template class TreeGUI<std::string>;
template class TreeGUI<Complex>;

