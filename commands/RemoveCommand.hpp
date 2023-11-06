#ifndef REMOVE_COMMAND_HPP
#define REMOVE_COMMAND_HPP

#include "command.hpp"
#include "../director.hpp"

class RemoveCommand:public Command{
public:
    std::string exec(Document& doc) override;
    std::unique_ptr<Command> clone() const override;
private:
    Director documentDirector_;
};

#endif //REMOVE_COMMAND_HPP