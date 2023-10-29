#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP

#include "command.hpp"
#include "../item.hpp"
#include "../itemRegistry.hpp"
#include <unordered_set>

class AddCommand: public Command{
public:
    std::string exec(Document& doc) override;
    std::unique_ptr<Command> clone() const override;
private:
    ItemRegistry register_;
    std::unordered_set<std::string> validOptions = {"-name"};
};

#endif //ADD_COMMADN_HPP