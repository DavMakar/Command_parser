#ifndef COMMAND_REGISTRY_HPP
#define COMMAND_REGISTRY_HPP

#include <unordered_map>
#include <memory>

#include "commands/command.hpp"

class CommandRegistry
{
using Register = std::unordered_map<std::string, std::unique_ptr<Command>>;

public:
    CommandRegistry();
    std::unique_ptr<Command> findCommand(const std::string& commandName);

private:
    Register registry_;
};

#endif //COMMAND_REGISTRY_HPP