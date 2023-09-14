#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <sstream>
#include <vector>
#include <string>
#include "commandRegistry.hpp"
#include "concrete_commands/command.hpp"

class CommandParser{
    public:
        std::unique_ptr<Command> parse(std::string token);
       
    private:
        CommandRegistry register_;
};

#endif // COMMAND_PARSER_HPP