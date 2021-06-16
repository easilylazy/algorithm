# set(CMAKE_GENERATOR "MinGW Makefiles")
cmake_minimum_required(VERSION 3.1.0)

project(great)
aux_source_directory(. DIR_SRCS)
# add_library(hello SHARED hello.cpp)
include_directories("C:/bin/eigen-3.3.9")
add_executable(great ${DIR_SRCS})
# target_link_libraries(great hello)
