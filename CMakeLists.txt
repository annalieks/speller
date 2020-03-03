cmake_minimum_required(VERSION 3.15)
project(speller)

set(CMAKE_CXX_STANDARD 14)
file(GLOB SOURCES sources/*.cpp)
file(GLOB INCLUDES includes/*.h)

add_executable(speller ${SOURCES} ${INCLUDES})
