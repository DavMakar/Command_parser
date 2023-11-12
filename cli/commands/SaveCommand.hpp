#ifndef SAVE_COMMAND_HPP
#define SAVE_COMMAND_HPP

#include "command.hpp"
#include "../../serializer/serializer.hpp"

class Director;

class SaveCommand:public Command{
public:
    std::string exec() override;
    std::unique_ptr<Command> clone() const override; 
private:
    Serializer saver;
};

#endif //SAVE_COMMAND_HPP
