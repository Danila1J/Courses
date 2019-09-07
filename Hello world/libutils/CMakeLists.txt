set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(utils_static STATIC
        include/libutils/Sort.h
        include/libutils/AVLTree.h
        include/libutils/Vector.h
        include/libutils/SafeRead.h
        include/libutils/List.h
        src/List.c
        src/Vector.c
        src/SafeRead.c
        src/AVLTree.c
        src/SortBubble.c
        src/SortQuick.c
        src/SortSelection.c
        src/SortShaker.c
        src/SortNaturalMerge.c)
add_library(utils_dynamic SHARED
        include/libutils/Sort.h
        src/SortBubble.c
        src/SortQuick.c
        src/SortSelection.c
        src/SortShaker.c
        src/SortNaturalMerge.c)


target_include_directories(utils_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(utils_dynamic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)