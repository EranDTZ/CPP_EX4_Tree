QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TreeProject
TEMPLATE = app

SOURCES += main.cpp \
           mainwindow.cpp

HEADERS += mainwindow.hpp \
           node.hpp \
           tree.hpp \
           iterator.hpp \
           complex.hpp

FORMS += mainwindow.ui
