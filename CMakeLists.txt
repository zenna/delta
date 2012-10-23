cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

include_directories (../)
add_subdirectory (machines)
add_subdirectory (primitives)
add_subdirectory (scripts)
