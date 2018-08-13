cmake_minimum_required(VERSION 3.10)
project(CppNote)

aux_source_directory(. DIR_ROOT)

aux_source_directory(chapter6_and_7_programing DIR_C6)
aux_source_directory(chapter8_function DIR_C8)
aux_source_directory(chapter9_oop DIR_C9)
aux_source_directory(chapter10_io DIR_C10)
aux_source_directory(chapter11_io DIR_C11)
aux_source_directory(chapter12_model DIR_C12)
#aux_source_directory(fltk/src/xutf8 DIR_FLTK_XUTF)
#aux_source_directory(fltk/src DIR_FLTK)

#add_subdirectory(fltk)
#
#include_directories(fltk/FL)

#link_directories(fltk/src)

include_directories(./)

set(CMAKE_CXX_STANDARD 11)

add_executable(CppNote ${DIR_C12} ${DIR_ROOT})

#find_package(FLTK)
#if (FLTK_FOUND)
#    include_directories(${FLTK_INCLUDE_DIRS})
#    target_link_libraries (helloworld ${FLTK_LIBRARIES})
#endif (FLTK_FOUND)

#target_link_libraries(CppNote fltk)