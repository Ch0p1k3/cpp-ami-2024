cmake_minimum_required(VERSION 3.14)
project(sem05-06)

set(CMAKE_CXX_STANDARD             20)
set(CMAKE_MODULE_PATH              "${CMAKE_SOURCE_DIR}/tools/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)

Include(FetchContent)
FetchContent_Declare(
    Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

function(add_catch TARGET)
  add_executable(${TARGET} ${ARGN})
  target_link_libraries(${TARGET} PRIVATE Catch2::Catch2WithMain)
endfunction()

add_subdirectory(deque)
add_subdirectory(stack)
add_subdirectory(string_view)
