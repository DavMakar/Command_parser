#ifndef COMMAND_CREATOR_HPP
#define COMMAND_CREATOR_HPP

#include "concrete_factories/commandFactory.hpp"
#include "concrete_commands/command.hpp"
#include "factoryRegistry.hpp"

class CommandCreator{
public:
    std::unique_ptr<Command> createCommand(const std::string& commandName, const std::vector<std::string>& args);

private:
    FactoryRegistry factoryRegistry_;
};

#endif  //COMMAND_CREATOR_HPP