#ifndef QUIT_COMMAND_HPP
#define QUIT_COMMAND_HPP

#include "command.hpp"

class QuitCommand:public Command{
public:
    std::string exec(Document& doc) override;
    std::unique_ptr<Command> clone() const override;
    //void addOperand(std::string key ,std::string value) override;    
};

#endif //QUIT_COMMAND_HPP