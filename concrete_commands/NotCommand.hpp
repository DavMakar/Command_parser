#ifndef NOT_COMMAND_HPP
#define NOT_COMMAND_HPP

#include "command.hpp"

class NotCommand: public Command{
public:
    double exec(const std::vector<double>& operands_)const override;
};

#endif //NOT_COMMADN_HPP