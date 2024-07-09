#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setupTree();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupTree() {
    tree.add_root(Complex(1, 2));
    tree.add_sub_node(Complex(1, 2), Complex(3, 4));
    tree.add_sub_node(Complex(1, 2), Complex(5, 6));
    tree.add_sub_node(Complex(3, 4), Complex(7, 8));
}

void MainWindow::displayTree() {
    QString output;

    output += "Pre-Order Traversal: ";
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        output += QString::fromStdString((*it).toString()) + " ";
    }
    output += "\n";

    output += "Post-Order Traversal: ";
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        output += QString::fromStdString((*it).toString()) + " ";
    }
    output += "\n";

    output += "In-Order Traversal: ";
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        output += QString::fromStdString((*it).toString()) + " ";
    }
    output += "\n";

    output += "BFS Traversal: ";
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        output += QString::fromStdString((*it).toString()) + " ";
    }
    output += "\n";

    output += "DFS Traversal: ";
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        output += QString::fromStdString((*it).toString()) + " ";
    }
    output += "\n";

    output += "Heap (BFS) Traversal: ";
    for (auto it = tree.myHeap(); it != tree.end_bfs_scan(); ++it) {
        output += QString::fromStdString((*it).toString()) + " ";
    }
    output += "\n";

    ui->treeDisplay->setText(output);
}

void MainWindow::on_displayButton_clicked() {
    displayTree();
}
