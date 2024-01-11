cmake_minimum_required(VERSION 3.10)

project(Nmea0138Listener VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(Nmea0138Listener
    src/main.cpp
    src/connection.cpp
    src/nmea_0138.cpp
)
