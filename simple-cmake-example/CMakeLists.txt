cmake_minimum_required(VERSION 3.10)

project(SimpleCMakeExample VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(SimpleCMakeExample
    src/main.cpp
    src/some_class.cpp
)
