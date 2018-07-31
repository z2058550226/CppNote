cmake_minimum_required(VERSION 3.10)
project(CppNote)

aux_source_directory(. DIR_ROOT)

aux_source_directory(./chapter6_programing DIR_C6)

set(CMAKE_CXX_STANDARD 11)

add_executable(CppNote chapter6_programing/test1.cpp ${DIR_ROOT} ${DIR_C6})