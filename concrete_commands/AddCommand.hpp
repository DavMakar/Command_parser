#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP

#include "command.hpp"

class AddCommand: public Command{
public:
    double exec(const std::vector<double>& operands_)const  override;
};

#endif //ADD_COMMADN_HPP