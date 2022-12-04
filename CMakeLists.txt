project(SparseSet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "-Ox")

set(SPARSE_SET_TEST_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_library(SparseSet INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/sparse_set.hpp)

add_executable(Test ${SPARSE_SET_TEST_SRC})
target_include_directories(Test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Test SparseSet)
