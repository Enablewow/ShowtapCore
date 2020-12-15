cmake_minimum_required(VERSION 3.10)

PROJECT("Showtap Core Library")

add_subdirectory(${CMAKE_SOURCE_DIR}/parser)
add_subdirectory(${CMAKE_SOURCE_DIR}/reader)

set(LIBRARIES
    input_parser
    stap_reader
)

foreach(item ${LIBRARIES})
    set(LIB_LIST ${LIB_LIST} $<TARGET_OBJECTS:${item}>)
    message("Import Library: ${item}")
endforeach()

add_library(showtap STATIC ${LIB_LIST})
