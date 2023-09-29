#include "commandRegistry.hpp"

#include "concrete_commands/AddCommand.hpp"
#include "concrete_commands/DisplayCommand.hpp"
#include "concrete_commands/QuitCommand.hpp"

CommandRegistry::CommandRegistry()
{
    registerCommands();
}

void CommandRegistry::registerCommands(){
    registry_["add"] = std::make_unique<AddCommand>();
    registry_["display"] = std::make_unique<DisplayCommand>();
    registry_["quit"] = std::make_unique<QuitCommand>();
}

std::unique_ptr<Command> CommandRegistry::findCommand(std::string commandName) 
{
    auto command_iter = registry_.find(commandName);    
    if(command_iter == registry_.end()){
        throw std::runtime_error("entered invalid command");
    }
    return command_iter->second->clone();
}
