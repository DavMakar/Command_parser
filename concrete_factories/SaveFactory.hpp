#ifndef SAVE_COMMAND_FACTORY_HPP
#define SAVE_COMMAND_FACTORY_HPP

#include "commandFactory.hpp"

class SaveFactory: public CommandFactory{
public:
    std::unique_ptr<Command> makeCommand(const std::vector<std::string>& args) override;
    std::unique_ptr<CommandFactory> clone() const override;
    void validateArgs(const std::vector<std::string>& args) override;
private:
    std::unordered_set<std::string> validOptions = {"-file"};
};

#endif //SAVE_COMMAND_FACTORY_HPP