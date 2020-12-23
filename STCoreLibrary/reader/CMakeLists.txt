cmake_minimum_required(VERSION 3.10)

project(Reader)
set(CMAKE_CXX_STANDARD 14)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
)

set(_DTO
        dto/showtap_object.cpp
        dto/thumbnail_info.cpp
        dto/showtap_metadata.cpp)

add_library(stap_reader SHARED
        showtap_file_reader.cpp

        ${_DTO})

target_include_directories(stap_reader
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/include)

