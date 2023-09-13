#ifndef COMMAND_REGISTRY_HPP
#define COMMAND_REGISTRY_HPP

#include "concrete_commands/command.hpp"
#include <string_view>
#include <string>
#include <unordered_map>
#include <memory>

using Register = std::unordered_map<std::string, std::unique_ptr<Command>>;


class CommandRegistry
{
public:
    CommandRegistry();

    Command* findCommand(std::string commandName);            
private:
    void registerCommands();
    Register registry_;        
};

#endif