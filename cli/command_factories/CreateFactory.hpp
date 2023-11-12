#ifndef CREATE_COMMAND_FACTORY_HPP
#define CREATE_COMMAND_FACTORY_HPP

#include "commandFactory.hpp"
#include <unordered_set>

class CreateFactory:public CommandFactory{
public:
    std::unique_ptr<Command> makeCommand(const std::vector<std::string>& args) override;
    std::unique_ptr<CommandFactory> clone() const override;
    void validateArgs(const std::vector<std::string>& args) override;
private:
    std::unordered_set<std::string> validOptions = {"-name","Slide"};
};

#endif //CREATE_COMMAND_FACTORY_HPP
