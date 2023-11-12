#ifndef LIST_COMMAND_FACTORY_HPP
#define LIST_COMMAND_FACTORY_HPP

#include "commandFactory.hpp"

class ListFactory:public CommandFactory{
public:
    std::unique_ptr<Command> makeCommand(const std::vector<std::string>& args)  override;
    std::unique_ptr<CommandFactory> clone() const override;
    void validateArgs(const std::vector<std::string>& args) override;
};

#endif //LIST_COMMAND_FACTORY_HPP
