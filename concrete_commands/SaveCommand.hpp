#ifndef SAVE_COMMAND_HPP
#define SAVE_COMMAND_HPP

#include "command.hpp"

class SaveCommand:public Command{
public:
    std::string exec(Document& doc) override;
    std::unique_ptr<Command> clone() const override; 
private:
    std::unordered_set<std::string> args = {"-file"};
};

#endif //SAVE_COMMAND_HPP
