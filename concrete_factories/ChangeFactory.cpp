#include "ChangeFactory.hpp"

#include "../concrete_commands/ChangeSlideCommand.hpp"
#include "../concrete_commands/ChangeItemCommand.hpp"


std::unique_ptr<Command> ChangeFactory::makeCommand(const std::vector<std::string> &args)
{
    validateArgs(args);
    std::unique_ptr<Command> newCommand;
    if (args.front() == "-slide"){
        newCommand = std::make_unique<ChangeSlideCommand>();
    } 
    else if(args.front() == "-item"){
        newCommand = std::make_unique<ChangeItemCommand>();
    }else{
        throw std::runtime_error("ask what to change [-slide] or [-item]");
    }
    std::vector<std::string> commandArgs(std::next(args.begin()),args.end());
    newCommand -> setArguments(std::move(commandArgs));
    return newCommand;
}

void ChangeFactory::validateArgs(const std::vector<std::string> &args)
{
    if(validOptions.find(*args.begin()) == validOptions.end()){
        throw std::runtime_error("valid options [-slide, -item ,-id]");
    }
}

std::unique_ptr<CommandFactory> ChangeFactory::clone() const{
    return std::make_unique<ChangeFactory>();
}