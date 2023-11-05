#include "CreateFactory.hpp"
#include "../commands/CreateCommand.hpp"
#include <algorithm>

std::unique_ptr<Command> CreateFactory::makeCommand(const std::vector<std::string> &args)
{
//    validateArgs(args);

    auto command = std::make_unique<CreateCommand>();
    command->setArguments(args);
    return command;
}

void CreateFactory::validateArgs(const std::vector<std::string> &args)
{
    for(auto& validOpt : validOptions){
        if(std::find(args.begin(),args.end(),validOpt) == args.end()){
            throw std::runtime_error("to create slide write [-name Slide]");
        }
    }
}

std::unique_ptr<CommandFactory> CreateFactory::clone() const{
    return std::make_unique<CreateFactory>();
}