cmake_minimum_required(VERSION 3.5.1)
project(student-manager VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)
enable_testing()
