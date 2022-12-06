cmake_minimum_required(VERSION 3.23)
project(SparseSet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(SPARSE_SET_HEADER
  ${CMAKE_CURRENT_SOURCE_DIR}/include/sparse_set.hpp)

set(SPARSE_SET_TEST_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp)

add_library(SparseSet INTERFACE ${SPARSE_SET_HEADER})
target_include_directories(SparseSet INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_executable(SparseSet-Test ${SPARSE_SET_TEST_SRC})
target_link_libraries(SparseSet-Test SparseSet)
