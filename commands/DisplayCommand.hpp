#ifndef DISPLAY_COMMAND_HPP
#define DISPLAY_COMMAND_HPP

#include "command.hpp"
#include <unordered_set>

class DisplayCommand: public Command{
public:
    std::string exec(Document& doc) override;
    std::unique_ptr<Command> clone() const override;
};

#endif //DISPLAY_COMMAND_HPP
