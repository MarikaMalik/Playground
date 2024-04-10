cmake_minimum_required(VERSION 3.5)
project("LinuxPlayground" LANGUAGES CXX)

# cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..

# Chapter 00 -> origin
add_subdirectory(chapter_00)

# Chapter 01 -> Gtest and Gmock
add_subdirectory(chapter_01_testing)

# My implementation of shared_pointer
add_subdirectory(shared_pointer)
