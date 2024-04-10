cmake_minimum_required(VERSION 3.5)
set(APPNAME "Shared_Pointer")

set(SOURCES
    src/SharedPointer.cpp
    src/main.cpp
)

project(${APPNAME} LANGUAGES CXX)
add_executable(${APPNAME} ${SOURCES})
target_compile_options(${APPNAME} PRIVATE -Wall -Wcast-align -Wconversion -Wctor-dtor-privacy -Werror -Wextra -Wpedantic -Wshadow -Wsign-conversion) # Enable warning

include_directories(src)