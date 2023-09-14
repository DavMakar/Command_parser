#ifndef NOT_COMMAND_HPP
#define NOT_COMMAND_HPP

#include "command.hpp"

class NotCommand: public Command{
public:
    double exec()const override;
    std::unique_ptr<Command> clone() const override;    
};

#endif //NOT_COMMADN_HPP