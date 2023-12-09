#include "commandCreator.hpp"

#include <sstream>

std::unique_ptr<Command> CommandCreator::CreateSlideCommand(std::istream& stream)
{
    std::string commandName;
    stream >> commandName;
    auto command = commandRegistry_.findCommand(commandName);
    parseArguments(stream, *command);
    return command;   
}

void CommandCreator::parseArguments(std::istream &stream, Command& command)
{
    std::string key;
    while (stream >> key)
    {
        auto argumentType = command.m_arguments.getArgumentType(key);
        switch (argumentType)
        {
        case ArgumentType::INT:
            setAs<int>(stream, key ,command);
            break;
        case ArgumentType::DOUBLE:
            setAs<double>(stream,key,command);
            break;
        case ArgumentType::STRING:
            setAs<std::string>(stream,key,command);
            break;
        }
    }
}