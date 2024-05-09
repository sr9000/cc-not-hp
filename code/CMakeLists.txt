cmake_minimum_required(VERSION 3.28)
project(cc_proof)

set(CMAKE_CXX_STANDARD 20)

SET(CMAKE_CXX_FLAGS_RELEASE " -O2 ")

add_executable(cc_proof main.cpp)
