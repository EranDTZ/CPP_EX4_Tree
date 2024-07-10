#include <iostream>
#include "tree.hpp"
#include "complex.hpp"
#include "tree_gui.hpp"

int main() {

    /*---------------------------------------------TREE-Complex-TEST----------------------------------------*/
    
    Tree<Complex> c;

    c.add_root(Complex(1, 2));
    c.add_sub_node(Complex(1, 2), Complex(3, 4));
    c.add_sub_node(Complex(1, 2), Complex(5, 6));
    c.add_sub_node(Complex(3, 4), Complex(7, 8));

    std::cout << "Pre-Order Traversal: ";
    for (auto it = c.begin_pre_order(); it != c.end_pre_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Post-Order Traversal: ";
    for (auto it = c.begin_post_order(); it != c.end_post_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "In-Order Traversal: ";
    for (auto it = c.begin_in_order(); it != c.end_in_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "BFS Traversal: ";
    for (auto it = c.begin_bfs_scan(); it != c.end_bfs_scan(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "DFS Traversal: ";
    for (auto it = c.begin_dfs_scan(); it != c.end_dfs_scan(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    /*---------------------------------------------GUI-TREE-example-1-string----------------------------------------*/

    Tree<std::string> k(3);

    k.add_root("Root");
    k.add_sub_node("Root", "Child1");
    k.add_sub_node("Root", "Child2");
    k.add_sub_node("Root", "Child3");
    k.add_sub_node("Child1", "Grandchild1");
    k.add_sub_node("Child1", "Grandchild2");

    // TreeGUI gui(k);
    // gui.run();


    /*---------------------------------------------GUI-TREE-example-2-BIG-string-----------------------------------*/



    // Tree<std::string> t(3);  // Set k to 3 to allow up to 3 children per node

    // // Adding root and its direct children
    // t.add_root("root");

    // t.add_sub_node("root", "child1");
    // t.add_sub_node("root", "child2");
    // t.add_sub_node("root", "child3");

    // // Adding grandchildren
    // t.add_sub_node("child1", "child1_1");
    // t.add_sub_node("child1", "child1_2");
    // t.add_sub_node("child1", "child1_3");

    // t.add_sub_node("child2", "child2_1");
    // t.add_sub_node("child2", "child2_2");
    // t.add_sub_node("child2", "child2_3");

    // t.add_sub_node("child3", "child3_1");
    // t.add_sub_node("child3", "child3_2");
    // t.add_sub_node("child3", "child3_3");

    // // Adding great-grandchildren
    // t.add_sub_node("child1_1", "child1_1_1");
    // t.add_sub_node("child1_1", "child1_1_2");

    // t.add_sub_node("child1_2", "child1_2_1");
    // t.add_sub_node("child1_2", "child1_2_2");

    // t.add_sub_node("child1_3", "child1_3_1");
    // t.add_sub_node("child1_3", "child1_3_2");

    // t.add_sub_node("child2_1", "child2_1_1");
    // t.add_sub_node("child2_1", "child2_1_2");

    // t.add_sub_node("child2_2", "child2_2_1");
    // t.add_sub_node("child2_2", "child2_2_2");

    // t.add_sub_node("child2_3", "child2_3_1");
    // t.add_sub_node("child2_3", "child2_3_2");

    // t.add_sub_node("child3_1", "child3_1_1");
    // t.add_sub_node("child3_1", "child3_1_2");

    // t.add_sub_node("child3_2", "child3_2_1");
    // t.add_sub_node("child3_2", "child3_2_2");

    // t.add_sub_node("child3_3", "child3_3_1");
    // t.add_sub_node("child3_3", "child3_3_2");

    // // Free this to initialize and run the GUI of t.
    // // TreeGUI gui(t);
    // // gui.run();

    // TreeGUI<std::string> stringGui(t);
    // stringGui.run();


   /*---------------------------------------------GUI-TREE-example-2-Complex--------------------------------------*/


    TreeGUI<Complex> complexGui(c);
    complexGui.run();

    /*---------------------------------------------GUI-TREE-example-2-int--------------------------------------*/

    // Tree<int> intTree(3);
    // intTree.add_root(1);
    // intTree.add_sub_node(1, 2);
    // intTree.add_sub_node(1, 3);
    // intTree.add_sub_node(2, 4);

    // std::cout << "Tree Representation (int): " << intTree.toString() << std::endl;

    // TreeGUI<int> intGui(intTree);
    // intGui.run();

    /*---------------------------------------------GUI-TREE-example-2-string--------------------------------------*/

    // Tree<std::string> stringTree(3);
    // stringTree.add_root("Root");
    // stringTree.add_sub_node("Root", "Child1");
    // stringTree.add_sub_node("Root", "Child2");

    // std::cout << "Tree Representation (string): " << stringTree.toString() << std::endl;

    // TreeGUI<std::string> stringGui(stringTree);
    // stringGui.run();

    return 0;
}

