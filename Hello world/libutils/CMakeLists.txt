set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(sort_static STATIC
        include/libutils/Sort.h
        src/SortBubble.c
        src/SortQuick.c
        src/SortSelection.c
        src/SortShaker.c
        src/SortNaturalMerge.c)
add_library(sort_dynamic SHARED
        include/libutils/Sort.h
        src/SortBubble.c
        src/SortQuick.c
        src/SortSelection.c
        src/SortShaker.c
        src/SortNaturalMerge.c)
target_include_directories(sort_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(sort_dynamic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(read_static STATIC
        include/libutils/SafeRead.h
        src/SafeRead.c)
add_library(read_dynamic SHARED
        include/libutils/SafeRead.h
        src/SafeRead.c)
target_include_directories(read_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(read_dynamic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)