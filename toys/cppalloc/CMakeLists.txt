# cmake file

# requirements


# configuration


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lm")


file(GLOB SRC_FILES . *.cpp)

foreach(SRC_FILE ${SRC_FILES})
  string(REGEX REPLACE "\\.cpp$" "" EXE ${SRC_FILE})
  get_filename_component(EXE ${EXE} NAME)
  message("setting up executable: ${EXE}")

  add_executable(${EXE} ${SRC_FILE})
  target_link_libraries(${EXE})
endforeach()


# installation



