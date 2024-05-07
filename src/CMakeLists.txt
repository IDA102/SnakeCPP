cmake_minimum_required(VERSION 3.5)

project(SnakeProj)

add_executable(Snake main.cpp Functions.cpp "../inc/Header.h")

set_target_properties(
        Snake PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
)