#ifndef OR_COMMAND_HPP
#define OR_COMMAND_HPP

#include "command.hpp"

class OrCommand: public Command{
public:
    double exec()const override;
    std::unique_ptr<Command> clone() const override;    
};

#endif //OR_COMMADN_HPP