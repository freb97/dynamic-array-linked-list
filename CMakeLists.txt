cmake_minimum_required(VERSION 3.10)

project(dynamic_modules_array)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/build)

add_executable(dynarray
  src/modules.h
  src/modules.c
  src/dynarray.h
  src/dynarray.c
  main.c
)