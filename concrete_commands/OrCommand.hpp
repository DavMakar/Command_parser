#ifndef OR_COMMAND_HPP
#define OR_COMMAND_HPP

#include "command.hpp"

class OrCommand: public Command{
public:
    double exec(const std::vector<double>& operands_)const override;
};

#endif //OR_COMMADN_HPP