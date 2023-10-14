#ifndef LOAD_COMMAND_HPP
#define LOAD_COMMAND_HPP

#include "command.hpp"
#include "../concrete_factories/AddFactory.hpp"

class LoadCommand:public Command{
public:
    std::string exec(ItemList& items) override;
    std::unique_ptr<Command> clone() const override; 
private:
    AddFactory factory;    
};

#endif //LOAD_COMMAND_HPP
