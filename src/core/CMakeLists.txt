aux_source_directory(. files)
add_library(core ${files})
target_link_libraries(core util)
