#include "command_parser.hpp"

#include "concrete_commands/RemoveCommand.hpp"
#include "concrete_commands/AddCommand.hpp"
#include "concrete_commands/DisplayCommand.hpp"
#include "concrete_commands/ListCommand.hpp"
#include "concrete_commands/QuitCommand.hpp"
#include "concrete_commands/SaveCommand.hpp"
#include "concrete_commands/LoadCommand.hpp"

CommandParser::CommandParser()
{
    registerCommands();    
}

std::unique_ptr<Command> CommandParser::parse(std::string token)
{
    return register_.findEntry(token);
}

void CommandParser::registerCommands()
{
    register_.registerEntry("add",std::make_unique<AddCommand>());
    register_.registerEntry("remove", std::make_unique<RemoveCommand>());
    register_.registerEntry("display", std::make_unique<DisplayCommand>());
    register_.registerEntry("list" , std::make_unique<ListCommand>());
    register_.registerEntry("quit" , std::make_unique<QuitCommand>());
    register_.registerEntry("load", std::make_unique<LoadCommand>());
    register_.registerEntry("save" , std::make_unique<SaveCommand>());
}
