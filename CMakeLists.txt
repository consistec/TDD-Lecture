cmake_minimum_required(VERSION 2.8)

find_package(GTest REQUIRED)

set(
  CMAKE_CXX_FLAGS
  "${CMAKE_CXX_FLAGS} -std=c++0x"
)

ADD_EXECUTABLE(test
  prime.cpp
  miniexample.cpp
)

TARGET_LINK_LIBRARIES(test pthread gtest)
