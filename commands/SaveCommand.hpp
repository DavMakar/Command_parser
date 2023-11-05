#ifndef SAVE_COMMAND_HPP
#define SAVE_COMMAND_HPP

#include "command.hpp"
#include "../director.hpp"

class SaveCommand:public Command{
public:
    std::string exec(Document& doc) override;
    std::unique_ptr<Command> clone() const override; 
private:
    Director documentDirector_;
};

#endif //SAVE_COMMAND_HPP
