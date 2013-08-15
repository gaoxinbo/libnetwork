project(network)
cmake_minimum_required(VERSION 2.8)

include_directories(${PROJECT_SOURCE_DIR}/src/util)

add_definitions(-Wall -Werror)
add_subdirectory(src)
