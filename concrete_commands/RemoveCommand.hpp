#ifndef REMOVE_COMMAND_HPP
#define REMOVE_COMMAND_HPP

#include "command.hpp"

class RemoveCommand:public Command{
public:
    std::string exec(ItemList& items) override;
    std::unique_ptr<Command> clone() const override;
private:
    std::unordered_set<std::string> args = {"-id"};
};

#endif //REMOVE_COMMAND_HPP