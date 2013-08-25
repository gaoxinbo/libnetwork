add_executable(client client.cc)
target_link_libraries(client core)

add_executable(server server.cc)
target_link_libraries(server core)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/target/example)
