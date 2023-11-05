#ifndef LIST_COMMAND_HPP
#define LIST_COMMAND_HPP

#include "command.hpp"

class ListCommand: public Command{
public:
    std::string exec(IDocument& doc) override;
    std::unique_ptr<Command> clone() const override; 
};

#endif //LIST_COMMAND_HPP
