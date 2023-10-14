#ifndef COMMAND_FACTORY_HPP
#define COMMAND_FACTORY_HPP

#include "../concrete_commands/command.hpp"
#include <memory>

class CommandFactory{
public:
    virtual std::unique_ptr<Command> makeCommand(const std::vector<std::string>& args) = 0;
    virtual std::unique_ptr<CommandFactory> clone() const = 0;
    virtual void validateArgs(const std::vector<std::string>& args) =0;
    virtual ~CommandFactory() = default;
};


#endif //COMMAND_FACTORY_HPP