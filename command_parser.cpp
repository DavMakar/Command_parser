#include "command_parser.hpp"

std::unique_ptr<Command> CommandParser::parse(std::string token){
    return register_.findCommand(token);
}