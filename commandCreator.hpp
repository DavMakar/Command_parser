#ifndef COMMAND_CREATOR_HPP
#define COMMAND_CREATOR_HPP

#include "concrete_factories/commandFactory.hpp"
#include "concrete_commands/command.hpp"
#include "registry.hpp"


class CommandCreator{
public:
    CommandCreator();
    std::unique_ptr<Command> createCommand(const std::string& commandName, const std::vector<std::string>& args);

private:
    TRegistry<CommandFactory> factoryRegistry_;
    //TODO try CommandFactory::createCommand
};

#endif  //COMMAND_CREATOR_HPP