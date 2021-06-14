cmake_minimum_required(VERSION 3.1.0)

project(astar)

aux_source_directory(. DIR_SRCS)

add_executable(astar ${DIR_SRCS})