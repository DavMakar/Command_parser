#include "ChangeFactory.hpp"
#include <stdexcept>
#include "../commands/ChangeSlideCommand.hpp"
#include "../commands/ChangeItemCommand.hpp"


std::unique_ptr<Command> ChangeFactory::makeCommand(const std::vector<std::string> &args)
{
    validateArgs(args);
    std::unique_ptr<Command> newCommand = selectCommand(args.front());
    
    std::vector<std::string> commandArgs(std::next(args.begin()),args.end());
    newCommand -> setArguments(std::move(commandArgs));
    return newCommand;
}

std::unique_ptr<Command> ChangeFactory::selectCommand(const std::string &arg)
{
    if(arg != "-slide" && arg != "-item"){
        throw std::runtime_error("ask what to change [-slide] or [-item]");
    }

    if (arg == "-slide"){
       return std::make_unique<ChangeSlideCommand>();
    } 
    return std::make_unique<ChangeItemCommand>();
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
