#include "commandRegistry.hpp"

#include "commands/AddCommand.hpp"
#include "commands/CreateSlideCommand.hpp"
#include "commands/ChangeItemCommand.hpp"
#include "commands/GoSlideCommand.hpp"
#include "commands/DisplayCommand.hpp"
#include "commands/DrawCommand.hpp"
#include "commands/ListCommand.hpp"
#include "commands/LoadCommand.hpp"
#include "commands/UndoCommand.hpp"
#include "commands/RedoCommand.hpp"
#include "commands/SaveCommand.hpp"
#include "commands/QuitCommand.hpp"

CommandRegistry::CommandRegistry()
{
    registry_["add"] = std::make_unique<AddCommand>();
    registry_["createSlide"] = std::make_unique<CreateSlideCommand>();
    //registry_["change"] = std::make_unique<ChangeItemCommand>();
    registry_["goSlide"] = std::make_unique<GoSlideCommand>();
    registry_["display"] = std::make_unique<DisplayCommand>();       
    registry_["draw"] = std::make_unique<DrawCommand>();       
    registry_["list"] = std::make_unique<ListCommand>();
    registry_["load"] = std::make_unique<LoadCommand>();
    registry_["undo"] = std::make_unique<UndoCommand>();
    registry_["redo"] = std::make_unique<RedoCommand>();
    registry_["save"] = std::make_unique<SaveCommand>();
    registry_["quit"] = std::make_unique<QuitCommand>();
}

std::unique_ptr<Command> CommandRegistry::findCommand(const std::string &commandName)
{
    auto commandIter = registry_.find(commandName);    
    if(commandIter == registry_.end()){
        throw std::runtime_error("entered invalid command");
    }
    return commandIter->second->clone();
}
