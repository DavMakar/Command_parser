cmake_minimum_required(VERSION 3.14)

project(Calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(calculator main.cpp controller.cpp command_parser.cpp)