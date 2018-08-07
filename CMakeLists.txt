cmake_minimum_required(VERSION 3.10)
project(CppNote)

aux_source_directory(. DIR_ROOT)

aux_source_directory(chapter6_and_7_programing DIR_C6)
aux_source_directory(chapter8_function DIR_C8)
aux_source_directory(chapter9_oop DIR_C9)

set(CMAKE_CXX_STANDARD 11)

add_executable(CppNote ${DIR_ROOT} ${DIR_C9})