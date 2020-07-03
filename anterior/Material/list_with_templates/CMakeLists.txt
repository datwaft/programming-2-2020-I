cmake_minimum_required(VERSION 3.13)
project(Delegate)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(main ${SOURCES})
