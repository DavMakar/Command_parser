#ifndef QUIT_COMMAND_HPP
#define QUIT_COMMAND_HPP

#include "command.hpp"

class QuitCommand:public Command
{
    public:
        double exec(const std::vector<double>& operands) const override;
};

#endif //QUIT_COMMAND_HPP