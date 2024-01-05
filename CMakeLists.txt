cmake_minimum_required(VERSION 3.26)
project(c_primer_plus_demo C)

set(CMAKE_C_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

set(MAJOR_VERSION 1)
set(SOJAR_VERSION 0)

message(STATUS "C_")

include(test.cmake)

configure_file(
  "${PROJECT_BINARY_DIR}/t.h.in"
  "${PROJECT_SOURCE_DIR}/t.h"
)

include(git.cmake)

SET(GIT_HASH "")
get_git_hash(GIT_HASH)

SET(GIT_BRANCH "")
get_git_branch(GIT_BRANCH)

message("current hash ${GIT_HASH}")
message("current branch ${GIT_BRANCH}")

include_directories(${PROJECT_BINARY_DIR})


option(SELF_FUNC "slef defined functions" on)

#if(DEFINED SELF_FUNC)
if (SELF_FUNC)
  include_directories("${PROJECT_SOURCE_DIR}/func")
  add_subdirectory(func)
  #  add_compile_definitions(SELF_FUNC)
  add_definitions(-DSELF_FUNC)
endif()

option(LIST_ON "flag on List" on)

if(NOT DEFINED LIST_ON)
  set(arr a b c d)
  set(LIST_LEN 0)
  list(LENGTH arr LIST_LEN)
  message("list length ${LIST_LEN}")
  set(JOIN_STR "")
  list(JOIN arr - JOIN_STR)
  message("Join string: ${JOIN_STR}")
endif()

message("self func : ${SELF_FUNC}")

add_executable(c_primer_plus_demo selfLib.c)

#if(DEFINED SELF_FUNC)
if(SELF_FUNC)
  target_link_libraries(c_primer_plus_demo MathFunctions)
endif()
