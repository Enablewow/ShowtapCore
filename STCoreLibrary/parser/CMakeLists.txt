cmake_minimum_required(VERSION 3.10)

add_library(input_parser OBJECT input_parser.cpp)

target_include_directories(input_parser
        PRIVATE ${CMAKE_SOURCE_DIR}/include)

