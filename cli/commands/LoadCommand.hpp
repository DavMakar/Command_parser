#ifndef LOAD_COMMAND_HPP
#define LOAD_COMMAND_HPP

#include "command.hpp"
//#include "../../serializer/SerializerVisitor.hpp"

class LoadCommand:public Command{
public:
    std::string exec() override;
    std::unique_ptr<Command> clone() const override; 
};

#endif //LOAD_COMMAND_HPP
