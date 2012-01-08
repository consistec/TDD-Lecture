cmake_minimum_required(VERSION 2.8)

find_package(GTest REQUIRED)

ADD_EXECUTABLE(test
  prime.cpp
)

TARGET_LINK_LIBRARIES(test pthread gtest)
