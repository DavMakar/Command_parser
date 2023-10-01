#ifndef LOAD_COMMAND_HPP
#define LOAD_COMMAND_HPP

#include "AddCommand.hpp"

class LoadCommand:public AddCommand{
public:
    std::string exec(Iterator argumentBegin, Iterator argumentEnd, ItemList& items) override;
    std::unique_ptr<Command> clone() const override; 
private:
    std::unordered_set<std::string> args = {"-file"};
};

#endif //LOAD_COMMAND_HPP
