#ifndef COMMAND_CREATOR_HPP
#define COMMAND_CREATOR_HPP

#include "commands/Command.hpp"
#include "commandRegistry.hpp"

class CommandCreator{
public:
    std::unique_ptr<Command> CreateSlideCommand(std::istream& stream);
    void parseArguments(std::istream& stream , Command& command);
private:
    CommandRegistry commandRegistry_;
};

#endif  //COMMAND_CREATOR_HPP


