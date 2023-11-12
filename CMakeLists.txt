cmake_minimum_required(VERSION 3.14)

project(PowerPoint)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES 
    main.cpp 
    Application.cpp
    director.cpp  
    consoleIO.cpp
    itemRegistry.cpp  
)

file(GLOB COMMAND_SOURCES "cli/*.cpp" "cli/commands/*.cpp" "cli/command_factories/*.cpp" "document/*.cpp" "serializer/*.cpp")

add_executable(PowerPoint ${SOURCES} ${COMMAND_SOURCES})

