cmake_minimum_required(VERSION 3.14)

project(Calculator)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp controller.cpp command_parser.cpp consoleIO.cpp)

file(GLOB COMMAND_SOURCES
    "concrete_commands/*.cpp"
)

add_executable(calculator ${SOURCES} ${COMMAND_SOURCES})