#include <iostream>
#include "tree.hpp"
#include "complex.hpp"

int main() {
    Tree<Complex> t;

    t.add_root(Complex(1, 2));
    t.add_sub_node(Complex(1, 2), Complex(3, 4));
    t.add_sub_node(Complex(1, 2), Complex(5, 6));
    t.add_sub_node(Complex(3, 4), Complex(7, 8));

    std::cout << "Pre-Order Traversal: ";
    for (auto it = t.begin_pre_order(); it != t.end_pre_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Post-Order Traversal: ";
    for (auto it = t.begin_post_order(); it != t.end_post_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "In-Order Traversal: ";
    for (auto it = t.begin_in_order(); it != t.end_in_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "BFS Traversal: ";
    for (auto it = t.begin_bfs_scan(); it != t.end_bfs_scan(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "DFS Traversal: ";
    for (auto it = t.begin_dfs_scan(); it != t.end_dfs_scan(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
