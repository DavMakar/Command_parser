#ifndef ADD_COMMAND_FACTORY_HPP
#define ADD_COMMAND_FACTORY_HPP

#include "commandFactory.hpp"

class AddFactory:public CommandFactory{
public:
    std::unique_ptr<Command> makeCommand(const std::vector<std::string>& args) override;
    std::unique_ptr<CommandFactory> clone() const override; 
    void validateArgs(const std::vector<std::string>& args) override;
private:
    std::unordered_set<std::string> validOptions = {"-name"};
};

#endif //ADD_COMMAND_FACTORY_HPP
