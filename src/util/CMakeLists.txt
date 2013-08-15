add_library(util Mutex.cc Guard.cc)

add_executable(test test.cc)
target_link_libraries(test util pthread)
