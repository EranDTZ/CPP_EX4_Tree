#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tree.hpp"
#include "complex.hpp"

// Node Tests
TEST_CASE("Node class operations") {
    Node<int> n(1, 3);

    SUBCASE("Node initialization") {
        CHECK(n.value == 1);
        CHECK(n.children.size() == 3);
    }

    SUBCASE("Node children") {
        Node<int>* child1 = new Node<int>(2, 3);
        Node<int>* child2 = new Node<int>(3, 3);
        n.children[0] = child1;
        n.children[1] = child2;

        CHECK(n.children[0]->value == 2);
        CHECK(n.children[1]->value == 3);
        CHECK(n.children[2] == nullptr);

        delete child1;
        delete child2;
    }
}

// Tree Tests
TEST_CASE("Tree<int> operations") {
    Tree<int> t(3);

    SUBCASE("Add and find nodes") {
        t.add_root(1);
        t.add_sub_node(1, 2);
        t.add_sub_node(1, 3);
        t.add_sub_node(2, 4);

        CHECK(t.getRoot() != nullptr);
        // CHECK(t.find(1) != nullptr);
        // CHECK(t.find(2) != nullptr);
        // CHECK(t.find(3) != nullptr);
        // CHECK(t.find(4) != nullptr);
        // CHECK(t.find(5) == nullptr);
    }

    SUBCASE("Maximum children per node") {
        t.add_root(1);
        t.add_sub_node(1, 2);
        t.add_sub_node(1, 3);
        t.add_sub_node(1, 4);
        CHECK_THROWS_AS(t.add_sub_node(1, 5), std::runtime_error);
    }
}

TEST_CASE("Tree<std::string> operations") {
    Tree<std::string> t(3);

    SUBCASE("Add and find nodes") {
        t.add_root("root");
        t.add_sub_node("root", "child1");
        t.add_sub_node("root", "child2");
        t.add_sub_node("child1", "child1.1");

        CHECK(t.getRoot() != nullptr);
        // CHECK(t.find("root") != nullptr);
        // CHECK(t.find("child1") != nullptr);
        // CHECK(t.find("child2") != nullptr);
        // CHECK(t.find("child1.1") != nullptr);
        // CHECK(t.find("child3") == nullptr);
    }
}

TEST_CASE("Tree<Complex> operations") {
    Tree<Complex> t(3);

    SUBCASE("Add and find nodes") {
        t.add_root(Complex(0, 0));
        t.add_sub_node(Complex(0, 0), Complex(1, 1));
        t.add_sub_node(Complex(0, 0), Complex(2, 2));
        t.add_sub_node(Complex(1, 1), Complex(3, 3));

        CHECK(t.getRoot() != nullptr);
        // CHECK(t.find(Complex(0, 0)) != nullptr);
        // CHECK(t.find(Complex(1, 1)) != nullptr);
        // CHECK(t.find(Complex(2, 2)) != nullptr);
        // CHECK(t.find(Complex(3, 3)) != nullptr);
        // CHECK(t.find(Complex(4, 4)) == nullptr);
    }
}

// Iterator Tests
TEST_CASE("Iterator class operations") {
    Tree<int> t(3);
    t.add_root(1);
    t.add_sub_node(1, 2);
    t.add_sub_node(1, 3);
    t.add_sub_node(2, 4);

    SUBCASE("Pre-order traversal") {
        Iterator<int> it = t.begin_pre_order();
        std::vector<int> values;
        while (it != t.end_pre_order()) {
            values.push_back(*it);
            ++it;
        }
        CHECK(values == std::vector<int>({1, 2, 4, 3}));
    }

    SUBCASE("Post-order traversal") {
        Iterator<int> it = t.begin_post_order();
        std::vector<int> values;
        while (it != t.end_post_order()) {
            values.push_back(*it);
            ++it;
        }
        CHECK(values == std::vector<int>({4, 2, 3, 1}));
    }


    SUBCASE("In-order traversal") {
        Iterator<int> it = t.begin_in_order();
        std::vector<int> values;
        while (it != t.end_in_order()) {
            values.push_back(*it);
            ++it;
        }
        CHECK(values == std::vector<int>({4, 2, 1, 3}));
    }


    SUBCASE("BFS traversal") {
        Iterator<int> it = t.begin_bfs_scan();
        std::vector<int> values;
        while (it != t.end_bfs_scan()) {
            values.push_back(*it);
            ++it;
        }
        CHECK(values == std::vector<int>({1, 2, 3, 4}));
    }

    SUBCASE("DFS traversal") {
        Iterator<int> it = t.begin_dfs_scan();
        std::vector<int> values;
        while (it != t.end_dfs_scan()) {
            values.push_back(*it);
            ++it;
        }
        CHECK(values == std::vector<int>({1, 2, 4, 3}));
    }
}

// Complex Tests
TEST_CASE("Complex class operations") {
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3(1, 2);

    SUBCASE("Equality operator") {
        CHECK(c1 == c3);
        CHECK_FALSE(c1 == c2);
    }

    SUBCASE("Comparison operators") {
        CHECK(c2 > c1);
        CHECK(c1 < c2);
    }

    SUBCASE("String representation") {
        CHECK(c1.toString() == "(1, 2)");
        CHECK(c2.toString() == "(3, 4)");
    }

    SUBCASE("Output stream operator") {
        std::ostringstream oss;
        oss << c1;
        CHECK(oss.str() == "(1, 2)");
    }
}
