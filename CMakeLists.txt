project(network)
cmake_minimum_required(VERSION 2.8)


include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/gtest/include)

add_definitions(-Wall -Werror -g)
link_directories(${PROJECT_BIN_DIR})

add_subdirectory(gtest)
add_subdirectory(src)
