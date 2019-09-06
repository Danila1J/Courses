cmake_minimum_required (VERSION 3.8)

add_executable(StructIO "main.c" "Person.c" "Person.h")
add_executable(SafeRead "mainR.c" "SafeRead.c" "SafeRead.h")
#add_library(SafeReadLibrary STATIC SafeRead.c)
#target_link_libraries(StructIO SafeReadLibrary)
