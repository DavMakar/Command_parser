#ifndef GENERIC_REGISTRY_HPP
#define GENERIC_REGISTRY_HPP

#include <unordered_map>
#include <string>
#include <memory>

template <typename T>
class TRegistry{

using Register = std::unordered_map<std::string,std::unique_ptr<T>>; 

public:
    TRegistry();
    std::unique_ptr<T> findEntry(const std::string& entryName);
    void registerEntry(const std::string& entryName, std::unique_ptr<T> entry);
private:
    Register registry_;
};

#include "registry.impl.hpp"

#endif //GENERIC_REGISTRY_HPP
