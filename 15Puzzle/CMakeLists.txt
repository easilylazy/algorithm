cmake_minimum_required(VERSION 3.1.0)

project(board)
link_libraries()
aux_source_directory(. DIR_SRCS)

add_executable(board ${DIR_SRCS})