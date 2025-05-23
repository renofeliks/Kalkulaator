cmake_minimum_required(VERSION 3.30)
project(Kalkulaator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(Kalkulaator
        main.cpp
        calculator.cpp
        parser.cpp
        mainwindow.cpp
        calculator.h
        parser.h
        mainwindow.h
        mainwindow.ui
)

target_include_directories(Kalkulaator PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}/Kalkulaator_autogen/include
)

target_link_libraries(Kalkulaator PRIVATE Qt6::Widgets)

set_target_properties(Kalkulaator PROPERTIES
        AUTOMOC ON
        AUTOUIC ON
        AUTORCC ON
)