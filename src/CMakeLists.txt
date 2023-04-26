cmake_minimum_required(VERSION 3.1)
project(ubc)

set(CMAKE_BUILD_TYPE Debug)

add_executable(ubc main.cpp uuint_t.h uuint_t.cpp chunks.h chunks.cpp)

target_compile_features(ubc PRIVATE cxx_std_11)
