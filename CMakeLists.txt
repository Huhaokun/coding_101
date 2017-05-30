cmake_minimum_required(VERSION 3.2)
project(coding_101 CXX)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS system REQUIRED)

#set(SOURCE_FILES Stack.h catch.h  queue.h hash_table.h )
set(SOURCE_FILES Stack.h catch.h)
#add_library(data_structure STATIC ${SOURCE_FILES})

add_executable(hash_table_unittest hash_table_unittest.cpp ${SOURCE_FILES})
add_executable(stack_unittest stack_unittest.cpp ${SOURCE_FILES})

target_link_libraries(hash_table_unittest Boost::system)
target_link_libraries(stack_unittest Boost::system)