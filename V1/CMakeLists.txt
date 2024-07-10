cmake_minimum_required(VERSION 3.5)

project(TreeProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)

add_executable(tree_cli main.cpp tree.cpp iterator.cpp mainwindow.cpp)
add_executable(tree_gui gui_main.cpp mainwindow.cpp tree.cpp iterator.cpp)

target_link_libraries(tree_gui Qt5::Widgets)

# The command-line executable
add_executable(tree_cli main.cpp tree.cpp iterator.cpp)
