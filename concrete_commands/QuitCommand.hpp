#ifndef QUIT_COMMAND_HPP
#define QUIT_COMMAND_HPP

#include "command.hpp"

class QuitCommand:public Command
{
    public:
        double exec(const double op1,const double op2)const override;
};

#endif //QUIT_COMMAND_HPP