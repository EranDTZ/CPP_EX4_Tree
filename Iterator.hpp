#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "node.hpp"
#include <stack>
#include <queue>

template<typename T>
class Iterator {
public:
    enum class Order { PRE_ORDER, POST_ORDER, IN_ORDER, BFS, DFS };

    Iterator(Node<T>* root, Order order = Order::BFS);

    T& operator*();
    Iterator& operator++();
    bool operator!=(const Iterator& other) const;

private:
    Node<T>* current;
    Order order;
    std::stack<Node<T>*> s;
    std::queue<Node<T>*> q;

    void initialize(Node<T>* root);
    void advance();
    void postOrderTraversal(Node<T>* node);
    void inOrderTraversal(Node<T>* node);
};

#include "iterator.cpp"

#endif // ITERATOR_HPP
