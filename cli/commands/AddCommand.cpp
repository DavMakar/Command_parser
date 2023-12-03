#include "AddCommand.hpp"
#include "../../director/Director.hpp"
#include <string>

using namespace std::literals;

AddCommand::AddCommand()
{
    arguments_.initArgument("-name",""s);
    arguments_.initArgument("-x",0.0);
    arguments_.initArgument("-y",0.0);
    arguments_.initArgument("-x1", 0.0);
    arguments_.initArgument("-x2", 0.0);
    arguments_.initArgument("-x3", 0.0);
    arguments_.initArgument("-y1", 0.0);
    arguments_.initArgument("-y2", 0.0);
    arguments_.initArgument("-y3", 0.0);
    arguments_.initArgument("-r", 0.0);
    arguments_.initArgument("-text", ""s);
    arguments_.initArgument("-size", 0i);
}

std::string AddCommand::exec()
{
    auto newItem = register_.findItem(arguments_.getArgument<std::string>("-name")); 

    for(auto& option : newItem->getOptions()){
        newItem->setAttribute(option , arguments_[option]);
    }
    Director::getInstance().addItemToSlide(std::move(newItem));

    return "item added"; 
}


std::unique_ptr<Command> AddCommand::clone() const
{
    return std::make_unique<AddCommand>();
}


