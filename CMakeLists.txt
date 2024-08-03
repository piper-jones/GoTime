cmake_minimum_required(VERSION 3.27)
project(GoTime)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(GoTime
        Graph.cpp
        main.cpp
        Graph.h)
