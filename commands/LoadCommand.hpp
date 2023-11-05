#ifndef LOAD_COMMAND_HPP
#define LOAD_COMMAND_HPP

#include "command.hpp"
#include "../command_factories/AddFactory.hpp"
#include "../director.hpp"

class LoadCommand:public Command{
public:
    std::string exec(Document& slides) override;
    std::unique_ptr<Command> clone() const override; 
private:
    Director documentDirector_;
};

#endif //LOAD_COMMAND_HPP
