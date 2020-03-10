cmake_minimum_required(VERSION 3.15)
project(speller)

set(CMAKE_CXX_STANDARD 14)

list(APPEND SOURCES src/sources/main.cpp
        src/sources/bin_tree_checker.cpp
                    src/sources/checker.cpp
                    src/sources/file.cpp
                    src/sources/hash_map_checker
        src/sources/hash_table_checker.cpp
                    src/sources/timer.cpp
        src/sources/vector_checker.cpp)

add_executable(speller ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include PRIVATE src/headers)
