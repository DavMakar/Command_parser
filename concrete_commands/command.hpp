#ifndef ABSTRACT_COMMAND_HPP
#define ABSTRACT_COMMAND_HPP

#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

#include "../item.hpp"
#include "../document.hpp"

using Iterator = std::vector<std::string>::iterator;

class Command{
public:
    virtual std::string exec(Document& slides) = 0;
    virtual std::unique_ptr<Command> clone() const = 0;
    void setArguments(const std::vector<std::string>& args){
        arguments_ = std::move(args);        
    };       
    virtual ~Command(){};
protected:
    std::vector<std::string> arguments_;
};

#endif //ABSTRACT_COMMAND_HPP
