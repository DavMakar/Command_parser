#ifndef MUL_COMMAND_HPP
#define MUL_COMMAND_HPP

#include "command.hpp"

class MulCommand: public Command{
public: 
    double exec()const override;
    std::unique_ptr<Command> clone() const override;
};

#endif //MUL_COMMAND_HPP