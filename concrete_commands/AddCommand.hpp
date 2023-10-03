#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP

#include "command.hpp"
#include "../registry.hpp"
#include "../item.hpp"
//#include "../itemRegistry.hpp"
#include <unordered_set>

class AddCommand: public Command{
public:
    AddCommand();
    virtual std::string exec(Iterator argumentBegin, Iterator argumentEnd, ItemList& items);
    virtual std::unique_ptr<Command> clone() const;
private:
    void registerItems();
    TRegistry<Item> register_;
    std::unordered_set<std::string> args = {"-name"};
};

#endif //ADD_COMMADN_HPP