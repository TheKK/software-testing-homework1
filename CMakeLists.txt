cmake_minimum_required(VERSION 3.7)

project("software_testing_homework")

add_subdirectory("${CMAKE_SOURCE_DIR}/third_party/googletest" EXCLUDE_FROM_ALL)
include_directories(SYSTEM "${CMAKE_SOURCE_DIR}/third_party/googletest/googletest/include")
link_libraries(gtest)

add_executable(unit_test_runner WIN32
  "${CMAKE_SOURCE_DIR}/tests/main.cpp")
