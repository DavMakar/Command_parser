#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "../director.hpp"

class CommandFactory;

class Serializer{
public:
    void load(const std::string& filename);
    void save(const std::string& filename);
private:
    std::unique_ptr<CommandFactory> selectFactory(const std::string& arg);
};

#include "../cli/command_factories/commandFactory.hpp"

#endif //SERIALIZER_HPP