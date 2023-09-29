#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP

#include "command.hpp"
#include "../itemRegistry.hpp"
#include <unordered_set>


class AddCommand: public Command{
public:
    std::string exec(Iterator argumentBegin, Iterator argumentEnd, ItemList& items) override;
    std::unique_ptr<Command> clone() const override;   
private:
    ItemRegistry register_;
    std::unordered_set<std::string> args = {"-name"};
};

#endif //ADD_COMMADN_HPP