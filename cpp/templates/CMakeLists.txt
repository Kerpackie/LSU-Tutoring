cmake_minimum_required(VERSION 4.0)
project(templates)

set(CMAKE_CXX_STANDARD 20)

add_executable(withoutTemplates withoutTemplates.cpp)
add_executable(functionTemplates functionTemplates.cpp)
add_executable(classTemplates classTemplates.cpp)
add_executable(templatesWithMultipleTypes templatesWithMultipleTypes.cpp)