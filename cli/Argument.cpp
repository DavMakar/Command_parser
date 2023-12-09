#include "Argument.hpp"

std::map<std::string, ArgumentType> Argument::argumentTypeMap = {
    {"-name", ArgumentType::STRING},
    {"-text",ArgumentType::STRING},
    {"-size", ArgumentType::INT},
    {"-id", ArgumentType::INT},
    {"-x1", ArgumentType::DOUBLE},
    {"-x2", ArgumentType::DOUBLE},
    {"-y1", ArgumentType::DOUBLE},
    {"-y2", ArgumentType::DOUBLE},
    {"-x", ArgumentType::DOUBLE},
    {"-y", ArgumentType::DOUBLE},
    {"-r", ArgumentType::DOUBLE}
};

Argument::iterator Argument::begin() {
    return m_arguments.begin();
}

Argument::iterator Argument::end() {
    return m_arguments.end();
}

Argument::const_iterator Argument::begin() const {
    return m_arguments.begin();
}

Argument::const_iterator Argument::end() const {
    return m_arguments.end();
}