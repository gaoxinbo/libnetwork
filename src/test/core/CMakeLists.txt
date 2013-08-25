cmake_minimum_required(VERSION 2.8)


aux_source_directory(. files)
add_executable(core_test ${files})
target_link_libraries(core_test gtest gtest_main core)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/target/test)

