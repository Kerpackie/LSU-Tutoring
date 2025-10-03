cmake_minimum_required(VERSION 4.0)
project(enums)

set(CMAKE_CXX_STANDARD 20)

add_executable(enums enums.cpp
        enumClass.cpp)
add_executable(scopedEnums scopedEnums.cpp)
add_executable(enumClass enumClass.cpp)
