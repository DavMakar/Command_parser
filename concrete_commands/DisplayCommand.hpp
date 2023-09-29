#ifndef DISPLAY_COMMAND_HPP
#define DISPLAY_COMMAND_HPP

#include "command.hpp"
#include <unordered_set>

class DisplayCommand: public Command{
public:
    std::string exec(Iterator argumentBegin, Iterator argumentEnd, ItemList& items) override;
    std::unique_ptr<Command> clone() const override; 
private:
    std::unordered_set<std::string> args = {"-id"};
};

#endif //DISPLAY_COMMAND_HPP
