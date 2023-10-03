#include "registry.hpp"

template <typename T>
TRegistry<T>::TRegistry()
{
}

template <typename T>
std::unique_ptr<T> TRegistry<T>::findEntry(const std::string& entryName)
{
    auto entryIter = registry_.find(entryName);    
    if(entryIter == registry_.end()){
        throw std::runtime_error("entered invalid name");
    }
    return entryIter->second->clone();
}

template <typename T>
void TRegistry<T>::registerEntry(const std::string &entryName, std::unique_ptr<T> entry)
{
    registry_[entryName] = std::move(entry);
}
