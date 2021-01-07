cmake_minimum_required(VERSION 3.10)

project(Reader)
set(CMAKE_CXX_STANDARD 14)

set(_DTO
        dto/thumbnail_info.cpp

        dto/showtap/object.cpp
        dto/showtap/metadata.cpp
        dto/showtap/page.cpp
        dto/showtap/resource.cpp
        dto/showtap/effect.cpp
        dto/showtap/font.cpp)

set(_EXTENSION
        extension/estring.cpp
        extension/efile.cpp)

add_library(stap_reader SHARED
        ${_DTO}
        ${_EXTENSION}

        display.cpp

        showtap_file_reader.cpp)

target_include_directories(stap_reader
        PUBLIC ${CMAKE_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR})

