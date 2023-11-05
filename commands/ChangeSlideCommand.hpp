#ifndef CHANGE_SLIDE_COMMAND_HPP
#define CHANGE_SLIDE_COMMAND_HPP

#include "command.hpp"
#include "../director.hpp"

class ChangeSlideCommand: public Command{
public:
    std::string exec(Document& doc) override;
    std::unique_ptr<Command> clone() const override;
private:
    Director documentDirector_;
};

#endif //CHANGE_SLIDE_COMMAND_HPP