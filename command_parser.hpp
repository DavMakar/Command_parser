#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <sstream>
#include <vector>
#include <string>
#include "registry.hpp"
//#include "commandRegistry.hpp"
#include "concrete_commands/command.hpp"

class CommandParser{
    public:
        CommandParser();
        std::unique_ptr<Command> parse(std::string token);
       
    private:
        void registerCommands();
        TRegistry<Command> register_;
};

#endif // COMMAND_PARSER_HPP