#include "tree.hpp"

template<typename T>
Tree<T>::Tree(int k) : root(nullptr), k(k) {}

template<typename T>
Tree<T>::~Tree() {
    deleteTree(root);
}

template<typename T>
void Tree<T>::add_root(const T& val) {
    if (root) {
        root->value = val;
    } else {
        root = new Node<T>(val, k);
    }
}

template<typename T>
void Tree<T>::add_sub_node(const T& parent_val, const T& child_val) {
    Node<T>* parent = find(root, parent_val);
    if (!parent) {
        throw std::invalid_argument("Parent node not found");
    }
    for (auto& child : parent->children) {
        if (!child) {
            child = new Node<T>(child_val, k);
            return;
        }
    }
    throw std::overflow_error("No available slot for a new child");
}

template<typename T>
Iterator<T> Tree<T>::begin_pre_order() {
    return Iterator<T>(root, Iterator<T>::Order::PRE_ORDER);
}

template<typename T>
Iterator<T> Tree<T>::end_pre_order() {
    return Iterator<T>(nullptr);
}

template<typename T>
Iterator<T> Tree<T>::begin_post_order() {
    return Iterator<T>(root, Iterator<T>::Order::POST_ORDER);
}

template<typename T>
Iterator<T> Tree<T>::end_post_order() {
    return Iterator<T>(nullptr);
}

template<typename T>
Iterator<T> Tree<T>::begin_in_order() {
    return Iterator<T>(root, Iterator<T>::Order::IN_ORDER);
}

template<typename T>
Iterator<T> Tree<T>::end_in_order() {
    return Iterator<T>(nullptr);
}

template<typename T>
Iterator<T> Tree<T>::begin_bfs_scan() {
    return Iterator<T>(root, Iterator<T>::Order::BFS);
}

template<typename T>
Iterator<T> Tree<T>::end_bfs_scan() {
    return Iterator<T>(nullptr);
}

template<typename T>
Iterator<T> Tree<T>::begin_dfs_scan() {
    return Iterator<T>(root, Iterator<T>::Order::DFS);
}

template<typename T>
Iterator<T> Tree<T>::end_dfs_scan() {
    return Iterator<T>(nullptr);
}

template<typename T>
Iterator<T> Tree<T>::myHeap() {
    std::vector<T> values;
    for (auto it = begin_bfs_scan(); it != end_bfs_scan(); ++it) {
        values.push_back(*it);
    }
    std::make_heap(values.begin(), values.end(), std::greater<T>());
    Iterator<T> it = begin_bfs_scan();
    for (const T& val : values) {
        *it = val;
        ++it;
    }
    return Iterator<T>(root, Iterator<T>::Order::BFS);
}

template<typename T>
void Tree<T>::deleteTree(Node<T>* node) {
    if (node) {
        for (auto& child : node->children) {
            deleteTree(child);
        }
        delete node;
    }
}

template<typename T>
Node<T>* Tree<T>::find(Node<T>* node, const T& val) {
    if (!node) return nullptr;
    if (node->value == val) return node;
    for (auto& child : node->children) {
        Node<T>* result = find(child, val);
        if (result) return result;
    }
    return nullptr;
}
