#ifndef QUIT_COMMAND_FACTORY_HPP
#define QUIT_COMMAND_FACTORY_HPP

#include "commandFactory.hpp"

class QuitFactory: public CommandFactory{
public:
    std::unique_ptr<Command> makeCommand(const std::vector<std::string>& args)  override;
    std::unique_ptr<CommandFactory> clone() const override;
    void validateArgs(const std::vector<std::string>& args) override;
};

#endif //QUIT_COMMAND_FACTORY_HPP
