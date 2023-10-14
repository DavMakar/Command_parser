#ifndef LIST_COMMAND_HPP
#define LIST_COMMAND_HPP

#include "command.hpp"

class ListCommand: public Command{
public:
    std::string exec(ItemList& items) override;
    std::unique_ptr<Command> clone() const override; 
};

#endif //LIST_COMMAND_HPP