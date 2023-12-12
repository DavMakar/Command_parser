#ifndef COMMAND_CREATOR_HPP
#define COMMAND_CREATOR_HPP

#include "commands/Command.hpp"
#include "commandRegistry.hpp"

class CommandCreator{
public:
    std::unique_ptr<Command> createCommand(std::istream& stream);
    void parseArguments(std::istream& stream , Command& command);
private:
    template<typename T>
    void setAs(std::istream& stream, std::string key , Command& command){
        T value;
        stream >> value;
        command.m_arguments.setArgument(key, value);
    }

private:
    CommandRegistry commandRegistry_;
};

#endif  //COMMAND_CREATOR_HPP


