#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP

#include "command.hpp"

class AddCommand: public Command{
public:
    double exec(const double op1,const double op2)const  override;
};

#endif //ADD_COMMADN_HPP