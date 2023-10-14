#ifndef DISPLAY_COMMAND_FACTORY_HPP
#define DISPLAY_COMMAND_FACTORY_HPP

#include "commandFactory.hpp"

class DisplayFactory:public CommandFactory{
public:
    std::unique_ptr<Command> makeCommand(const std::vector<std::string>& args) override;
    void validateArgs(const std::vector<std::string>& args) override;
    std::unique_ptr<CommandFactory> clone() const override;
private:
    std::unordered_set<std::string> validOpts = {"-id"};
};


#endif //DISPLAY_COMMAND_FACTORY_HPP
