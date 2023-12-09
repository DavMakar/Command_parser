#ifndef ARGUMENT_HPP
#define ARGUMENT_HPP

#include <map>
#include <string>
#include <variant>
#include <stdexcept>

enum class ArgumentType :int {
    STRING = 0,
    DOUBLE = 1,
    INT = 2
};

class Argument {
public:
    using ArgumentContainer = std::map<std::string, std::variant<std::string, double, int>>;
    using iterator = ArgumentContainer::iterator;
    using const_iterator = ArgumentContainer::const_iterator;

public:
    template<typename T>
    void setArgument(const std::string& key, T value) {
        m_arguments[key] = value;
    }

    template<typename T>
    T getArgument(const std::string& key) const {
        try {
            auto value = m_arguments.at(key);
            return std::get<T>(value);
        }
        catch(const std::out_of_range&) {
            throw std::out_of_range("Key not found on getArgument");
        }
        catch(const std::bad_variant_access&) {
            throw std::runtime_error("Incorrect type in getArgument for key: " + key);
        }
    }

    template<typename T>
    void initArgument(const std::string& key, T value) {
        m_arguments[key] = value;
    }

    ArgumentType getArgumentType(const std::string& key) const {
        auto it = argumentTypeMap.find(key);
        if (it != argumentTypeMap.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Invalid key : " + key);
        } 
    }
    
    std::variant<std::string, double, int>& operator[](const std::string& key) {
        return m_arguments[key];
    }

public:
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

protected:
    ArgumentContainer m_arguments;

private:
    static std::map<std::string, ArgumentType> argumentTypeMap;
};

#endif //ARGUMENT_HPP