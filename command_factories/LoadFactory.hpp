#ifndef LOAD_COMMAND_FACTORY_HPP
#define LOAD_COMMAND_FACTORY_HPP

#include "commandFactory.hpp"

class LoadFactory: public CommandFactory{
public:
    std::unique_ptr<Command> makeCommand(const std::vector<std::string>& args) override;
    std::unique_ptr<CommandFactory> clone() const override;
    void validateArgs(const std::vector<std::string>& args) override;
private:
    std::unordered_set<std::string> validOptions = {"-file"};
};

#endif //LOAD_COMMAND_FACTORY_HPP
