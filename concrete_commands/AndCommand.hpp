#ifndef AND_COMMAND_HPP
#define AND_COMMAND_HPP

#include "command.hpp"

class AndCommand: public Command{
public:
    double exec() const override;
    std::unique_ptr<Command> clone() const override;    
};

#endif //AND_COMMADN_HPP