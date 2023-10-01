#include "commandRegistry.hpp"

#include "concrete_commands/RemoveCommand.hpp"
#include "concrete_commands/AddCommand.hpp"
#include "concrete_commands/DisplayCommand.hpp"
#include "concrete_commands/ListCommand.hpp"
#include "concrete_commands/QuitCommand.hpp"
#include "concrete_commands/SaveCommand.hpp"
#include "concrete_commands/LoadCommand.hpp"

CommandRegistry::CommandRegistry()
{
    registerCommands();
}

void CommandRegistry::registerCommands(){
    registry_["add"] = std::make_unique<AddCommand>();
    registry_["remove"] = std::make_unique<RemoveCommand>();
    registry_["display"] = std::make_unique<DisplayCommand>();
    registry_["list"] = std::make_unique<ListCommand>();
    registry_["quit"] = std::make_unique<QuitCommand>();
    registry_["load"] = std::make_unique<LoadCommand>();
    registry_["save"] = std::make_unique<SaveCommand>();
}

std::unique_ptr<Command> CommandRegistry::findCommand(std::string commandName) 
{
    auto command_iter = registry_.find(commandName);    
    if(command_iter == registry_.end()){
        throw std::runtime_error("entered invalid command");
    }
    return command_iter->second->clone();
}
