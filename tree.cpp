#ifndef TREE_CPP
#define TREE_CPP

#include "tree.hpp"

template <typename T>
Tree<T>::Tree(int k) : root(nullptr), k(k) {}

template <typename T>
Tree<T>::~Tree() {
    deleteTree(root);
}

template <typename T>
void Tree<T>::add_root(const T& val) {
    if (root) {
        root->value = val;
    } else {
        root = new Node<T>(val, k);
    }
}

template <typename T>
void Tree<T>::add_sub_node(const T& parent_val, const T& child_val) {
    Node<T>* parent = find(root, parent_val);
    if (parent) {
        if (parent->children.size() < k) {
            Node<T>* child = new Node<T>(child_val, k);
            parent->children.push_back(child);
        } else {
            std::cerr << "Node already has the maximum number of children." << std::endl;
        }
    } else {
        std::cerr << "Parent not found." << std::endl;
    }
}

template <typename T>
Iterator<T> Tree<T>::begin_pre_order() {
    return Iterator<T>(root, Iterator<T>::PRE_ORDER);
}

template <typename T>
Iterator<T> Tree<T>::end_pre_order() {
    return Iterator<T>(nullptr, Iterator<T>::PRE_ORDER);
}

template <typename T>
Iterator<T> Tree<T>::begin_post_order() {
    return Iterator<T>(root, Iterator<T>::POST_ORDER);
}

template <typename T>
Iterator<T> Tree<T>::end_post_order() {
    return Iterator<T>(nullptr, Iterator<T>::POST_ORDER);
}

template <typename T>
Iterator<T> Tree<T>::begin_in_order() {
    return Iterator<T>(root, Iterator<T>::IN_ORDER);
}

template <typename T>
Iterator<T> Tree<T>::end_in_order() {
    return Iterator<T>(nullptr, Iterator<T>::IN_ORDER);
}

template <typename T>
Iterator<T> Tree<T>::begin_bfs_scan() {
    return Iterator<T>(root, Iterator<T>::BFS);
}

template <typename T>
Iterator<T> Tree<T>::end_bfs_scan() {
    return Iterator<T>(nullptr, Iterator<T>::BFS);
}

template <typename T>
Iterator<T> Tree<T>::begin_dfs_scan() {
    return Iterator<T>(root, Iterator<T>::DFS);
}

template <typename T>
Iterator<T> Tree<T>::end_dfs_scan() {
    return Iterator<T>(nullptr, Iterator<T>::DFS);
}

template <typename T>
void Tree<T>::deleteTree(Node<T>* node) {
    if (node) {
        for (Node<T>* child : node->children) {
            deleteTree(child);
        }
        delete node;
    }
}

template <typename T>
Node<T>* Tree<T>::find(Node<T>* node, const T& val) {
    if (node) {
        if (node->value == val) return node;
        for (Node<T>* child : node->children) {
            Node<T>* found = find(child, val);
            if (found) return found;
        }
    }
    return nullptr;
}

#endif // TREE_CPP
