#ifndef ABSTRACT_COMMAND_HPP
#define ABSTRACT_COMMAND_HPP

#include <vector>
#include <memory>
#include <string>
#include <unordered_map>
#include "../Argument.hpp"

class Command{
public:
    virtual std::string exec() = 0;
    virtual std::unique_ptr<Command> clone() const = 0;    
    virtual ~Command(){};
public:
    Argument m_arguments;    
};

#endif //ABSTRACT_COMMAND_HPP
