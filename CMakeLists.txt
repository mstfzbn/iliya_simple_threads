cmake_minimum_required(VERSION 3.7)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

project(iliya_thread)

add_executable(

  iliya_thread
  includes.h
  defines.h
  main.cpp
)
