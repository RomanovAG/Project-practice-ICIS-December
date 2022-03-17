cmake_minimum_required(VERSION 3.5)

project(LogiTectNonQT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LogiTectNonQT main.cpp classes.h logictypes.h logicalelement.cpp methods.h methods.cpp net.cpp menu.cpp menu.h)
