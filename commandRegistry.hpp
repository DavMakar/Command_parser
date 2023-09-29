#ifndef COMMAND_REGISTRY_HPP
#define COMMAND_REGISTRY_HPP

#include "concrete_commands/command.hpp"
#include <string_view>
#include <string>
#include <unordered_map>
#include <memory>

class CommandRegistry
{
using Register = std::unordered_map<std::string, std::unique_ptr<Command>>;

public:
    CommandRegistry();

    std::unique_ptr<Command> findCommand(std::string commandName);            
private:
    void registerCommands();
    Register registry_;        
};

#endif