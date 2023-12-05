#ifndef ARGUMENT_HPP
#define ARGUMENT_HPP

#include <map>
#include <string>
#include <any>
#include <stdexcept>

class Argument{
public:
    using ArgumentContainer = std::map<std::string, std::any>;
    using iterator = ArgumentContainer::iterator;
    using const_iterator = ArgumentContainer::const_iterator;
public:
    template<typename T>
    void setArgument(const std::string& key , T value){
        m_arguments.at(key) = value;
    }
    
    template<typename T>
    T getArgument(const std::string& key){
        try{
            auto value = m_arguments.at(key);
            return std::any_cast<T>(value);
        }
        catch(const std::out_of_range&){
            throw std::out_of_range("key not found on getArgument");
        }
        catch(const std::bad_any_cast&){
            throw ;
        }
    }

    template<typename T>
    void initArgument(const std::string& key , T value){
        m_arguments.insert(std::make_pair(key, value));
    }

    std::any& operator[] (const std::string& key){
        return m_arguments[key];
    }

public:
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

protected:
    ArgumentContainer m_arguments;
};

#endif //ARGUMENT_HPP
