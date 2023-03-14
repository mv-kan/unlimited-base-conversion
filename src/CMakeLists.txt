project(ubc)
cmake_minimum_required(VERSION 3.0)

#set(CMAKE_BUILD_TYPE Debug)

add_executable(ubc main.cpp uuint_t.h uuint_t.cpp chunks.h chunks.cpp)
