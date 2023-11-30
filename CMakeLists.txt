cmake_minimum_required(VERSION 3.14)

project(PowerPoint)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES 
    main.cpp 
    Application.cpp
    director/Director.cpp  
    io/consoleIO.cpp
    cli/controller.cpp
    cli/commandRegistry.cpp
    cli/commandCreator.cpp
    cli/commands/AddCommand.cpp
    cli/commands/CreateCommand.cpp
    #cli/commands/ChangeItemCommand.cpp
    cli/commands/GoSlideCommand.cpp
    cli/commands/DisplayCommand.cpp
    cli/commands/RemoveCommand.cpp
    cli/commands/ListCommand.cpp
    cli/commands/LoadCommand.cpp
    cli/commands/SaveCommand.cpp
    cli/commands/QuitCommand.cpp
    cli/commands/CommandArgument.cpp
)

file(GLOB COMMAND_SOURCES "document/*.cpp" "serializer/*.cpp")

add_executable(PowerPoint ${SOURCES} ${COMMAND_SOURCES})

