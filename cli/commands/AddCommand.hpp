#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP

#include "command.hpp"
#include "../../document/itemRegistry.hpp"
#include <unordered_set>

class AddCommand: public Command{
public:
    AddCommand();
    std::string exec() override;
    std::unique_ptr<Command> clone() const override;
private:
    ItemRegistry register_;
};

#endif //ADD_COMMADN_HPP