cmake_minimum_required(VERSION 3.5) 
project(containers)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O2 -pipe")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories(include)

enable_testing()
add_subdirectory(test)
