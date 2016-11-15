# cmake file

# requirements


# configuration


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lm")


file(GLOB SRC_FILES . *.c)

foreach(SRC_FILE ${SRC_FILES})
  string(REGEX REPLACE "\\.c$" "" EXE ${SRC_FILE})
  get_filename_component(EXE ${EXE} NAME)
  message("setting up executable: ${EXE}")

  add_executable(${EXE} ${SRC_FILE})
  target_link_libraries(${EXE})

  target_include_directories(${EXE} PRIVATE ${MEMORY_ALLOCATOR_INCLUDE_PATH})
  target_link_libraries(${EXE} ${MEMORY_ALLOCATOR_LIB})
  target_link_libraries(${EXE} ${CMAKE_THREADS_LIBS_INIT})
endforeach()


# installation



