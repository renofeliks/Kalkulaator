cmake_minimum_required(VERSION 3.30)
project(Kalkulaator)

set(CMAKE_CXX_STANDARD 20)

add_executable(Kalkulaator main.cpp
        calculator.cpp
        calculator.h
        parser.cpp
        parser.h)
