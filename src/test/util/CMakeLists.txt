cmake_minimum_required(VERSION 2.8)


aux_source_directory(. files)
add_executable(util_test ${files})
target_link_libraries(util_test gtest gtest_main util)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/target/test)

