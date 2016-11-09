# cmake file

cmake_minimum_required(VERSION 3.0)

project(alison-toys)


# requirements

if(NOT DEFINED MEMORY_ALLOCATOR_ROOT)
  message(FATAL_ERROR "Memory allocator root directory was not specified")
endif()


find_library(MEMORY_ALLOCATOR_LIB
  NAMES "libjemalloc_pic.a"
  PATHS ${MEMORY_ALLOCATOR_ROOT}/lib)

find_path(MEMORY_ALLOCATOR_INCLUDE_PATH
  "jemalloc/jemalloc.h"
  PATHS ${MEMORY_ALLOCATOR_ROOT}/include)


find_package(Threads REQUIRED)


# configuration

add_subdirectory(stats)


# installation


