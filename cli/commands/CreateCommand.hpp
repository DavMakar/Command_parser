#ifndef CREATE_COMMAND_HPP
#define CREATE_COMMAND_HPP

#include "command.hpp"

class CreateCommand: public Command{
public:
    CreateCommand();
    std::string exec() override;
    std::unique_ptr<Command> clone() const override;
};

#endif //CREATE_COMMAND_HPP
