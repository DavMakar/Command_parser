cmake_minimum_required(VERSION 3.14)

project(PowerPoint)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES 
    main.cpp 
    controller.cpp 
    commandCreator.cpp 
    itemRegistry.cpp 
    factoryRegistry.cpp 
    consoleIO.cpp
    director.cpp
    item.cpp 
    Rect.cpp
)


file(GLOB COMMAND_SOURCES "commands/*.cpp" "command_factories/*.cpp" "document/*.cpp" "serializer/*.cpp")

add_executable(powerPoint ${SOURCES} ${COMMAND_SOURCES})

