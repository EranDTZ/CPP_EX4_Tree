#include "iterator.hpp"

template<typename T>
Iterator<T>::Iterator(Node<T>* root, Order order) : order(order), current(root) {
    if (root) {
        initialize(root);
    }
}

template<typename T>
T& Iterator<T>::operator*() {
    return current->value;
}

template<typename T>
Iterator<T>& Iterator<T>::operator++() {
    advance();
    return *this;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const {
    return current != other.current;
}

template<typename T>
void Iterator<T>::initialize(Node<T>* root) {
    if (order == Order::PRE_ORDER) {
        s.push(root);
    } else if (order == Order::POST_ORDER) {
        postOrderTraversal(root);
    } else if (order == Order::IN_ORDER) {
        inOrderTraversal(root);
    } else if (order == Order::BFS) {
        q.push(root);
    } else if (order == Order::DFS) {
        s.push(root);
    }
    advance();
}

template<typename T>
void Iterator<T>::advance() {
    if (order == Order::PRE_ORDER || order == Order::DFS) {
        if (!s.empty()) {
            current = s.top();
            s.pop();
            for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
                if (*it) s.push(*it);
            }
        } else {
            current = nullptr;
        }
    } else if (order == Order::BFS) {
        if (!q.empty()) {
            current = q.front();
            q.pop();
            for (auto& child : current->children) {
                if (child) q.push(child);
            }
        } else {
            current = nullptr;
        }
    } else {
        if (!s.empty()) {
            current = s.top();
            s.pop();
        } else {
            current = nullptr;
        }
    }
}

template<typename T>
void Iterator<T>::postOrderTraversal(Node<T>* node) {
    if (node) {
        for (auto& child : node->children) {
            postOrderTraversal(child);
        }
        s.push(node);
    }
}

template<typename T>
void Iterator<T>::inOrderTraversal(Node<T>* node) {
    if (node) {
        if (!node->children.empty()) inOrderTraversal(node->children[0]);
        s.push(node);
        for (size_t i = 1; i < node->children.size(); ++i) {
            inOrderTraversal(node->children[i]);
        }
    }
}
