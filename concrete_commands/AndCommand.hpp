#ifndef AND_COMMAND_HPP
#define AND_COMMAND_HPP

#include "command.hpp"

class AndCommand: public Command{
public:
    double exec(const std::vector<double>& operands_)const override;
};

#endif //AND_COMMADN_HPP