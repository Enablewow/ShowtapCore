cmake_minimum_required(VERSION 3.10)

project(Reader)
set(CMAKE_CXX_STANDARD 14)

set(_DTO
        dto/showtap/object.cpp
        dto/thumbnail_info.cpp
        dto/showtap/metadata.cpp
        dto/showtap/page.cpp dto/showtap/resource.cpp)

add_library(stap_reader SHARED
        showtap_file_reader.cpp

        ${_DTO} display.cpp)

target_include_directories(stap_reader
        PUBLIC ${CMAKE_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR})

