cmake_minimum_required(VERSION 3.6)
project(coding_101)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS system REQUIRED)

set(SOURCE_FILES Stack.h catch.h stack_unittest.cpp)
add_executable(coding_101 ${SOURCE_FILES})

target_link_libraries(coding_101 Boost::system)