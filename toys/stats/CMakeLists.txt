# cmake file

# requirements


# configuration

set(PRJ_NAME "stats")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lm")

add_executable(${PRJ_NAME} 
  stats.c)

target_include_directories(${PRJ_NAME} PRIVATE ${MEMORY_ALLOCATOR_INCLUDE_PATH})
target_link_libraries(${PRJ_NAME} ${MEMORY_ALLOCATOR_LIB})
target_link_libraries(${PRJ_NAME} ${CMAKE_THREADS_LIBS_INIT})


# installation



