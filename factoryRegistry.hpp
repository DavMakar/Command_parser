#ifndef FACTORY_REGISTRY_HPP
#define FACTORY_REGISTRY_HPP

#include <unordered_map>
#include <string>
#include <memory>
#include "concrete_factories/commandFactory.hpp"

class FactoryRegistry{

using Register = std::unordered_map<std::string,std::unique_ptr<CommandFactory>>; 

public:
    FactoryRegistry();
    std::unique_ptr<CommandFactory> findFactory(const std::string& entryName);
    void registerFactory(const std::string& entryName, std::unique_ptr<CommandFactory> entry);
private:
    Register registry_;
};

#endif //FACTORY_REGISTRY_HPP
