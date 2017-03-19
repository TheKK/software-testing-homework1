cmake_minimum_required(VERSION 2.8)

project("software_testing_homework")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package(Boost 1.55.0 REQUIRED)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
link_libraries(${Boost_LIBRARIES})

add_subdirectory("${CMAKE_SOURCE_DIR}/third_party/googletest" EXCLUDE_FROM_ALL)
include_directories(SYSTEM "${CMAKE_SOURCE_DIR}/third_party/googletest/googletest/include")
link_libraries(gtest)

include_directories("${CMAKE_SOURCE_DIR}/src")

file(GLOB_RECURSE LIB_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/src/*.cpp")

add_executable(unit_test_runner WIN32
  "${CMAKE_SOURCE_DIR}/tests/main.cpp"
  ${LIB_SOURCES}
  ${TEST_SOURCES}
  )
