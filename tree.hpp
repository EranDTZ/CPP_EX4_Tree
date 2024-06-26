#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include "iterator.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdexcept>

template<typename T>
class Tree {
public:
    Tree(int k = 2);
    ~Tree();

    void add_root(const T& val);
    void add_sub_node(const T& parent_val, const T& child_val);

    Iterator<T> begin_pre_order();
    Iterator<T> end_pre_order();
    Iterator<T> begin_post_order();
    Iterator<T> end_post_order();
    Iterator<T> begin_in_order();
    Iterator<T> end_in_order();
    Iterator<T> begin_bfs_scan();
    Iterator<T> end_bfs_scan();
    Iterator<T> begin_dfs_scan();
    Iterator<T> end_dfs_scan();

    Iterator<T> myHeap();

private:
    Node<T>* root;
    int k;

    void deleteTree(Node<T>* node);
    Node<T>* find(Node<T>* node, const T& val);
};

#include "tree.cpp"

#endif // TREE_HPP
