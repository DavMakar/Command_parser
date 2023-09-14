#include "commandRegistry.hpp"

#include "concrete_commands/AddCommand.hpp"
#include "concrete_commands/DivCommand.hpp"
#include "concrete_commands/MulCommand.hpp"
#include "concrete_commands/SubCommand.hpp"
#include "concrete_commands/QuitCommand.hpp"
#include "concrete_commands/AndCommand.hpp"
#include "concrete_commands/OrCommand.hpp"
#include "concrete_commands/NotCommand.hpp"


CommandRegistry::CommandRegistry()
{
    registerCommands();
}

void CommandRegistry::registerCommands(){
    registry_["div"] = std::make_unique<DivCommand>();
    registry_["add"] = std::make_unique<AddCommand>();
    registry_["sub"] = std::make_unique<SubCommand>();
    registry_["mul"] = std::make_unique<MulCommand>();
    registry_["and"] = std::make_unique<AndCommand>();
    registry_["not"] = std::make_unique<NotCommand>();
    registry_["or"] = std::make_unique<OrCommand>();
    registry_["quit"] = std::make_unique<QuitCommand>();
}

std::unique_ptr<Command> CommandRegistry::findCommand(std::string commandName)
{
    auto command_iter = registry_.find(commandName);    
    if(command_iter == registry_.end()){
        throw std::runtime_error("entered invalid command");
    }
    return command_iter->second.get()->clone();
}
