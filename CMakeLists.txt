cmake_minimum_required(VERSION 3.10)

project(dynamic_modules_array)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/build)

add_executable(dynamicarray
  src/modules.h
  src/modules.c
  src/dynamic_array.h
  src/dynamic_array.c
  dynamic_array.c
)

add_executable(linkedlist
  src/modules.h
  src/modules.c
  src/linked_list.h
  src/linked_list.c
  linked_list.c
)