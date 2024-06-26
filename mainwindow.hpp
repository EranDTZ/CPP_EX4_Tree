#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QTextEdit>
#include "tree.hpp"
#include "complex.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_displayButton_clicked();

private:
    Ui::MainWindow *ui;
    Tree<Complex> tree;
    void setupTree();
    void displayTree();
};

#endif // MAINWINDOW_HPP
