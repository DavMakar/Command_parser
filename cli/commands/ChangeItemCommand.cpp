#include "ChangeItemCommand.hpp"
#include "../../director.hpp"

std::string ChangeItemCommand::exec()
{
    auto id = std::stoi(*std::next(arguments_.begin()));
    Director::getInstance().changeItem(id,std::move(arguments_));
    return "changed";
}

std::unique_ptr<Command> ChangeItemCommand::clone() const
{
    return std::make_unique<ChangeItemCommand>();
}