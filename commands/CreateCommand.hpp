#ifndef CREATE_COMMAND_HPP
#define CREATE_COMMAND_HPP

#include "command.hpp"
#include "../director.hpp"

class CreateCommand: public Command{
public:
    std::string exec(Document& doc) override;
    std::unique_ptr<Command> clone() const override;
private:
    Director documentDirector_;
};

#endif //CREATE_COMMAND_HPP
