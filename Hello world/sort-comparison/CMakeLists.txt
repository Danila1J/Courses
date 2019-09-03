add_executable(sort-comparison "Main.c")
target_link_libraries(sort-comparison sort_static)
target_link_libraries(sort-comparison read_static)