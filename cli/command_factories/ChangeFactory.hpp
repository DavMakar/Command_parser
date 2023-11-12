#ifndef CHANGE_COMMAND_FACTORY_HPP
#define CHANGE_COMMAND_FACTORY_HPP

#include "commandFactory.hpp"
#include <unordered_set>

class ChangeFactory:public CommandFactory{
public:
    std::unique_ptr<Command> makeCommand(const std::vector<std::string>& args) override;
    std::unique_ptr<Command> selectCommand(const std::string& arg);
    std::unique_ptr<CommandFactory> clone() const override;
    void validateArgs(const std::vector<std::string>& args) override;
private:
    std::unordered_set<std::string> validOptions = {"-slide","-item","-id"};
};

#endif //CHANGE_COMMAND_FACTORY_HPP